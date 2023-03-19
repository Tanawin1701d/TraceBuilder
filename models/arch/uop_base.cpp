//
// Created by tanawin on 12/2/2566.
//

#include "uop_base.h"

#include <utility>
#include "core/tracers/uop_wd.h"

uint64_t
UOP_BASE::getSeqNum() const {
    return seqNum;
}

void
UOP_BASE::setSeqNum(uint64_t _seqNum) {
    seqNum = _seqNum;
}


////// simple compute reg
/////////////////////////////////////////////////////////////////////////////
void UOP_SIMPLE::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    doMemDepenCheck(uop_window);
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}
