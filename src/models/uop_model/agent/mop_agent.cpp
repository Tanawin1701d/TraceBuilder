//
// Created by tanawin on 19/7/2566.
//

#include "mop_agent.h"
#include "models/inst_model/rt_instr.h"


namespace traceBuilder::model{

    MOP_AGENT::MOP_AGENT(RT_INSTR* owner): _owner(owner) {
        assert(owner != nullptr);
    }

    void MOP_AGENT::addUopAgent(UOP_AGENT* uopAgentPtr) {
        assert(uopAgentPtr != nullptr);
        _uopAgents.push_back(uopAgentPtr);
    }

    void MOP_AGENT::addUopAgents(const std::vector<UOP_AGENT*>& uopAgents) {
        assert(!uopAgents.empty());
        for (auto uopAgentPtr: uopAgents){
            addUopAgent(uopAgentPtr);
        }
    }

    std::vector<UOP_BASE*> MOP_AGENT::genUops() {
        std::vector<UOP_BASE*> results;
        /** start generate*/
        for (auto uopAgentPtr: _uopAgents){
            uopAgentPtr->genUop();
        }
        /** clean the agent prepare for next */
        for (auto uopAgentPtr: _uopAgents){
            uopAgentPtr->cleanAgent();
        }
        return results;
    }

    void BIND_MOP_AGENT(py::module& m){
        py::class_<MOP_AGENT>(m, "MOP_AGENT")
                .def(py::init<RT_INSTR*>(),
                     py::arg("runtimeInstr"),
                     "mop agent initializer")
                .def("addUopAgent", &MOP_AGENT::addUopAgent)
                .def("addUopAgents", &MOP_AGENT::addUopAgents);
    }
}