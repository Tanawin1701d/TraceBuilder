//
// Created by tanawin on 13/2/2566.
//

#ifndef TRACEBUILDER_DECODER_H
#define TRACEBUILDER_DECODER_H

#include "mop_base.h"



//// decoder for input is runtime instruction
//// output is uop base class

//// if it is x86 decoder we will use another file.

class RT_INSTR;
class DECODER{
protected:
    MOP_SIMPLE* simpleMop;

public:
    DECODER();
    virtual MOP_BASE* decodeMOP(RT_INSTR& rt_instr);

};

#endif //TRACEBUILDER_DECODER_H
