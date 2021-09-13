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

import TermSearcher
import TraceNpy as tf
import LeakCheck
import Utils
import Config
import Logger
import Factory

import numpy as np
import random
import time
import os
import sys
from functools import reduce
def norm(x):
    return x - np.mean(x)
# tvalue for difference between two distributions
# and const relative mean
# x - values from fixed vs. random test
# D - mean difference from random vs. random test
# v - variance of values from the random set
def tvaluediff(x, D, v):
    n=np.shape(x)[0]
    y=x[n//2:]
    x=x[:n//2]
    vx = np.var(x)
    vy = np.var(y)
    Xc1 = D + np.sqrt(v) * 6/np.sqrt(n//2)
    Xc0 = D - np.sqrt(v) * 6/np.sqrt(n//2)
    
    mx= np.mean(x)
    my= np.mean(y)
    #print('hhh:', t0, pv0, pn0, t1, pv1, pn1, pv)
    t0 = np.sqrt(n//2) * ((mx - my) - Xc0) / np.sqrt(vx + vy) 
    t1 = np.sqrt(n//2) * (Xc1 - (mx -my)) / np.sqrt(vx + vy)
    return t0, t1
def meandiff(x):
    n=np.shape(x)[0]
    y=x[n//2:]
    x=x[:n//2]
    return (np.mean(x) - np.mean(y), np.var(x-y))
def tvalue(x):
    n=np.shape(x)[0]
    y=x[n//2:]
    x=x[:n//2]
    vx = np.var(x)
    vy = np.var(y)
    t = np.sqrt(n//2) * (np.mean(x)-np.mean(y))/( np.sqrt(vx+vy) )
    V1 = vx / vy
    V1 *= V1
    V2 = vy / vx
    V2 *= V2

    df = (n//2 -1) * (1 + 2 / (V1 + V2) )
    return (t, df)
def setsub(a, b):
    return list(set(a) - set(b))
def defaulttermset():
    termset = list(range(0, 22))
    termset.extend(list(range(24, Config.get_config().cfg_nprops)))
    return termset
def pickterms(sampleterms, termset):
    return np.sum(sampleterms[:, termset], axis=1)
def get_interact_samples(sampleterms, termsets, sampleinds):
    interactsamples = norm(pickterms(sampleterms[0], termsets[0]))
    for i in range(1, len(sampleinds)):
        interactsamples = np.multiply(interactsamples, norm(pickterms(sampleterms[i], termsets[i])))
    return interactsamples
class LeakyTermSearcher(TermSearcher.TermSearcher):

    def __init__(self):
        self.reader = Factory.build_stat_reader(None)
        self.tftraces = tf.TraceNpy()
        self.tftraces.open(Config.get_config().elmo_term_dump)
        
        self.tfrandtraces = tf.TraceNpy()
        self.tfrandtraces.open(Config.get_config().elmo_rand_term_dump)
        
        self.results = {}
        # cleanup
        self.ms = [ 'C','PI','SI','O1', #3
                'O2','B1','B2','WP1', #7
                'WP2','DP1','DP2','WS1', #11
                'WS2','DS1','DS2','Op1I', #15
                'Op2I','B1I','B2I','L', #19
                'S', 'Op1Op2', 'Op1', 'Op2', #23
                'E', 'M', 'Op1*Op2', 'Op2*Op1']
        self.ns = self.tftraces.get_nsamples()
        self.nt = self.tftraces.get_ntraces()
        self.nterms = self.tftraces.get_nterms()
        
        self.traces = self.tftraces.get_traces()
        self.randtraces = self.tfrandtraces.get_traces()
        self.is_transposed = self.tftraces.is_transposed()
        self.TH = LeakCheck.tvaluethres(Utils.nc2(self.ns))
        self.tost_runs = 0
        self.monte_runs = 0
        print('TH', self.TH)
        print('ns', self.ns)
        print('nt', self.nt)
        print('nterms', self.nterms)

    def loadsampledata(self, sampleinds, traces):
        self.sampleterms = []
        print("sampleinds::", sampleinds)
        for s in range(0, len(sampleinds)):
            self.sampleterms += [np.empty((self.nt,self.nterms), dtype=np.float32)]

        for sampleindind in range(0,len(sampleinds)):
            sampleterm = self.sampleterms[sampleindind]
            sampleind = sampleinds[sampleindind]
            for t in range(0, self.nterms):
                if self.is_transposed:
                    sampleterm[:,t] = np.transpose( traces[self.ns*t + sampleind, :] )
                else:
                    sampleterm[:,t] = traces[:,self.ns*t + sampleind]

    def run(self, sampleindslist):
        retmap = {}
        # st: sample index tuple
        for s, st in enumerate(sampleindslist):
            print("info: ", s, st)
            self.loadsampledata(st, self.randtraces)
            startt = time.perf_counter()
            self.process_rand_dist(st)
            print("ttt", time.perf_counter()-startt)
            self.loadsampledata(st, self.traces)
            res = self.run_tost(st)
            #res = self.run_montecarlo(st)
            if len(res) == 0:
                print("search failed for", st)
                continue
            for i, sampleind in enumerate(st):
                print("sss",res)
                mstrset = set(map(lambda a: self.ms[a], res[i]))
                print('info: ext', st, sampleind, mstrset)
                if sampleind in retmap:
                    retmap[sampleind].update(mstrset)
                else:
                    retmap[sampleind] = mstrset
        print("retmap", retmap)
        return retmap
    def run_tost(self, sampleinds):
        print('sample inds',sampleinds)
        termsets = [defaulttermset().copy()] * len(sampleinds)
        termset = defaulttermset().copy() 
        nzterms = len(termsets[0])
        termsets_o = termsets.copy()
        relations = []
        print(sampleinds)
        for s, sampleind in enumerate(sampleinds):
            somerelation = []
            tvals = []
            for t in range(0, nzterms):
                termsets = termsets_o.copy()
                termsets[s] = setsub(termset,[termset[t]])
                meandiff, v = self.meandiffs[(sampleind,t)]
                
                interactsamples = get_interact_samples(self.sampleterms, termsets, sampleinds)
                t0, t1 = tvaluediff(interactsamples, meandiff, v)
                
                # One side t-distribution t values for 0.00001 confidence
                if t0 > 4.5 and t1 > 4.5:
                    somerelation += [termset[t]]
                    #tvals += [(tvalue0, tvalue1)]
                    
            relations += [somerelation]
            if len(somerelation) > 5:
                Logger.log_info("sample inds:", sampleinds, "high rel", tvals, self.reader.gettval(sampleind))
        
        if reduce(lambda x, y: x+len(y), relations, 0) == 0:
            return self.run_montecarlo(sampleinds)
        self.tost_runs += 1
        print("rel",relations)
        return relations
    def process_rand_dist(self, sampleinds):
        print('rand sample inds',sampleinds)
        termsets = [defaulttermset().copy()] * len(sampleinds)
        termset = defaulttermset().copy() 
        nzterms = len(termsets[0])
        termsets_o = termsets.copy()
        
        # collect mean differences and variances for random value set
        self.meandiffs = {}
        
        for s, sampleind in enumerate(sampleinds):
            for t in range(0, nzterms):
                termsets = termsets_o.copy()
                termsets[s] = setsub(termset,[termset[t]])
                interactsamples = get_interact_samples(self.sampleterms, termsets, sampleinds)
               
                self.meandiffs[(sampleind,t)] = meandiff(interactsamples)
                print('mean diff:',(sampleind,t),self.meandiffs[(sampleind,t)])

    # run Monte Carlo simulation for finding leaky terms where 
    # there exists more than two leakages a sample set
    def run_montecarlo(self, sampleinds):
        termsets = [defaulttermset().copy()] * len(sampleinds)
        npdefterms = np.asarray(defaulttermset().copy())
        nzterms = len(termsets[0])
        bins = [ np.zeros((nzterms), dtype=np.int32),
                 np.zeros((nzterms), dtype=np.int32) ]
        totruns = 0
        leakyruns = 0
        ret = [[].copy()] * len(sampleinds)
        while totruns < Config.get_config().cfg_monte_carlo_reps: 
            newtermsets = []
            newtermsetsidx = []
            for ts in termsets:
                newts = random.sample(list(enumerate(ts)), k=len(ts)//2)
                newtermsets += [list(map(lambda x : x[1], newts))]
                newtermsetsidx += [list(map(lambda x : x[0], newts))]
            tvalue, df = self.calc_tvalue_termsets(newtermsets, sampleinds)
            if self.TH < np.abs(tvalue): #np.abs(tvalue) > 4.5:
                for idx in newtermsetsidx[0]:
                    bins[0][idx] += 1
                for idx in newtermsetsidx[1]:
                    bins[1][idx] += 1
                #if totruns > 400:
                #    plt.plot(kk)
                #    plt.show()
                #print(leakyruns,totruns)
                leakyruns += 1
            totruns += 1
        ret = [[].copy()] * len(sampleinds)
        for i,b in enumerate(bins):
            tup = np.nonzero(np.abs(b - np.mean(b)) > Config.get_config().cfg_monte_carlo_std_multplier*np.std(b))
            ret[i] = npdefterms[np.asarray(tup[0])]

        if reduce(lambda x, y: x+len(y), ret, 0) > 0:
            self.monte_runs += 1
        #plt.plot(vals)
        #plt.show()
        print("info monte:", ret)
        return ret
    def get_stats(self):
        return {'monte': self.monte_runs, 'tost': self.tost_runs, 'total': (self.tost_runs + self.monte_runs)}
    # tvalues for termsets from each sample point
    # each sample point at the code has some number of terms (self.nterms) the
    # sum of these are the emulated differential voltage at that point
    def calc_tvalue_termsets(self, termsets, sampleinds):
        interactsamples = get_interact_samples(self.sampleterms, termsets, sampleinds)
        return tvalue(interactsamples)
