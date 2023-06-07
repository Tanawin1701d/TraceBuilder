//
// Created by tanawin on 12/2/2566.
//

#ifndef TRACEBUILDER_UOP_BASE_H
#define TRACEBUILDER_UOP_BASE_H


#include "dep_base.h"
#include "dep_simple.h"
#include "models/inst_model/operand.h"
#include "models/res_model/execUnit/execUnit.h"
#include "stat/statPool.h"

namespace traceBuilder::core{
    class UOP_WINDOW;
}

namespace traceBuilder::model {


    using namespace traceBuilder::core;

    enum UOP_TYPE {
        UOP_COMP,
        UOP_LOAD,
        UOP_STORE,
        UOP_IMM,
        UOP_DUMMY
    };

    class UOP_BASE : public REG_DEP, public MEM_DEP, public TEM_DEP, public EXEC_UNIT_DEP {

    protected:
        uint64_t seqNum;// sequence number of uop in each thread
        UOP_TYPE uop_type;
        EXEC_UNIT_ID exec_unit_id;
        DEP_BASE dep_pool_owner;

    public:
        UOP_BASE();

        virtual  ~UOP_BASE() = default;

        void setSeqNum(uint64_t _seqNum) { seqNum = _seqNum; };

        void setUopType(UOP_TYPE _uopType) { uop_type = _uopType; };

        void setExecUnit(EXEC_UNIT_ID _exec_unit_id) { exec_unit_id = _exec_unit_id; };

        uint64_t getSeqNum() const { return seqNum; };

        UOP_TYPE getUopType() const { return uop_type; };

        EXEC_UNIT_ID getExecUnit() const { return exec_unit_id; };

        //// use to ask successor to check dependecy and store ourself dependency
        ////// crucial this is fundamental of the program the program
        virtual void doDepenCheck(traceBuilder::core::UOP_WINDOW* uop_window) = 0;

        void doRegDepenCheck(UOP_WINDOW* uop_window) override;

        void doMemDepenCheck(UOP_WINDOW* uop_window) override;

        void doTemDepenCheck(UOP_WINDOW* uop_window) override;

        void doExecDepenCheck(UOP_WINDOW* uop_window) override;


    };

//////////// simple compute uop

    class UOP_SIMPLE : public UOP_BASE {

    public:
        //// for construction uop
        UOP_SIMPLE(UOP_TYPE _uop_type);

        //// for this uop to ask other in instruction window that it depend on
        void doDepenCheck(UOP_WINDOW *uop_window) override;

    };
}

#endif //TRACEBUILDER_UOP_BASE_H