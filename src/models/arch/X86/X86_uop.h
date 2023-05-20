#ifndef X86_UOPL_H
#define X86_UOPL_H
#include"models/arch/dep.h"
#include"models/arch/uop_base.h"




class SIM_ALU$R_R$R$0 : public UOP_BASE{
public:
  SIM_ALU$R_R$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM_ALU$R_R$T$0 : public UOP_BASE{
public:
  SIM_ALU$R_R$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST$T$M$0 : public UOP_BASE{
public:
  MOV_MEM_ST$T$M$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_preDes ,OPR_MEM& opr_m_des_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD$I$T$0 : public UOP_BASE{
public:
  MOV_MEM_LD$I$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_i_src_1 ,OPR_TREG& opr_t_1);
};///////////////////////////////////////////////////////////////



class SIM_ALU$R_T$R$0 : public UOP_BASE{
public:
  SIM_ALU$R_T$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM_ALU$R_T$T$0 : public UOP_BASE{
public:
  SIM_ALU$R_T$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD$M$T$0 : public UOP_BASE{
public:
  MOV_MEM_LD$M$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_m_src_1 ,OPR_TREG& opr_t_1);
};///////////////////////////////////////////////////////////////



class SIM_ALU$T_R$R$0 : public UOP_BASE{
public:
  SIM_ALU$T_R$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM_ALU$T_R$T$0 : public UOP_BASE{
public:
  SIM_ALU$T_R$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class SIM_ALU$T_T$R$0 : public UOP_BASE{
public:
  SIM_ALU$T_T$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM_ALU$T_T$T$0 : public UOP_BASE{
public:
  SIM_ALU$T_T$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MUL_ALU$R_R$R$0 : public UOP_BASE{
public:
  MUL_ALU$R_R$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class MUL_ALU$R_R$T$0 : public UOP_BASE{
public:
  MUL_ALU$R_R$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MUL_ALU$R_T$R$0 : public UOP_BASE{
public:
  MUL_ALU$R_T$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class MUL_ALU$R_T$T$0 : public UOP_BASE{
public:
  MUL_ALU$R_T$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MUL_ALU$T_R$R$0 : public UOP_BASE{
public:
  MUL_ALU$T_R$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class MUL_ALU$T_R$T$0 : public UOP_BASE{
public:
  MUL_ALU$T_R$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MUL_ALU$T_T$R$0 : public UOP_BASE{
public:
  MUL_ALU$T_T$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class MUL_ALU$T_T$T$0 : public UOP_BASE{
public:
  MUL_ALU$T_T$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class DIV_ALU$R_R$R$0 : public UOP_BASE{
public:
  DIV_ALU$R_R$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class DIV_ALU$R_R$T$0 : public UOP_BASE{
public:
  DIV_ALU$R_R$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class DIV_ALU$R_T$R$0 : public UOP_BASE{
public:
  DIV_ALU$R_T$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class DIV_ALU$R_T$T$0 : public UOP_BASE{
public:
  DIV_ALU$R_T$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class DIV_ALU$T_R$R$0 : public UOP_BASE{
public:
  DIV_ALU$T_R$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class DIV_ALU$T_R$T$0 : public UOP_BASE{
public:
  DIV_ALU$T_R$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class DIV_ALU$T_T$R$0 : public UOP_BASE{
public:
  DIV_ALU$T_T$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class DIV_ALU$T_T$T$0 : public UOP_BASE{
public:
  DIV_ALU$T_T$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MOV$R$R$0 : public UOP_BASE{
public:
  MOV$R$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0 ,OPR_REG& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV$R$M$0 : public UOP_BASE{
public:
  MOV$R$M$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0 ,OPR_MEM& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV$I$R$0 : public UOP_BASE{
public:
  MOV$I$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_i_src_0 ,OPR_REG& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV$I$T$0 : public UOP_BASE{
public:
  MOV$I$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_i_src_0 ,OPR_TREG& opr_t_0);
};///////////////////////////////////////////////////////////////



class MOV$T$M$0 : public UOP_BASE{
public:
  MOV$T$M$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0 ,OPR_MEM& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV$M$R$0 : public UOP_BASE{
public:
  MOV$M$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_m_src_0 ,OPR_REG& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV$M$T$0 : public UOP_BASE{
public:
  MOV$M$T$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_m_src_0 ,OPR_TREG& opr_t_0);
};///////////////////////////////////////////////////////////////



class MOV_INTERNAL$R$R$0 : public UOP_BASE{
public:
  MOV_INTERNAL$R$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST$R$M$0 : public UOP_BASE{
public:
  MOV_MEM_ST$R$M$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0 ,OPR_MEM& opr_m_des_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD$I$R$0 : public UOP_BASE{
public:
  MOV_MEM_LD$I$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_i_src_0 ,OPR_REG& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD$M$R$0 : public UOP_BASE{
public:
  MOV_MEM_LD$M$R$0():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_m_src_0 ,OPR_REG& opr_x_des_0);
};
#endif