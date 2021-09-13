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
import DeviceContext
import Factory
import Meta
import LeakyTermSearchWorker
import LeakCheck
import Utils
import Logger
import hashlib

class LeakageModelVisitor:
    def on_visit(self, lm, exec_cycles, statreader, asm_inst_lines, asm_inst_idx, asm_trace_lines, asm_trace_idx):
        raise NotImplementedError()
    def on_visiting_done(self):
        pass
class SearchHandler:
    def __init__(self):
        self.ps = LeakyTermSearchWorker.LeakyTermSearchWorker()
    def search_interactions(self, tval, markers, intlist):
        if not Meta.get_meta().isunivariate():
            # only places where intlist len is 0 is where second sample point is 
            # marked leaky since it interacts with a sample point above it
            # if fixes are successful both sample points' leakage is fixed
            # so dont do anything when len(intlist) == 0
            # print(LeakCheck.isleaky(Utils.nc2(Meta.get_meta().nsamples), tval),tval)
            if len(intlist) > 0 and markers.isempty() and LeakCheck.isleaky(Utils.nc2(Meta.get_meta().nsamples), tval): # abs(tval) > 4.5:
                intlist = list(map(lambda t: (t[:-1]), intlist))
                Logger.log_info(intlist)
                markers = self.ps.run(intlist)
        return markers
    def finit(self):
        self.ps.finit()
class Printer(LeakageModelVisitor):
    PR_C_NORMAL = "\033[0;37;40m"
    PR_C_RED = "\033[1;31;40m"
    def __init__(self, args):
        self.ptvala = Factory.build_stat_analyzer()
        self.sh = SearchHandler()
    def on_visit(self, lm, exec_cycles, statreader, asm_inst_lines, asm_inst_idx, asm_trace_lines, asm_trace_idx):
        startmark = ""
        endmark = ""
        tval = statreader.gettval(asm_trace_idx)
        #if abs(tval) > 4.5:
        if LeakCheck.isleaky(Utils.nc2(Meta.get_meta().nsamples), tval):
            if Config.get_config().cfg_leak_mark:
                startmark = Config.get_config().cfg_leak_mark
                endmark = ""
            else:
                startmark = self.PR_C_RED
                endmark = self.PR_C_NORMAL
        
        dbg = lm._get_debug_info(asm_trace_lines[asm_trace_idx])
        if dbg:
            dbg = str(dbg)
        else:
            dbg = ""

        #print(statreader)
        #exit(-1)
        #print(asm_inst_lines[asm_inst_idx])
        #print(len(asm_inst_lines), asm_inst_idx)
        #print(asm_inst_lines[asm_inst_idx])
        markers = self.sh.search_interactions(tval, 
                self.ptvala.get_markers(statreader.getproptvals(asm_trace_idx)), 
                statreader.getinteractions(asm_trace_idx))
        if statreader != []:
            print("%s"%(str(statreader.getinteractions(asm_trace_idx))), 
                # self.ptvala.get_markers(statreader.getproptvals(asm_trace_idx)))
                "\t%s"%(markers),"\t%2s"%startmark,"\t%15.4f" % tval, "\t%4d" % asm_inst_lines[asm_inst_idx].get_line_no(),
                "\t%-30s" % asm_inst_lines[asm_inst_idx].get_line().replace('\t', ' '),
                "\t%4d" % exec_cycles,
                "\t%4d" % asm_trace_idx, "\t%-30s"% asm_trace_lines[asm_trace_idx], " ", dbg ,endmark, sep="")
        else:
            print("XXX","%2s"%startmark,"\t%15.4f" % tval, "\t%4d" % asm_inst_lines[asm_inst_idx].get_line_no(),
                "\t%-30s" % asm_inst_lines[asm_inst_idx].get_line().replace('\t', ' '), 
                "\t%4d" % exec_cycles,
                "\t%4d" % asm_trace_idx, "\t%-30s"% asm_trace_lines[asm_trace_idx], " ", dbg ,endmark, sep="")
    def on_visiting_done(self):
        self.sh.finit()
        
class InstMatcher(LeakageModelVisitor): 
    def __init__(self, matchers, args):
        self.matchers = matchers
        self.leakages = {}
        self.ptvala = Factory.build_stat_analyzer()
        self.sh = SearchHandler()
    def on_visit(self, lm, exec_cycles, statreader, asm_inst_lines, asm_inst_idx, asm_trace_lines, asm_trace_idx):
        tval = statreader.gettval(asm_trace_idx)
        # gather each leaky instruction so that we can operate on them later
        markers = self.sh.search_interactions(tval, self.ptvala.get_markers(statreader.getproptvals(asm_trace_idx)),
                statreader.getinteractions(asm_trace_idx))
        
        #if abs(tval) > 4.5:
        if LeakCheck.isleaky(Utils.nc2(Meta.get_meta().nsamples), tval):
            tup = (asm_inst_lines[asm_inst_idx].get_file().file, asm_inst_lines[asm_inst_idx].get_line_no())
            self.leakages[tup] = (tval, asm_inst_lines, asm_inst_idx, markers)
    def on_visiting_done(self):
        print('=---------')
        self.sh.finit()
    def match(self):
        reps_list = []
        for file, line_no in self.leakages.keys():
            tup = (file, line_no)
            tv, asm, idx, ptmarkers = self.leakages[tup]
            print ("lll ", idx)
            rep_list = []
            for m in self.matchers:
                repnew, prio = m.match(asm, idx, ptmarkers)
                if repnew:
                    rep_list.append((repnew, prio))

            rep_list = sorted(rep_list, key=lambda x:x[1])
            rep = rep_list[-1][0]
            sha = hashlib.sha1()
            for nline in rep.rep_insts:
                sha.update(nline.strip().encode('utf-8'))

            #lastmarkersetstr = rep.src_inst.get_last_editmarkerset()
            hashhex = rep.src_inst.get_last_hash()
            if hashhex:
                if hashhex == sha.hexdigest():
                    #if lastmarkersetstr:
                    #    if rep.markerlist.makeset().issubset(SetFromStr.set_from_str(lastmarkersetstr)):
                    print("warn: removing repeating code replacement!")
                    rep =None
            if rep:
                reps_list.append(rep)

        return reps_list

class CycleAccurateTValEmitter(LeakageModelVisitor):
    def __init__(self, dc: DeviceContext.DeviceContext):
        self.cc = dc.get_cyclecounter() 
        self.ib = dc.get_instbuilder()
    def on_visit(self, lm, exec_cycles, tval, statreader, asm_inst_lines, asm_inst_idx, asm_trace_lines, asm_trace_idx):
        inst = self.ib.build_from_elmoout(asm_trace_lines[asm_trace_idx])
        if inst is None:
            print(0)
        else:
            for i in range(0, self.cc.get_cycle_count(inst)):
                print(tval)
