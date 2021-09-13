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
import json

class Meta:
    def __init__(self):
        A=json.load(open(Config.get_config().elmo_meta,'r'))
        self.analysis =A['analysis']
        self.nsamples =A['nsamples']
        self.ntraces =A['ntraces']
        self.terms_dump_file =A['terms_dump']
    def isunivariate(self):
        return self.analysis.find('univ') != -1
__g_meta = None

def get_meta():
    global __g_meta
    if __g_meta == None:
        __g_meta = Meta()
    return __g_meta
