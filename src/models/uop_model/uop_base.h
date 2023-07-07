//
// Created by tanawin on 12/2/2566.
//

#ifndef TRACEBUILDER_UOP_BASE_H
#define TRACEBUILDER_UOP_BASE_H


#include "models/uop_model/dep/dep_base.h"
#include "models/uop_model/dep/dep_simple.h"
#include "models/uop_model/metaData/metaBase.h"
#include "models/uop_model/metaData/metaType.h"
#include "models/inst_model/operand.h"
#include "models/res_model/execUnit/execUnit.h"
#include "stat/statPool.h"
#include "models/uop_model/metaData/metaBase.h"

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

    class UOP_BASE{

    protected:

        /** this is storage to store meta data for each typeclass*/
        META_GRP_BASE* metaDatas[META_CLASS::META_NUM]{};
        /** this is storage to store dependency for each type*/
        DEP_BASE*      deps     [DEP_CLASS::DEP_NUM]{};
        /** this is storage to colect all dep that base share between instr*/
        DEP_RWD_BASE   dep_inter_pool;
        /** uop meta data*/
        uint64_t     seqNum;// sequence number of uop in each thread
        UOP_TYPE     uop_type;
        EXEC_UNIT_ID exec_unit_id;

    public:
        UOP_BASE();

        virtual  ~UOP_BASE();

        void setSeqNum(uint64_t _seqNum) { seqNum = _seqNum; };

        void setUopType(UOP_TYPE _uopType) { uop_type = _uopType; };

        void setExecUnit(EXEC_UNIT_ID _exec_unit_id) { exec_unit_id = _exec_unit_id; };

        uint64_t getSeqNum() const { return seqNum; };

        UOP_TYPE getUopType() const { return uop_type; };

        EXEC_UNIT_ID getExecUnit() const { return exec_unit_id; };

        DEP_RWD_BASE& getDep_inter_instr_pool(){return dep_inter_pool;};

        /** meta class operation*/
        template<META_CLASS meta_class_enum, typename META_TYPE>
        void addMeta(META_TYPE metaDayta);

        template<META_CLASS meta_class_enum, typename META_TYPE>
        META_GRP<META_TYPE>* getMetaPtr();


        /** dep class operation*/
            /// return that dep is newly added or not
        template<DEP_CLASS dep_class_enum>
        bool addDep(UOP_BASE* uop, UOP_WINDOW* uop_window);

        template<DEP_CLASS dep_class_enum>
        DEP_BASE* getDepClassPtr();

        template<DEP_CLASS dep_class_enum>
        void doDepenCheck(UOP_WINDOW *traceWindow);
        //// use to ask successor to check dependecy and store ourself dependency
        ////// crucial this is fundamental of the program the program
        virtual void doPlannedDepenCheck(UOP_WINDOW* uop_window) = 0;
    };

//////////// simple compute uop

    class UOP_SIMPLE : public UOP_BASE {

    public:
        //// for construction uop
        UOP_SIMPLE(UOP_TYPE _uop_type);

        //// for this uop to ask other in instruction window that it depend on
        void doPlannedDepenCheck(UOP_WINDOW *uop_window) override;

    };
}

#endif //TRACEBUILDER_UOP_BASE_H
