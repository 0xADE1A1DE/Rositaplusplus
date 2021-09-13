import pandas as pd
import numpy as np
import sys
A= pd.read_csv(sys.argv[1], header=None).to_numpy(dtype=np.float32).flatten()
B= pd.read_csv(sys.argv[2], header=None).to_numpy(dtype=np.float32).flatten()

C=np.abs(A-B)
print('norm err:', np.sum(C)/np.shape(A)[0])

print('max err:', np.max(C))
