//
// Created by tanawin on 17/6/2566.
//

#include "tbdGem5ISA.h"


namespace traceBuilder::core{

    TBD_GEM5_ISA::TBD_GEM5_ISA(const std::string &machProtoFilePath):
    desFileStream(new ProtoOutputStream(machProtoFilePath))
    {}

    void TBD_GEM5_ISA::onGetUopsResult(std::vector<UOP_BASE*>& result, RT_INSTR* rt_instr) {

    }

    void TBD_GEM5_ISA::setRes(CORE *core,
                              SHARED_TRACEINFO *sharedInfo,
                              SPECIFIC_TRACEINFO *specificInfo) {}


}