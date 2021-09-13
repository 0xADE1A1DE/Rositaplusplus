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

import inspect
from multiprocessing import Lock
def clean_modname(frame):
    modname = inspect.getmodulename(frame.filename)
    if modname is None:
        return frame.filename + ":" + str(frame.lineno)
    return modname + ":" + str(frame.lineno)
def argstostr(*args):
    ret = ""
    for i, arg in enumerate(args):
        ret += str(arg)
        if i < len(args)-1:
            ret += " "
    return ret
def tobytes(line):
    return line.encode('utf-8')

class LoggerImpl:
    infolog = None
    errorlog = None
    def __init__(self, logfile):
        self.infolog = open(logfile, "wb", buffering=0)
        self.errlog = self.infolog
        self.lock = Lock()
    def log_error(self, *args):
        with self.lock:
            self.errlog.write(tobytes("[E] " + clean_modname(inspect.stack()[2]) + " " + argstostr(*args) + "\n"))
            self.errlog.flush()
    def log_info(self, *args):
        with self.lock:
            self.infolog.write(tobytes("[I] " + clean_modname(inspect.stack()[2]) + " " + argstostr(*args) + "\n"))
            self.infolog.flush()
__g_log = None
def init_log(logfile):
    global __g_log
    __g_log = LoggerImpl(logfile)
def log_info(*args):
    __g_log.log_info(*args)
def log_error(*args):
    __g_log.log_error(*args)
