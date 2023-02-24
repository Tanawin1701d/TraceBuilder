//
// Created by tanawin on 13/2/2566.
//

#include "decoder.h"

MOP_BASE*
DECODER::decodeMOP(RT_INSTR &rt_instr) {

    assert(simpleMop != nullptr);
    return simpleMop;
}

DECODER::DECODER():
simpleMop(new MOP_SIMPLE()){}
