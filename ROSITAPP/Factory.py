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

import StatReader
import StatReaderHO2
import StatReaderHO3
import StatAnalyzer
import DummyStatAnalyzer
import Meta
def build_stat_analyzer():
    analysis = Meta.get_meta().analysis
    if analysis.find('rosita,univ,first-order-ttest') != -1:
        return StatAnalyzer.StatAnalyzer()
    elif analysis.find('rosita,biv,first-order-ttest') != -1:
        return DummyStatAnalyzer.DummyStatAnalyzer()
    elif analysis.find('rosita,triv,first-order-ttest') != -1:
        return DummyStatAnalyzer.DummyStatAnalyzer()
    else:
        raise NotImplementedError()

def build_stat_reader(proptvals):
    analysis = Meta.get_meta().analysis
    if analysis.find('rosita,univ,first-order-ttest') != -1:
        return StatReader.StatReader(proptvals)
    elif analysis.find('rosita,biv,first-order-ttest') != -1:
        return StatReaderHO2.StatReaderHO2(proptvals, 2)
    elif analysis.find('rosita,triv,first-order-ttest') != -1:
        return StatReaderHO3.StatReaderHO3(proptvals, 2)
    else:
        raise NotImplementedError()
