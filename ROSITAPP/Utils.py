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

# n choose r, when r==2
def nc2(n):
    return n*(n-1)/2

def iscxxfile(file):
    return file.endswith(".cpp") | file.endswith(".cc")

def iscfile(file):
    return file.endswith(".c")

def isasfile(file):
    return file.endswith(".s")

def isobjfile(file):
    return file.endswith(".o")

def backupfile(f):
    import os
    i = 0
    TMPL = ".bak.%d"
    newf = ""
    while True:
        fn = f+ TMPL % (i)
        if os.path.isfile(fn):
            i += 1
        else:
            newf = fn
            break
    os.renames(f, newf)

