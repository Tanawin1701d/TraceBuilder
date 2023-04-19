//
// Created by tanawin on 13/2/2566.
//

#include "decoder.h"

MOP_BASE*
DECODER_BASE::decodeMOP(RT_INSTR &rt_instr) {

    assert(simpleMop != nullptr);
    return simpleMop;
}

DECODER_BASE::DECODER_BASE():
simpleMop(new MOP_SIMPLE()){
    simpleMop->setIsAutoGen();
}
