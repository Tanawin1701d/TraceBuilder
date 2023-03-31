#include"x86_uop.h"
/////////////// UOP_GEN_MEM_LD_T

UOP_GEN_MEM_LD_T::UOP_GEN_MEM_LD_T() : UOP_BASE(UOP_LOAD){}

void UOP_GEN_MEM_LD_T::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    doMemDepenCheck(uop_window);
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_GEN_MEM_LD_T::addMeta(MEM_OPERAND* A, TREGNUM* B){
///////// input
///MEM with name A
addMemMeta(A->getMeta()  , true);
addRegMeta(A->getBaseRegId(), true);
addRegMeta(A->getIndexRegId(), true);
///////// output
///TREG with name B
addTRegMeta(*B, false);
}

//////////////////////////////////////



/////////////// UOP_GEN_MEM_ST_T

UOP_GEN_MEM_ST_T::UOP_GEN_MEM_ST_T() : UOP_BASE(UOP_STORE){}

void UOP_GEN_MEM_ST_T::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    doMemDepenCheck(uop_window);
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_GEN_MEM_ST_T::addMeta(TREGNUM* A, MEM_OPERAND* B){
///////// input
///TREG with name A
addTRegMeta(*A, true);
///////// output
///MEM with name B
addMemMeta(B->getMeta(), false);
addRegMeta(B->getBaseRegId(), true);
addRegMeta(B->getIndexRegId(), true);
}

//////////////////////////////////////



/////////////// UOP_GEN_MOV_R_R

UOP_GEN_MOV_R_R::UOP_GEN_MOV_R_R() : UOP_BASE(UOP_COMP){}

void UOP_GEN_MOV_R_R::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_GEN_MOV_R_R::addMeta(REG_OPERAND* A, REG_OPERAND* B){
///////// input
///REG with name A
addRegMeta(A->getMeta(), true);
///////// output
///REG with name B
addRegMeta(B->getMeta(), false);
}

//////////////////////////////////////



/////////////// UOP_GEN_MOV_R_T

UOP_GEN_MOV_R_T::UOP_GEN_MOV_R_T() : UOP_BASE(UOP_COMP){}

void UOP_GEN_MOV_R_T::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_GEN_MOV_R_T::addMeta(REG_OPERAND* A, TREGNUM* B){
///////// input
///REG with name A
addRegMeta(A->getMeta(), true);
///////// output
///TREG with name B
addTRegMeta(*B, false);
}

//////////////////////////////////////



/////////////// UOP_GEN_MOV_T_R

UOP_GEN_MOV_T_R::UOP_GEN_MOV_T_R() : UOP_BASE(UOP_COMP){}

