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
import Args
import LeakCheck
import StatConfig
import Logger
import numpy as n
import pandas as pd

N_PROP = Config.get_config().cfg_nprops
# only supports first-order,bi-variate leakage
class StatReaderHO3:
    def __init__(self, proptvals, nvariates):
        if nvariates == 1:
            self.init_1(proptvals)
        else:
            self.init_nopropvals()
            #self.init_2(proptvals)

    def init_1(self, proptvals):
        self.tvals_max = pd.read_csv(Config.get_config().elmo_tvalues, header=None).to_numpy(dtype=n.float32).flatten()
        self.props_max = pd.read_csv(Config.get_config().elmo_ptvalues, header=None).to_numpy(dtype=n.float32).flatten()

    def init_nopropvals(self):
        cwd = Config.get_config().elmo_cwd
        elmo_output_dir = Args.get_args().get().elmo_output_dir
        ptrace_ = n.load( cwd + "/" + elmo_output_dir + "/power-triv-fottest.npy" )
        ptrace = ptrace_[ptrace_.shape[0]-1,:]
        self.tvals = ptrace.flatten()

        self.props_map = {}
        # Given that the total combination count is K, n of
        # ^nC_3 = K is given by,
        # n^3 - 3n^2 + 2n - 6K = 0.
        # The depressed cubic of above is,
        # x^3 - x - 6K = 0
        # The real root of this eq is n - 1
        K=ptrace.shape[0]
        C = n.sqrt( ((-6*K)**2)/4.0 - 1/27.0)
        ns = int(round( (3*K+C)**(1/3.0) + (3*K-C)**(1/3.0) )) + 1

        Logger.log_info("ns", ns)

        self.nL = ptrace.shape[0]
        self.TH = LeakCheck.tvaluethres(self.nL)
        self.flat = n.empty((ns,), dtype=n.int32)
        flatidx = 0
        emptylist = list()
        self.tvals_lookup = [None]*ns
        for i in range(0, ns):
            self.tvals_lookup[i] = emptylist.copy()
        self.tvals_max = n.zeros((ns,), dtype=n.float32)
        i=0
        j=0
        k=0
        start_eff_range = StatConfig.get_statconfig().get_sample_range()[0]
        end_eff_range = ns - StatConfig.get_statconfig().get_sample_range()[1] -1
        Logger.log_info("effective sample range:", start_eff_range, end_eff_range)
        while i < ns - 2:
            self.flat[i] = flatidx
            maxtval = self.tvals[flatidx]
            j = i+1
            while j < ns:
                k = j+1
                while k < ns:
                    maxtval = max(maxtval, abs(self.tvals[flatidx]))
                    if ((start_eff_range <= i) and (i <= end_eff_range)) \
                        and ((start_eff_range <= j and j <= end_eff_range)) \
                        and ((start_eff_range <= k and k <= end_eff_range)):
                        if n.abs(self.tvals[flatidx]) > self.TH: # n.abs(self.tvals[flatidx]) > 4.5:
                            self.tvals_lookup[i].append((i,j,k,flatidx))
                            self.tvals_lookup[j].append((j,i,k,flatidx))
                            self.tvals_lookup[k].append((k,i,j,flatidx))
                        self.tvals_max[i] = max(self.tvals_max[i], n.abs(self.tvals[flatidx]))
                        self.tvals_max[j] = max(self.tvals_max[j], n.abs(self.tvals[flatidx]))
                        self.tvals_max[k] = max(self.tvals_max[k], n.abs(self.tvals[flatidx]))
                    flatidx += 1
                    k += 1
                j += 1
            i += 1

    def get_props(self, proptvals):
        props1 = []
        props2 = []
        for i in range(0, N_PROP):
            for j in range(0, N_PROP):
                if proptvals[i*N_PROP + j] > self.TH : # proptvals[i*N_PROP + j] > 4.5:
                    props1 += [i]
                    props2 += [j]
        return (props1, props2)
    def add_props_map(self, i, propslist):
        if i not in self.props_map:
            self.props_map[i] = n.zeros((N_PROP), dtype=n.float32)
        for j in propslist:
            self.props_map[i][j] = 5
    def getinteractions(self, index):
        return self.tvals_lookup[index]
    def gettval(self, index):
        return self.tvals_max[index] 
        #return n.max(n.asarray(self.tvals_lookup[index]))
    def getproptvals(self, index):
        #return self.props_max[index,:]
        if index in self.props_map:
            #print(self.props_map[index])
            return self.props_map[index]
        else:
            return n.zeros((N_PROP), dtype=n.float32)
