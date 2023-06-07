//
// Created by tanawin on 12/2/2566.
//

#include "dep_base.h"
#include "core/tracers/uop_wd.h"
#include "models/uop_model/uop_base.h"

namespace traceBuilder::model {

////////////////////////////////////
////// base dependency
////////////////////////////////////

    bool DEP_BASE::addDep(UOP_BASE* uop, UOP_WINDOW* traceWindow) {
        ////// if there is not added
        assert(uop != nullptr);
        //////// incase we need to add to dep pool [optimize]
        if (depPool != nullptr){
            depPool->addDep(uop, traceWindow);
        }
        if (isThereDep(uop, traceWindow)){
            auto[idxInDepSet, idxInDepSetEle] = getDepSetIdx(uop, traceWindow);
            uint64_t bitCheck = ((uint64_t)1) << idxInDepSetEle;
            depSet[idxInDepSet] |= bitCheck;
            depUops[depCnt++] = uop;
            return true;
        }
        return false;
    }

    bool DEP_BASE::isThereDep(UOP_BASE* uop, UOP_WINDOW* traceWindow){
        auto [idxInDepSet, idxInDepSetEle] = getDepSetIdx(uop, traceWindow);
        uint64_t bitCheck = ((uint64_t)1) << idxInDepSetEle;
        uint64_t checked = depSet[idxInDepSet] &= bitCheck;
        return checked;
    }

    std::pair<int, int> DEP_BASE::getDepSetIdx(UOP_BASE* uop, UOP_WINDOW* traceWindow) {
        auto lastSeq = traceWindow->getLastPushSeqNum();
        auto depSeq = uop->getSeqNum();
        auto idxInWindow = lastSeq - depSeq;
        auto idxInDepSet = idxInWindow / AMT_BIT_UINT64;
        auto idxInDepSetEle = idxInWindow % AMT_BIT_UINT64;
        assert(idxInWindow > 0 && idxInWindow < UOP_WINDOW_SIZE);
        assert(idxInDepSet < AMT_USED_UOP_REP && idxInDepSetEle < AMT_BIT_UINT64);
        return {idxInDepSet, idxInDepSetEle};
    }


}