//
// Created by tanawin on 6/1/2566.
//

#ifndef TRACEBUILDER_THREAD_MODEL_H
#define TRACEBUILDER_THREAD_MODEL_H

#include "../inst_model/rt_instr.h"
#include <fstream>
#include "../../resMng/regMap/regMapper.h"
#include "../../tracerFrontEnd/staticTraceVar.h"

typedef int THREAD_ID;

class THREAD_MODEL{

private:

    unordered_map<uint64_t, RT_INSTR*> instr_pool; /// map runtime instruction id to runtime instruction
    ifstream* inputFile;


public:
    explicit THREAD_MODEL(const string& instr_model_file);
    ~THREAD_MODEL();
    RT_INSTR getInstrTemplate(uint64_t instr_id);
    // TODO we will inject the runtime value to the operand and we will get runtime instruction that ready to compute
    RT_INSTR getRtInstrfromRtTrace(const string& raw);


};


#endif //TRACEBUILDER_THREAD_MODEL_H
