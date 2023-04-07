//
// Created by tanawin on 6/1/2566.
//

#ifndef TRACEBUILDER_THREAD_MODEL_H
#define TRACEBUILDER_THREAD_MODEL_H

#include "models/inst_model/rt_instr.h"
#include <sstream>
#include "core/resMng/regMap/regMapper.h"
//// [WARN] please beware about circular link
#include "core/tracerFrontEnd/staticTraceVar.h"
#include "core/tracerFrontEnd/dynTraceVar.h"

typedef int THREAD_ID;

class THREAD_MODEL{

private:

    std::unordered_map<uint64_t, RT_INSTR*> instr_pool; /// map runtime instruction id to runtime instruction


public:
    explicit THREAD_MODEL();
    ~THREAD_MODEL();

    /////// get runtime instruction that not decoded to generate micro-op or added with
    ////////////// runtime data
    RT_INSTR* getInstrTemplate(uint64_t instr_id);

    //////// when tracer collect raw static instruction token which we will decoded it
    void onGetStTraceValue(staticTraceData stData); // for only per instruction

};


#endif //TRACEBUILDER_THREAD_MODEL_H
