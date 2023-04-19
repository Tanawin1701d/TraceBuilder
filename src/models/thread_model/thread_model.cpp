//
// Created by tanawin on 6/1/2566.
//

#include "thread_model.h"

////////////////////////////////////////////////////////////////////////
////////////// instruction model pool

THREAD_MODEL::THREAD_MODEL()
{}

THREAD_MODEL::~THREAD_MODEL() {
    for (auto& e : instr_pool){
        delete e.second;
    }
}

RT_INSTR*
THREAD_MODEL::getInstrTemplate(uint64_t instr_id) {
    auto finder = instr_pool.find(instr_id);
    assert( finder != instr_pool.end() );
    auto* ret_rt = new RT_INSTR(*(finder->second));
    return ret_rt;

}


void
THREAD_MODEL::onGetStTraceValue(staticTraceData stData) {

    auto* newInstr = new RT_INSTR();
    /// interpret instruction
    newInstr->interpretStaticTracedData(stData.rawData);
    /// insert new instruction to instruction pool
    instr_pool.insert({newInstr->getRtInstrId(), newInstr});
    ////////////////////////////////////////////////////////

}