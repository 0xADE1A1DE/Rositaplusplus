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

import Logger
import os.path 
import json
class StatConfig():
    # default values
    sample_range = [0,0]
    def __init__(self, cwd):
        jsonpath = os.path.join(cwd, "./rosita.json")
        if os.path.exists(jsonpath):
            jsonstr = open(jsonpath,'r').read()
            Logger.log_info("loading stat config from:", jsonpath)
            A = json.loads(jsonstr)
            self.sample_range = A['effective_sample_range']
    def get_sample_range(self):
        return self.sample_range
__g_statconfig = None
def init_statconfig(cwd):
    global __g_statconfig
    __g_statconfig = StatConfig(cwd)
def get_statconfig():
    return __g_statconfig
