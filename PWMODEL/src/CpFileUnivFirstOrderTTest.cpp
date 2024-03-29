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

#include <vector>

#include "Trace.h"
#include "CpFileUnivFirstOrderTTest.h"
#include "FirstOrderTTestAnalysis.h"
#include "AnalysisOuput.h"
#include "PWFactory.h"
#include "TraceUtils.h"
#include "Passes.h"

struct cp_file_univ_first_order_ttest_priv_t
{
    analysis_output_t aos;
    analysis_t* fottests;
    traceinfo_t traceinfo;
    pwtermset_mode_t mode;
};

cp_file_univ_first_order_ttest_t::cp_file_univ_first_order_ttest_t()
{
    pimpl.init();
}
void cp_file_univ_first_order_ttest_t::init(const traceinfo_t *traceinfo, pwtermset_mode_t mode)
{
    auto p = pimpl.get();
    p->mode = mode;
    p->traceinfo = *traceinfo;
    p->mode = mode;

    std::vector<char> outfilepath(255);
    snprintf(outfilepath.data(), 254, "%s-univ-fottest.npy", traceinfo->title.c_str());
    p->fottests = pwfactory_t::get_instance()->new_analysis("first-order-ttest");
    p->aos.init(outfilepath.data(), "numpy");
    p->fottests->init(traceinfo, &p->aos);
}
void cp_file_univ_first_order_ttest_t::process(const trace_t* trace)
{
    auto p = pimpl.get();
    pwpass_moving_average(const_cast<trace_t*>(trace)); 
    p->fottests->trace_submit(trace);
}
void cp_file_univ_first_order_ttest_t::finit()
{
    auto p = pimpl.get();
    
    p->fottests->finit();
}
cp_file_univ_first_order_ttest_t::~cp_file_univ_first_order_ttest_t()
{
}
