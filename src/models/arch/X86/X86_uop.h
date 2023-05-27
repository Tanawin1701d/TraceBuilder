#ifndef X86_UOPL_H
#define X86_UOPL_H
#include"models/arch/dep.h"
#include"models/arch/uop_base.h"




class INT_SIM_ALU$R_R$R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_R$R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_R$T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_R$T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST$T$M$99 : public UOP_BASE{
public:
  MOV_MEM_ST$T$M$99():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_preDes ,OPR_MEM& opr_m_des_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD$I$T$6 : public UOP_BASE{
public:
  MOV_MEM_LD$I$T$6():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_i_src_1 ,OPR_TREG& opr_t_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_T$R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_T$R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_T$T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$R_T$T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD$M$T$6 : public UOP_BASE{
public:
  MOV_MEM_LD$M$T$6():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_m_src_1 ,OPR_TREG& opr_t_1);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_R$R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_R$R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_R$T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_R$T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_T$R$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_T$R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$T_T$T$1 : public UOP_BASE{
public:
  INT_SIM_ALU$T_T$T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_R$R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_R$R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_R$T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_R$T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_T$R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_T$R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_T$T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$R_T$T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_R$R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_R$R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_R$T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_R$T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_T$R$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_T$R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$T_T$T$2 : public UOP_BASE{
public:
  INT_MUL_DIV_ALU$T_T$T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$R$5 : public UOP_BASE{
public:
  SIM128_ALU$R_R$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$T$5 : public UOP_BASE{
public:
  SIM128_ALU$R_R$T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_T$R$5 : public UOP_BASE{
public:
  SIM128_ALU$R_T$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_T$T$5 : public UOP_BASE{
public:
  SIM128_ALU$R_T$T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_R$R$5 : public UOP_BASE{
public:
  SIM128_ALU$T_R$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_R$T$5 : public UOP_BASE{
public:
  SIM128_ALU$T_R$T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_T$R$5 : public UOP_BASE{
public:
  SIM128_ALU$T_T$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
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



class MOV_REG$R$M$1 : public UOP_BASE{
public:
  MOV_REG$R$M$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0 ,OPR_MEM& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD$I$R$6 : public UOP_BASE{
public:
  MOV_MEM_LD$I$R$6():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_i_src_0 ,OPR_REG& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD$M$R$6 : public UOP_BASE{
public:
  MOV_MEM_LD$M$R$6():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_m_src_0 ,OPR_REG& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST$R$M$99 : public UOP_BASE{
public:
  MOV_MEM_ST$R$M$99():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0 ,OPR_MEM& opr_m_des_0);
};
#endif