//
// Created by tanawin on 28/12/2565.
//

#ifndef TRACEBUILDER_RTINSTR_H
#define TRACEBUILDER_RTINSTR_H


////// runtime instr it like dynamic instruction in gem5

#include "operand.h"

class RT_INSTR{
private:
    /////// src operand data and metadata
    vector<REG_OPERAND> srcRegOperands;
    vector<LD_OPERAND>  srcLdOperands;
    vector<IMM_OPERAND> srcImmOperands;
    /////// des operand data and metadata
    vector<RE>
    /////// micro op
};


#endif //TRACEBUILDER_RTINSTR_H
