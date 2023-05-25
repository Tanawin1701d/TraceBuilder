#include"X86_uop.h"
#include"core/tracers/uop_wd.h"
void SIM_ALU$R_R$R$1::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void SIM_ALU$R_R$R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM_ALU$R_R$T$1::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void SIM_ALU$R_R$T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST$T$M$9::addMeta(OPR_TREG& opr_preDes ,OPR_MEM& opr_m_des_0){
       addTRegMeta(opr_preDes.getMeta());
       addMemMeta (opr_m_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void MOV_MEM_ST$T$M$9::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD$I$T$8::addMeta(OPR_IMM& opr_i_src_1 ,OPR_TREG& opr_t_1){
       /* imm had no meta data*/;
       addTRegMeta(opr_t_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(8);
}
void MOV_MEM_LD$I$T$8::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void SIM_ALU$R_T$R$1::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void SIM_ALU$R_T$R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM_ALU$R_T$T$1::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void SIM_ALU$R_T$T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD$M$T$8::addMeta(OPR_MEM& opr_m_src_1 ,OPR_TREG& opr_t_1){
       addMemMeta (opr_m_src_1.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(8);
}
void MOV_MEM_LD$M$T$8::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM_ALU$T_R$R$1::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void SIM_ALU$T_R$R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM_ALU$T_R$T$1::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void SIM_ALU$T_R$T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM_ALU$T_T$R$1::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void SIM_ALU$T_T$R$1::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void SIM_ALU$T_T$T$1::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void SIM_ALU$T_T$T$1::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MUL_ALU$R_R$R$2::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void MUL_ALU$R_R$R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL_ALU$R_R$T$2::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void MUL_ALU$R_R$T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL_ALU$R_T$R$2::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void MUL_ALU$R_T$R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL_ALU$R_T$T$2::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void MUL_ALU$R_T$T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL_ALU$T_R$R$2::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void MUL_ALU$T_R$R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL_ALU$T_R$T$2::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void MUL_ALU$T_R$T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL_ALU$T_T$R$2::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void MUL_ALU$T_T$R$2::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MUL_ALU$T_T$T$2::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void MUL_ALU$T_T$T$2::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void DIV_ALU$R_R$R$3::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void DIV_ALU$R_R$R$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV_ALU$R_R$T$3::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void DIV_ALU$R_R$T$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV_ALU$R_T$R$3::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void DIV_ALU$R_T$R$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV_ALU$R_T$T$3::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void DIV_ALU$R_T$T$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV_ALU$T_R$R$3::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void DIV_ALU$T_R$R$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV_ALU$T_R$T$3::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void DIV_ALU$T_R$T$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV_ALU$T_T$R$3::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void DIV_ALU$T_T$R$3::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void DIV_ALU$T_T$T$3::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void DIV_ALU$T_T$T$3::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_R$R$4::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void SIM128_ALU$R_R$R$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_R$T$4::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void SIM128_ALU$R_R$T$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_T$R$4::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void SIM128_ALU$R_T$R$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_T$T$4::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void SIM128_ALU$R_T$T$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_R$R$4::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void SIM128_ALU$T_R$R$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_R$T$4::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void SIM128_ALU$T_R$T$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_T$R$4::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void SIM128_ALU$T_T$R$4::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void SIM128_ALU$T_T$T$4::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void SIM128_ALU$T_T$T$4::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MUL128_ALU$R_R$R$5::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void MUL128_ALU$R_R$R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL128_ALU$R_R$T$5::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void MUL128_ALU$R_R$T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL128_ALU$R_T$R$5::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void MUL128_ALU$R_T$R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL128_ALU$R_T$T$5::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void MUL128_ALU$R_T$T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL128_ALU$T_R$R$5::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void MUL128_ALU$T_R$R$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL128_ALU$T_R$T$5::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void MUL128_ALU$T_R$T$5::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MUL128_ALU$T_T$R$5::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void MUL128_ALU$T_T$R$5::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MUL128_ALU$T_T$T$5::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(5);
}
void MUL128_ALU$T_T$T$5::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void DIV128_ALU$R_R$R$6::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(6);
}
void DIV128_ALU$R_R$R$6::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV128_ALU$R_R$T$6::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(6);
}
void DIV128_ALU$R_R$T$6::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV128_ALU$R_T$R$6::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(6);
}
void DIV128_ALU$R_T$R$6::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV128_ALU$R_T$T$6::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(6);
}
void DIV128_ALU$R_T$T$6::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV128_ALU$T_R$R$6::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(6);
}
void DIV128_ALU$T_R$R$6::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV128_ALU$T_R$T$6::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addRegMeta (opr_r_src_1.getMeta(), true);
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(6);
}
void DIV128_ALU$T_R$T$6::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void DIV128_ALU$T_T$R$6::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(6);
}
void DIV128_ALU$T_T$R$6::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void DIV128_ALU$T_T$T$6::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
       addTRegMeta(opr_t_0.getMeta());
       addTRegMeta(opr_t_1.getMeta());
       addTRegMeta(opr_preDes.getMeta());
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(6);
}
void DIV128_ALU$T_T$T$6::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MOV_REG$R$R$10::addMeta(OPR_REG& opr_r_src_0 ,OPR_REG& opr_x_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addRegMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(10);
}
void MOV_REG$R$R$10::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_REG$R$M$10::addMeta(OPR_REG& opr_r_src_0 ,OPR_MEM& opr_x_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addMemMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(10);
}
void MOV_REG$R$M$10::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD$I$R$8::addMeta(OPR_IMM& opr_i_src_0 ,OPR_REG& opr_x_des_0){
       /* imm had no meta data*/;
       addRegMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(8);
}
void MOV_MEM_LD$I$R$8::doDepenCheck(UOP_WINDOW* uop_window){
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD$M$R$8::addMeta(OPR_MEM& opr_m_src_0 ,OPR_REG& opr_x_des_0){
       addMemMeta (opr_m_src_0.getMeta(), true);
       addRegMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(8);
}
void MOV_MEM_LD$M$R$8::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST$R$M$9::addMeta(OPR_REG& opr_r_src_0 ,OPR_MEM& opr_m_des_0){
       addRegMeta (opr_r_src_0.getMeta(), true);
       addMemMeta (opr_m_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void MOV_MEM_ST$R$M$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
}
