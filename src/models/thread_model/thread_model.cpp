//
// Created by tanawin on 6/1/2566.
//

#include "thread_model.h"

namespace traceBuilder::model {

    using namespace traceBuilder::core;

////////////////////////////////////////////////////////////////////////
////////////// instruction model pool

    THREAD_MODEL::THREAD_MODEL() = default;

    THREAD_MODEL::~THREAD_MODEL() = default;

    RT_INSTR_PTR
    THREAD_MODEL::getRtInstr(uint64_t instr_id) {
        assert(instr_id < instrPool.size());
        return instrPool[instr_id];
    }

    void THREAD_MODEL::addDecodedInstr(uint64_t instrId, const MOP_AGENT_PTR& mopAgent) {
        assert(instrId < instrPool.size());
        instrPool[instrId]->setMopAgent(mopAgent);

    }


    void
    THREAD_MODEL::onGetStTraceValue(const staticTraceData& stData) {

        auto newInstr = std::make_shared<RT_INSTR>();
        /// interpret instruction
        newInstr->interpretStaticTracedData(stData.rawData);
        /// insert new instruction to instruction pool
        instrPool.push_back(newInstr);
        assert((instrPool.size()-1) == newInstr->getRtInstrId());
        ////////////////////////////////////////////////////////

    }

    void BIND_THREAD_MODEL(py::module& m){
        py::class_<THREAD_MODEL, std::shared_ptr<THREAD_MODEL>>(m, "THREAD_MODEL")
                .def(py::init<>())
                .def("getRtInstr", &THREAD_MODEL::getRtInstr)
                .def("getAmountInstr", &THREAD_MODEL::getAmountInstr)
                .def("addDecodedInstr", &THREAD_MODEL::addDecodedInstr);
    }

}