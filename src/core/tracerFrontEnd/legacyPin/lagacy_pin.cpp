//
// Created by tanawin on 14/2/2566.
//

#include "lagacy_pin.h"


////////// lagacy pin tracer

LAGACY_PIN_TRACER::LAGACY_PIN_TRACER(const std::string& _fileName_static,
                                     const std::string& _fileName_dyn):
        TRACE_TOOL_FRONT_END()
{
    staticFile  = new std::ifstream(_fileName_static);
    dynFile     = new std::ifstream(_fileName_dyn);
    bufferRtObj = new RT_OBJ[MAX_RT_BUFFER];

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
            if(
                    !line.empty() &&
                    line.substr(ST_IDXL_FETCH_TYPE,  1) == ST_VAL_COMPO_FETCH
            )
            {
                ///// if we get fetch component type so we should send thread model to decode
                tmd->onGetStTraceValue(presentData);
                maxInstrNumber++;
            }
        }
    }
}

void
LAGACY_PIN_TRACER::startDynTrace(){

    dynTraceData dynData{};

    //// ask tracer to initialize their runtime instruction
    tracer->onInitialize(maxInstrNumber);
    //// ask tracer to trace each runtime instruction
    uint64_t readedObj_count = 0;
    while (dynFile->read( (char*) (bufferRtObj) , (long)(MAX_RT_BUFFER * sizeof(RT_OBJ)))){

        uint64_t newreaded_count = dynFile->gcount() / (sizeof (RT_OBJ));
        uint64_t cur_batch_count = newreaded_count - readedObj_count;
        readedObj_count          = newreaded_count;

        for (int rtObjIdx = 0; rtObjIdx < cur_batch_count; rtObjIdx++ ){
            dynData.rawData = *(bufferRtObj + rtObjIdx);
            tracer->onGetDynTraceValue(dynData);
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