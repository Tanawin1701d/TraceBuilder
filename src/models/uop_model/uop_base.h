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
        uint64_t     seqNum;// sequence number is set from tracer not uop agent
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
        void addMeta(META_TYPE metaDayta){
            auto metaGrp = getMetaPtr<meta_class_enum, META_TYPE>();
            metaGrp->addMeta(metaDayta);
        }

        template<META_CLASS meta_class_enum, typename META_TYPE>
        META_GRP<META_TYPE>* getMetaPtr(){
            return metaDatas[meta_class_enum]->castDown<META_GRP<META_TYPE>>();
        }


        /** dep class operation*/
            /// return that dep is newly added or not
        template<DEP_CLASS dep_class_enum>
        bool addDep(UOP_BASE* uop, UOP_WINDOW* uop_window){
                auto dep = getDepClassPtr<dep_class_enum>();
                return dep->addDep(uop, uop_window);
        }

        template<DEP_CLASS dep_class_enum>
        DEP_BASE* getDepClassPtr(){
            return deps[dep_class_enum];
        }

        template<DEP_CLASS dep_class_enum>
        void doDepenCheck(UOP_WINDOW* traceWindow){
            auto depPtr = getDepClassPtr<dep_class_enum>();
            depPtr->doDepenCheck(this, traceWindow);
        }

        void doAllDepenCheck(UOP_WINDOW* traceWindow){
            doDepenCheck<DEP_MREG>(traceWindow);
            doDepenCheck<DEP_MEM>(traceWindow);
            doDepenCheck<DEP_TEMP>(traceWindow);
            doDepenCheck<DEP_EXEC_UNIT>(traceWindow);

        }
    };

}

#endif //TRACEBUILDER_UOP_BASE_H
