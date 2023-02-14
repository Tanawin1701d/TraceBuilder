//
// Created by tanawin on 14/2/2566.
//

#include "traceToolFed.h"
#include "staticTraceVar.h"

TRACE_TOOL_FRONT_END::TRACE_TOOL_FRONT_END(){}

void
TRACE_TOOL_FRONT_END::setListenners(THREAD_MODEL* _tmd,
                                    TRACER_BASE* _tracer){
    tmd = _tmd;
    tracer = _tracer;

    assert(tmd != nullptr);
    assert(tracer != nullptr);
}


////////// lagacy pin tracer

LAGACY_PIN_TRACER::LAGACY_PIN_TRACER(std::string _fileName_static,
                                     std::string _fileName_dyn):
        TRACE_TOOL_FRONT_END()
{
    staticFile = new std::ifstream(_fileName_static);
    dynFile    = new std::ifstream(_fileName_dyn);

    assert(staticFile != nullptr);
    assert(dynFile    != nullptr);

}

LAGACY_PIN_TRACER::~LAGACY_PIN_TRACER() noexcept {
    staticFile->close();
    dynFile->close();
    delete staticFile;
    delete dynFile;
}

void
LAGACY_PIN_TRACER::startStaticTrace(){

    staticTraceData presentData;

    std::string line;

    while(std::getline(*staticFile, line)){

        if(!line.empty()) {
            presentData.rawData.push_back(line);
            if(line.substr(ST_IDXL_FETCH_TYPE,  1) == ST_VAL_COMPO_FETCH)
            {
                ///// if we get fetch component type so we should send thread model to decode

            }
        }
    }

}

void
LAGACY_PIN_TRACER::start(){
    //// verify before running
    assert(tmd        != nullptr);
    assert(tracer     != nullptr);
    assert(staticFile != nullptr);
    assert(dynFile    != nullptr);

    startStaticTrace();
    startDynTrace();

}