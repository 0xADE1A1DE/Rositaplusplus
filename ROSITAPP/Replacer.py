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

import Config
import Utils
import Logger
import os
import sys
import hashlib

class Replacer:
    def __init__(self):
        pass
    # get all replacements per file and produce new file, then rename 
    # it to overwrite old file
    def replace(self, reps, isdry=False):
        rep_dict = {}
        for rep in reps:
            if rep.file.file not in rep_dict:
                rep_dict[rep.file.file] = { rep.src_lineno : rep }
            else:
                rep_dict[rep.file.file][rep.src_lineno] = rep

        for f in rep_dict.keys():
            f_reps_dict = rep_dict[f]
            fsrc = open(f)
            line_no = 1
            fdest =None
            if isdry:
                fdest = sys.stdout #open(sys.stdout,"w")
            else:
                fdest = open(f + ".tmp", "w")

            lines = list(fsrc.readlines())
            while len(lines) > line_no -1:
                if isdry:
                    line =  str(line_no) + "\t" 
                else:
                    line = ""
                line += lines[line_no -1]
                    
                if line_no in f_reps_dict:
                    print("> Replacing:", line.strip(), line_no, f_reps_dict[line_no].src_length, 
                            f_reps_dict[line_no].markerlist)

                    Logger.log_info("> Replacing:", line.strip(), line_no, f_reps_dict[line_no].src_length, 
                            f_reps_dict[line_no].markerlist)

                    sha = hashlib.sha1()
                    for nline in f_reps_dict[line_no].rep_insts:
                        print("> \t", nline.strip(), f_reps_dict[line_no].from_matcher)
                        Logger.log_info("> \t", nline.strip(), f_reps_dict[line_no].from_matcher)
                        sha.update(nline.strip().encode('utf-8'))

                    markerlist = f_reps_dict[line_no].markerlist
                    replist = f_reps_dict[line_no].rep_insts
            
                    Logger.log_info("line_no", line_no, "markers", markerlist) 
                    for i, nline in enumerate(replist):
                        nline = nline.strip()
                        nline += Config.get_config().cfg_mod_line_end_marker
                        if i == len(replist) -1:
                            nline += " " + str(markerlist) + " hash {" + sha.hexdigest() + "}"
                        nline += "\n"
                        fdest.write(nline)
                    # number of lines to skip
                    lno_ignore = f_reps_dict[line_no].src_length

                    lno = 0
                    while lno < lno_ignore:
                        line = lines[line_no -1]
                        if line.strip()[0] == '.' or line.strip()[0] == '@':
                            fdest.write(line)
                        else:
                            lno +=1
                        line_no +=1
                else:
                    fdest.write(line)
                    line_no += 1
            fdest.close()
            fsrc.close()

            if not isdry:
                Utils.backupfile(f)
                os.renames(f+".tmp", f)
            
