#ifndef X86_UOPL_H
#define X86_UOPL_H
#include"models/uop_model/dep.h"
#include"models/uop_model/uop_base.h"




namespace traceBuilder::model {



class INT_SIM_ALU$R_R$R_R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_R$R_R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_R$R_T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_R$R_T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST$T$M$99 : public UOP_BASE{
public:
  MOV_MEM_ST$T$M$99():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_preDes_1 ,OPR_MEM& opr_m_des_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_R$R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_R$R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_R$T_R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_R$T_R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_R$T_T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_R$T_T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_R$T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_R$T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LDI$I$T$1 : public UOP_BASE{
public:
  MOV_MEM_LDI$I$T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_i_src_1 ,OPR_TREG& opr_t_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_T$R_R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_T$R_R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_T$R_T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_T$R_T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_T$R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_T$R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_T$T_R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_T$T_R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_T$T_T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_T$T_T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_T$T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_T$T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD$M$T$6 : public UOP_BASE{
public:
  MOV_MEM_LD$M$T$6():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_m_src_1 ,OPR_TREG& opr_t_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_R$R_R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_R$R_R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_R$R_T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_R$R_T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_R$R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_R$R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_R$T_R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_R$T_R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_R$T_T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_R$T_T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_R$T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_R$T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_T$R_R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_T$R_R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_T$R_T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_T$R_T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_T$R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_T$R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_T$T_R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_T$T_R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_T$T_T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_T$T_T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_T$T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_T$T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_R$R_R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_R$R_R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_R$R_T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_R$R_T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_R$R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_R$R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_R$T_R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_R$T_R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_R$T_T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_R$T_T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_R$T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_R$T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_T$R_R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_T$R_R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_T$R_T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_T$R_T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_T$R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_T$R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_T$T_R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_T$T_R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_T$T_T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_T$T_T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_T$T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_T$T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_R$R_R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_R$R_R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_R$R_T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_R$R_T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_R$R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_R$R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_R$T_R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_R$T_R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_R$T_T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_R$T_T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_R$T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_R$T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_T$R_R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_T$R_R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_T$R_T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_T$R_T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_T$R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_T$R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_T$T_R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_T$T_R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_T$T_T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_T$T_T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_T$T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_T$T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_R$R_R$5 : public UOP_BASE{
public:
  SIM64_ALU$R_R$R_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_R$R_T$5 : public UOP_BASE{
public:
  SIM64_ALU$R_R$R_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_R$R$5 : public UOP_BASE{
public:
  SIM64_ALU$R_R$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_R$T_R$5 : public UOP_BASE{
public:
  SIM64_ALU$R_R$T_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_R$T_T$5 : public UOP_BASE{
public:
  SIM64_ALU$R_R$T_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_R$T$5 : public UOP_BASE{
public:
  SIM64_ALU$R_R$T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_T$R_R$5 : public UOP_BASE{
public:
  SIM64_ALU$R_T$R_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_T$R_T$5 : public UOP_BASE{
public:
  SIM64_ALU$R_T$R_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_T$R$5 : public UOP_BASE{
public:
  SIM64_ALU$R_T$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_T$T_R$5 : public UOP_BASE{
public:
  SIM64_ALU$R_T$T_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_T$T_T$5 : public UOP_BASE{
public:
  SIM64_ALU$R_T$T_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_T$T$5 : public UOP_BASE{
public:
  SIM64_ALU$R_T$T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$T_R$R_R$5 : public UOP_BASE{
public:
  SIM64_ALU$T_R$R_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$T_R$R_T$5 : public UOP_BASE{
public:
  SIM64_ALU$T_R$R_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$T_R$R$5 : public UOP_BASE{
public:
  SIM64_ALU$T_R$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$T_R$T_R$5 : public UOP_BASE{
public:
  SIM64_ALU$T_R$T_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$T_R$T_T$5 : public UOP_BASE{
public:
  SIM64_ALU$T_R$T_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$T_R$T$5 : public UOP_BASE{
public:
  SIM64_ALU$T_R$T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes_0);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$T_T$R_R$5 : public UOP_BASE{
public:
  SIM64_ALU$T_T$R_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$T_T$R_T$5 : public UOP_BASE{
public:
  SIM64_ALU$T_T$R_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$T_T$R$5 : public UOP_BASE{
public:
  SIM64_ALU$T_T$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$T_T$T_R$5 : public UOP_BASE{
public:
  SIM64_ALU$T_T$T_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$T_T$T_T$5 : public UOP_BASE{
public:
  SIM64_ALU$T_T$T_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM64_ALU$T_T$T$5 : public UOP_BASE{
public:
  SIM64_ALU$T_T$T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes_0);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$R_R$5 : public UOP_BASE{
public:
  SIM128_ALU$R_R$R_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$R_T$5 : public UOP_BASE{
public:
  SIM128_ALU$R_R$R_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$R$5 : public UOP_BASE{
public:
  SIM128_ALU$R_R$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$T_R$5 : public UOP_BASE{
public:
  SIM128_ALU$R_R$T_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$T_T$5 : public UOP_BASE{
public:
  SIM128_ALU$R_R$T_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$T$5 : public UOP_BASE{
public:
  SIM128_ALU$R_R$T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_T$R_R$5 : public UOP_BASE{
public:
  SIM128_ALU$R_T$R_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_T$R_T$5 : public UOP_BASE{
public:
  SIM128_ALU$R_T$R_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_T$R$5 : public UOP_BASE{
public:
  SIM128_ALU$R_T$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_T$T_R$5 : public UOP_BASE{
public:
  SIM128_ALU$R_T$T_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_T$T_T$5 : public UOP_BASE{
public:
  SIM128_ALU$R_T$T_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_T$T$5 : public UOP_BASE{
public:
  SIM128_ALU$R_T$T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_R$R_R$5 : public UOP_BASE{
public:
  SIM128_ALU$T_R$R_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_R$R_T$5 : public UOP_BASE{
public:
  SIM128_ALU$T_R$R_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_R$R$5 : public UOP_BASE{
public:
  SIM128_ALU$T_R$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_R$T_R$5 : public UOP_BASE{
public:
  SIM128_ALU$T_R$T_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_R$T_T$5 : public UOP_BASE{
public:
  SIM128_ALU$T_R$T_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_R$T$5 : public UOP_BASE{
public:
  SIM128_ALU$T_R$T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_T$R_R$5 : public UOP_BASE{
public:
  SIM128_ALU$T_T$R_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_T$R_T$5 : public UOP_BASE{
public:
  SIM128_ALU$T_T$R_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_T$R$5 : public UOP_BASE{
public:
  SIM128_ALU$T_T$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_T$T_R$5 : public UOP_BASE{
public:
  SIM128_ALU$T_T$T_R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_REG& opr_r_des_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_T$T_T$5 : public UOP_BASE{
public:
  SIM128_ALU$T_T$T_T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes, OPR_TREG& opr_preDes_1);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_T$T$5 : public UOP_BASE{
public:
  SIM128_ALU$T_T$T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MOV_REG$R$R$1 : public UOP_BASE{
public:
  MOV_REG$R$R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0 ,OPR_REG& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST$R$M$99 : public UOP_BASE{
public:
  MOV_MEM_ST$R$M$99():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0 ,OPR_MEM& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LDI$I$R$1 : public UOP_BASE{
public:
  MOV_MEM_LDI$I$R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_i_src_0 ,OPR_REG& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD$M$R$6 : public UOP_BASE{
public:
  MOV_MEM_LD$M$R$6():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_m_src_0 ,OPR_REG& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class CMP_SIM_ALU$R_R$$1 : public UOP_BASE{
public:
  CMP_SIM_ALU$R_R$$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 );
};///////////////////////////////////////////////////////////////



class CMP_SIM_ALU$R_T$$1 : public UOP_BASE{
public:
  CMP_SIM_ALU$R_T$$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 );
};///////////////////////////////////////////////////////////////



class CMP_SIM_ALU$T_R$$1 : public UOP_BASE{
public:
  CMP_SIM_ALU$T_R$$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 );
};///////////////////////////////////////////////////////////////



class CMP_SIM_ALU$T_T$$1 : public UOP_BASE{
public:
  CMP_SIM_ALU$T_T$$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 );
};///////////////////////////////////////////////////////////////



class JMP_SIM_ALU$R$R$1 : public UOP_BASE{
public:
  JMP_SIM_ALU$R$R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0 ,OPR_REG& opr_reg_des_1);
};
}

#endif