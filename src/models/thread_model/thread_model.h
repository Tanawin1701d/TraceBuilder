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

    unordered_map<uint64_t, RT_INSTR*> instr_pool; /// map runtime instruction id to runtime instruction


public:
    explicit THREAD_MODEL();
    ~THREAD_MODEL();
    RT_INSTR* getInstrTemplate(uint64_t instr_id);
//    RT_INSTR getInstrWithDynFill(uint64_t          instr_id,
//                                 convertedDynData& dynData);
    void onGetStTraceValue(staticTraceData stData); // for only per instruction

};


#endif //TRACEBUILDER_THREAD_MODEL_H
