#include"X86_uop.h"
#include"core/tracers/uop_wd.h"
namespace traceBuilder::model {



using namespace stat;




void IntAlu$R_R$R_R$1::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_R$R_R$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_R$R_T$1::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_R$R_T$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD_INT$T$M$47::addMeta(OPR_TREG& opr_oprStFrom1_0, OPR_MEM& opr_oprStTo1, ADDR oprStTo1b_byte_, ADDR oprStTo1e_byte_){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
       getMetaPtr<META_DES_MEM,MEM_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1b_byte_, oprStTo1e_byte_));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_LOAD);
       setExecUnit(47);
}
void MOV_MEM_LD_INT$T$M$47::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MEM>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_R$R$1::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_R$R$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_R$T_R$1::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_R$T_R$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_R$T_T$1::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_R$T_T$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_R$T$1::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_R$T$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LDI$I$T$1::addMeta(OPR_IMM& opr_oprLdFrom1, OPR_TREG& opr_oprLdTo1_0){
///////////////// add meta data
       getMetaPtr<META_SRC_IMM,IMM_META>()->addMeta(opr_oprLdFrom1.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_IMM);
       setExecUnit(1);
}
void MOV_MEM_LDI$I$T$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_T$R_R$1::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_T$R_R$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_T$R_T$1::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_T$R_T$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_T$R$1::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_T$R$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_T$T_R$1::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_T$T_R$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_T$T_T$1::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_T$T_T$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_T$T$1::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_T$T$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD_INT$M$T$47::addMeta(OPR_MEM& opr_oprLdFrom1, OPR_TREG& opr_oprLdTo1_0, ADDR oprLdFrom1b_byte_, ADDR oprLdFrom1e_byte_){
///////////////// add meta data
       getMetaPtr<META_SRC_MEM,MEM_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1b_byte_, oprLdFrom1e_byte_));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_LOAD);
       setExecUnit(47);
}
void MOV_MEM_LD_INT$M$T$47::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MEM>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_R$R_R$1::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_R$R_R$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_R$R_T$1::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_R$R_T$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_R$R$1::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_R$R$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_R$T_R$1::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_R$T_R$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_R$T_T$1::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_R$T_T$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_R$T$1::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_R$T$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_T$R_R$1::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_T$R_R$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_T$R_T$1::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_T$R_T$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_T$R$1::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_T$R$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_T$T_R$1::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_T$T_R$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_T$T_T$1::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_T$T_T$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_T$T$1::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_T$T$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_R$R_R$2::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_R$R_R$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_R$R_T$2::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_R$R_T$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_R$R$2::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_R$R$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_R$T_R$2::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_R$T_R$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_R$T_T$2::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_R$T_T$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_R$T$2::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_R$T$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_T$R_R$2::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_T$R_R$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_T$R_T$2::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_T$R_T$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_T$R$2::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_T$R$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_T$T_R$2::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_T$T_R$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_T$T_T$2::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_T$T_T$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$R_T$T$2::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$R_T$T$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_R$R_R$2::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_R$R_R$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_R$R_T$2::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_R$R_T$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_R$R$2::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_R$R$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_R$T_R$2::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_R$T_R$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_R$T_T$2::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_R$T_T$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_R$T$2::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_R$T$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_T$R_R$2::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_T$R_R$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_T$R_T$2::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_T$R_T$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_T$R$2::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_T$R$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_T$T_R$2::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_T$T_R$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_T$T_T$2::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_T$T_T$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntMult$T_T$T$2::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(2);
}
void IntMult$T_T$T$2::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_R$R_R$3::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_R$R_R$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_R$R_T$3::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_R$R_T$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_R$R$3::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_R$R$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_R$T_R$3::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_R$T_R$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_R$T_T$3::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_R$T_T$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_R$T$3::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_R$T$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_T$R_R$3::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_T$R_R$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_T$R_T$3::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_T$R_T$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_T$R$3::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_T$R$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_T$T_R$3::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_T$T_R$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_T$T_T$3::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_T$T_T$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$R_T$T$3::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$R_T$T$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_R$R_R$3::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_R$R_R$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_R$R_T$3::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_R$R_T$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_R$R$3::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_R$R$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_R$T_R$3::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_R$T_R$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_R$T_T$3::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_R$T_T$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_R$T$3::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_R$T$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_T$R_R$3::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_T$R_R$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_T$R_T$3::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_T$R_T$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_T$R$3::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_T$R$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_T$T_R$3::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_T$T_R$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_T$T_T$3::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_T$T_T$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntDiv$T_T$T$3::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(3);
}
void IntDiv$T_T$T$3::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_R$R_R$4::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_R$R_R$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_R$R_T$4::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_R$R_T$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD_FLT$T$M$49::addMeta(OPR_TREG& opr_oprStFrom1_0, OPR_MEM& opr_oprStTo1, ADDR oprStTo1b_byte_, ADDR oprStTo1e_byte_){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
       getMetaPtr<META_DES_MEM,MEM_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1b_byte_, oprStTo1e_byte_));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_LOAD);
       setExecUnit(49);
}
void MOV_MEM_LD_FLT$T$M$49::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MEM>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_R$R$4::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_R$R$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_R$T_R$4::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_R$T_R$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_R$T_T$4::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_R$T_T$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_R$T$4::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_R$T$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_T$R_R$4::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_T$R_R$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_T$R_T$4::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_T$R_T$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_T$R$4::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_T$R$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_T$T_R$4::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_T$T_R$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_T$T_T$4::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_T$T_T$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$R_T$T$4::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$R_T$T$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD_FLT$M$T$49::addMeta(OPR_MEM& opr_oprLdFrom1, OPR_TREG& opr_oprLdTo1_0, ADDR oprLdFrom1b_byte_, ADDR oprLdFrom1e_byte_){
///////////////// add meta data
       getMetaPtr<META_SRC_MEM,MEM_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1b_byte_, oprLdFrom1e_byte_));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_LOAD);
       setExecUnit(49);
}
void MOV_MEM_LD_FLT$M$T$49::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MEM>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_R$R_R$4::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_R$R_R$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_R$R_T$4::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_R$R_T$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_R$R$4::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_R$R$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_R$T_R$4::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_R$T_R$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_R$T_T$4::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_R$T_T$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_R$T$4::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_R$T$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_T$R_R$4::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_T$R_R$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_T$R_T$4::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_T$R_T$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_T$R$4::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_T$R$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_T$T_R$4::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_T$T_R$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_T$T_T$4::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_T$T_T$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatAdd$T_T$T$4::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(4);
}
void FloatAdd$T_T$T$4::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_R$R_R$7::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_R$R_R$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_R$R_T$7::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_R$R_T$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_R$R$7::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_R$R$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_R$T_R$7::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_R$T_R$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_R$T_T$7::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_R$T_T$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_R$T$7::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_R$T$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_T$R_R$7::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_T$R_R$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_T$R_T$7::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_T$R_T$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_T$R$7::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_T$R$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_T$T_R$7::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_T$T_R$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_T$T_T$7::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_T$T_T$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$R_T$T$7::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$R_T$T$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_R$R_R$7::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_R$R_R$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_R$R_T$7::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_R$R_T$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_R$R$7::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_R$R$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_R$T_R$7::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_R$T_R$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_R$T_T$7::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_R$T_T$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_R$T$7::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_R$T$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_T$R_R$7::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_T$R_R$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_T$R_T$7::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_T$R_T$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_T$R$7::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_T$R$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_T$T_R$7::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_T$T_R$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_T$T_T$7::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_T$T_T$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatMult$T_T$T$7::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(7);
}
void FloatMult$T_T$T$7::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_R$R_R$9::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_R$R_R$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_R$R_T$9::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_R$R_T$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_R$R$9::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_R$R$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_R$T_R$9::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_R$T_R$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_R$T_T$9::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_R$T_T$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_R$T$9::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_R$T$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_T$R_R$9::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_T$R_R$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_T$R_T$9::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_T$R_T$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_T$R$9::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_T$R$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_T$T_R$9::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_T$T_R$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_T$T_T$9::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_T$T_T$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$R_T$T$9::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$R_T$T$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_R$R_R$9::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_R$R_R$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_R$R_T$9::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_R$R_T$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_R$R$9::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_R$R$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_R$T_R$9::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_R$T_R$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_R$T_T$9::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_R$T_T$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_R$T$9::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_R$T$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_T$R_R$9::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_T$R_R$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_T$R_T$9::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_T$R_T$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_T$R$9::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_T$R$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_T$T_R$9::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_T$T_R$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_T$T_T$9::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_T$T_T$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void FloatDiv$T_T$T$9::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(9);
}
void FloatDiv$T_T$T$9::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_R$R_R$14::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_R$R_R$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_R$R_T$14::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_R$R_T$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_R$R$14::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_R$R$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_R$T_R$14::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_R$T_R$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_R$T_T$14::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_R$T_T$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_R$T$14::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_R$T$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_T$R_R$14::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_T$R_R$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_T$R_T$14::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_T$R_T$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_T$R$14::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_T$R$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_T$T_R$14::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_T$T_R$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_T$T_T$14::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_T$T_T$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$R_T$T$14::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$R_T$T$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_R$R_R$14::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_R$R_R$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_R$R_T$14::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_R$R_T$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_R$R$14::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_R$R$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_R$T_R$14::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_R$T_R$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_R$T_T$14::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_R$T_T$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_R$T$14::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_R$T$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_T$R_R$14::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_T$R_R$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_T$R_T$14::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_T$R_T$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_T$R$14::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_T$R$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_T$T_R$14::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_T$T_R$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_T$T_T$14::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_T$T_T$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdAlu$T_T$T$14::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(14);
}
void SimdAlu$T_T$T$14::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_R$R_R$18::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_R$R_R$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_R$R_T$18::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_R$R_T$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_R$R$18::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_R$R$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_R$T_R$18::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_R$T_R$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_R$T_T$18::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_R$T_T$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_R$T$18::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_R$T$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_T$R_R$18::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_T$R_R$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_T$R_T$18::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_T$R_T$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_T$R$18::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_T$R$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_T$T_R$18::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_T$T_R$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_T$T_T$18::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_T$T_T$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$R_T$T$18::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$R_T$T$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_R$R_R$18::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_R$R_R$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_R$R_T$18::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_R$R_T$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_R$R$18::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_R$R$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_R$T_R$18::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_R$T_R$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_R$T_T$18::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_R$T_T$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_R$T$18::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_R$T$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_T$R_R$18::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_T$R_R$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_T$R_T$18::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_T$R_T$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_T$R$18::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_T$R$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_T$T_R$18::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_T$T_R$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_T$T_T$18::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_T$T_T$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdMult$T_T$T$18::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(18);
}
void SimdMult$T_T$T$18::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_R$R_R$22::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_R$R_R$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_R$R_T$22::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_R$R_T$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_R$R$22::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_R$R$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_R$T_R$22::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_R$T_R$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_R$T_T$22::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_R$T_T$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_R$T$22::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_R$T$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_T$R_R$22::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_T$R_R$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_T$R_T$22::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_T$R_T$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_T$R$22::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_T$R$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_T$T_R$22::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_T$T_R$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_T$T_T$22::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_T$T_T$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$R_T$T$22::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$R_T$T$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_R$R_R$22::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_R$R_R$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_R$R_T$22::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_R$R_T$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_R$R$22::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_R$R$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_R$T_R$22::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_R$T_R$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_R$T_T$22::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_R$T_T$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_R$T$22::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_R$T$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_T$R_R$22::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_T$R_R$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_T$R_T$22::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_T$R_T$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_T$R$22::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_T$R$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_T$T_R$22::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_T$T_R$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_T$T_T$22::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_T$T_T$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdDiv$T_T$T$22::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(22);
}
void SimdDiv$T_T$T$22::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_R$R_R$25::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_R$R_R$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_R$R_T$25::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_R$R_T$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_R$R$25::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_R$R$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_R$T_R$25::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_R$T_R$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_R$T_T$25::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_R$T_T$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_R$T$25::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_R$T$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_T$R_R$25::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_T$R_R$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_T$R_T$25::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_T$R_T$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_T$R$25::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_T$R$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_T$T_R$25::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_T$T_R$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_T$T_T$25::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_T$T_T$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$R_T$T$25::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$R_T$T$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_R$R_R$25::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_R$R_R$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_R$R_T$25::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_R$R_T$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_R$R$25::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_R$R$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_R$T_R$25::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_R$T_R$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_R$T_T$25::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_R$T_T$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_R$T$25::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_R$T$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_T$R_R$25::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_T$R_R$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_T$R_T$25::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_T$R_T$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_T$R$25::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_T$R$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_T$T_R$25::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_T$T_R$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_T$T_T$25::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_T$T_T$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatAlu$T_T$T$25::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(25);
}
void SimdFloatAlu$T_T$T$25::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_R$R_R$30::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_R$R_R$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_R$R_T$30::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_R$R_T$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_R$R$30::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_R$R$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_R$T_R$30::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_R$T_R$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_R$T_T$30::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_R$T_T$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_R$T$30::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_R$T$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_T$R_R$30::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_T$R_R$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_T$R_T$30::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_T$R_T$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_T$R$30::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_T$R$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_T$T_R$30::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_T$T_R$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_T$T_T$30::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_T$T_T$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$R_T$T$30::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$R_T$T$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_R$R_R$30::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_R$R_R$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_R$R_T$30::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_R$R_T$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_R$R$30::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_R$R$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_R$T_R$30::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_R$T_R$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_R$T_T$30::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_R$T_T$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_R$T$30::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_R$T$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_T$R_R$30::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_T$R_R$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_T$R_T$30::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_T$R_T$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_T$R$30::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_T$R$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_T$T_R$30::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_T$T_R$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_T$T_T$30::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_T$T_T$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatMult$T_T$T$30::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(30);
}
void SimdFloatMult$T_T$T$30::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_R$R_R$28::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_R$R_R$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_R$R_T$28::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_R$R_T$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_R$R$28::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_R$R$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_R$T_R$28::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_R$T_R$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_R$T_T$28::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_R$T_T$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_R$T$28::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_R$T$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_T$R_R$28::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_T$R_R$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_T$R_T$28::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_T$R_T$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_T$R$28::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_T$R$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_T$T_R$28::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_T$T_R$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_T$T_T$28::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_T$T_T$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$R_T$T$28::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$R_T$T$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_R$R_R$28::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_R$R_R$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_R$R_T$28::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_R$R_T$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_R$R$28::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_R$R$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_R$T_R$28::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_R$T_R$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_R$T_T$28::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_R$T_T$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_R$T$28::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_R$T$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_T$R_R$28::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_T$R_R$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_T$R_T$28::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_T$R_T$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_T$R$28::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo0.getMeta(oprStTo0subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_T$R$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_T$T_R$28::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_oprStTo1.getMeta(oprStTo1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_T$T_R$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_T$T_T$28::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_T$T_T$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void SimdFloatDiv$T_T$T$28::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_oprStFrom0_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(28);
}
void SimdFloatDiv$T_T$T$28::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST_INT$R$R$48::addMeta(OPR_REG& opr_srcOpr, OPR_REG& opr_desOpr, int srcOprsubRegIdx, int desOprsubRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_srcOpr.getMeta(srcOprsubRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_desOpr.getMeta(desOprsubRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_STORE);
       setExecUnit(48);
}
void MOV_MEM_ST_INT$R$R$48::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST_INT$R$T$48::addMeta(OPR_REG& opr_srcOpr, OPR_TREG& opr_ld_to_0, int srcOprsubRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_srcOpr.getMeta(srcOprsubRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_ld_to_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_STORE);
       setExecUnit(48);
}
void MOV_MEM_ST_INT$R$T$48::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST_INT$I$R$48::addMeta(OPR_IMM& opr_srcOpr, OPR_REG& opr_desOpr, int desOprsubRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_IMM,IMM_META>()->addMeta(opr_srcOpr.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_desOpr.getMeta(desOprsubRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_STORE);
       setExecUnit(48);
}
void MOV_MEM_ST_INT$I$R$48::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST_INT$I$T$48::addMeta(OPR_IMM& opr_srcOpr, OPR_TREG& opr_ld_to_0){
///////////////// add meta data
       getMetaPtr<META_SRC_IMM,IMM_META>()->addMeta(opr_srcOpr.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_ld_to_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_STORE);
       setExecUnit(48);
}
void MOV_MEM_ST_INT$I$T$48::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD_INT$M$R$47::addMeta(OPR_MEM& opr_srcOpr, OPR_REG& opr_desOpr, ADDR srcOprb_byte_, ADDR srcOpre_byte_, int desOprsubRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MEM,MEM_META>()->addMeta(opr_srcOpr.getMeta(srcOprb_byte_, srcOpre_byte_));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_desOpr.getMeta(desOprsubRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_LOAD);
       setExecUnit(47);
}
void MOV_MEM_LD_INT$M$R$47::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MEM>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST_FLT$R$R$50::addMeta(OPR_REG& opr_srcOpr, OPR_REG& opr_desOpr, int srcOprsubRegIdx, int desOprsubRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_srcOpr.getMeta(srcOprsubRegIdx));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_desOpr.getMeta(desOprsubRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_STORE);
       setExecUnit(50);
}
void MOV_MEM_ST_FLT$R$R$50::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST_FLT$R$T$50::addMeta(OPR_REG& opr_srcOpr, OPR_TREG& opr_ld_to_0, int srcOprsubRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_srcOpr.getMeta(srcOprsubRegIdx));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_ld_to_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_STORE);
       setExecUnit(50);
}
void MOV_MEM_ST_FLT$R$T$50::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST_FLT$I$R$50::addMeta(OPR_IMM& opr_srcOpr, OPR_REG& opr_desOpr, int desOprsubRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_IMM,IMM_META>()->addMeta(opr_srcOpr.getMeta());
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_desOpr.getMeta(desOprsubRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_STORE);
       setExecUnit(50);
}
void MOV_MEM_ST_FLT$I$R$50::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_ST_FLT$I$T$50::addMeta(OPR_IMM& opr_srcOpr, OPR_TREG& opr_ld_to_0){
///////////////// add meta data
       getMetaPtr<META_SRC_IMM,IMM_META>()->addMeta(opr_srcOpr.getMeta());
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_ld_to_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_STORE);
       setExecUnit(50);
}
void MOV_MEM_ST_FLT$I$T$50::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void MOV_MEM_LD_FLT$M$R$49::addMeta(OPR_MEM& opr_srcOpr, OPR_REG& opr_desOpr, ADDR srcOprb_byte_, ADDR srcOpre_byte_, int desOprsubRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MEM,MEM_META>()->addMeta(opr_srcOpr.getMeta(srcOprb_byte_, srcOpre_byte_));
       getMetaPtr<META_DES_MREG,MREG_META>()->addMeta(opr_desOpr.getMeta(desOprsubRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_LOAD);
       setExecUnit(49);
}
void MOV_MEM_LD_FLT$M$R$49::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MEM>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_R$$1::addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_R$$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$R_T$$1::addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, int oprLdFrom0subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom0.getMeta(oprLdFrom0subRegIdx));
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$R_T$$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_R$$1::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, int oprLdFrom1subRegIdx){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_MREG,MREG_META>()->addMeta(opr_oprLdFrom1.getMeta(oprLdFrom1subRegIdx));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_R$$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MREG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void IntAlu$T_T$$1::addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo0_0.getMeta());
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_oprLdTo1_0.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(1);
}
void IntAlu$T_T$$1::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}

}
