#include"x86_uop.h"
void UOP_ADD::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_ADD::addMeta(REGNUM A, TREGNUM B, REGNUM C){
///////// input
   addRegMeta(A, true);
   addTRegMeta(B, true);
///////// output
   addRegMeta(C, false);
}

void UOP_LD::doDepenCheck(UOP_WINDOW* uop_window) {
    
    doMemDepenCheck(uop_window);
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_LD::addMeta(ADAS A, TREGNUM C){
///////// input
   addMemMeta(A, true);
///////// output
   addTRegMeta(C, false);
}
