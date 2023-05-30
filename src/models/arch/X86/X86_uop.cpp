#include"X86_uop.h"
#include"core/tracers/uop_wd.h"
void INT_SIM_ALU$R_R$R_R$1::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$R_R$R_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_R$R_T$1::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$R_R$R_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST$T$M$99::addMeta(OPR_TREG& opr_preDes_1 ,OPR_MEM& opr_m_des_1){
       addTRegMeta(opr_preDes_1.getMeta());
       addMemMeta (opr_m_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_STORE);
       setExecUnit(99);
}
void MOV_MEM_ST$T$M$99::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_R$R$1::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$R_R$R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_R$T_R$1::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$R_R$T_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_R$T_T$1::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$R_R$T_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_R$T$1::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$R_R$T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD$I$T$6::addMeta(OPR_IMM& opr_i_src_1 ,OPR_TREG& opr_t_1){
       /* imm had no meta data*/;
       addTRegMeta(opr_t_1.getMeta());
       setUopType(UOP_TYPE::UOP_LOAD);
       setExecUnit(6);
}
void MOV_MEM_LD$I$T$6::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_T$R_R$1::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$R_T$R_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_T$R_T$1::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$R_T$R_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_T$R$1::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$R_T$R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_T$T_R$1::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$R_T$T_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_T$T_T$1::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$R_T$T_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_T$T$1::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$R_T$T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD$M$T$6::addMeta(OPR_MEM& opr_m_src_1 ,OPR_TREG& opr_t_1){
       addMemMeta (opr_m_src_1.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       setUopType(UOP_TYPE::UOP_LOAD);
       setExecUnit(6);
}
void MOV_MEM_LD$M$T$6::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$T_R$R_R$1::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$T_R$R_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$T_R$R_T$1::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$T_R$R_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$T_R$R$1::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$T_R$R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$T_R$T_R$1::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$T_R$T_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$T_R$T_T$1::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$T_R$T_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$T_R$T$1::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$T_R$T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$T_T$R_R$1::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$T_T$R_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$T_T$R_T$1::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$T_T$R_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$T_T$R$1::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$T_T$R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$T_T$T_R$1::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$T_T$T_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$T_T$T_T$1::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$T_T$T_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$T_T$T$1::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void INT_SIM_ALU$T_T$T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_R$R_R$2::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$R_R$R_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_R$R_T$2::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$R_R$R_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_R$R$2::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$R_R$R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_R$T_R$2::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$R_R$T_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_R$T_T$2::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$R_R$T_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_R$T$2::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$R_R$T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_T$R_R$2::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$R_T$R_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_T$R_T$2::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$R_T$R_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_T$R$2::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$R_T$R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_T$T_R$2::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$R_T$T_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_T$T_T$2::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$R_T$T_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_T$T$2::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$R_T$T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$T_R$R_R$2::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$T_R$R_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$T_R$R_T$2::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$T_R$R_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$T_R$R$2::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$T_R$R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$T_R$T_R$2::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$T_R$T_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$T_R$T_T$2::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$T_R$T_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$T_R$T$2::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$T_R$T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$T_T$R_R$2::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$T_T$R_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$T_T$R_T$2::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$T_T$R_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$T_T$R$2::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$T_T$R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$T_T$T_R$2::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$T_T$T_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$T_T$T_T$2::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$T_T$T_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$T_T$T$2::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void INT_MUL_DIV_ALU$T_T$T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_R$R_R$5::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$R_R$R_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_R$R_T$5::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$R_R$R_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_R$R$5::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$R_R$R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_R$T_R$5::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$R_R$T_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_R$T_T$5::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$R_R$T_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_R$T$5::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$R_R$T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_T$R_R$5::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$R_T$R_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_T$R_T$5::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$R_T$R_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_T$R$5::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$R_T$R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_T$T_R$5::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$R_T$T_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_T$T_T$5::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$R_T$T_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_T$T$5::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$R_T$T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$T_R$R_R$5::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$T_R$R_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$T_R$R_T$5::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$T_R$R_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$T_R$R$5::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$T_R$R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$T_R$T_R$5::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$T_R$T_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$T_R$T_T$5::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$T_R$T_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$T_R$T$5::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes_0.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$T_R$T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$T_T$R_R$5::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$T_T$R_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$T_T$R_T$5::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$T_T$R_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$T_T$R$5::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$T_T$R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$T_T$T_R$5::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$T_T$T_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$T_T$T_T$5::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$T_T$T_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM64_ALU$T_T$T$5::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes_0.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM64_ALU$T_T$T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_R$R_R$5::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$R_R$R_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_R$R_T$5::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$R_R$R_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_R$R$5::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$R_R$R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_R$T_R$5::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$R_R$T_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_R$T_T$5::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$R_R$T_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_R$T$5::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$R_R$T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_T$R_R$5::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$R_T$R_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_T$R_T$5::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$R_T$R_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_T$R$5::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$R_T$R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_T$T_R$5::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$R_T$T_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_T$T_T$5::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$R_T$T_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_T$T$5::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$R_T$T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_R$R_R$5::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$T_R$R_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_R$R_T$5::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$T_R$R_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_R$R$5::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$T_R$R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_R$T_R$5::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$T_R$T_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_R$T_T$5::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$T_R$T_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_R$T$5::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$T_R$T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_T$R_R$5::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$T_T$R_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_T$R_T$5::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$T_T$R_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_T$R$5::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$T_T$R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_T$T_R$5::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$T_T$T_R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_T$T_T$5::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       addTRegMeta(opr_preDes_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$T_T$T_T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_T$T$5::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void SIM128_ALU$T_T$T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_REG$R$R$1::addMeta(OPR_REG& opr_r_src_0 ,OPR_REG& opr_x_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void MOV_REG$R$R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_REG$R$M$1::addMeta(OPR_REG& opr_r_src_0 ,OPR_MEM& opr_x_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addMemMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void MOV_REG$R$M$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD$I$R$6::addMeta(OPR_IMM& opr_i_src_0 ,OPR_REG& opr_x_des_0){
       /* imm had no meta data*/;
       addRegMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_LOAD);
       setExecUnit(6);
}
void MOV_MEM_LD$I$R$6::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD$M$R$6::addMeta(OPR_MEM& opr_m_src_0 ,OPR_REG& opr_x_des_0){
       addMemMeta (opr_m_src_0.getMeta(), true);
       addRegMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_LOAD);
       setExecUnit(6);
}
void MOV_MEM_LD$M$R$6::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST$R$M$99::addMeta(OPR_REG& opr_r_src_0 ,OPR_MEM& opr_m_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addMemMeta (opr_m_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_STORE);
       setExecUnit(99);
}
void MOV_MEM_ST$R$M$99::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$R_R$$1::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void CMP_SIM_ALU$R_R$$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$R_T$$1::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void CMP_SIM_ALU$R_T$$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$T_R$$1::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void CMP_SIM_ALU$T_R$$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$T_T$$1::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void CMP_SIM_ALU$T_T$$1::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void JMP_SIM_ALU$R$R$1::addMeta(OPR_REG& opr_r_src_0 ,OPR_REG& opr_reg_des_1){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_reg_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void JMP_SIM_ALU$R$R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
