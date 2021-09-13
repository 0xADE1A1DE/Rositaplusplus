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
import Config
import StatConfig
import Logger
import numpy as n
import os

class OutputGen:
    def generate_outputs(self, output_dir):
        raise NotImplementedError()


class UniOutputGen(OutputGen):
    def generate_outputs(self, output_dir):
        cwd = Config.get_config().elmo_cwd
        fotttest_tmpl = cwd + '/terms-fottest-%d.npy'
        pfottest = cwd + '/power-fottest-0.npy'
        P = n.load(pfottest)
        P = P[P.shape[0]-1,:]
        n.savetxt(cwd + '/output/fixedvsrandomtstatistics.txt', P)
        A = n.load( fotttest_tmpl % (0) )
        G = n.zeros((A.shape[1],Config.get_config().cfg_nprops), dtype=n.float32)

        for i in range(0,Config.get_config().cfg_nprops):
            A = n.load( fotttest_tmpl % (i) )
            A = A[A.shape[0]-1,:]
            G[:,i] = n.transpose(A)

        n.savetxt(cwd + '/output/fixedvsrandompropttest.txt', G)

class HOOutputGen(OutputGen):
    def __init__(self, hofottestfile):
        self.hofottestfile = hofottestfile
    def generate_outputs(self, output_dir):
        cwd = Config.get_config().elmo_cwd
        P = n.load(cwd + '/' + output_dir + '/' + self.hofottestfile)
        P = P[P.shape[0]-1,:]
        ns = int(n.sqrt(0.25 + 2*P.shape[0]) + 0.5)
        sr_start = StatConfig.get_statconfig().get_sample_range()[0]
        sr_end = ns - StatConfig.get_statconfig().get_sample_range()[1] -1
        flatidx = 0
        Logger.log_info("sr_start:", sr_start, "sr_end:", sr_end, "ns:", ns, "tot:", P.shape[0])
        for i in range(0, ns):
            for j in range(i+1, ns):
                if not ((sr_start <= i and i <= sr_end) and (sr_start <= j and j <= sr_end)):
                    P[flatidx] = 0
                flatidx+=1;
        n.savetxt(cwd + '/output/fixedvsrandomtstatistics.txt', P)

    
class BiOutputGen(HOOutputGen):
    def __init__(self):
        super().__init__("power-biv-fottest.npy")
class TriOutputGen(HOOutputGen):
    def __init__(self):
        super().__init__("power-triv-fottest.npy")
def build_outputgen():
    if Meta.get_meta().analysis.find("univ") >= 0:
        return UniOutputGen()
    elif Meta.get_meta().analysis.find("biv") >= 0:
        return BiOutputGen()
    elif Meta.get_meta().analysis.find("triv") >= 0:
        return TriOutputGen()
    else:
        raise NotImplementedError()

