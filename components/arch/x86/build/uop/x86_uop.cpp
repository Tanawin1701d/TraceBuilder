#include"x86_uop.h"
void UOP_ADD::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    doMemDepenCheck(uop_window);
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_ADD::addMeta(REGNUM A, ADAS B, TREGNUM C, REGNUM D, TREGNUM E){
///////// input
   addRegMeta(A, true);
   addMemMeta(B, true);
   addTRegMeta(C, true);
///////// output
   addRegMeta(D, false);
   addTRegMeta(E, false);
}

void UOP_ADD2::doDepenCheck(UOP_WINDOW* uop_window) {
    
    doMemDepenCheck(uop_window);
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_ADD2::addMeta(ADAS A, ADAS B, ADAS C){
///////// input
   addMemMeta(A, true);
   addMemMeta(B, true);
///////// output
   addMemMeta(C, false);
}
