//
// Created by tanawin on 19/7/2566.
//

#include "mop_agent.h"
#include "models/inst_model/rt_instr.h"
#include "stat/statPool.h"


namespace traceBuilder::model{

    MOP_AGENT::MOP_AGENT(RT_INSTR* owner): _owner(owner) {
        assert(owner != nullptr);
    }

//    OPR_TREG_PTR MOP_AGENT::createAndAddTempOpr(int tRegId) {
//        auto oprTemp = std::make_shared<OPR_TREG>(tRegId);
//        tempOperandsPtr.push_back(oprTemp);
//        return oprTemp;
//    }
//
//    OPR_REG_PTR MOP_AGENT::createAndAddRegOpr(int archRegId, int maxSubRegId) {
//        AREGNUM reg = {archRegId, maxSubRegId};
//        auto oprReg = std::make_shared<OPR_REG>(reg, -1);
//        regOperandsPtr.push_back(oprReg);
//        return oprReg;
//    }

    void MOP_AGENT::addOprReg(const OPR_REG_PTR& regOpr) {
        regOperandsPtr.push_back(regOpr);
    }

    void MOP_AGENT::addOprTemp(const OPR_TREG_PTR& tregOpr) {
        tempOperandsPtr.push_back(tregOpr);
    }

    void MOP_AGENT::addOprImm(const OPR_IMM_PTR& immOpr){
        immOperandPtr.push_back(immOpr);
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
        /////////////////// statistic collection
        stat::MAIN_STAT["MOP" + std::string(isWeakDecoded ? "_WEAK": "")]["COUNT"][_owner->getDecodeKey()].asUINT()++;
        stat::MAIN_STAT["MOP" + std::string(isWeakDecoded ? "_WEAK": "")]["UOPCNT"][_owner->getDecodeKey()].asUINT() = results.size();
        stat::MAIN_STAT["MOP" + std::string(isWeakDecoded ? "_WEAK": "")]["TOTAL"].asUINT()++;
        return results;
    }



    MOP_AGENT_PTR MOP_AGENT::MOP_AGENT_CLONE()
    {
        auto clonedMopAgent = std::make_shared<MOP_AGENT>(_owner);
        /** tempOperand we use same as old agent because it are created uniq for each instruction*/
        clonedMopAgent->tempOperandsPtr = tempOperandsPtr;
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
                //.def("buildTempOpr"  , &MOP_AGENT::createAndAddTempOpr)
                //.def("buildRegOpr", &MOP_AGENT::createAndAddRegOpr)
                .def("addOprReg", &MOP_AGENT::addOprReg)
                .def("addOprTemp", &MOP_AGENT::addOprTemp)
                .def("addOprImm", &MOP_AGENT::addOprImm)
                .def("addUopAgent", &MOP_AGENT::addUopAgent)
                .def("addUopAgents", &MOP_AGENT::addUopAgents)
                .def("setWeakDecode", &MOP_AGENT::setWeakDecode);
    }
}