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

#include "SNRAnalysis.h"
#include "WorkContext.h"
#include <vector>

typedef double real_t;

struct cs_t
{
    real_t mean;
    real_t cs2;
    cs_t() :
        mean(0.0),
        cs2(0.0)
    {}
};

struct snr_analysis_priv_t
{
    traceinfo_t traceinfo;
    analysis_output_t* output;
    uint32_t output_at;
    std::vector<cs_t> cs[2];
    std::vector<cs_t> copycs[2];
    uint32_t copydone[2];
    std::vector<uint32_t> n;
    uint32_t totalproctraces;
};

static uint32_t group(const trace_t* trace)
{
    return (uint32_t)trace->_data[0];
}

snr_analysis_t::snr_analysis_t()
{
    pimpl.init(); 
}
void snr_analysis_t::init(const traceinfo_t *traceinfo, 
                      analysis_output_t* output, 
                      const analysis_opts_t& opts)
{
    pimpl.get()->traceinfo = *traceinfo;
    pimpl.get()->cs[0].resize(traceinfo->nsamples);
    pimpl.get()->cs[1].resize(traceinfo->nsamples);
    pimpl.get()->copycs[0].resize(traceinfo->nsamples);
    pimpl.get()->copycs[1].resize(traceinfo->nsamples);
    pimpl.get()->output = output;
    
    traceinfo_t tout = *traceinfo;
    tout.ndata = 0;
    tout.nterms = 1;
    output->init(&tout);
    
    pimpl.get()->totalproctraces = 0;
    pimpl.get()->n.resize(2);
    pimpl.get()->output_at = wc_gopts_get("at_each_ntraces").get_int();
    
    pimpl.get()->copydone[0] = 0;
    pimpl.get()->copydone[1] = 0;
}
void snr_analysis_t::trace_submit(const trace_t *trace)
{
    auto& ti = pimpl.get()->traceinfo;
    auto& cs = pimpl.get()->cs[group(trace)];
    auto& copycs = pimpl.get()->copycs[group(trace)];
    auto p = pimpl.get();
    int g = group(trace);
    uint32_t n = p->n[g]++;
    
    real_t nx = 1.0/n;
    real_t nn = (n-1.0)/n;
    if (n == 1)
    {
        for (auto i=0u;i<ti.nsamples;i++)
        {
            cs[i].mean = trace->_samples[i];
            cs[i].cs2 = 0;
        }
    }
    else
    {
        for (auto i=0u;i<ti.nsamples;i++)
        {
            real_t delta= trace->_samples[i] - cs[i].mean;
            cs[i].mean = cs[i].mean + delta * nx;
            // Schneider et al. Leakage Assessment Methodology Eq. (3), d=2
            // $s^2 = CM_2; CM_d = CS_d/n; s^2 = CS_2/n$
            cs[i].cs2 = cs[i].cs2 + delta * delta * nn;
        }
    }
    
    uint32_t m = p->output_at/2;
    if (n % m == 0)
    {
        copycs = cs;
        p->copydone[g] = n;
        LogInfo("xd %d %d\n",g, n);
    }
    // calc t-test values at each interval and submit to analysis_output_t
    if ( (p->copydone[0] >0) && (p->copydone[0] == p->copydone[1]) )
    {
        traceinfo_t oi{ti.nsamples, ti.ntraces, 1, 0};
        trace_t outputtrace(&oi);
        uint32_t tracecount = std::min(p->n[0], p->n[1]);
        calc_output(tracecount, &outputtrace);
        
        p->output->on_result_trace(&outputtrace);
        
        p->copydone[0] = 0;
        p->copydone[1] = 0;
    }
    
}
void snr_analysis_t::calc_output(uint32_t outputtraces, trace_t *trace)
{
    auto& cs = pimpl.get()->copycs;
    for (auto index=0u;index<pimpl.get()->traceinfo.nsamples;index++)
    {
        // $ t-test = (m_1 - m_2)/sqrt( s_1^2/n + s_2^2/n ) $
        // $ s^2 = CS_2/n $
        
        double b = 0;
        if ( (cs[1])[index].cs2 != 0.0 )
        {
            b = (cs[0])[index].cs2 / (cs[1])[index].cs2;
        }
        trace->_samples[index] = b;
    }
}
void snr_analysis_t::finit()
{
    auto p = pimpl.get();
    LogInfo("groups %u %u\n",p->n[0],p->n[1]);
    // finish output
    p->output->finit();
}
snr_analysis_t::~snr_analysis_t() 
{
    
}
