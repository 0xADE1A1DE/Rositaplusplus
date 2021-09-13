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
import math
from scipy import stats
import numpy as _np

def get_nsamples(rows):
    if Meta.get_meta().isunivariate():
        return rows
    else:
        # solving fo n in (n-1)n/2 = K, K = self.tftvals.get_nsamples()
        nL = int(_np.sqrt(0.25 + 2*rows) + 0.5)
 
        return nL 

def isleaky(nL, tvalue):
    conf = 0.00001
    confTh = 1.0 - math.pow(1.0-conf, 1.0/nL)
    return _np.abs(tvalue) > stats.norm.ppf(1-confTh/2)

def tvaluethres(nL):
    conf = 0.00001
    confTh = 1.0 - math.pow(1.0-conf, 1.0/nL)
    
    return stats.norm.ppf(1-confTh/2)

def isnotleaky(nL, tvalue):
    return _np.logical_not( isleaky(nL, tvalue) )
