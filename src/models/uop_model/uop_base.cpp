//
// Created by tanawin on 12/2/2566.
//

#include "uop_base.h"
#include "core/tracers/uop_wd.h"

//////////////////////////////////////
////// UOP_BASE
//////////////////////////////////////

namespace traceBuilder::model {

    using namespace traceBuilder::core;

    UOP_BASE::UOP_BASE() :
            seqNum(UINT64_MAX),
            uop_type(UOP_DUMMY),
            exec_unit_id(DUMMY_EXEC_UNIT_ID) {}

    void UOP_BASE::doRegDepenCheck(UOP_WINDOW *uop_window) {
        uop_window->assignRegDep(this);
    }

    void UOP_BASE::doMemDepenCheck(UOP_WINDOW *uop_window) {
        assert(uop_window != nullptr);
        auto uopWindow_ptr = uop_window->getUopwindow();
        ////// TODO we might upgrade for clever method to achieve better performance
        /////////// like line sweep algorithm
        for (auto &uopWindow_itr: *uopWindow_ptr) {
            for (auto &ldAdas: loadAdas) {
                if (uopWindow_itr->isdependOnMem(ldAdas, true))
                    addMemDep(uopWindow_itr);
            }
            for (auto &stAdas: storeAdas) {
                if (uopWindow_itr->isdependOnMem(stAdas, false))
                    addMemDep(uopWindow_itr);
            }
        }
    }

    void UOP_BASE::doTemDepenCheck(UOP_WINDOW *uop_window) {}

    void UOP_BASE::doExecDepenCheck(UOP_WINDOW *uop_window) {
        uop_window->assignExecDep(this);
    }

////// simple compute reg
/////////////////////////////////////////////////////////////////////////////
    void UOP_SIMPLE::doDepenCheck(UOP_WINDOW *uop_window) {
        //////// we check all possible dependency
        doRegDepenCheck(uop_window);
        doMemDepenCheck(uop_window);
        doTemDepenCheck(uop_window);
        doExecDepenCheck(uop_window);
    }

    UOP_SIMPLE::UOP_SIMPLE(UOP_TYPE _uop_type) :
            UOP_BASE() {
        uop_type = _uop_type;
    }

}