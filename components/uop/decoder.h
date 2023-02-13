//
// Created by tanawin on 13/2/2566.
//

#ifndef TRACEBUILDER_DECODER_H
#define TRACEBUILDER_DECODER_H

#include "../inst_model/rt_instr.h"
#include "uop_base.h"



//// decoder for input is runtime instruction
//// output is uop base class

//// if it is x86 decoder we will use another file.
class DECODER{
public:
    vector<UOP_BASE*> decode(RT_INSTR& rt_instr);
};

#endif //TRACEBUILDER_DECODER_H
