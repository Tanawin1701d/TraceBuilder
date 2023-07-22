//
// Created by tanawin on 19/7/2566.
//

#ifndef TRACEBUILDER_MOP_AGENT_H
#define TRACEBUILDER_MOP_AGENT_H
#include<vector>
#include"models/uop_model/agent/uop_agent.h"

namespace traceBuilder::model{

    /**
     *
     * UOP AGENT is a class that aggregrete uops for each a instruction. the class
     * will be orchestrator for uop generation for a instruction.
     *
     *
     * */
    class RT_INSTR;
    class MOP_AGENT;
    typedef  std::shared_ptr<MOP_AGENT> MOP_AGENT_PTR;
    class MOP_AGENT{
    private:
        RT_INSTR* _owner;
        std::vector<OPR_TREG_PTR>   tempOperandsPtr;
        std::vector<OPR_REG_PTR>    regOperandsPtr;
        std::vector<UOP_AGENT_PTR> _uopAgents;
    public:
        explicit      MOP_AGENT(RT_INSTR* owner);
        MOP_AGENT_PTR MOP_AGENT_CLONE();
        //OPR_TREG_PTR  createAndAddTempOpr(int tRegId);
        //OPR_REG_PTR   createAndAddRegOpr(int archRegId, int maxSubRegId);
        void          addUopAgent(const UOP_AGENT_PTR& uopAgentPtr);
        void          addUopAgents(const std::vector<UOP_AGENT_PTR>& uopAgents);
        void          addOprReg(const OPR_REG_PTR& regOpr);
        void          addOprTemp(const OPR_TREG_PTR& tregOpr);
        std::vector<UOP_BASE*> genUops();
        int           getUopCount(){return _uopAgents.size();};
    };



    void BIND_MOP_AGENT(py::module& m);



}

#endif //TRACEBUILDER_MOP_AGENT_H
