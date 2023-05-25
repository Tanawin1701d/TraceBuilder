//
// Created by tanawin on 25/5/2566.
//

#include "depHelp_issBarier.h"


DEP_HELP_ISS_BARIER::DEP_HELP_ISS_BARIER(EXEC_UNIT_RES *_exe_unit_info)
: exe_unit_info(_exe_unit_info)
{
    assert(_exe_unit_info != nullptr);
}

void DEP_HELP_ISS_BARIER::onPushToWd(UOP_BASE *uop, UOP_WINDOW *wd) {
    assert(uop != nullptr);
    EXEC_UNIT_ID execId = uop->getExecUnit();
    if (execId == DUMMY_EXEC_UNIT_ID) return;
    assert(execId < MAX_UNIT_ID);
    ///// push_back uop to exeunit
    units[execId].push_front(uop);
}

void DEP_HELP_ISS_BARIER::onPopFromWd(UOP_BASE *uop, UOP_WINDOW *wd) {
    assert(uop != nullptr);
    EXEC_UNIT_ID execId = uop->getExecUnit();
    if (execId == DUMMY_EXEC_UNIT_ID) return;
    assert(execId < MAX_UNIT_ID);
    /////// pop_front
    assert(uop == units[execId].back());
    units[execId].pop_back();
}

void DEP_HELP_ISS_BARIER::assignDepHelp(UOP_BASE *uop, UOP_WINDOW *wd) {
    assert(uop != nullptr);
    EXEC_UNIT_ID execId = uop->getExecUnit();
    if (execId == DUMMY_EXEC_UNIT_ID) return;
    assert(execId < MAX_UNIT_ID);
    ///////
    int maxAvailableUnit = exe_unit_info->getMaxAvailable(execId);
    assert(maxAvailableUnit > 0);
    if (units[execId].size() >= maxAvailableUnit){
        int targetDepUnitIdx = maxAvailableUnit - 1;
        uop->addExecDep(units[targetDepUnitIdx][targetDepUnitIdx]);
    }
}
