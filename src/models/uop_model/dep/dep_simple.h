//
// Created by tanawin on 7/6/2566.
//

#ifndef TRACEBUILDER_DEP_SIMPLE_H
#define TRACEBUILDER_DEP_SIMPLE_H

#include "dep_base.h"
#include "models/inst_model/operand.h"
#include "models/uop_model/metaData/metaBase.h"
#include "models/uop_model/metaData/metaType.h"

namespace traceBuilder::model {

    /** register dependency*/
    class REG_DEP : public DEP_RWD_BASE {
    public:
        void doDepenCheck(UOP_BASE* uop, UOP_WINDOW*  traceWindow) override;
    };
    ///////////////////////////////////////////////////////////////////////

    /** memory dependency*/
    class MEM_DEP : public DEP_RWD_BASE {
        ///// scan overlaping
        static bool scanOverlap(ADAS adas, META_GRP<MEM_META>* adasVec);
    public:
        /** for successor depend on mem*/
        virtual bool isdependOnMem(UOP_BASE* uop, ADAS suc_adas, bool isLoad);
        /** for asking procedure to get dep */
        void doDepenCheck(UOP_BASE* uop, UOP_WINDOW*  traceWindow) override;
    };
    ///////////////////////////////////////////////////////////////////////

    /**temporary register*/
    class TEM_DEP : public DEP_ULS_BASE {
    public:
        /** for asking procedure to get dep */
        void doDepenCheck(UOP_BASE* uop, UOP_WINDOW*  traceWindow) override;
    };
    ///////////////////////////////////////////////////////////////////////

    /**execUnit dependency*/
    class EXEC_UNIT_DEP : public DEP_RWD_BASE {
    public:
        /** for asking procedure to get dep */
        void doDepenCheck(UOP_BASE* uop, UOP_WINDOW*  traceWindow) override;

    };
    ///////////////////////////////////////////////////////////////////////

}

#endif //TRACEBUILDER_DEP_SIMPLE_H
