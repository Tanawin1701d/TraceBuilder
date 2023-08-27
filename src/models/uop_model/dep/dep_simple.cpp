//
// Created by tanawin on 7/6/2566.
//

#include "dep_simple.h"
#include "core/tracers/uop_wd.h"


namespace traceBuilder::model {

    /** register dependency*/
    void
    REG_DEP::doDepenCheck(UOP_BASE *uop, UOP_WINDOW*  traceWindow) {
        traceWindow->assignRegDep(uop);
    }

    /**memory dependency*/

    bool MEM_DEP::scanOverlap(ADAS adas, META_GRP<MEM_META>* myMetas) {
        for (auto desMeta: *myMetas) {
            if (!desMeta.suppressed && isADASoverlap(desMeta.p_area, adas)) {
                return true;
            }
        }
        return false;
    }

    bool MEM_DEP::isdependOnMem(UOP_BASE* my_uop, ADAS suc_adas, bool isLoad) {
        /** succesor will use this function at predessor side
         * to ask that memory address is overlap*/
        //// if statement is load after load excluding
        auto memLdMeta = my_uop->getMetaPtr<META_CLASS::META_SRC_MEM, MEM_META>();
        if ((!isLoad) && scanOverlap(suc_adas, memLdMeta))
            return true;

        auto memStMeta = my_uop->getMetaPtr<META_CLASS::META_DES_MEM, MEM_META>();
        return scanOverlap(suc_adas, memStMeta);
    }

    void MEM_DEP::doDepenCheck(UOP_BASE * my_uop, UOP_WINDOW*  traceWindow) {
        assert(traceWindow != nullptr);
        auto uopWindow_ptr = traceWindow->getUopwindow();
        auto my_ldMetaGrpPtr = my_uop->getMetaPtr<META_CLASS::META_SRC_MEM, MEM_META>();
        auto my_stMetaGrpPtr = my_uop->getMetaPtr<META_CLASS::META_DES_MEM, MEM_META>();
        ////// TODO we might upgrade for clever method to achieve better performance
        /////////// like line sweep algorithm
        for (auto preDesUopPtr: *uopWindow_ptr) {
            /** load depend check*/
            for (auto my_ldMeta: *my_ldMetaGrpPtr){
                if (my_ldMeta.suppressed){
                    continue;
                }
                /** predessor des Dep*/
                auto preMemDepPtr = (MEM_DEP*)preDesUopPtr->getDepClassPtr<DEP_MEM>();
                if (preMemDepPtr->isdependOnMem(preDesUopPtr, my_ldMeta.p_area, true))
                    my_uop->addDep<DEP_MEM>(preDesUopPtr, traceWindow);
            }
            /** store depend check1*/
            for (auto my_stMeta: *my_stMetaGrpPtr){
                if (my_stMeta.suppressed){
                    continue;
                }
                /** predessosr des dep*/
                auto preMemDepPtr = (MEM_DEP*)preDesUopPtr->getDepClassPtr<DEP_MEM>();
                if (preMemDepPtr->isdependOnMem(preDesUopPtr, my_stMeta.p_area, false))
                    my_uop->addDep<DEP_MEM>(preDesUopPtr, traceWindow);
            }
        }
    }


    /** temporary register dependency*/

    void TEM_DEP::doDepenCheck(UOP_BASE *uop, UOP_WINDOW*  traceWindow) {}

    /** execUnit dependency*/

    void EXEC_UNIT_DEP::doDepenCheck(UOP_BASE *uop, UOP_WINDOW*  traceWindow) {
        traceWindow->assignExecDep(uop);
    }
}