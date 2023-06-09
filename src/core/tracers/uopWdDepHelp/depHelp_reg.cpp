//
// Created by tanawin on 25/5/2566.
//


#include"depHelp_reg.h"
#include"core/tracers/uop_wd.h"

namespace traceBuilder::core {


    DEP_HELP_REG::DEP_HELP_REG() {
        /////// initialize array that contain last owner reg to nullptr
        for (auto &regItem: lastOwnerReg) {
            regItem = nullptr;
        }
    }

    void DEP_HELP_REG::onPushToWd(UOP_BASE *uop, UOP_WINDOW *wd) {
        for (REGNUM desReg: uop->getdesReg()) {
            //// we can ensure that no unused reg(-1) righthere
            lastOwnerReg[desReg] = uop;
        }
    }

    void DEP_HELP_REG::onPopFromWd(UOP_BASE *uop, UOP_WINDOW *wd) {
        assert(uop != nullptr);
        for (REGNUM desReg: uop->getdesReg()) {
            //// we can ensure that no unused reg(-1) righthere
            if (uop == lastOwnerReg[desReg]) {
                lastOwnerReg[desReg] = nullptr;
            }
        }
    }

    void DEP_HELP_REG::assignDepHelp(UOP_BASE *uop, UOP_WINDOW *wd) {
        assert(uop != nullptr);
        for (auto &regNum: uop->getdesReg()) {
            assert(regNum != unusedReg);
            if (lastOwnerReg[regNum] != nullptr) {
                uop->addRegDep(lastOwnerReg[regNum], wd);
            }
        }
    }


}