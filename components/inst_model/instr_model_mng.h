//
// Created by tanawin on 6/1/2566.
//

#ifndef TRACEBUILDER_INSTR_MODEL_MNG_H
#define TRACEBUILDER_INSTR_MODEL_MNG_H

#include "../regMap/regMapper.h"
#include "rt_instr.h"
#include "../../tracerFrontEnd/staticTraceVar.h"


class INSTR_MODEL_MANAGER{

private:

    unordered_map<uint64_t, RT_INSTR*> instr_pool; /// map runtime instruction id to runtime instruction
    ifstream* inputFile;


public:
    explicit INSTR_MODEL_MANAGER(const string& instr_model_file);
    ~INSTR_MODEL_MANAGER();
    RT_INSTR getInstrTemplate(uint64_t instr_id);


};


#endif //TRACEBUILDER_INSTR_MODEL_MNG_H
