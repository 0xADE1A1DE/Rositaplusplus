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

#include "CpSNR.h"
#include "SNRAnalysis.h"
#include "AnalysisOuput.h"
#include "WorkContext.h"
#include "PWFactory.h"
#include "TraceReader.h"
struct cp_snr_priv_t
{
    snr_analysis_t snr;
    analysis_output_t ao;
    std::string ext;
    std::string filename;
    tracereader_t* reader;
    traceinfo_t traceinfo;
    traceinfo_t winti;
};
cp_snr_t::cp_snr_t()
{
    pimpl.init();
}
void cp_snr_t::init(const traceinfo_t *traceinfo, pwtermset_mode_t mode)
{
    std::string outfilepath = wc_generate_path(traceinfo->title.c_str(), "snr.npy");
    pimpl.get()->ao.init(outfilepath.c_str(),"numpy");
    //pimpl.get()->snr.init(traceinfo, &pimpl.get()->ao, {{"at_each_ntraces","500"}});
    pimpl.get()->winti = *traceinfo; 
    pimpl.get()->winti.nsamples = 1000;
    pimpl.get()->winti.nterms = 1;
    //pimpl.get()->corr.init(&pimpl.get()->winti, &pimpl.get()->ao, {{"at_each_ntraces","500"}});
    pimpl.get()->snr.init(traceinfo, &pimpl.get()->ao, {{"at_each_ntraces","10000"}});
    
    
    traceinfo_print("", traceinfo);
}

void cp_snr_t::init(const char* filename)
{
}
void cp_snr_t::process()
{ 

}
void cp_snr_t::process(const trace_t* trace)
{
    pimpl.get()->snr.trace_submit(trace);
}
void cp_snr_t::finit()
{
    pimpl.get()->snr.finit();
}
cp_snr_t::~cp_snr_t()
{}
