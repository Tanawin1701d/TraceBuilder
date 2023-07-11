//
// Created by tanawin on 25/5/2566.
//


#include"depHelp_reg.h"
#include"core/tracers/uop_wd.h"
#include"models/uop_model/metaData/metaBase.h"
#include"models/uop_model/metaData/metaType.h"

namespace traceBuilder::core {


    DEP_HELP_REG::DEP_HELP_REG() {
        /////// initialize array that contain last owner reg to nullptr
        for (auto &regItem: lastOwnerReg) {
            regItem = nullptr;
        }
    }

    void DEP_HELP_REG::onPushToWd(UOP_BASE *uop, UOP_WINDOW *wd) {
        using namespace model;
        auto desRegMetaPtr = uop->getMetaPtr<META_CLASS::META_DES_MREG, MREG_META>();
        for (REGNUM desReg: *desRegMetaPtr) {
            //// we can ensure that no unused reg(-1) righthere
            lastOwnerReg[desReg] = uop;
        }
    }

    void DEP_HELP_REG::onPopFromWd(UOP_BASE *uop, UOP_WINDOW *wd) {
        assert(uop != nullptr);
        auto desRegMetaPtr = uop->getMetaPtr<META_CLASS::META_DES_MREG, MREG_META>();
        for (REGNUM desReg: *desRegMetaPtr) {
            //// we can ensure that no unused reg(-1) righthere
            if (uop == lastOwnerReg[desReg]) {
                lastOwnerReg[desReg] = nullptr;
            }
        }
    }

    void DEP_HELP_REG::assignDepHelp(UOP_BASE *uop, UOP_WINDOW *wd) {
        assert(uop != nullptr);
        auto srcRegPtr = uop->getMetaPtr<META_CLASS::META_SRC_MREG, MREG_META>();
        for (REGNUM regNum: *srcRegPtr) {
            assert(regNum != UNUSEDREG);
            if (lastOwnerReg[regNum] != nullptr) {
                uop->addDep<DEP_CLASS::DEP_MREG>(lastOwnerReg[regNum], wd);
            }
        }
    }


}