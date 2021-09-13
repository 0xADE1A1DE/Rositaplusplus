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

def set_from_str(setstr):
    ret = set([])
    i = 0
    inelem = 0
    elemstr = ""
    while i<len(setstr):
        c = setstr[i]
        if c == '{':
            pass
        if c == '}':
            ret.add(elemstr)
        elif c == '\'':
            inelem = 1 - inelem # toggle element start end
        elif c == ',':
            ret.add(elemstr)
            elemstr = ""
        elif inelem == 1:
            elemstr += c

        i+=1
    return ret
