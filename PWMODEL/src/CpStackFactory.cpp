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

#include "CpStack.h"
#include "StMean.h"
#include "StNorm.h"
#include "StCorr.h"
#include "StFott.h"
#include "StTraceCombiner.h"
static cp_stack_t* make_meancorr()
{
    auto stmean = new st_mean_t();
    auto stnorm = new st_norm_t(stmean);
    auto stcorr = new st_corr_t();
    auto stcomb = new st_trace_combiner_t();
    
    auto cps = new cp_stack_t();
    cps->stack_add(stmean, 0);
    cps->stack_add(stnorm, 1);
    cps->stack_add(stcomb, 1);
    cps->stack_add(stcorr, 1);
    return cps;
}
static cp_stack_t* make_corr()
{
    auto stcorr = new st_corr_t();
    
    auto cps = new cp_stack_t();
    cps->stack_add(stcorr, 0);
    return cps;
}
static cp_stack_t* make_fott()
{
    auto stfott = new st_fott_t();
    auto stmean = new st_mean_t();
    auto stnorm = new st_norm_t(stmean);
    auto stcomb = new st_trace_combiner_t();
    auto cps = new cp_stack_t();

    cps->stack_add(stmean, 0);
    cps->stack_add(stnorm, 1);
    cps->stack_add(stcomb, 1);
    cps->stack_add(stfott, 1);
    return cps;
}
cp_stack_t* cp_stack_t::make_instance(const std::string& name)
{
    if (name == "meancorr")
    {
        return make_meancorr();
    }
    else if (name == "corr")
    {   
        return make_corr();
    }
    else if (name == "stfott")
    {   
        return make_fott();
    }
    return nullptr;
}

