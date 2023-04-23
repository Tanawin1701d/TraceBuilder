#include"X86_uop.h"
#include"core/tracers/uop_wd.h"
void COMP$T_T$T::addMeta(OPR_TREG& opr_a0, OPR_TREG& opr_a1 ,OPR_TREG& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       addTRegMeta(opr_a1.getMeta());
       addTRegMeta(opr_b0.getMeta());
}
void COMP$T_T$T::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void COMP$T_T$R::addMeta(OPR_TREG& opr_a0, OPR_TREG& opr_a1 ,OPR_REG& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       addTRegMeta(opr_a1.getMeta());
       addRegMeta (opr_b0.getMeta(), false);
}
void COMP$T_T$R::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void COMP$T_T$M::addMeta(OPR_TREG& opr_a0, OPR_TREG& opr_a1 ,OPR_MEM& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       addTRegMeta(opr_a1.getMeta());
       addMemMeta (opr_b0.getMeta(), false);
}
void COMP$T_T$M::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$T_R$T::addMeta(OPR_TREG& opr_a0, OPR_REG& opr_a1 ,OPR_TREG& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       addRegMeta (opr_a1.getMeta(), true);
       addTRegMeta(opr_b0.getMeta());
}
void COMP$T_R$T::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$T_R$R::addMeta(OPR_TREG& opr_a0, OPR_REG& opr_a1 ,OPR_REG& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       addRegMeta (opr_a1.getMeta(), true);
       addRegMeta (opr_b0.getMeta(), false);
}
void COMP$T_R$R::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$T_R$M::addMeta(OPR_TREG& opr_a0, OPR_REG& opr_a1 ,OPR_MEM& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       addRegMeta (opr_a1.getMeta(), true);
       addMemMeta (opr_b0.getMeta(), false);
}
void COMP$T_R$M::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$T_I$T::addMeta(OPR_TREG& opr_a0, OPR_IMM& opr_a1 ,OPR_TREG& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       /* imm had no meta data*/;
       addTRegMeta(opr_b0.getMeta());
}
void COMP$T_I$T::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void COMP$T_I$R::addMeta(OPR_TREG& opr_a0, OPR_IMM& opr_a1 ,OPR_REG& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       /* imm had no meta data*/;
       addRegMeta (opr_b0.getMeta(), false);
}
void COMP$T_I$R::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void COMP$T_I$M::addMeta(OPR_TREG& opr_a0, OPR_IMM& opr_a1 ,OPR_MEM& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       /* imm had no meta data*/;
       addMemMeta (opr_b0.getMeta(), false);
}
void COMP$T_I$M::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$T_M$T::addMeta(OPR_TREG& opr_a0, OPR_MEM& opr_a1 ,OPR_TREG& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       addMemMeta (opr_a1.getMeta(), true);
       addTRegMeta(opr_b0.getMeta());
}
void COMP$T_M$T::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$T_M$R::addMeta(OPR_TREG& opr_a0, OPR_MEM& opr_a1 ,OPR_REG& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       addMemMeta (opr_a1.getMeta(), true);
       addRegMeta (opr_b0.getMeta(), false);
}
void COMP$T_M$R::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$T_M$M::addMeta(OPR_TREG& opr_a0, OPR_MEM& opr_a1 ,OPR_MEM& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       addMemMeta (opr_a1.getMeta(), true);
       addMemMeta (opr_b0.getMeta(), false);
}
void COMP$T_M$M::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$R_T$T::addMeta(OPR_REG& opr_a0, OPR_TREG& opr_a1 ,OPR_TREG& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       addTRegMeta(opr_a1.getMeta());
       addTRegMeta(opr_b0.getMeta());
}
void COMP$R_T$T::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$R_T$R::addMeta(OPR_REG& opr_a0, OPR_TREG& opr_a1 ,OPR_REG& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       addTRegMeta(opr_a1.getMeta());
       addRegMeta (opr_b0.getMeta(), false);
}
void COMP$R_T$R::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$R_T$M::addMeta(OPR_REG& opr_a0, OPR_TREG& opr_a1 ,OPR_MEM& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       addTRegMeta(opr_a1.getMeta());
       addMemMeta (opr_b0.getMeta(), false);
}
void COMP$R_T$M::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$R_R$T::addMeta(OPR_REG& opr_a0, OPR_REG& opr_a1 ,OPR_TREG& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       addRegMeta (opr_a1.getMeta(), true);
       addTRegMeta(opr_b0.getMeta());
}
void COMP$R_R$T::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$R_R$R::addMeta(OPR_REG& opr_a0, OPR_REG& opr_a1 ,OPR_REG& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       addRegMeta (opr_a1.getMeta(), true);
       addRegMeta (opr_b0.getMeta(), false);
}
void COMP$R_R$R::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$R_R$M::addMeta(OPR_REG& opr_a0, OPR_REG& opr_a1 ,OPR_MEM& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       addRegMeta (opr_a1.getMeta(), true);
       addMemMeta (opr_b0.getMeta(), false);
}
void COMP$R_R$M::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$R_I$T::addMeta(OPR_REG& opr_a0, OPR_IMM& opr_a1 ,OPR_TREG& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       /* imm had no meta data*/;
       addTRegMeta(opr_b0.getMeta());
}
void COMP$R_I$T::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$R_I$R::addMeta(OPR_REG& opr_a0, OPR_IMM& opr_a1 ,OPR_REG& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       /* imm had no meta data*/;
       addRegMeta (opr_b0.getMeta(), false);
}
void COMP$R_I$R::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$R_I$M::addMeta(OPR_REG& opr_a0, OPR_IMM& opr_a1 ,OPR_MEM& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       /* imm had no meta data*/;
       addMemMeta (opr_b0.getMeta(), false);
}
void COMP$R_I$M::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$R_M$T::addMeta(OPR_REG& opr_a0, OPR_MEM& opr_a1 ,OPR_TREG& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       addMemMeta (opr_a1.getMeta(), true);
       addTRegMeta(opr_b0.getMeta());
}
void COMP$R_M$T::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$R_M$R::addMeta(OPR_REG& opr_a0, OPR_MEM& opr_a1 ,OPR_REG& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       addMemMeta (opr_a1.getMeta(), true);
       addRegMeta (opr_b0.getMeta(), false);
}
void COMP$R_M$R::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$R_M$M::addMeta(OPR_REG& opr_a0, OPR_MEM& opr_a1 ,OPR_MEM& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       addMemMeta (opr_a1.getMeta(), true);
       addMemMeta (opr_b0.getMeta(), false);
}
void COMP$R_M$M::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$M_T$T::addMeta(OPR_MEM& opr_a0, OPR_TREG& opr_a1 ,OPR_TREG& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       addTRegMeta(opr_a1.getMeta());
       addTRegMeta(opr_b0.getMeta());
}
void COMP$M_T$T::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$M_T$R::addMeta(OPR_MEM& opr_a0, OPR_TREG& opr_a1 ,OPR_REG& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       addTRegMeta(opr_a1.getMeta());
       addRegMeta (opr_b0.getMeta(), false);
}
void COMP$M_T$R::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$M_T$M::addMeta(OPR_MEM& opr_a0, OPR_TREG& opr_a1 ,OPR_MEM& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       addTRegMeta(opr_a1.getMeta());
       addMemMeta (opr_b0.getMeta(), false);
}
void COMP$M_T$M::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$M_R$T::addMeta(OPR_MEM& opr_a0, OPR_REG& opr_a1 ,OPR_TREG& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       addRegMeta (opr_a1.getMeta(), true);
       addTRegMeta(opr_b0.getMeta());
}
void COMP$M_R$T::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$M_R$R::addMeta(OPR_MEM& opr_a0, OPR_REG& opr_a1 ,OPR_REG& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       addRegMeta (opr_a1.getMeta(), true);
       addRegMeta (opr_b0.getMeta(), false);
}
void COMP$M_R$R::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$M_R$M::addMeta(OPR_MEM& opr_a0, OPR_REG& opr_a1 ,OPR_MEM& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       addRegMeta (opr_a1.getMeta(), true);
       addMemMeta (opr_b0.getMeta(), false);
}
void COMP$M_R$M::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$M_I$T::addMeta(OPR_MEM& opr_a0, OPR_IMM& opr_a1 ,OPR_TREG& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       /* imm had no meta data*/;
       addTRegMeta(opr_b0.getMeta());
}
void COMP$M_I$T::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$M_I$R::addMeta(OPR_MEM& opr_a0, OPR_IMM& opr_a1 ,OPR_REG& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       /* imm had no meta data*/;
       addRegMeta (opr_b0.getMeta(), false);
}
void COMP$M_I$R::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$M_I$M::addMeta(OPR_MEM& opr_a0, OPR_IMM& opr_a1 ,OPR_MEM& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       /* imm had no meta data*/;
       addMemMeta (opr_b0.getMeta(), false);
}
void COMP$M_I$M::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$M_M$T::addMeta(OPR_MEM& opr_a0, OPR_MEM& opr_a1 ,OPR_TREG& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       addMemMeta (opr_a1.getMeta(), true);
       addTRegMeta(opr_b0.getMeta());
}
void COMP$M_M$T::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$M_M$R::addMeta(OPR_MEM& opr_a0, OPR_MEM& opr_a1 ,OPR_REG& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       addMemMeta (opr_a1.getMeta(), true);
       addRegMeta (opr_b0.getMeta(), false);
}
void COMP$M_M$R::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void COMP$M_M$M::addMeta(OPR_MEM& opr_a0, OPR_MEM& opr_a1 ,OPR_MEM& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       addMemMeta (opr_a1.getMeta(), true);
       addMemMeta (opr_b0.getMeta(), false);
}
void COMP$M_M$M::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV$T$T::addMeta(OPR_TREG& opr_a0 ,OPR_TREG& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       addTRegMeta(opr_b0.getMeta());
}
void MOV$T$T::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MOV$T$R::addMeta(OPR_TREG& opr_a0 ,OPR_REG& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       addRegMeta (opr_b0.getMeta(), false);
}
void MOV$T$R::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MOV$T$I::addMeta(OPR_TREG& opr_a0 ,OPR_IMM& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       /* imm had no meta data*/;
}
void MOV$T$I::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MOV$T$M::addMeta(OPR_TREG& opr_a0 ,OPR_MEM& opr_b0){
       addTRegMeta(opr_a0.getMeta());
       addMemMeta (opr_b0.getMeta(), false);
}
void MOV$T$M::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV$R$T::addMeta(OPR_REG& opr_a0 ,OPR_TREG& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       addTRegMeta(opr_b0.getMeta());
}
void MOV$R$T::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV$R$R::addMeta(OPR_REG& opr_a0 ,OPR_REG& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       addRegMeta (opr_b0.getMeta(), false);
}
void MOV$R$R::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV$R$I::addMeta(OPR_REG& opr_a0 ,OPR_IMM& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       /* imm had no meta data*/;
}
void MOV$R$I::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV$R$M::addMeta(OPR_REG& opr_a0 ,OPR_MEM& opr_b0){
       addRegMeta (opr_a0.getMeta(), true);
       addMemMeta (opr_b0.getMeta(), false);
}
void MOV$R$M::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV$I$T::addMeta(OPR_IMM& opr_a0 ,OPR_TREG& opr_b0){
       /* imm had no meta data*/;
       addTRegMeta(opr_b0.getMeta());
}
void MOV$I$T::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MOV$I$R::addMeta(OPR_IMM& opr_a0 ,OPR_REG& opr_b0){
       /* imm had no meta data*/;
       addRegMeta (opr_b0.getMeta(), false);
}
void MOV$I$R::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MOV$I$I::addMeta(OPR_IMM& opr_a0 ,OPR_IMM& opr_b0){
       /* imm had no meta data*/;
       /* imm had no meta data*/;
}
void MOV$I$I::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MOV$I$M::addMeta(OPR_IMM& opr_a0 ,OPR_MEM& opr_b0){
       /* imm had no meta data*/;
       addMemMeta (opr_b0.getMeta(), false);
}
void MOV$I$M::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV$M$T::addMeta(OPR_MEM& opr_a0 ,OPR_TREG& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       addTRegMeta(opr_b0.getMeta());
}
void MOV$M$T::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV$M$R::addMeta(OPR_MEM& opr_a0 ,OPR_REG& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       addRegMeta (opr_b0.getMeta(), false);
}
void MOV$M$R::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV$M$I::addMeta(OPR_MEM& opr_a0 ,OPR_IMM& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       /* imm had no meta data*/;
}
void MOV$M$I::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV$M$M::addMeta(OPR_MEM& opr_a0 ,OPR_MEM& opr_b0){
       addMemMeta (opr_a0.getMeta(), true);
       addMemMeta (opr_b0.getMeta(), false);
}
void MOV$M$M::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
