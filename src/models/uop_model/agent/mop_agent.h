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
    class MOP_AGENT{
    private:
        RT_INSTR* _owner;
        std::vector<OPR_TREG*>   tempOperands;
        std::vector<UOP_AGENT_PTR> _uopAgents;
    public:
        explicit MOP_AGENT(RT_INSTR* owner);
        std::shared_ptr<MOP_AGENT> MOP_AGENT_CLONE();
        OPR_TREG* createAndAddTempOpr(int tRegId);
        void addUopAgent(const UOP_AGENT_PTR& uopAgentPtr);
        void addUopAgents(const std::vector<UOP_AGENT_PTR>& uopAgents);
        std::vector<UOP_BASE*> genUops();
        int getUopCount(){return _uopAgents.size();};
    };

    typedef  std::shared_ptr<MOP_AGENT> MOP_AGENT_PTR;

    void BIND_MOP_AGENT(py::module& m);



}

#endif //TRACEBUILDER_MOP_AGENT_H
