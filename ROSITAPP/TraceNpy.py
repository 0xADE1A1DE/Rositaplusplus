# Copyright 2021 University of Adelaide
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import numpy.lib.format as npf
import numpy
_header_size_info = {
    (1, 0): ('<H', 'latin1'),
    (2, 0): ('<I', 'latin1'),
    (3, 0): ('<I', 'utf8'),
}

def _read_bytes(fp, size, error_template="ran out of data"):
    data = bytes()
    while True:
        try:
            r = fp.read(size - len(data))
            data += r
            if len(r) == 0 or len(data) == size:
                break
        except io.BlockingIOError:
            pass
    if len(data) != size:
        msg = "EOF: reading %s, expected %d bytes got %d"
        raise ValueError(msg % (error_template, size, len(data)))
    else:
        return data
def _filter_header(s):
    """Clean up 'L' in npz header ints.

    Cleans up the 'L' in strings representing integers. Needed to allow npz
    headers produced in Python2 to be read in Python3.

    Parameters
    ----------
    s : string
        Npy file header.

    Returns
    -------
    header : str
        Cleaned up header.

    """
    import tokenize
    from io import StringIO

    tokens = []
    last_token_was_number = False
    for token in tokenize.generate_tokens(StringIO(s).readline):
        token_type = token[0]
        token_string = token[1]
        if (last_token_was_number and
                token_type == tokenize.NAME and
                token_string == "L"):
            continue
        else:
            tokens.append(token)
        last_token_was_number = (token_type == tokenize.NUMBER)
    return tokenize.untokenize(tokens)

def safe_eval(source):
    import ast
    return ast.literal_eval(source)

def descr_to_dtype(descr):
    '''
    descr may be stored as dtype.descr, which is a list of
    (name, format, [shape]) tuples where format may be a str or a tuple.
    Offsets are not explicitly saved, rather empty fields with
    name, format == '', '|Vn' are added as padding.

    This function reverses the process, eliminating the empty padding fields.
    '''
    if isinstance(descr, str):
        # No padding removal needed
        return numpy.dtype(descr)
    elif isinstance(descr, tuple):
        # subtype, will always have a shape descr[1]
        dt = descr_to_dtype(descr[0])
        return numpy.dtype((dt, descr[1]))

    titles = []
    names = []
    formats = []
    offsets = []
    offset = 0
    for field in descr:
        if len(field) == 2:
            name, descr_str = field
            dt = descr_to_dtype(descr_str)
        else:
            name, descr_str, shape = field
            dt = numpy.dtype((descr_to_dtype(descr_str), shape))

        # Ignore padding bytes, which will be void bytes with '' as name
        # Once support for blank names is removed, only "if name == ''" needed)
        is_pad = (name == '' and dt.type is numpy.void and dt.names is None)
        if not is_pad:
            title, name = name if isinstance(name, tuple) else (None, name)
            titles.append(title)
            names.append(name)
            formats.append(dt)
            offsets.append(offset)
        offset += dt.itemsize

    return numpy.dtype({'names': names, 'formats': formats, 'titles': titles,
                        'offsets': offsets, 'itemsize': offset})

class TraceNpy:
    def open(self, filename):
        self.filename = filename
        fp = open(filename, 'rb')
        import struct
        import ast
    
        version = npf.read_magic(fp)
        hinfo = _header_size_info.get(version)
        if hinfo is None:
            raise ValueError("Invalid version {!r}".format(version))
        hlength_type, encoding = hinfo
        
        hlength_str = _read_bytes(fp, struct.calcsize(hlength_type), "array header length")
        header_length = struct.unpack(hlength_type, hlength_str)[0]
        header = _read_bytes(fp, header_length, "array header")
        header = header.decode(encoding)
        offset = fp.tell()
        header_dict = ast.literal_eval(header)
        self.ntraces = header_dict['shape'][0]
        self.nsamples = header_dict['shape'][1]
        self.transposed = False
        if 'other' in header_dict:
            # ugly hack for transposed numpy files
            splits = header_dict['other'].split()
            self.nterms = int(splits[1])
            self.nsamples = int(splits[2])
            if self.ntraces != int(splits[3]):
                self.transposed = True
            self.ntraces = int(splits[3])
        else:
            self.nterms = 1
        print(header_dict, filename)

        header = _filter_header(header)
        try:
            d = safe_eval(header)
        except SyntaxError as e:
            msg = "Cannot parse header: {!r}\nException: {!r}"
            raise ValueError(msg.format(header, e))
        if not isinstance(d, dict):
            msg = "Header is not a dictionary: {!r}"
            raise ValueError(msg.format(d))
        keys = sorted(d.keys())

        # Sanity-check the values.
        if (not isinstance(d['shape'], tuple) or
                not numpy.all([isinstance(x, int) for x in d['shape']])):
            msg = "shape is not valid: {!r}"
            raise ValueError(msg.format(d['shape']))
        if not isinstance(d['fortran_order'], bool):
            msg = "fortran_order is not a valid bool: {!r}"
            raise ValueError(msg.format(d['fortran_order']))
        try:
            dtype = descr_to_dtype(d['descr'])
        except TypeError:
            msg = "descr is not a valid dtype descriptor: {!r}"
            raise ValueError(msg.format(d['descr']))

        if d['fortran_order']:
            order = 'F'
        else:
            order = 'C'

        fp.close()

        self.traces = numpy.memmap(filename, dtype=dtype, shape=d['shape'],
                                   order=order,
                                   mode='r+', offset=offset)

        #self.traces = npf.open_memmap(self.filename, mode='r')

    def is_transposed(self):
        return self.transposed
    def get_nsamples(self):
        return self.nsamples
    def get_ntraces(self):
        return self.ntraces
    def get_nterms(self):
        return self.nterms
    def get_traces(self):
        return self.traces
