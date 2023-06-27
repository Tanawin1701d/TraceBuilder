#include"X86_uop.h"
#include"core/tracers/uop_wd.h"
namespace traceBuilder::model {



using namespace stat;




void IntAlu$R_R$R_R$1::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_R$R_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_R$R_T$1::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_R$R_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST$T$M$34::addMeta(OPR_TREG& opr_preDes_1 ,OPR_MEM& opr_m_des_1){
          addTRegMeta(opr_preDes_1.getMeta(), true);
          addMemMeta_phyArea (opr_m_des_1.getMeta_phyArea(), false);
          addMemMeta_virArea (opr_m_des_1.getMeta_virArea(), false);
          addMemMeta_Static (opr_m_des_1.getMeta_Static());
       setUopType(UOP_TYPE::UOP_IMM);
       setExecUnit(34);
}
void MOV_MEM_ST$T$M$34::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_R$R$1::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_R$R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_R$T_R$1::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_R$T_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_R$T_T$1::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_R$T_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_R$T$1::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_R$T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LDI$I$T$0::addMeta(OPR_IMM& opr_i_src_1 ,OPR_TREG& opr_t_1){
          /* imm had no meta data*/;
          addTRegMeta(opr_t_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_STORE);
       setExecUnit(0);
}
void MOV_MEM_LDI$I$T$0::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_T$R_R$1::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_T$R_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_T$R_T$1::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_T$R_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_T$R$1::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_T$R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_T$T_R$1::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_T$T_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_T$T_T$1::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_T$T_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_T$T$1::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_T$T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD$M$T$33::addMeta(OPR_MEM& opr_m_src_1 ,OPR_TREG& opr_t_1){
          addMemMeta_phyArea (opr_m_src_1.getMeta_phyArea(), true);
          addMemMeta_virArea (opr_m_src_1.getMeta_virArea(), true);
          addMemMeta_Static (opr_m_src_1.getMeta_Static());
          addTRegMeta(opr_t_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_LOAD);
       setExecUnit(33);
}
void MOV_MEM_LD$M$T$33::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_R$R_R$1::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_R$R_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_R$R_T$1::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_R$R_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_R$R$1::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_R$R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_R$T_R$1::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_R$T_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_R$T_T$1::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_R$T_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_R$T$1::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_R$T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_T$R_R$1::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_T$R_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_T$R_T$1::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_T$R_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_T$R$1::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_T$R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_T$T_R$1::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_T$T_R$1::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_T$T_T$1::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_T$T_T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_T$T$1::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_T$T$1::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_R$R_R$2::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_R$R_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_R$R_T$2::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_R$R_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_R$R$2::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_R$R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_R$T_R$2::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_R$T_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_R$T_T$2::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_R$T_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_R$T$2::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_R$T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_T$R_R$2::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_T$R_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_T$R_T$2::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_T$R_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_T$R$2::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_T$R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_T$T_R$2::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_T$T_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_T$T_T$2::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_T$T_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_T$T$2::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_T$T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_R$R_R$2::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_R$R_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_R$R_T$2::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_R$R_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_R$R$2::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_R$R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_R$T_R$2::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_R$T_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_R$T_T$2::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_R$T_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_R$T$2::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_R$T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_T$R_R$2::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_T$R_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_T$R_T$2::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_T$R_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_T$R$2::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_T$R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_T$T_R$2::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_T$T_R$2::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_T$T_T$2::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_T$T_T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_T$T$2::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_T$T$2::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_R$R_R$3::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_R$R_R$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_R$R_T$3::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_R$R_T$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_R$R$3::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_R$R$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_R$T_R$3::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_R$T_R$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_R$T_T$3::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_R$T_T$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_R$T$3::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_R$T$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_T$R_R$3::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_T$R_R$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_T$R_T$3::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_T$R_T$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_T$R$3::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_T$R$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_T$T_R$3::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_T$T_R$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_T$T_T$3::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_T$T_T$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_T$T$3::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_T$T$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_R$R_R$3::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_R$R_R$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_R$R_T$3::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_R$R_T$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_R$R$3::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_R$R$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_R$T_R$3::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_R$T_R$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_R$T_T$3::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_R$T_T$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_R$T$3::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_R$T$3::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_T$R_R$3::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_T$R_R$3::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_T$R_T$3::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_T$R_T$3::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_T$R$3::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_T$R$3::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_T$T_R$3::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_T$T_R$3::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_T$T_T$3::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_T$T_T$3::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_T$T$3::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_T$T$3::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_R$R_R$4::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_R$R_R$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_R$R_T$4::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_R$R_T$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_R$R$4::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_R$R$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_R$T_R$4::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_R$T_R$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_R$T_T$4::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_R$T_T$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_R$T$4::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_R$T$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_T$R_R$4::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_T$R_R$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_T$R_T$4::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_T$R_T$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_T$R$4::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_T$R$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_T$T_R$4::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_T$T_R$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_T$T_T$4::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_T$T_T$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_T$T$4::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_T$T$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_R$R_R$4::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_R$R_R$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_R$R_T$4::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_R$R_T$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_R$R$4::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_R$R$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_R$T_R$4::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_R$T_R$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_R$T_T$4::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_R$T_T$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_R$T$4::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_R$T$4::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_T$R_R$4::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_T$R_R$4::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_T$R_T$4::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_T$R_T$4::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_T$R$4::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_T$R$4::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_T$T_R$4::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_T$T_R$4::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_T$T_T$4::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_T$T_T$4::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_T$T$4::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_T$T$4::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_R$R_R$7::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_R$R_R$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_R$R_T$7::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_R$R_T$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_R$R$7::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_R$R$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_R$T_R$7::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_R$T_R$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_R$T_T$7::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_R$T_T$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_R$T$7::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_R$T$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_T$R_R$7::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_T$R_R$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_T$R_T$7::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_T$R_T$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_T$R$7::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_T$R$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_T$T_R$7::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_T$T_R$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_T$T_T$7::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_T$T_T$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_T$T$7::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_T$T$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_R$R_R$7::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_R$R_R$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_R$R_T$7::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_R$R_T$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_R$R$7::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_R$R$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_R$T_R$7::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_R$T_R$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_R$T_T$7::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_R$T_T$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_R$T$7::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_R$T$7::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_T$R_R$7::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_T$R_R$7::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_T$R_T$7::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_T$R_T$7::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_T$R$7::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_T$R$7::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_T$T_R$7::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_T$T_R$7::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_T$T_T$7::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_T$T_T$7::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_T$T$7::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_T$T$7::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_R$R_R$9::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_R$R_R$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_R$R_T$9::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_R$R_T$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_R$R$9::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_R$R$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_R$T_R$9::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_R$T_R$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_R$T_T$9::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_R$T_T$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_R$T$9::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_R$T$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_T$R_R$9::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_T$R_R$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_T$R_T$9::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_T$R_T$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_T$R$9::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_T$R$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_T$T_R$9::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_T$T_R$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_T$T_T$9::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_T$T_T$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_T$T$9::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_T$T$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_R$R_R$9::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_R$R_R$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_R$R_T$9::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_R$R_T$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_R$R$9::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_R$R$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_R$T_R$9::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_R$T_R$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_R$T_T$9::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_R$T_T$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_R$T$9::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_R$T$9::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_T$R_R$9::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_T$R_R$9::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_T$R_T$9::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_T$R_T$9::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_T$R$9::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_T$R$9::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_T$T_R$9::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_T$T_R$9::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_T$T_T$9::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_T$T_T$9::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_T$T$9::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_T$T$9::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_R$R_R$14::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_R$R_R$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_R$R_T$14::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_R$R_T$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_R$R$14::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_R$R$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_R$T_R$14::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_R$T_R$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_R$T_T$14::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_R$T_T$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_R$T$14::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_R$T$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_T$R_R$14::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_T$R_R$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_T$R_T$14::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_T$R_T$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_T$R$14::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_T$R$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_T$T_R$14::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_T$T_R$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_T$T_T$14::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_T$T_T$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_T$T$14::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_T$T$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_R$R_R$14::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_R$R_R$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_R$R_T$14::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_R$R_T$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_R$R$14::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_R$R$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_R$T_R$14::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_R$T_R$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_R$T_T$14::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_R$T_T$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_R$T$14::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_R$T$14::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_T$R_R$14::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_T$R_R$14::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_T$R_T$14::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_T$R_T$14::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_T$R$14::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_T$R$14::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_T$T_R$14::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_T$T_R$14::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_T$T_T$14::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_T$T_T$14::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_T$T$14::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_T$T$14::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_R$R_R$18::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_R$R_R$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_R$R_T$18::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_R$R_T$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_R$R$18::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_R$R$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_R$T_R$18::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_R$T_R$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_R$T_T$18::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_R$T_T$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_R$T$18::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_R$T$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_T$R_R$18::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_T$R_R$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_T$R_T$18::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_T$R_T$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_T$R$18::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_T$R$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_T$T_R$18::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_T$T_R$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_T$T_T$18::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_T$T_T$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_T$T$18::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_T$T$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_R$R_R$18::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_R$R_R$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_R$R_T$18::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_R$R_T$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_R$R$18::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_R$R$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_R$T_R$18::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_R$T_R$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_R$T_T$18::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_R$T_T$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_R$T$18::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_R$T$18::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_T$R_R$18::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_T$R_R$18::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_T$R_T$18::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_T$R_T$18::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_T$R$18::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_T$R$18::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_T$T_R$18::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_T$T_R$18::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_T$T_T$18::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_T$T_T$18::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_T$T$18::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_T$T$18::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_R$R_R$22::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_R$R_R$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_R$R_T$22::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_R$R_T$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_R$R$22::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_R$R$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_R$T_R$22::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_R$T_R$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_R$T_T$22::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_R$T_T$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_R$T$22::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_R$T$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_T$R_R$22::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_T$R_R$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_T$R_T$22::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_T$R_T$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_T$R$22::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_T$R$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_T$T_R$22::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_T$T_R$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_T$T_T$22::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_T$T_T$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_T$T$22::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_T$T$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_R$R_R$22::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_R$R_R$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_R$R_T$22::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_R$R_T$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_R$R$22::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_R$R$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_R$T_R$22::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_R$T_R$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_R$T_T$22::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_R$T_T$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_R$T$22::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_R$T$22::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_T$R_R$22::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_T$R_R$22::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_T$R_T$22::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_T$R_T$22::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_T$R$22::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_T$R$22::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_T$T_R$22::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_T$T_R$22::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_T$T_T$22::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_T$T_T$22::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_T$T$22::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_T$T$22::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_R$R_R$25::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_R$R_R$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_R$R_T$25::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_R$R_T$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_R$R$25::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_R$R$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_R$T_R$25::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_R$T_R$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_R$T_T$25::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_R$T_T$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_R$T$25::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_R$T$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_T$R_R$25::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_T$R_R$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_T$R_T$25::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_T$R_T$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_T$R$25::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_T$R$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_T$T_R$25::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_T$T_R$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_T$T_T$25::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_T$T_T$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_T$T$25::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_T$T$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_R$R_R$25::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_R$R_R$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_R$R_T$25::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_R$R_T$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_R$R$25::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_R$R$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_R$T_R$25::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_R$T_R$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_R$T_T$25::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_R$T_T$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_R$T$25::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_R$T$25::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_T$R_R$25::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_T$R_R$25::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_T$R_T$25::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_T$R_T$25::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_T$R$25::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_T$R$25::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_T$T_R$25::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_T$T_R$25::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_T$T_T$25::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_T$T_T$25::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_T$T$25::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_T$T$25::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_R$R_R$30::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_R$R_R$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_R$R_T$30::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_R$R_T$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_R$R$30::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_R$R$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_R$T_R$30::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_R$T_R$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_R$T_T$30::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_R$T_T$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_R$T$30::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_R$T$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_T$R_R$30::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_T$R_R$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_T$R_T$30::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_T$R_T$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_T$R$30::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_T$R$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_T$T_R$30::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_T$T_R$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_T$T_T$30::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_T$T_T$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_T$T$30::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_T$T$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_R$R_R$30::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_R$R_R$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_R$R_T$30::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_R$R_T$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_R$R$30::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_R$R$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_R$T_R$30::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_R$T_R$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_R$T_T$30::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_R$T_T$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_R$T$30::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_R$T$30::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_T$R_R$30::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_T$R_R$30::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_T$R_T$30::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_T$R_T$30::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_T$R$30::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_T$R$30::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_T$T_R$30::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_T$T_R$30::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_T$T_T$30::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_T$T_T$30::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_T$T$30::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_T$T$30::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_R$R_R$28::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_R$R_R$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_R$R_T$28::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_R$R_T$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_R$R$28::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_R$R$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_R$T_R$28::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_R$T_R$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_R$T_T$28::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_R$T_T$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_R$T$28::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_R$T$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_T$R_R$28::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_T$R_R$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_T$R_T$28::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_T$R_T$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_T$R$28::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_T$R$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_T$T_R$28::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_T$T_R$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_T$T_T$28::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_T$T_T$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_T$T$28::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_T$T$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_R$R_R$28::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_R$R_R$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_R$R_T$28::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_R$R_T$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_R$R$28::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_R$R$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_R$T_R$28::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_R$T_R$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_R$T_T$28::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_R$T_T$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_R$T$28::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_R$T$28::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_T$R_R$28::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_T$R_R$28::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_T$R_T$28::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_T$R_T$28::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_T$R$28::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addRegMeta (opr_r_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_T$R$28::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_T$T_R$28::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addRegMeta (opr_r_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_T$T_R$28::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_T$T_T$28::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
          addTRegMeta(opr_preDes_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_T$T_T$28::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_T$T$28::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
          addTRegMeta(opr_preDes.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_T$T$28::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_REG$R$R$0::addMeta(OPR_REG& opr_r_src_0 ,OPR_REG& opr_x_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOV_REG$R$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST$R$M$34::addMeta(OPR_REG& opr_r_src_0 ,OPR_MEM& opr_x_des_0){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addMemMeta_phyArea (opr_x_des_0.getMeta_phyArea(), false);
          addMemMeta_virArea (opr_x_des_0.getMeta_virArea(), false);
          addMemMeta_Static (opr_x_des_0.getMeta_Static());
       setUopType(UOP_TYPE::UOP_IMM);
       setExecUnit(34);
}
void MOV_MEM_ST$R$M$34::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doMemDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LDI$I$R$0::addMeta(OPR_IMM& opr_i_src_0 ,OPR_REG& opr_x_des_0){
          /* imm had no meta data*/;
          addRegMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_STORE);
       setExecUnit(0);
}
void MOV_MEM_LDI$I$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD$M$R$33::addMeta(OPR_MEM& opr_m_src_0 ,OPR_REG& opr_x_des_0){
          addMemMeta_phyArea (opr_m_src_0.getMeta_phyArea(), true);
          addMemMeta_virArea (opr_m_src_0.getMeta_virArea(), true);
          addMemMeta_Static (opr_m_src_0.getMeta_Static());
          addRegMeta (opr_x_des_0.getMeta(), false);
       setUopType(UOP_TYPE::UOP_LOAD);
       setExecUnit(33);
}
void MOV_MEM_LD$M$R$33::doDepenCheck(UOP_WINDOW* uop_window){
   doMemDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$R_R$$0::addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void CMP_SIM_ALU$R_R$$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$R_T$$0::addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void CMP_SIM_ALU$R_T$$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$T_R$$0::addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ){
          addTRegMeta(opr_t_0.getMeta(), true);
          addRegMeta (opr_r_src_1.getMeta(), true);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void CMP_SIM_ALU$T_R$$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$T_T$$0::addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ){
          addTRegMeta(opr_t_0.getMeta(), true);
          addTRegMeta(opr_t_1.getMeta(), true);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void CMP_SIM_ALU$T_T$$0::doDepenCheck(UOP_WINDOW* uop_window){
   doExecDepenCheck(uop_window);
}
///////////////////////////////////////////////////////////////



void JMP_SIM_ALU$R$R$0::addMeta(OPR_REG& opr_r_src_0 ,OPR_REG& opr_reg_des_1){
          addRegMeta (opr_r_src_0.getMeta(), true);
          addRegMeta (opr_reg_des_1.getMeta(), false);
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void JMP_SIM_ALU$R$R$0::doDepenCheck(UOP_WINDOW* uop_window){
   doRegDepenCheck(uop_window);
   doExecDepenCheck(uop_window);
}

}
