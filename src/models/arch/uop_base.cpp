//
// Created by tanawin on 12/2/2566.
//

#include "uop_base.h"

#include <utility>
#include "core/tracers/uop_wd.h"

UOP_BASE::UOP_BASE(UOP_TYPE _uop_type):
uop_type(_uop_type){}

uint64_t
UOP_BASE::getSeqNum() const {
    return seqNum;
}

void
UOP_BASE::setSeqNum(uint64_t _seqNum) {
    seqNum = _seqNum;
}

UOP_TYPE UOP_BASE::getUopType() const {
    return uop_type;
}

void UOP_BASE::setUopType(UOP_TYPE uopType) {
    uop_type = uopType;
}


////// simple compute reg
/////////////////////////////////////////////////////////////////////////////
void UOP_SIMPLE::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    doMemDepenCheck(uop_window);
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}
