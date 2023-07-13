#ifndef X86_UOPL_H
#define X86_UOPL_H
#include"models/uop_model/dep/dep_simple.h"
#include"models/uop_model/metaData/metaBase.h"
#include"models/uop_model/uop_base.h"




namespace traceBuilder::model {



class IntAlu$R_R$R_R$1 : public UOP_BASE{
public:
  IntAlu$R_R$R_R$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$R_R$R_T$1 : public UOP_BASE{
public:
  IntAlu$R_R$R_T$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD_INT$T$M$47 : public UOP_BASE{
public:
  MOV_MEM_LD_INT$T$M$47():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprStFrom1_0, OPR_MEM& opr_oprStTo1, ADDR oprStTo1b_byte_, ADDR oprStTo1e_byte_);
};///////////////////////////////////////////////////////////////



class IntAlu$R_R$R$1 : public UOP_BASE{
public:
  IntAlu$R_R$R$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$R_R$T_R$1 : public UOP_BASE{
public:
  IntAlu$R_R$T_R$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$R_R$T_T$1 : public UOP_BASE{
public:
  IntAlu$R_R$T_T$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$R_R$T$1 : public UOP_BASE{
public:
  IntAlu$R_R$T$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LDI$I$T$1 : public UOP_BASE{
public:
  MOV_MEM_LDI$I$T$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_oprLdFrom1, OPR_TREG& opr_oprLdTo1_0);
};///////////////////////////////////////////////////////////////



class IntAlu$R_T$R_R$1 : public UOP_BASE{
public:
  IntAlu$R_T$R_R$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$R_T$R_T$1 : public UOP_BASE{
public:
  IntAlu$R_T$R_T$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$R_T$R$1 : public UOP_BASE{
public:
  IntAlu$R_T$R$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$R_T$T_R$1 : public UOP_BASE{
public:
  IntAlu$R_T$T_R$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$R_T$T_T$1 : public UOP_BASE{
public:
  IntAlu$R_T$T_T$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$R_T$T$1 : public UOP_BASE{
public:
  IntAlu$R_T$T$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD_INT$M$T$47 : public UOP_BASE{
public:
  MOV_MEM_LD_INT$M$T$47():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_oprLdFrom1, OPR_TREG& opr_oprLdTo1_0, ADDR oprLdFrom1b_byte_, ADDR oprLdFrom1e_byte_);
};///////////////////////////////////////////////////////////////



class IntAlu$T_R$R_R$1 : public UOP_BASE{
public:
  IntAlu$T_R$R_R$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$T_R$R_T$1 : public UOP_BASE{
public:
  IntAlu$T_R$R_T$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$T_R$R$1 : public UOP_BASE{
public:
  IntAlu$T_R$R$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$T_R$T_R$1 : public UOP_BASE{
public:
  IntAlu$T_R$T_R$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$T_R$T_T$1 : public UOP_BASE{
public:
  IntAlu$T_R$T_T$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$T_R$T$1 : public UOP_BASE{
public:
  IntAlu$T_R$T$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$T_T$R_R$1 : public UOP_BASE{
public:
  IntAlu$T_T$R_R$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$T_T$R_T$1 : public UOP_BASE{
public:
  IntAlu$T_T$R_T$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$T_T$R$1 : public UOP_BASE{
public:
  IntAlu$T_T$R$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$T_T$T_R$1 : public UOP_BASE{
public:
  IntAlu$T_T$T_R$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$T_T$T_T$1 : public UOP_BASE{
public:
  IntAlu$T_T$T_T$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0);
};///////////////////////////////////////////////////////////////



class IntAlu$T_T$T$1 : public UOP_BASE{
public:
  IntAlu$T_T$T$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0);
};///////////////////////////////////////////////////////////////



class IntMult$R_R$R_R$2 : public UOP_BASE{
public:
  IntMult$R_R$R_R$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$R_R$R_T$2 : public UOP_BASE{
public:
  IntMult$R_R$R_T$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$R_R$R$2 : public UOP_BASE{
public:
  IntMult$R_R$R$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$R_R$T_R$2 : public UOP_BASE{
public:
  IntMult$R_R$T_R$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$R_R$T_T$2 : public UOP_BASE{
public:
  IntMult$R_R$T_T$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$R_R$T$2 : public UOP_BASE{
public:
  IntMult$R_R$T$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$R_T$R_R$2 : public UOP_BASE{
public:
  IntMult$R_T$R_R$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$R_T$R_T$2 : public UOP_BASE{
public:
  IntMult$R_T$R_T$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$R_T$R$2 : public UOP_BASE{
public:
  IntMult$R_T$R$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$R_T$T_R$2 : public UOP_BASE{
public:
  IntMult$R_T$T_R$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$R_T$T_T$2 : public UOP_BASE{
public:
  IntMult$R_T$T_T$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$R_T$T$2 : public UOP_BASE{
public:
  IntMult$R_T$T$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$T_R$R_R$2 : public UOP_BASE{
public:
  IntMult$T_R$R_R$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$T_R$R_T$2 : public UOP_BASE{
public:
  IntMult$T_R$R_T$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$T_R$R$2 : public UOP_BASE{
public:
  IntMult$T_R$R$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$T_R$T_R$2 : public UOP_BASE{
public:
  IntMult$T_R$T_R$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$T_R$T_T$2 : public UOP_BASE{
public:
  IntMult$T_R$T_T$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$T_R$T$2 : public UOP_BASE{
public:
  IntMult$T_R$T$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$T_T$R_R$2 : public UOP_BASE{
public:
  IntMult$T_T$R_R$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$T_T$R_T$2 : public UOP_BASE{
public:
  IntMult$T_T$R_T$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$T_T$R$2 : public UOP_BASE{
public:
  IntMult$T_T$R$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$T_T$T_R$2 : public UOP_BASE{
public:
  IntMult$T_T$T_R$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntMult$T_T$T_T$2 : public UOP_BASE{
public:
  IntMult$T_T$T_T$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0);
};///////////////////////////////////////////////////////////////



class IntMult$T_T$T$2 : public UOP_BASE{
public:
  IntMult$T_T$T$2():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0);
};///////////////////////////////////////////////////////////////



class IntDiv$R_R$R_R$3 : public UOP_BASE{
public:
  IntDiv$R_R$R_R$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$R_R$R_T$3 : public UOP_BASE{
public:
  IntDiv$R_R$R_T$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$R_R$R$3 : public UOP_BASE{
public:
  IntDiv$R_R$R$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$R_R$T_R$3 : public UOP_BASE{
public:
  IntDiv$R_R$T_R$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$R_R$T_T$3 : public UOP_BASE{
public:
  IntDiv$R_R$T_T$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$R_R$T$3 : public UOP_BASE{
public:
  IntDiv$R_R$T$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$R_T$R_R$3 : public UOP_BASE{
public:
  IntDiv$R_T$R_R$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$R_T$R_T$3 : public UOP_BASE{
public:
  IntDiv$R_T$R_T$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$R_T$R$3 : public UOP_BASE{
public:
  IntDiv$R_T$R$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$R_T$T_R$3 : public UOP_BASE{
public:
  IntDiv$R_T$T_R$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$R_T$T_T$3 : public UOP_BASE{
public:
  IntDiv$R_T$T_T$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$R_T$T$3 : public UOP_BASE{
public:
  IntDiv$R_T$T$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$T_R$R_R$3 : public UOP_BASE{
public:
  IntDiv$T_R$R_R$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$T_R$R_T$3 : public UOP_BASE{
public:
  IntDiv$T_R$R_T$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$T_R$R$3 : public UOP_BASE{
public:
  IntDiv$T_R$R$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$T_R$T_R$3 : public UOP_BASE{
public:
  IntDiv$T_R$T_R$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$T_R$T_T$3 : public UOP_BASE{
public:
  IntDiv$T_R$T_T$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$T_R$T$3 : public UOP_BASE{
public:
  IntDiv$T_R$T$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$T_T$R_R$3 : public UOP_BASE{
public:
  IntDiv$T_T$R_R$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$T_T$R_T$3 : public UOP_BASE{
public:
  IntDiv$T_T$R_T$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$T_T$R$3 : public UOP_BASE{
public:
  IntDiv$T_T$R$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$T_T$T_R$3 : public UOP_BASE{
public:
  IntDiv$T_T$T_R$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntDiv$T_T$T_T$3 : public UOP_BASE{
public:
  IntDiv$T_T$T_T$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0);
};///////////////////////////////////////////////////////////////



class IntDiv$T_T$T$3 : public UOP_BASE{
public:
  IntDiv$T_T$T$3():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0);
};///////////////////////////////////////////////////////////////



class FloatAdd$R_R$R_R$4 : public UOP_BASE{
public:
  FloatAdd$R_R$R_R$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$R_R$R_T$4 : public UOP_BASE{
public:
  FloatAdd$R_R$R_T$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD_FLT$T$M$49 : public UOP_BASE{
public:
  MOV_MEM_LD_FLT$T$M$49():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprStFrom1_0, OPR_MEM& opr_oprStTo1, ADDR oprStTo1b_byte_, ADDR oprStTo1e_byte_);
};///////////////////////////////////////////////////////////////



class FloatAdd$R_R$R$4 : public UOP_BASE{
public:
  FloatAdd$R_R$R$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$R_R$T_R$4 : public UOP_BASE{
public:
  FloatAdd$R_R$T_R$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$R_R$T_T$4 : public UOP_BASE{
public:
  FloatAdd$R_R$T_T$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$R_R$T$4 : public UOP_BASE{
public:
  FloatAdd$R_R$T$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$R_T$R_R$4 : public UOP_BASE{
public:
  FloatAdd$R_T$R_R$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$R_T$R_T$4 : public UOP_BASE{
public:
  FloatAdd$R_T$R_T$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$R_T$R$4 : public UOP_BASE{
public:
  FloatAdd$R_T$R$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$R_T$T_R$4 : public UOP_BASE{
public:
  FloatAdd$R_T$T_R$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$R_T$T_T$4 : public UOP_BASE{
public:
  FloatAdd$R_T$T_T$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$R_T$T$4 : public UOP_BASE{
public:
  FloatAdd$R_T$T$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD_FLT$M$T$49 : public UOP_BASE{
public:
  MOV_MEM_LD_FLT$M$T$49():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_oprLdFrom1, OPR_TREG& opr_oprLdTo1_0, ADDR oprLdFrom1b_byte_, ADDR oprLdFrom1e_byte_);
};///////////////////////////////////////////////////////////////



class FloatAdd$T_R$R_R$4 : public UOP_BASE{
public:
  FloatAdd$T_R$R_R$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$T_R$R_T$4 : public UOP_BASE{
public:
  FloatAdd$T_R$R_T$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$T_R$R$4 : public UOP_BASE{
public:
  FloatAdd$T_R$R$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$T_R$T_R$4 : public UOP_BASE{
public:
  FloatAdd$T_R$T_R$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$T_R$T_T$4 : public UOP_BASE{
public:
  FloatAdd$T_R$T_T$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$T_R$T$4 : public UOP_BASE{
public:
  FloatAdd$T_R$T$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$T_T$R_R$4 : public UOP_BASE{
public:
  FloatAdd$T_T$R_R$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$T_T$R_T$4 : public UOP_BASE{
public:
  FloatAdd$T_T$R_T$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$T_T$R$4 : public UOP_BASE{
public:
  FloatAdd$T_T$R$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$T_T$T_R$4 : public UOP_BASE{
public:
  FloatAdd$T_T$T_R$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatAdd$T_T$T_T$4 : public UOP_BASE{
public:
  FloatAdd$T_T$T_T$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0);
};///////////////////////////////////////////////////////////////



class FloatAdd$T_T$T$4 : public UOP_BASE{
public:
  FloatAdd$T_T$T$4():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0);
};///////////////////////////////////////////////////////////////



class FloatMult$R_R$R_R$7 : public UOP_BASE{
public:
  FloatMult$R_R$R_R$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$R_R$R_T$7 : public UOP_BASE{
public:
  FloatMult$R_R$R_T$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$R_R$R$7 : public UOP_BASE{
public:
  FloatMult$R_R$R$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$R_R$T_R$7 : public UOP_BASE{
public:
  FloatMult$R_R$T_R$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$R_R$T_T$7 : public UOP_BASE{
public:
  FloatMult$R_R$T_T$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$R_R$T$7 : public UOP_BASE{
public:
  FloatMult$R_R$T$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$R_T$R_R$7 : public UOP_BASE{
public:
  FloatMult$R_T$R_R$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$R_T$R_T$7 : public UOP_BASE{
public:
  FloatMult$R_T$R_T$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$R_T$R$7 : public UOP_BASE{
public:
  FloatMult$R_T$R$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$R_T$T_R$7 : public UOP_BASE{
public:
  FloatMult$R_T$T_R$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$R_T$T_T$7 : public UOP_BASE{
public:
  FloatMult$R_T$T_T$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$R_T$T$7 : public UOP_BASE{
public:
  FloatMult$R_T$T$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$T_R$R_R$7 : public UOP_BASE{
public:
  FloatMult$T_R$R_R$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$T_R$R_T$7 : public UOP_BASE{
public:
  FloatMult$T_R$R_T$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$T_R$R$7 : public UOP_BASE{
public:
  FloatMult$T_R$R$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$T_R$T_R$7 : public UOP_BASE{
public:
  FloatMult$T_R$T_R$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$T_R$T_T$7 : public UOP_BASE{
public:
  FloatMult$T_R$T_T$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$T_R$T$7 : public UOP_BASE{
public:
  FloatMult$T_R$T$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$T_T$R_R$7 : public UOP_BASE{
public:
  FloatMult$T_T$R_R$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$T_T$R_T$7 : public UOP_BASE{
public:
  FloatMult$T_T$R_T$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$T_T$R$7 : public UOP_BASE{
public:
  FloatMult$T_T$R$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$T_T$T_R$7 : public UOP_BASE{
public:
  FloatMult$T_T$T_R$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatMult$T_T$T_T$7 : public UOP_BASE{
public:
  FloatMult$T_T$T_T$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0);
};///////////////////////////////////////////////////////////////



class FloatMult$T_T$T$7 : public UOP_BASE{
public:
  FloatMult$T_T$T$7():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0);
};///////////////////////////////////////////////////////////////



class FloatDiv$R_R$R_R$9 : public UOP_BASE{
public:
  FloatDiv$R_R$R_R$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$R_R$R_T$9 : public UOP_BASE{
public:
  FloatDiv$R_R$R_T$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$R_R$R$9 : public UOP_BASE{
public:
  FloatDiv$R_R$R$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$R_R$T_R$9 : public UOP_BASE{
public:
  FloatDiv$R_R$T_R$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$R_R$T_T$9 : public UOP_BASE{
public:
  FloatDiv$R_R$T_T$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$R_R$T$9 : public UOP_BASE{
public:
  FloatDiv$R_R$T$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$R_T$R_R$9 : public UOP_BASE{
public:
  FloatDiv$R_T$R_R$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$R_T$R_T$9 : public UOP_BASE{
public:
  FloatDiv$R_T$R_T$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$R_T$R$9 : public UOP_BASE{
public:
  FloatDiv$R_T$R$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$R_T$T_R$9 : public UOP_BASE{
public:
  FloatDiv$R_T$T_R$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$R_T$T_T$9 : public UOP_BASE{
public:
  FloatDiv$R_T$T_T$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$R_T$T$9 : public UOP_BASE{
public:
  FloatDiv$R_T$T$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$T_R$R_R$9 : public UOP_BASE{
public:
  FloatDiv$T_R$R_R$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$T_R$R_T$9 : public UOP_BASE{
public:
  FloatDiv$T_R$R_T$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$T_R$R$9 : public UOP_BASE{
public:
  FloatDiv$T_R$R$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$T_R$T_R$9 : public UOP_BASE{
public:
  FloatDiv$T_R$T_R$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$T_R$T_T$9 : public UOP_BASE{
public:
  FloatDiv$T_R$T_T$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$T_R$T$9 : public UOP_BASE{
public:
  FloatDiv$T_R$T$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$T_T$R_R$9 : public UOP_BASE{
public:
  FloatDiv$T_T$R_R$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$T_T$R_T$9 : public UOP_BASE{
public:
  FloatDiv$T_T$R_T$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$T_T$R$9 : public UOP_BASE{
public:
  FloatDiv$T_T$R$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$T_T$T_R$9 : public UOP_BASE{
public:
  FloatDiv$T_T$T_R$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class FloatDiv$T_T$T_T$9 : public UOP_BASE{
public:
  FloatDiv$T_T$T_T$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0);
};///////////////////////////////////////////////////////////////



class FloatDiv$T_T$T$9 : public UOP_BASE{
public:
  FloatDiv$T_T$T$9():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0);
};///////////////////////////////////////////////////////////////



class SimdAlu$R_R$R_R$14 : public UOP_BASE{
public:
  SimdAlu$R_R$R_R$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$R_R$R_T$14 : public UOP_BASE{
public:
  SimdAlu$R_R$R_T$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$R_R$R$14 : public UOP_BASE{
public:
  SimdAlu$R_R$R$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$R_R$T_R$14 : public UOP_BASE{
public:
  SimdAlu$R_R$T_R$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$R_R$T_T$14 : public UOP_BASE{
public:
  SimdAlu$R_R$T_T$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$R_R$T$14 : public UOP_BASE{
public:
  SimdAlu$R_R$T$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$R_T$R_R$14 : public UOP_BASE{
public:
  SimdAlu$R_T$R_R$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$R_T$R_T$14 : public UOP_BASE{
public:
  SimdAlu$R_T$R_T$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$R_T$R$14 : public UOP_BASE{
public:
  SimdAlu$R_T$R$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$R_T$T_R$14 : public UOP_BASE{
public:
  SimdAlu$R_T$T_R$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$R_T$T_T$14 : public UOP_BASE{
public:
  SimdAlu$R_T$T_T$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$R_T$T$14 : public UOP_BASE{
public:
  SimdAlu$R_T$T$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$T_R$R_R$14 : public UOP_BASE{
public:
  SimdAlu$T_R$R_R$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$T_R$R_T$14 : public UOP_BASE{
public:
  SimdAlu$T_R$R_T$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$T_R$R$14 : public UOP_BASE{
public:
  SimdAlu$T_R$R$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$T_R$T_R$14 : public UOP_BASE{
public:
  SimdAlu$T_R$T_R$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$T_R$T_T$14 : public UOP_BASE{
public:
  SimdAlu$T_R$T_T$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$T_R$T$14 : public UOP_BASE{
public:
  SimdAlu$T_R$T$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$T_T$R_R$14 : public UOP_BASE{
public:
  SimdAlu$T_T$R_R$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$T_T$R_T$14 : public UOP_BASE{
public:
  SimdAlu$T_T$R_T$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$T_T$R$14 : public UOP_BASE{
public:
  SimdAlu$T_T$R$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$T_T$T_R$14 : public UOP_BASE{
public:
  SimdAlu$T_T$T_R$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdAlu$T_T$T_T$14 : public UOP_BASE{
public:
  SimdAlu$T_T$T_T$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0);
};///////////////////////////////////////////////////////////////



class SimdAlu$T_T$T$14 : public UOP_BASE{
public:
  SimdAlu$T_T$T$14():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0);
};///////////////////////////////////////////////////////////////



class SimdMult$R_R$R_R$18 : public UOP_BASE{
public:
  SimdMult$R_R$R_R$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$R_R$R_T$18 : public UOP_BASE{
public:
  SimdMult$R_R$R_T$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$R_R$R$18 : public UOP_BASE{
public:
  SimdMult$R_R$R$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$R_R$T_R$18 : public UOP_BASE{
public:
  SimdMult$R_R$T_R$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$R_R$T_T$18 : public UOP_BASE{
public:
  SimdMult$R_R$T_T$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$R_R$T$18 : public UOP_BASE{
public:
  SimdMult$R_R$T$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$R_T$R_R$18 : public UOP_BASE{
public:
  SimdMult$R_T$R_R$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$R_T$R_T$18 : public UOP_BASE{
public:
  SimdMult$R_T$R_T$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$R_T$R$18 : public UOP_BASE{
public:
  SimdMult$R_T$R$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$R_T$T_R$18 : public UOP_BASE{
public:
  SimdMult$R_T$T_R$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$R_T$T_T$18 : public UOP_BASE{
public:
  SimdMult$R_T$T_T$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$R_T$T$18 : public UOP_BASE{
public:
  SimdMult$R_T$T$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$T_R$R_R$18 : public UOP_BASE{
public:
  SimdMult$T_R$R_R$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$T_R$R_T$18 : public UOP_BASE{
public:
  SimdMult$T_R$R_T$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$T_R$R$18 : public UOP_BASE{
public:
  SimdMult$T_R$R$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$T_R$T_R$18 : public UOP_BASE{
public:
  SimdMult$T_R$T_R$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$T_R$T_T$18 : public UOP_BASE{
public:
  SimdMult$T_R$T_T$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$T_R$T$18 : public UOP_BASE{
public:
  SimdMult$T_R$T$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$T_T$R_R$18 : public UOP_BASE{
public:
  SimdMult$T_T$R_R$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$T_T$R_T$18 : public UOP_BASE{
public:
  SimdMult$T_T$R_T$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$T_T$R$18 : public UOP_BASE{
public:
  SimdMult$T_T$R$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$T_T$T_R$18 : public UOP_BASE{
public:
  SimdMult$T_T$T_R$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdMult$T_T$T_T$18 : public UOP_BASE{
public:
  SimdMult$T_T$T_T$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0);
};///////////////////////////////////////////////////////////////



class SimdMult$T_T$T$18 : public UOP_BASE{
public:
  SimdMult$T_T$T$18():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0);
};///////////////////////////////////////////////////////////////



class SimdDiv$R_R$R_R$22 : public UOP_BASE{
public:
  SimdDiv$R_R$R_R$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$R_R$R_T$22 : public UOP_BASE{
public:
  SimdDiv$R_R$R_T$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$R_R$R$22 : public UOP_BASE{
public:
  SimdDiv$R_R$R$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$R_R$T_R$22 : public UOP_BASE{
public:
  SimdDiv$R_R$T_R$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$R_R$T_T$22 : public UOP_BASE{
public:
  SimdDiv$R_R$T_T$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$R_R$T$22 : public UOP_BASE{
public:
  SimdDiv$R_R$T$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$R_T$R_R$22 : public UOP_BASE{
public:
  SimdDiv$R_T$R_R$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$R_T$R_T$22 : public UOP_BASE{
public:
  SimdDiv$R_T$R_T$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$R_T$R$22 : public UOP_BASE{
public:
  SimdDiv$R_T$R$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$R_T$T_R$22 : public UOP_BASE{
public:
  SimdDiv$R_T$T_R$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$R_T$T_T$22 : public UOP_BASE{
public:
  SimdDiv$R_T$T_T$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$R_T$T$22 : public UOP_BASE{
public:
  SimdDiv$R_T$T$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$T_R$R_R$22 : public UOP_BASE{
public:
  SimdDiv$T_R$R_R$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$T_R$R_T$22 : public UOP_BASE{
public:
  SimdDiv$T_R$R_T$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$T_R$R$22 : public UOP_BASE{
public:
  SimdDiv$T_R$R$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$T_R$T_R$22 : public UOP_BASE{
public:
  SimdDiv$T_R$T_R$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$T_R$T_T$22 : public UOP_BASE{
public:
  SimdDiv$T_R$T_T$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$T_R$T$22 : public UOP_BASE{
public:
  SimdDiv$T_R$T$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$T_T$R_R$22 : public UOP_BASE{
public:
  SimdDiv$T_T$R_R$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$T_T$R_T$22 : public UOP_BASE{
public:
  SimdDiv$T_T$R_T$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$T_T$R$22 : public UOP_BASE{
public:
  SimdDiv$T_T$R$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$T_T$T_R$22 : public UOP_BASE{
public:
  SimdDiv$T_T$T_R$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdDiv$T_T$T_T$22 : public UOP_BASE{
public:
  SimdDiv$T_T$T_T$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0);
};///////////////////////////////////////////////////////////////



class SimdDiv$T_T$T$22 : public UOP_BASE{
public:
  SimdDiv$T_T$T$22():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_R$R_R$25 : public UOP_BASE{
public:
  SimdFloatAlu$R_R$R_R$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_R$R_T$25 : public UOP_BASE{
public:
  SimdFloatAlu$R_R$R_T$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_R$R$25 : public UOP_BASE{
public:
  SimdFloatAlu$R_R$R$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_R$T_R$25 : public UOP_BASE{
public:
  SimdFloatAlu$R_R$T_R$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_R$T_T$25 : public UOP_BASE{
public:
  SimdFloatAlu$R_R$T_T$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_R$T$25 : public UOP_BASE{
public:
  SimdFloatAlu$R_R$T$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_T$R_R$25 : public UOP_BASE{
public:
  SimdFloatAlu$R_T$R_R$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_T$R_T$25 : public UOP_BASE{
public:
  SimdFloatAlu$R_T$R_T$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_T$R$25 : public UOP_BASE{
public:
  SimdFloatAlu$R_T$R$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_T$T_R$25 : public UOP_BASE{
public:
  SimdFloatAlu$R_T$T_R$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_T$T_T$25 : public UOP_BASE{
public:
  SimdFloatAlu$R_T$T_T$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_T$T$25 : public UOP_BASE{
public:
  SimdFloatAlu$R_T$T$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$T_R$R_R$25 : public UOP_BASE{
public:
  SimdFloatAlu$T_R$R_R$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$T_R$R_T$25 : public UOP_BASE{
public:
  SimdFloatAlu$T_R$R_T$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$T_R$R$25 : public UOP_BASE{
public:
  SimdFloatAlu$T_R$R$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$T_R$T_R$25 : public UOP_BASE{
public:
  SimdFloatAlu$T_R$T_R$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$T_R$T_T$25 : public UOP_BASE{
public:
  SimdFloatAlu$T_R$T_T$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$T_R$T$25 : public UOP_BASE{
public:
  SimdFloatAlu$T_R$T$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$T_T$R_R$25 : public UOP_BASE{
public:
  SimdFloatAlu$T_T$R_R$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$T_T$R_T$25 : public UOP_BASE{
public:
  SimdFloatAlu$T_T$R_T$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$T_T$R$25 : public UOP_BASE{
public:
  SimdFloatAlu$T_T$R$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$T_T$T_R$25 : public UOP_BASE{
public:
  SimdFloatAlu$T_T$T_R$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$T_T$T_T$25 : public UOP_BASE{
public:
  SimdFloatAlu$T_T$T_T$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0);
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$T_T$T$25 : public UOP_BASE{
public:
  SimdFloatAlu$T_T$T$25():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_R$R_R$30 : public UOP_BASE{
public:
  SimdFloatMult$R_R$R_R$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_R$R_T$30 : public UOP_BASE{
public:
  SimdFloatMult$R_R$R_T$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_R$R$30 : public UOP_BASE{
public:
  SimdFloatMult$R_R$R$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_R$T_R$30 : public UOP_BASE{
public:
  SimdFloatMult$R_R$T_R$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_R$T_T$30 : public UOP_BASE{
public:
  SimdFloatMult$R_R$T_T$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_R$T$30 : public UOP_BASE{
public:
  SimdFloatMult$R_R$T$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_T$R_R$30 : public UOP_BASE{
public:
  SimdFloatMult$R_T$R_R$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_T$R_T$30 : public UOP_BASE{
public:
  SimdFloatMult$R_T$R_T$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_T$R$30 : public UOP_BASE{
public:
  SimdFloatMult$R_T$R$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_T$T_R$30 : public UOP_BASE{
public:
  SimdFloatMult$R_T$T_R$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_T$T_T$30 : public UOP_BASE{
public:
  SimdFloatMult$R_T$T_T$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_T$T$30 : public UOP_BASE{
public:
  SimdFloatMult$R_T$T$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$T_R$R_R$30 : public UOP_BASE{
public:
  SimdFloatMult$T_R$R_R$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$T_R$R_T$30 : public UOP_BASE{
public:
  SimdFloatMult$T_R$R_T$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$T_R$R$30 : public UOP_BASE{
public:
  SimdFloatMult$T_R$R$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$T_R$T_R$30 : public UOP_BASE{
public:
  SimdFloatMult$T_R$T_R$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$T_R$T_T$30 : public UOP_BASE{
public:
  SimdFloatMult$T_R$T_T$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$T_R$T$30 : public UOP_BASE{
public:
  SimdFloatMult$T_R$T$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$T_T$R_R$30 : public UOP_BASE{
public:
  SimdFloatMult$T_T$R_R$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$T_T$R_T$30 : public UOP_BASE{
public:
  SimdFloatMult$T_T$R_T$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$T_T$R$30 : public UOP_BASE{
public:
  SimdFloatMult$T_T$R$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$T_T$T_R$30 : public UOP_BASE{
public:
  SimdFloatMult$T_T$T_R$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$T_T$T_T$30 : public UOP_BASE{
public:
  SimdFloatMult$T_T$T_T$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0);
};///////////////////////////////////////////////////////////////



class SimdFloatMult$T_T$T$30 : public UOP_BASE{
public:
  SimdFloatMult$T_T$T$30():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_R$R_R$28 : public UOP_BASE{
public:
  SimdFloatDiv$R_R$R_R$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_R$R_T$28 : public UOP_BASE{
public:
  SimdFloatDiv$R_R$R_T$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_R$R$28 : public UOP_BASE{
public:
  SimdFloatDiv$R_R$R$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_R$T_R$28 : public UOP_BASE{
public:
  SimdFloatDiv$R_R$T_R$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_R$T_T$28 : public UOP_BASE{
public:
  SimdFloatDiv$R_R$T_T$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_R$T$28 : public UOP_BASE{
public:
  SimdFloatDiv$R_R$T$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_T$R_R$28 : public UOP_BASE{
public:
  SimdFloatDiv$R_T$R_R$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_T$R_T$28 : public UOP_BASE{
public:
  SimdFloatDiv$R_T$R_T$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_T$R$28 : public UOP_BASE{
public:
  SimdFloatDiv$R_T$R$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprLdFrom0subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_T$T_R$28 : public UOP_BASE{
public:
  SimdFloatDiv$R_T$T_R$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_T$T_T$28 : public UOP_BASE{
public:
  SimdFloatDiv$R_T$T_T$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_T$T$28 : public UOP_BASE{
public:
  SimdFloatDiv$R_T$T$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$T_R$R_R$28 : public UOP_BASE{
public:
  SimdFloatDiv$T_R$R_R$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$T_R$R_T$28 : public UOP_BASE{
public:
  SimdFloatDiv$T_R$R_T$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$T_R$R$28 : public UOP_BASE{
public:
  SimdFloatDiv$T_R$R$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_REG& opr_oprStTo0, int oprLdFrom1subRegIdx, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$T_R$T_R$28 : public UOP_BASE{
public:
  SimdFloatDiv$T_R$T_R$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprLdFrom1subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$T_R$T_T$28 : public UOP_BASE{
public:
  SimdFloatDiv$T_R$T_T$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$T_R$T$28 : public UOP_BASE{
public:
  SimdFloatDiv$T_R$T$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, OPR_TREG& opr_oprStFrom0_0, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$T_T$R_R$28 : public UOP_BASE{
public:
  SimdFloatDiv$T_T$R_R$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_REG& opr_oprStTo1, int oprStTo0subRegIdx, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$T_T$R_T$28 : public UOP_BASE{
public:
  SimdFloatDiv$T_T$R_T$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, OPR_TREG& opr_oprStFrom1_0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$T_T$R$28 : public UOP_BASE{
public:
  SimdFloatDiv$T_T$R$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_REG& opr_oprStTo0, int oprStTo0subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$T_T$T_R$28 : public UOP_BASE{
public:
  SimdFloatDiv$T_T$T_R$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_REG& opr_oprStTo1, int oprStTo1subRegIdx);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$T_T$T_T$28 : public UOP_BASE{
public:
  SimdFloatDiv$T_T$T_T$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0, OPR_TREG& opr_oprStFrom1_0);
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$T_T$T$28 : public UOP_BASE{
public:
  SimdFloatDiv$T_T$T$28():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0, OPR_TREG& opr_oprStFrom0_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST_INT$R$R$48 : public UOP_BASE{
public:
  MOV_MEM_ST_INT$R$R$48():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_srcOpr, OPR_REG& opr_desOpr, int srcOprsubRegIdx, int desOprsubRegIdx);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST_INT$R$T$48 : public UOP_BASE{
public:
  MOV_MEM_ST_INT$R$T$48():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_srcOpr, OPR_TREG& opr_ld_to_0, int srcOprsubRegIdx);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST_INT$I$R$48 : public UOP_BASE{
public:
  MOV_MEM_ST_INT$I$R$48():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_srcOpr, OPR_REG& opr_desOpr, int desOprsubRegIdx);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST_INT$I$T$48 : public UOP_BASE{
public:
  MOV_MEM_ST_INT$I$T$48():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_srcOpr, OPR_TREG& opr_ld_to_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD_INT$M$R$47 : public UOP_BASE{
public:
  MOV_MEM_LD_INT$M$R$47():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_srcOpr, OPR_REG& opr_desOpr, ADDR srcOprb_byte_, ADDR srcOpre_byte_, int desOprsubRegIdx);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST_FLT$R$R$50 : public UOP_BASE{
public:
  MOV_MEM_ST_FLT$R$R$50():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_srcOpr, OPR_REG& opr_desOpr, int srcOprsubRegIdx, int desOprsubRegIdx);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST_FLT$R$T$50 : public UOP_BASE{
public:
  MOV_MEM_ST_FLT$R$T$50():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_srcOpr, OPR_TREG& opr_ld_to_0, int srcOprsubRegIdx);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST_FLT$I$R$50 : public UOP_BASE{
public:
  MOV_MEM_ST_FLT$I$R$50():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_srcOpr, OPR_REG& opr_desOpr, int desOprsubRegIdx);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST_FLT$I$T$50 : public UOP_BASE{
public:
  MOV_MEM_ST_FLT$I$T$50():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_srcOpr, OPR_TREG& opr_ld_to_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD_FLT$M$R$49 : public UOP_BASE{
public:
  MOV_MEM_LD_FLT$M$R$49():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_srcOpr, OPR_REG& opr_desOpr, ADDR srcOprb_byte_, ADDR srcOpre_byte_, int desOprsubRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$R_R$$1 : public UOP_BASE{
public:
  IntAlu$R_R$$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_REG& opr_oprLdFrom1, int oprLdFrom0subRegIdx, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$R_T$$1 : public UOP_BASE{
public:
  IntAlu$R_T$$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_oprLdFrom0, OPR_TREG& opr_oprLdTo1_0, int oprLdFrom0subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$T_R$$1 : public UOP_BASE{
public:
  IntAlu$T_R$$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_REG& opr_oprLdFrom1, int oprLdFrom1subRegIdx);
};///////////////////////////////////////////////////////////////



class IntAlu$T_T$$1 : public UOP_BASE{
public:
  IntAlu$T_T$$1():UOP_BASE(){};
  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_oprLdTo0_0, OPR_TREG& opr_oprLdTo1_0);
};
}

#endif