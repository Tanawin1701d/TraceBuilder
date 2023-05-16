//
// Created by tanawin on 12/2/2566.
//

#include "uop_base.h"
#include "core/tracers/uop_wd.h"

UOP_BASE::UOP_BASE():
seqNum(UINT64_MAX),
uop_type(UOP_DUMMY),
exec_unit_id(DUMMY_EXEC_UNIT_ID)
{

}

////// simple compute reg
/////////////////////////////////////////////////////////////////////////////
void UOP_SIMPLE::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    doMemDepenCheck(uop_window);
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

UOP_SIMPLE::UOP_SIMPLE(UOP_TYPE _uop_type):
UOP_BASE()
{
    uop_type = _uop_type;
}