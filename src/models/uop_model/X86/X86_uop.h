#ifndef X86_UOPL_H
#define X86_UOPL_H
#include"models/uop_model/dep/dep_simple.h"
#include"models/uop_model/metaData/metaBase.h"
#include"models/uop_model/uop_base.h"




namespace traceBuilder::model {



class MOVCXX$M$T$0 : public UOP_BASE{
public:
  MOVCXX$M$T$0():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_loadOpr1, OPR_TREG& opr_loadTemp1, ADDR b_byte_loadOpr1, ADDR e_byte_loadOpr1, bool directloadTemp1);
};///////////////////////////////////////////////////////////////



class COMPUOP$T_R$R$0 : public UOP_BASE{
public:
  COMPUOP$T_R$R$0():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_loadTemp1, OPR_REG& opr_regOprload, OPR_REG& opr_storeOpr1, bool directloadTemp1);
};
}

#endif