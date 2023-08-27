//
// Created by tanawin on 12/2/2566.
//

#include "dep_base.h"
#include "core/tracers/uop_wd.h"
#include "models/uop_model/uop_base.h"

namespace traceBuilder::model {

////////////////////////////////////
////// RWD(related to uop window) dependency
////////////////////////////////////

    DEP_RWD_BASE::DEP_RWD_BASE(): _depPool(nullptr), depUops(nullptr){}

    bool DEP_RWD_BASE::addDep(UOP_BASE* uop, UOP_WINDOW*  traceWindow) {
        assert(uop != nullptr);
        assert(traceWindow != nullptr);
        //////// incase we need to add to dep pool [optimize]
        if (_depPool != nullptr){
            _depPool->addDep(uop, traceWindow);
        }
        size_t idxInWd = traceWindow->getLastPushSeqNum() - uop->getSeqNum();
        if (!isThereDep(uop, traceWindow)){
            depUops.pushIdx(uop, idxInWd, false);
            return true;
        }
        return false;
    }

    bool DEP_RWD_BASE::isThereDep(UOP_BASE* uop, UOP_WINDOW*  traceWindow){
        assert(uop != nullptr);
        assert(traceWindow != nullptr);
        size_t idxInWd =  traceWindow->getLastPushSeqNum() - uop->getSeqNum();
        return depUops.isThereIdx(idxInWd);
    }

////////////////////////////////////
////// ULS(uniq list) dependency
////////////////////////////////////


    bool DEP_ULS_BASE::addDep(UOP_BASE *uop, UOP_WINDOW*  traceWindow) {
        assert(uop != nullptr);
        _depUops[_depCnt++] = uop;
        assert(_depCnt <= UOP_WINDOW_SIZE);
        return true;
    }

    bool DEP_ULS_BASE::isThereDep(UOP_BASE* uop, UOP_WINDOW*  traceWindow){
        assert(uop != nullptr);
        for (size_t idx = 0; idx < _depCnt; idx++){
            if (_depUops[idx] == uop){
                return true;
            }
        }
        return false;
    }

}