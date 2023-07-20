//
// Created by tanawin on 19/7/2566.
//

#ifndef TRACEBUILDER_UOP_AGENT_H
#define TRACEBUILDER_UOP_AGENT_H

#include "models/inst_model/operand.h"
#include "models/uop_model/dep/dep_base.h"
#include "models/uop_model/uop_base.h"

#define ADD_LINK_OPR_REG_FUNC_NAME addLink_OPR_REG
#define ADD_LINK_OPR_TREG_FUNC_NAME addLink_OPR_TREG
#define ADD_LINK_OPR_MEMREG_FUNC_NAME addLink_OPR_MEM
#define ADD_LINK_OPR_IMM_FUNC_NAME addLink_OPR_IMM
#define ADD_LINK_UOP_TEMP_FUNC_NAME addLink_Uop

#define ADD_LINK_OPR_REG_FUNC_NAME_STR    "addLink_OPR_REG"
#define ADD_LINK_OPR_TREG_FUNC_NAME_STR   "addLink_OPR_TREG"
#define ADD_LINK_OPR_MEMREG_FUNC_NAME_STR "addLink_OPR_MEM"
#define ADD_LINK_OPR_IMM_FUNC_NAME_STR    "addLink_OPR_IMM"
#define ADD_LINK_UOP_TEMP_FUNC_NAME_STR   "addLink_Uop"



namespace traceBuilder::model {
    /**
     *
     * UOP AGENT is a class dedicated to be an representative of microop
     * the class will generate uop base according command from python
     * the class is not actual uop, the actual uop is uopBase
     * uop Agent might be stored in mop agent
     * */
    class UOP_AGENT;
    typedef std::shared_ptr<UOP_AGENT> UOP_AGENT_PTR;
    class UOP_AGENT {
        /** store link argument template for generate meta data*/
        struct OPR_REG_ARGS{
            OPR_REG* opr;
            int subRegIdx;
            bool isSrc;
        };
        struct OPR_TREG_ARGS{
            OPR_TREG* opr;
            bool isSrc;
        };
        struct OPR_MEM_ARGS{
            OPR_MEM* opr;
            int startByte;
            int stopByte;
            bool isSrc;
        };
        struct OPR_IMM_ARGS{
            OPR_IMM* opr;
        };
        /** store hub*/
        std::vector<OPR_REG_ARGS>  oprRegLinker;
        std::vector<OPR_TREG_ARGS> oprTRegLinker;
        std::vector<OPR_MEM_ARGS>  oprMemLinker;
        std::vector<OPR_IMM_ARGS>  oprImmLinker;

        /** dep hub*/
        static const DEP_CLASS tempClass = DEP_TEMP;
        std::vector<UOP_AGENT_PTR> tempDeps; /** the vector must link to uop agent not uop base*/
        /** clone uop agent*/
        UOP_AGENT_PTR newCloneAgent; /**last uop agent that copy this agent*/


        /** in processing uop*/
        UOP_BASE* procUop;
        /** uop fix meta data*/
        UOP_TYPE     _uopType;
        EXEC_UNIT_ID _execUnit;

        void addMetaToNewUop();
        void addDepToNewUop();


    public:

        UOP_AGENT(UOP_TYPE uopType, EXEC_UNIT_ID execUnit);
        UOP_AGENT_PTR UOP_AGENT_CLONE();



        void ADD_LINK_OPR_REG_FUNC_NAME(OPR_REG* opr, int subRegIdx, bool isSrc);
        void ADD_LINK_OPR_TREG_FUNC_NAME(OPR_TREG* opr, bool isSrc);
        void ADD_LINK_OPR_MEMREG_FUNC_NAME(OPR_MEM* opr, int startByte, int stopByte, bool isSrc);
        void ADD_LINK_OPR_IMM_FUNC_NAME(OPR_IMM* opr);
        void ADD_LINK_UOP_TEMP_FUNC_NAME(UOP_AGENT_PTR uopAgent);

        /** uop base management*/
        UOP_BASE* genUop();

        UOP_BASE* getInProcessUop();

        void cleanAgent();
        /** clone agent*/
        UOP_AGENT_PTR getClonedUopAgent(){return newCloneAgent;}
        void       setNewCloneAgent(UOP_AGENT_PTR uopAgentPtr){newCloneAgent = uopAgentPtr;}


    };

    typedef std::shared_ptr<UOP_AGENT> UOP_AGENT_PTR;
    ////////////////////////////////////////////////////////////////////////////////////////
    ///////// pybind declaration
    namespace py = pybind11;
    void BIND_UOP_AGENT(py::module& m);


}

#endif //TRACEBUILDER_UOP_AGENT_H
