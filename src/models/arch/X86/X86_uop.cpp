#include"X86_uop.h"
#include"core/tracers/uop_wd.h"
void SIM_ALU$R_R$R$0::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void SIM_ALU$R_R$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM_ALU$R_R$T$0::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void SIM_ALU$R_R$T$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST$T$M$0::addMeta(OPR_TREG& opr_preDes ,OPR_MEM& opr_m_des_0){
       addTRegMeta(opr_preDes.getMeta());
       addMemMeta (opr_m_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOV_MEM_ST$T$M$0::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD$I$T$0::addMeta(OPR_IMM& opr_i_src_1 ,OPR_TREG& opr_t_1){
       /* imm had no meta data*/;
       addTRegMeta(opr_t_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOV_MEM_LD$I$T$0::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void SIM_ALU$R_T$R$0::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void SIM_ALU$R_T$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM_ALU$R_T$T$0::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void SIM_ALU$R_T$T$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD$M$T$0::addMeta(OPR_MEM& opr_m_src_1 ,OPR_TREG& opr_t_1){
       addMemMeta (opr_m_src_1.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOV_MEM_LD$M$T$0::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM_ALU$T_R$R$0::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void SIM_ALU$T_R$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM_ALU$T_R$T$0::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void SIM_ALU$T_R$T$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM_ALU$T_T$R$0::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void SIM_ALU$T_T$R$0::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void SIM_ALU$T_T$T$0::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void SIM_ALU$T_T$T$0::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MUL_ALU$R_R$R$0::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MUL_ALU$R_R$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL_ALU$R_R$T$0::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MUL_ALU$R_R$T$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL_ALU$R_T$R$0::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MUL_ALU$R_T$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL_ALU$R_T$T$0::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MUL_ALU$R_T$T$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL_ALU$T_R$R$0::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MUL_ALU$T_R$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL_ALU$T_R$T$0::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MUL_ALU$T_R$T$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL_ALU$T_T$R$0::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MUL_ALU$T_T$R$0::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MUL_ALU$T_T$T$0::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MUL_ALU$T_T$T$0::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void DIV_ALU$R_R$R$0::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void DIV_ALU$R_R$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV_ALU$R_R$T$0::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void DIV_ALU$R_R$T$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV_ALU$R_T$R$0::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void DIV_ALU$R_T$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV_ALU$R_T$T$0::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void DIV_ALU$R_T$T$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV_ALU$T_R$R$0::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void DIV_ALU$T_R$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV_ALU$T_R$T$0::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void DIV_ALU$T_R$T$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV_ALU$T_T$R$0::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void DIV_ALU$T_T$R$0::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void DIV_ALU$T_T$T$0::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void DIV_ALU$T_T$T$0::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MOV$R$R$0::addMeta(OPR_REG& opr_r_src_0 ,OPR_REG& opr_x_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOV$R$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV$R$M$0::addMeta(OPR_REG& opr_r_src_0 ,OPR_MEM& opr_x_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addMemMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOV$R$M$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV$I$R$0::addMeta(OPR_IMM& opr_i_src_0 ,OPR_REG& opr_x_des_0){
       /* imm had no meta data*/;
       addRegMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOV$I$R$0::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MOV$I$T$0::addMeta(OPR_IMM& opr_i_src_0 ,OPR_TREG& opr_t_0){
       /* imm had no meta data*/;
       addTRegMeta(opr_t_0.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOV$I$T$0::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MOV$T$M$0::addMeta(OPR_TREG& opr_t_0 ,OPR_MEM& opr_x_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addMemMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOV$T$M$0::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV$M$R$0::addMeta(OPR_MEM& opr_m_src_0 ,OPR_REG& opr_x_des_0){
       addMemMeta (opr_m_src_0.getMeta(), true);
       addRegMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOV$M$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV$M$T$0::addMeta(OPR_MEM& opr_m_src_0 ,OPR_TREG& opr_t_0){
       addMemMeta (opr_m_src_0.getMeta(), true);
       addTRegMeta(opr_t_0.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOV$M$T$0::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_INTERNAL$R$R$0::addMeta(OPR_REG& opr_r_src_0 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOV_INTERNAL$R$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST$R$M$0::addMeta(OPR_REG& opr_r_src_0 ,OPR_MEM& opr_m_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addMemMeta (opr_m_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOV_MEM_ST$R$M$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD$I$R$0::addMeta(OPR_IMM& opr_i_src_0 ,OPR_REG& opr_x_des_0){
       /* imm had no meta data*/;
       addRegMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOV_MEM_LD$I$R$0::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD$M$R$0::addMeta(OPR_MEM& opr_m_src_0 ,OPR_REG& opr_x_des_0){
       addMemMeta (opr_m_src_0.getMeta(), true);
       addRegMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOV_MEM_LD$M$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
