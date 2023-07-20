//
// Created by tanawin on 19/7/2566.
//

#include "uop_agent.h"

namespace traceBuilder::model{




    UOP_AGENT::UOP_AGENT(UOP_TYPE uopType, EXEC_UNIT_ID execUnit):
    _uopType(uopType),
    _execUnit(execUnit),
    newCloneAgent(nullptr),
    procUop(nullptr)
    {}

    UOP_AGENT_PTR
    UOP_AGENT::UOP_AGENT_CLONE(){
        auto cloned_uop_agent = std::make_shared<UOP_AGENT>(_uopType, _execUnit);
        setNewCloneAgent(cloned_uop_agent);
        /** clone linker*/
        cloned_uop_agent->oprRegLinker =  oprRegLinker;
        cloned_uop_agent->oprTRegLinker=  oprTRegLinker;
        cloned_uop_agent->oprMemLinker =  oprMemLinker;
        cloned_uop_agent->oprImmLinker =  oprImmLinker;
        /**temp deps*/
        for (const auto& tempAgentPtr: tempDeps){
            /** copy new pointer with new succesor*/
            cloned_uop_agent->tempDeps.push_back(tempAgentPtr->getClonedUopAgent());
        }
        cloned_uop_agent->newCloneAgent = cloned_uop_agent;
        procUop = nullptr;
        return cloned_uop_agent;
    }

    /**add meta data for each type to new inproc uop*/
    void UOP_AGENT::addMetaToNewUop() {
        /** regmeta from regOpr*/
        for (auto args : oprRegLinker){
            auto regMeta = args.opr->GET_META_FUNCNAME(args.subRegIdx);
            if (args.isSrc)
                procUop->addMeta<META_SRC_MREG, MREG_META>(regMeta);
            else
                procUop->addMeta<META_DES_MREG, MREG_META>(regMeta);
        }
        /** tregMeta from tregOprand*/
        for (auto args : oprTRegLinker){
            auto tregMeta = args.opr->GET_META_FUNCNAME();
            if (args.isSrc)
                procUop->addMeta<META_SRC_TEMP, TREG_META>(tregMeta);
            else
                procUop->addMeta<META_DES_TEMP, TREG_META>(tregMeta);
        }
        /** mem meta from memoperand*/
        for (auto args: oprMemLinker){
            auto memMeta = args.opr->GET_META_FUNCNAME(args.startByte, args.stopByte);
            if (args.isSrc)
                procUop->addMeta<META_SRC_MEM, MEM_META>(memMeta);
            else
                procUop->addMeta<META_DES_MEM, MEM_META>(memMeta);
        }
        /** imm meta from imm operand*/
        for (auto args: oprImmLinker){
            auto immMeta = args.opr->GET_META_FUNCNAME();
            procUop->addMeta<META_SRC_IMM, IMM_META>(immMeta);
        }

    }

    /**add dep to New Uop*/
    void UOP_AGENT::addDepToNewUop() {
        for (auto agentUop: tempDeps) {
            auto uopBasePtr = agentUop->getInProcessUop();
            assert(uopBasePtr != nullptr);
            procUop->addDep<tempClass>(uopBasePtr, nullptr);
        }
    }

    /** add link for uop generation*/

    void UOP_AGENT::ADD_LINK_OPR_REG_FUNC_NAME(OPR_REG *opr, int subRegIdx, bool isSrc) {
        assert(opr != nullptr);
        assert(subRegIdx >= 0);
        oprRegLinker.push_back({opr, subRegIdx, isSrc});
    }

    void UOP_AGENT::ADD_LINK_OPR_TREG_FUNC_NAME(OPR_TREG *opr, bool isSrc) {
        assert(opr != nullptr);
        oprTRegLinker.push_back({opr, isSrc});
    }

    void UOP_AGENT::ADD_LINK_OPR_MEMREG_FUNC_NAME(OPR_MEM *opr, int startByte, int stopByte, bool isSrc) {
        assert(opr != nullptr);
        assert(startByte < stopByte);
        oprMemLinker.push_back({opr, startByte, stopByte, isSrc});
    }

    void UOP_AGENT::ADD_LINK_OPR_IMM_FUNC_NAME(OPR_IMM *opr) {
        assert(opr != nullptr);
        oprImmLinker.push_back({opr});
    }

    void UOP_AGENT::ADD_LINK_UOP_TEMP_FUNC_NAME(UOP_AGENT_PTR uopAgent) {
        assert(uopAgent != nullptr);
        tempDeps.push_back(uopAgent);
    }



    /**gen uop base which is called from mop*/
    UOP_BASE* UOP_AGENT::genUop() {
        assert(procUop == nullptr);
        procUop = new UOP_BASE();
        procUop->setExecUnit(_execUnit);
        procUop->setUopType(_uopType);
        addMetaToNewUop();
        addDepToNewUop();
        return procUop;
    }

    UOP_BASE* UOP_AGENT::getInProcessUop() {
        assert(procUop != nullptr);
        return procUop;
    }

    void UOP_AGENT::cleanAgent() {
        procUop = nullptr;
    }



    ////////////////////////////////////////////////////////////////////////////////////////
    ///////// pybind declaration

    void BIND_UOP_AGENT(py::module& m){
        py::class_<UOP_AGENT, std::shared_ptr<UOP_AGENT>>(m, "UOP")
                .def(py::init<UOP_TYPE, EXEC_UNIT_ID>())
                .def(ADD_LINK_OPR_REG_FUNC_NAME_STR   , &UOP_AGENT::ADD_LINK_OPR_REG_FUNC_NAME   )
                .def(ADD_LINK_OPR_TREG_FUNC_NAME_STR  , &UOP_AGENT::ADD_LINK_OPR_TREG_FUNC_NAME  )
                .def(ADD_LINK_OPR_MEMREG_FUNC_NAME_STR, &UOP_AGENT::ADD_LINK_OPR_MEMREG_FUNC_NAME)
                .def(ADD_LINK_OPR_IMM_FUNC_NAME_STR   , &UOP_AGENT::ADD_LINK_OPR_IMM_FUNC_NAME   )
                .def(ADD_LINK_UOP_TEMP_FUNC_NAME_STR  , &UOP_AGENT::ADD_LINK_UOP_TEMP_FUNC_NAME  )
                ;
    }


}