// Copyright 2021 University of Adelaide
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "Analysis.h"
#include "PImpl.h"

struct first_order_ttest_analysis_priv_t;

class first_order_ttest_analysis_t : public analysis_t
{
public:
    struct is_sample_independent {};
    
    first_order_ttest_analysis_t();
    first_order_ttest_analysis_t(const first_order_ttest_analysis_t&);
    first_order_ttest_analysis_t(first_order_ttest_analysis_t&&);
    void init(const traceinfo_t *traceinfo, 
              analysis_output_t* output, const analysis_opts_t& opts = {});
    void trace_submit(const trace_t *trace);
    void finit();
    ~first_order_ttest_analysis_t();
private:
    void calc_output(uint32_t outputtraces, trace_t *trace);
    void var_output(uint32_t outputtraces, trace_t *trace, int group);
    
    PImpl<first_order_ttest_analysis_priv_t> pimpl;
};