void UOP_GEN_MOV_T_R::doDepenCheck(UOP_WINDOW* uop_window) {
    
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_GEN_MOV_T_R::addMeta(TREGNUM* A, REG_OPERAND* B){
///////// input
///TREG with name A
addTRegMeta(*A, true);
///////// output
///REG with name B
addRegMeta(B->getMeta(), false);
}

//////////////////////////////////////



/////////////// UOP_GEN_COMP_R_R_R

UOP_GEN_COMP_R_R_R::UOP_GEN_COMP_R_R_R() : UOP_BASE(UOP_COMP){}

void UOP_GEN_COMP_R_R_R::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_GEN_COMP_R_R_R::addMeta(REG_OPERAND* A, REG_OPERAND* B, REG_OPERAND* C){
///////// input
///REG with name A
addRegMeta(A->getMeta(), true);
///REG with name B
addRegMeta(B->getMeta(), true);
///////// output
///REG with name C
addRegMeta(C->getMeta(), false);
}

//////////////////////////////////////



/////////////// UOP_GEN_COMP_R_T_R

UOP_GEN_COMP_R_T_R::UOP_GEN_COMP_R_T_R() : UOP_BASE(UOP_COMP){}

void UOP_GEN_COMP_R_T_R::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_GEN_COMP_R_T_R::addMeta(REG_OPERAND* A, TREGNUM* B, REG_OPERAND* C){
///////// input
///REG with name A
addRegMeta(A->getMeta(), true);
///TREG with name B
addTRegMeta(*B, true);
///////// output
///REG with name C
addRegMeta(C->getMeta(), false);
}

//////////////////////////////////////



/////////////// UOP_GEN_COMP_T_R_R

UOP_GEN_COMP_T_R_R::UOP_GEN_COMP_T_R_R() : UOP_BASE(UOP_COMP){}

void UOP_GEN_COMP_T_R_R::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_GEN_COMP_T_R_R::addMeta(TREGNUM* A, REG_OPERAND* B, REG_OPERAND* C){
///////// input
///TREG with name A
addTRegMeta(*A, true);
///REG with name B
addRegMeta(B->getMeta(), true);
///////// output
///REG with name C
addRegMeta(C->getMeta(), false);
}

//////////////////////////////////////



/////////////// UOP_GEN_COMP_T_T_R

UOP_GEN_COMP_T_T_R::UOP_GEN_COMP_T_T_R() : UOP_BASE(UOP_COMP){}

void UOP_GEN_COMP_T_T_R::doDepenCheck(UOP_WINDOW* uop_window) {
    
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_GEN_COMP_T_T_R::addMeta(TREGNUM* A, TREGNUM* B, REG_OPERAND* C){
///////// input
///TREG with name A
addTRegMeta(*A, true);
///TREG with name B
addTRegMeta(*B, true);
///////// output
///REG with name C
addRegMeta(C->getMeta(), false);
}

//////////////////////////////////////



/////////////// UOP_GEN_COMP_R_R_T

UOP_GEN_COMP_R_R_T::UOP_GEN_COMP_R_R_T() : UOP_BASE(UOP_COMP){}

void UOP_GEN_COMP_R_R_T::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_GEN_COMP_R_R_T::addMeta(REG_OPERAND* A, REG_OPERAND* B, TREGNUM* C){
///////// input
///REG with name A
addRegMeta(A->getMeta(), true);
///REG with name B
addRegMeta(B->getMeta(), true);
///////// output
///TREG with name C
addTRegMeta(*C, false);
}

//////////////////////////////////////



/////////////// UOP_GEN_COMP_R_T_T

UOP_GEN_COMP_R_T_T::UOP_GEN_COMP_R_T_T() : UOP_BASE(UOP_COMP){}

void UOP_GEN_COMP_R_T_T::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_GEN_COMP_R_T_T::addMeta(REG_OPERAND* A, TREGNUM* B, TREGNUM* C){
///////// input
///REG with name A
addRegMeta(A->getMeta(), true);
///TREG with name B
addTRegMeta(*B, true);
///////// output
///TREG with name C
addTRegMeta(*C, false);
}

//////////////////////////////////////



/////////////// UOP_GEN_COMP_T_R_T

UOP_GEN_COMP_T_R_T::UOP_GEN_COMP_T_R_T() : UOP_BASE(UOP_COMP){}

void UOP_GEN_COMP_T_R_T::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_GEN_COMP_T_R_T::addMeta(TREGNUM* A, REG_OPERAND* B, TREGNUM* C){
///////// input
///TREG with name A
addTRegMeta(*A, true);
///REG with name B
addRegMeta(B->getMeta(), true);
///////// output
///TREG with name C
addTRegMeta(*C, false);
}

//////////////////////////////////////



/////////////// UOP_GEN_COMP_T_T_T

UOP_GEN_COMP_T_T_T::UOP_GEN_COMP_T_T_T() : UOP_BASE(UOP_COMP){}

void UOP_GEN_COMP_T_T_T::doDepenCheck(UOP_WINDOW* uop_window) {
    
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_GEN_COMP_T_T_T::addMeta(TREGNUM* A, TREGNUM* B, TREGNUM* C){
///////// input
///TREG with name A
addTRegMeta(*A, true);
///TREG with name B
addTRegMeta(*B, true);
///////// output
///TREG with name C
addTRegMeta(*C, false);
}

//////////////////////////////////////



/////////////// UOP_GEN_LD_IMM

UOP_GEN_LD_IMM::UOP_GEN_LD_IMM() : UOP_BASE(UOP_IMM){}

void UOP_GEN_LD_IMM::doDepenCheck(UOP_WINDOW* uop_window) {
    
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_GEN_LD_IMM::addMeta(TREGNUM* T1){
///////// input
///////// output
///TREG with name T1
addTRegMeta(*T1, false);
}

//////////////////////////////////////



/////////////// UOP_LD_RIP

UOP_LD_RIP::UOP_LD_RIP() : UOP_BASE(UOP_COMP){}

void UOP_LD_RIP::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_LD_RIP::addMeta(REG_OPERAND* RIP, TREGNUM* T1){
///////// input
///REG with name RIP
addRegMeta(RIP->getMeta(), true);
///////// output
///TREG with name T1
addTRegMeta(*T1, false);
}

//////////////////////////////////////



/////////////// UOP_ST_RIP_1T

UOP_ST_RIP_1T::UOP_ST_RIP_1T() : UOP_BASE(UOP_COMP){}

void UOP_ST_RIP_1T::doDepenCheck(UOP_WINDOW* uop_window) {
    
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_ST_RIP_1T::addMeta(TREGNUM* T1, REG_OPERAND* RIP){
///////// input
///TREG with name T1
addTRegMeta(*T1, true);
///////// output
///REG with name RIP
addRegMeta(RIP->getMeta(), false);
}

//////////////////////////////////////



/////////////// UOP_ST_RIP_1R

UOP_ST_RIP_1R::UOP_ST_RIP_1R() : UOP_BASE(UOP_COMP){}

void UOP_ST_RIP_1R::doDepenCheck(UOP_WINDOW* uop_window) {
    doRegDepenCheck(uop_window);
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_ST_RIP_1R::addMeta(REG_OPERAND* R1, REG_OPERAND* RIP){
///////// input
///REG with name R1
addRegMeta(R1->getMeta(), true);
///////// output
///REG with name RIP
addRegMeta(RIP->getMeta(), false);
}

//////////////////////////////////////



/////////////// UOP_ST_RIP_2T

UOP_ST_RIP_2T::UOP_ST_RIP_2T() : UOP_BASE(UOP_COMP){}

void UOP_ST_RIP_2T::doDepenCheck(UOP_WINDOW* uop_window) {
    
    
    ///// for future use
    /////   doExeDepenCheck(uop_window)

}

void UOP_ST_RIP_2T::addMeta(TREGNUM* T1, TREGNUM* T2, REG_OPERAND* RIP){
///////// input
///TREG with name T1
addTRegMeta(*T1, true);
///TREG with name T2
addTRegMeta(*T2, true);
///////// output
///REG with name RIP
addRegMeta(RIP->getMeta(), false);
}

//////////////////////////////////////


