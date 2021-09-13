import sys
import numpy as n

C = n.load(sys.argv[1])
C = C[C.shape[0]-1,:]
#C = C[257,:]
ns = int(n.sqrt(0.25 + 2*C.shape[0]) + 0.5)

cc=0
A = n.zeros((ns), dtype=n.float32)
L = [-1] * (ns)
for i in range(ns):
    for j in range(i+1, ns):
        if A[i] < n.abs(C[cc]):
            L[i] = j
            A[i] = n.abs(C[cc])
        cc+=1

n.savetxt(sys.argv[2],A)

n.savetxt(sys.argv[2]+".cmb",n.asarray(L,dtype=n.int32), fmt="%d")
