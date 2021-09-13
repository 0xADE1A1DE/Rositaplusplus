#! /usr/bin/python3
#
# Based on the equations from the paper
#
# A. A. Ding, L. Zhang, F. Durvaux, F.-X. Standaert, and Y. Fei, 
# “Towards sound and optimal leakage detection procedure,” in 
# CARDIS, 2017, vol. 10728, pp. 105–122,
# [Online]. Available: https://eprint.iacr.org/2017/287.pdf.

import numpy as n
import sys
import re
import math
from scipy.stats import t

def load_index(numpyfile, ind):
    T = n.load(numpyfile)
    selindex = int(ind)
    T = T[selindex,:]
    return T
def help():
    print("genttestthreshold.py <variance-numpy> <select-trace-index> <total-traces>")

var = [None, None]

N = int(sys.argv[3])//2

for i in range(0, 2):
    newf = re.sub(r"(\d+).npy", str(i) + ".npy", sys.argv[1])
    var[i] = load_index(newf, int(sys.argv[2]))
S = var[0].shape[0]    
for i in range(0, var[0].shape[0]):
    vs = (var[0][i]/N + var[1][i]/N)**2 / ( (var[0][i]/N)**2/(N-1) + (var[0][i]/N)**2/(N-1) )

    conf = 0.00001
    alphaTh = 1.0 - math.pow(1.0-conf, 1.0/S)
    print(t.ppf(1 - alphaTh/2, df=vs))



