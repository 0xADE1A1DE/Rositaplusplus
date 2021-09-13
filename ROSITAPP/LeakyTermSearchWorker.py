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

import Meta
import Args
import MarkerListFO
import TermSearcher
import LeakyTermSearcher
import Utils
import Config
import Logger

from collections import defaultdict
import numpy as np
import random
from multiprocessing import Process, Queue
from queue import Empty
import pickle
import os
import time
import sys
import pprint

def p_run(qin: Queue, qout: Queue, con: Queue):
    obj = LeakyTermSearcher.LeakyTermSearcher()
    while con.empty():
        try:
            arg = qin.get(False)
            startt = time.perf_counter()
            ret = obj.run(arg)
            endt = time.perf_counter()
            print('info: ret',ret, 'time:', endt - startt)
            qout.put((tuple(arg),ret))
        except Empty:
            time.sleep(1)
            pass
    print("joining", obj.get_stats())
    Logger.log_info("stat:", obj.get_stats())

class LeakyTermSearchWorkerSave(TermSearcher.TermSearcher):
    def __init__(self):
        self.qin = Queue()
        self.qout = Queue()
        self.con = Queue()
        self.p = []
        self.sentset = set([])
        for i in range(0, Config.get_config().cfg_leak_search_threads):
            self.p += [Process(target=p_run, args=(self.qin,self.qout,self.con))]
            print("info: started work on %d"%(i))
            self.p[i].daemon = True
            self.p[i].start()
    def run(self, sampleindslist):
        tt = tuple(sampleindslist)
        if tt not in self.sentset:
            self.qin.put(sampleindslist)
            self.sentset.add(tt)
        # no result can be provided at this moment as 
        # the worker threads are loaded, so return {} and
        # wait for results to be written to file 
        # only ./rosita-$suffix -d -m <bc> gives correct
        # output 
        return MarkerListFO.MarkerListFO(set([]))
    def run_once(self, sampleinds):
        return []
    def finit(self):
        print("info: main thread waiting")
        dumplist = {}
        while len(self.sentset) != 0:
            try:
                ret = self.qout.get(block=False)
                dumplist[ret[0]] = ret[1]
                self.sentset.remove(tuple(ret[0]))
            except Empty:
                time.sleep(2)
        fnobjs = Config.get_config().cwd + "/objs.pickled"
        if os._exists(fnobjs):
            Utils.backupfile(fnobjs)
        fout = open(fnobjs, "wb")
        pickle.dump(dumplist,fout)
        fout.close()
        ftout = open("objs.txt","w")
        pprint.pprint(dumplist, ftout)
        ftout.close()
        print("info: output written")

        self.con.put(None)
        for i in range(0, Config.get_config().cfg_leak_search_threads):
            print("info: %d joined"%(i))
            self.p[i].join()

class LeakyTermSearchWorkerLoad(TermSearcher.TermSearcher):
    def __init__(self):
        self.dummy = True
        objsname = Config.get_config().cwd + "/objs.pickled"
        self.marker_map_by_inst = defaultdict(set)
        if os.path.exists(objsname):
            fin = open(objsname,"rb")
            self.marker_map = pickle.load(fin)
            print('info c:', self.marker_map)
            self.dummy = False
            # merge all results
            for key, smap in self.marker_map.items():
                for skey, sval in smap.items():
                    self.marker_map_by_inst[skey].update(sval)
        #else:
        #    raise FileNotFoundError(objsname)
    def run(self, sampleindslist):
        if self.dummy == False:
            try:
                return MarkerListFO.MarkerListFO(self.marker_map_by_inst[sampleindslist[0][0]])
            except:
                print('not found:', tuple(sampleindslist), file=sys.stderr)
                print(self.marker_map, file=sys.stderr)
                exit(-1)
        return MarkerListFO.MarkerListFO(set())
    def run_once(self, sampleinds):
        return []
    

class LeakyTermSearchWorker(TermSearcher.TermSearcher):
    def __init__(self):
        self.wrapped = None
        if Args.get_args().get().save:
            self.wrapped = LeakyTermSearchWorkerSave()
        else:
            self.wrapped = LeakyTermSearchWorkerLoad()

    def run(self, sampleindslist):
        return self.wrapped.run(sampleindslist)
    def run_once(self, sampleinds):
        return self.wrapped.run_once(sampleinds)
    def finit(self):
        return self.wrapped.finit()
