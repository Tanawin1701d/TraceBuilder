#ifndef X86_UOPL_H
#define X86_UOPL_H
#include"models/arch/dep.h"
#include"models/arch/uop_base.h"




class COMP$T_T$T : public UOP_BASE{
public:
  COMP$T_T$T():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0, OPR_TREG& opr_a1 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$T_T$R : public UOP_BASE{
public:
  COMP$T_T$R():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0, OPR_TREG& opr_a1 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$T_T$M : public UOP_BASE{
public:
  COMP$T_T$M():UOP_BASE(UOP_STORE){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0, OPR_TREG& opr_a1 ,OPR_MEM& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$T_R$T : public UOP_BASE{
public:
  COMP$T_R$T():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0, OPR_REG& opr_a1 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$T_R$R : public UOP_BASE{
public:
  COMP$T_R$R():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0, OPR_REG& opr_a1 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$T_R$M : public UOP_BASE{
public:
  COMP$T_R$M():UOP_BASE(UOP_STORE){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0, OPR_REG& opr_a1 ,OPR_MEM& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$T_I$T : public UOP_BASE{
public:
  COMP$T_I$T():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0, OPR_IMM& opr_a1 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$T_I$R : public UOP_BASE{
public:
  COMP$T_I$R():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0, OPR_IMM& opr_a1 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$T_I$M : public UOP_BASE{
public:
  COMP$T_I$M():UOP_BASE(UOP_STORE){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0, OPR_IMM& opr_a1 ,OPR_MEM& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$T_M$T : public UOP_BASE{
public:
  COMP$T_M$T():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0, OPR_MEM& opr_a1 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$T_M$R : public UOP_BASE{
public:
  COMP$T_M$R():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0, OPR_MEM& opr_a1 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$T_M$M : public UOP_BASE{
public:
  COMP$T_M$M():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0, OPR_MEM& opr_a1 ,OPR_MEM& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$R_T$T : public UOP_BASE{
public:
  COMP$R_T$T():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0, OPR_TREG& opr_a1 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$R_T$R : public UOP_BASE{
public:
  COMP$R_T$R():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0, OPR_TREG& opr_a1 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$R_T$M : public UOP_BASE{
public:
  COMP$R_T$M():UOP_BASE(UOP_STORE){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0, OPR_TREG& opr_a1 ,OPR_MEM& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$R_R$T : public UOP_BASE{
public:
  COMP$R_R$T():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0, OPR_REG& opr_a1 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$R_R$R : public UOP_BASE{
public:
  COMP$R_R$R():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0, OPR_REG& opr_a1 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$R_R$M : public UOP_BASE{
public:
  COMP$R_R$M():UOP_BASE(UOP_STORE){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0, OPR_REG& opr_a1 ,OPR_MEM& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$R_I$T : public UOP_BASE{
public:
  COMP$R_I$T():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0, OPR_IMM& opr_a1 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$R_I$R : public UOP_BASE{
public:
  COMP$R_I$R():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0, OPR_IMM& opr_a1 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$R_I$M : public UOP_BASE{
public:
  COMP$R_I$M():UOP_BASE(UOP_STORE){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0, OPR_IMM& opr_a1 ,OPR_MEM& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$R_M$T : public UOP_BASE{
public:
  COMP$R_M$T():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0, OPR_MEM& opr_a1 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$R_M$R : public UOP_BASE{
public:
  COMP$R_M$R():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0, OPR_MEM& opr_a1 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$R_M$M : public UOP_BASE{
public:
  COMP$R_M$M():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0, OPR_MEM& opr_a1 ,OPR_MEM& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$M_T$T : public UOP_BASE{
public:
  COMP$M_T$T():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0, OPR_TREG& opr_a1 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$M_T$R : public UOP_BASE{
public:
  COMP$M_T$R():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0, OPR_TREG& opr_a1 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$M_T$M : public UOP_BASE{
public:
  COMP$M_T$M():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0, OPR_TREG& opr_a1 ,OPR_MEM& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$M_R$T : public UOP_BASE{
public:
  COMP$M_R$T():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0, OPR_REG& opr_a1 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$M_R$R : public UOP_BASE{
public:
  COMP$M_R$R():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0, OPR_REG& opr_a1 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$M_R$M : public UOP_BASE{
public:
  COMP$M_R$M():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0, OPR_REG& opr_a1 ,OPR_MEM& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$M_I$T : public UOP_BASE{
public:
  COMP$M_I$T():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0, OPR_IMM& opr_a1 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$M_I$R : public UOP_BASE{
public:
  COMP$M_I$R():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0, OPR_IMM& opr_a1 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$M_I$M : public UOP_BASE{
public:
  COMP$M_I$M():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0, OPR_IMM& opr_a1 ,OPR_MEM& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$M_M$T : public UOP_BASE{
public:
  COMP$M_M$T():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0, OPR_MEM& opr_a1 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$M_M$R : public UOP_BASE{
public:
  COMP$M_M$R():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0, OPR_MEM& opr_a1 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class COMP$M_M$M : public UOP_BASE{
public:
  COMP$M_M$M():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0, OPR_MEM& opr_a1 ,OPR_MEM& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$T$T : public UOP_BASE{
public:
  MOV$T$T():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$T$R : public UOP_BASE{
public:
  MOV$T$R():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$T$I : public UOP_BASE{
public:
  MOV$T$I():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0 ,OPR_IMM& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$T$M : public UOP_BASE{
public:
  MOV$T$M():UOP_BASE(UOP_STORE){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_a0 ,OPR_MEM& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$R$T : public UOP_BASE{
public:
  MOV$R$T():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$R$R : public UOP_BASE{
public:
  MOV$R$R():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$R$I : public UOP_BASE{
public:
  MOV$R$I():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0 ,OPR_IMM& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$R$M : public UOP_BASE{
public:
  MOV$R$M():UOP_BASE(UOP_STORE){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_a0 ,OPR_MEM& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$I$T : public UOP_BASE{
public:
  MOV$I$T():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_a0 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$I$R : public UOP_BASE{
public:
  MOV$I$R():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_a0 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$I$I : public UOP_BASE{
public:
  MOV$I$I():UOP_BASE(UOP_COMP){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_a0 ,OPR_IMM& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$I$M : public UOP_BASE{
public:
  MOV$I$M():UOP_BASE(UOP_STORE){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_a0 ,OPR_MEM& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$M$T : public UOP_BASE{
public:
  MOV$M$T():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0 ,OPR_TREG& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$M$R : public UOP_BASE{
public:
  MOV$M$R():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0 ,OPR_REG& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$M$I : public UOP_BASE{
public:
  MOV$M$I():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0 ,OPR_IMM& opr_b0);
};///////////////////////////////////////////////////////////////



class MOV$M$M : public UOP_BASE{
public:
  MOV$M$M():UOP_BASE(UOP_LOAD){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_a0 ,OPR_MEM& opr_b0);
};
#endif