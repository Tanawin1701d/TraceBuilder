//
// Created by tanawin on 19/7/2566.
//

#include "mop_agent.h"
#include "models/inst_model/rt_instr.h"


namespace traceBuilder::model{

    MOP_AGENT::MOP_AGENT(RT_INSTR* owner): _owner(owner) {
        assert(owner != nullptr);
    }

    OPR_TREG* MOP_AGENT::createAndAddTempOpr(int tRegId) {
        auto oprTemp = new OPR_TREG(tRegId);
        tempOperands.push_back(oprTemp);
        return oprTemp;
    }

    void MOP_AGENT::addUopAgent(const UOP_AGENT_PTR& uopAgentPtr) {
        assert(uopAgentPtr != nullptr);
        _uopAgents.push_back(uopAgentPtr);
    }

    void MOP_AGENT::addUopAgents(const std::vector<UOP_AGENT_PTR>& uopAgents) {
        assert(!uopAgents.empty());
        //assert(uopAgents.size() == 1);
        for (const auto& uopAgentPtr: uopAgents){
            addUopAgent(uopAgentPtr);
        }
    }

    std::vector<UOP_BASE*> MOP_AGENT::genUops() {
        std::vector<UOP_BASE*> results;
        /** start generate*/
        results.reserve(_uopAgents.size());
        for (const auto& uopAgentPtr: _uopAgents){
            results.push_back(uopAgentPtr->genUop());
        }
        /** clean the agent prepare for next */
        for (const auto& uopAgentPtr: _uopAgents){
            uopAgentPtr->cleanAgent();
        }
        return results;
    }

    MOP_AGENT_PTR MOP_AGENT::MOP_AGENT_CLONE()
    {
        auto clonedMopAgent = std::make_shared<MOP_AGENT>(_owner);
        /** tempOperand we use same as old agent because it are created uniq for each instruction*/
        clonedMopAgent->tempOperands = tempOperands;
        for (const auto& uopAgentPtr: _uopAgents){
            clonedMopAgent->_uopAgents.push_back(uopAgentPtr->UOP_AGENT_CLONE());
        }
        return clonedMopAgent;
    }

    void BIND_MOP_AGENT(py::module& m){
        py::class_<MOP_AGENT, std::shared_ptr<MOP_AGENT>>(m, "MOP")
                .def(py::init<RT_INSTR*>(),
                     py::arg("runtimeInstr"),
                     "mop agent initializer")
                .def("buildTOpr", &MOP_AGENT::createAndAddTempOpr)
                .def("addUopAgent", &MOP_AGENT::addUopAgent)
                .def("addUopAgents", &MOP_AGENT::addUopAgents);
    }
}