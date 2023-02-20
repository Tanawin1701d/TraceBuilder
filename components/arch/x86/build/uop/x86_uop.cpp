#include"x86_uop.h"
void UOP_ADD::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    doMemDepenCheck(uop_window);
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_ADD::addMeta(REGNUM A, ADAS B, REGNUM C){
///////// input
   addRegMeta(A, true);
   addMemMeta(B, true);
///////// output
   addRegMeta(C, false);
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
