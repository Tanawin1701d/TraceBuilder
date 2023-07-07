#include"X86_uop.h"
#include"core/tracers/uop_wd.h"
namespace traceBuilder::model {



using namespace stat;




void MOVCXX$M$T$0::addMeta(OPR_MEM& opr_loadOpr1, OPR_TREG& opr_loadTemp1, ADDR b_byte_loadOpr1, ADDR e_byte_loadOpr1, bool directloadTemp1){
///////////////// add meta data
       getMetaPtr<META_SRC_MEM,MEM_META>()->addMeta(opr_loadOpr1.getMeta(b_byte_loadOpr1, e_byte_loadOpr1));
       getMetaPtr<META_DES_TEMP,TREG_META>()->addMeta(opr_loadTemp1.getMeta(directloadTemp1));
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void MOVCXX$M$T$0::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_MEM>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}
///////////////////////////////////////////////////////////////



void COMPUOP$T_R$R$0::addMeta(OPR_TREG& opr_loadTemp1, OPR_REG& opr_regOprload, OPR_REG& opr_storeOpr1, bool directloadTemp1){
///////////////// add meta data
       getMetaPtr<META_SRC_TEMP,TREG_META>()->addMeta(opr_loadTemp1.getMeta(directloadTemp1));
       getMetaPtr<META_SRC_REG,REG_META>()->addMeta(opr_regOprload.getMeta());
       getMetaPtr<META_DES_REG,REG_META>()->addMeta(opr_storeOpr1.getMeta());
///////////////// finish meta data
       setUopType(UOP_TYPE::UOP_COMP);
       setExecUnit(0);
}
void COMPUOP$T_R$R$0::doPlannedDepenCheck(UOP_WINDOW* uop_window){
   doDepenCheck<DEP_REG>(uop_window);
   doDepenCheck<DEP_EXEC_UNIT>(uop_window);
}

}
