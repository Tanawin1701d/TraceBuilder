#ifndef X86_UOPL_H
#define X86_UOPL_H
#include"models/arch/dep.h"
#include"models/arch/uop_base.h"




class SIM_ALU$R_R$R$1 : public UOP_BASE{
public:
  SIM_ALU$R_R$R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM_ALU$R_R$T$1 : public UOP_BASE{
public:
  SIM_ALU$R_R$T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST$T$M$9 : public UOP_BASE{
public:
  MOV_MEM_ST$T$M$9():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_preDes ,OPR_MEM& opr_m_des_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD$I$T$8 : public UOP_BASE{
public:
  MOV_MEM_LD$I$T$8():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_i_src_1 ,OPR_TREG& opr_t_1);
};///////////////////////////////////////////////////////////////



class SIM_ALU$R_T$R$1 : public UOP_BASE{
public:
  SIM_ALU$R_T$R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM_ALU$R_T$T$1 : public UOP_BASE{
public:
  SIM_ALU$R_T$T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD$M$T$8 : public UOP_BASE{
public:
  MOV_MEM_LD$M$T$8():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_m_src_1 ,OPR_TREG& opr_t_1);
};///////////////////////////////////////////////////////////////



class SIM_ALU$T_R$R$1 : public UOP_BASE{
public:
  SIM_ALU$T_R$R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM_ALU$T_R$T$1 : public UOP_BASE{
public:
  SIM_ALU$T_R$T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class SIM_ALU$T_T$R$1 : public UOP_BASE{
public:
  SIM_ALU$T_T$R$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM_ALU$T_T$T$1 : public UOP_BASE{
public:
  SIM_ALU$T_T$T$1():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MUL_ALU$R_R$R$2 : public UOP_BASE{
public:
  MUL_ALU$R_R$R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class MUL_ALU$R_R$T$2 : public UOP_BASE{
public:
  MUL_ALU$R_R$T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MUL_ALU$R_T$R$2 : public UOP_BASE{
public:
  MUL_ALU$R_T$R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class MUL_ALU$R_T$T$2 : public UOP_BASE{
public:
  MUL_ALU$R_T$T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MUL_ALU$T_R$R$2 : public UOP_BASE{
public:
  MUL_ALU$T_R$R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class MUL_ALU$T_R$T$2 : public UOP_BASE{
public:
  MUL_ALU$T_R$T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MUL_ALU$T_T$R$2 : public UOP_BASE{
public:
  MUL_ALU$T_T$R$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class MUL_ALU$T_T$T$2 : public UOP_BASE{
public:
  MUL_ALU$T_T$T$2():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class DIV_ALU$R_R$R$3 : public UOP_BASE{
public:
  DIV_ALU$R_R$R$3():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class DIV_ALU$R_R$T$3 : public UOP_BASE{
public:
  DIV_ALU$R_R$T$3():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class DIV_ALU$R_T$R$3 : public UOP_BASE{
public:
  DIV_ALU$R_T$R$3():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class DIV_ALU$R_T$T$3 : public UOP_BASE{
public:
  DIV_ALU$R_T$T$3():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class DIV_ALU$T_R$R$3 : public UOP_BASE{
public:
  DIV_ALU$T_R$R$3():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class DIV_ALU$T_R$T$3 : public UOP_BASE{
public:
  DIV_ALU$T_R$T$3():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class DIV_ALU$T_T$R$3 : public UOP_BASE{
public:
  DIV_ALU$T_T$R$3():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class DIV_ALU$T_T$T$3 : public UOP_BASE{
public:
  DIV_ALU$T_T$T$3():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$R$4 : public UOP_BASE{
public:
  SIM128_ALU$R_R$R$4():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$T$4 : public UOP_BASE{
public:
  SIM128_ALU$R_R$T$4():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_T$R$4 : public UOP_BASE{
public:
  SIM128_ALU$R_T$R$4():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_T$T$4 : public UOP_BASE{
public:
  SIM128_ALU$R_T$T$4():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_R$R$4 : public UOP_BASE{
public:
  SIM128_ALU$T_R$R$4():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_R$T$4 : public UOP_BASE{
public:
  SIM128_ALU$T_R$T$4():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_T$R$4 : public UOP_BASE{
public:
  SIM128_ALU$T_T$R$4():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class SIM128_ALU$T_T$T$4 : public UOP_BASE{
public:
  SIM128_ALU$T_T$T$4():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MUL128_ALU$R_R$R$5 : public UOP_BASE{
public:
  MUL128_ALU$R_R$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class MUL128_ALU$R_R$T$5 : public UOP_BASE{
public:
  MUL128_ALU$R_R$T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MUL128_ALU$R_T$R$5 : public UOP_BASE{
public:
  MUL128_ALU$R_T$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class MUL128_ALU$R_T$T$5 : public UOP_BASE{
public:
  MUL128_ALU$R_T$T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MUL128_ALU$T_R$R$5 : public UOP_BASE{
public:
  MUL128_ALU$T_R$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class MUL128_ALU$T_R$T$5 : public UOP_BASE{
public:
  MUL128_ALU$T_R$T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MUL128_ALU$T_T$R$5 : public UOP_BASE{
public:
  MUL128_ALU$T_T$R$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class MUL128_ALU$T_T$T$5 : public UOP_BASE{
public:
  MUL128_ALU$T_T$T$5():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class DIV128_ALU$R_R$R$6 : public UOP_BASE{
public:
  DIV128_ALU$R_R$R$6():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class DIV128_ALU$R_R$T$6 : public UOP_BASE{
public:
  DIV128_ALU$R_R$T$6():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class DIV128_ALU$R_T$R$6 : public UOP_BASE{
public:
  DIV128_ALU$R_T$R$6():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class DIV128_ALU$R_T$T$6 : public UOP_BASE{
public:
  DIV128_ALU$R_T$T$6():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class DIV128_ALU$T_R$R$6 : public UOP_BASE{
public:
  DIV128_ALU$T_R$R$6():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class DIV128_ALU$T_R$T$6 : public UOP_BASE{
public:
  DIV128_ALU$T_R$T$6():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_REG& opr_r_src_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class DIV128_ALU$T_T$R$6 : public UOP_BASE{
public:
  DIV128_ALU$T_T$R$6():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_REG& opr_r_des_0);
};///////////////////////////////////////////////////////////////



class DIV128_ALU$T_T$T$6 : public UOP_BASE{
public:
  DIV128_ALU$T_T$T$6():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_TREG& opr_t_0, OPR_TREG& opr_t_1 ,OPR_TREG& opr_preDes);
};///////////////////////////////////////////////////////////////



class MOV_REG$R$R$10 : public UOP_BASE{
public:
  MOV_REG$R$R$10():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0 ,OPR_REG& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV_REG$R$M$10 : public UOP_BASE{
public:
  MOV_REG$R$M$10():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0 ,OPR_MEM& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD$I$R$8 : public UOP_BASE{
public:
  MOV_MEM_LD$I$R$8():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_IMM& opr_i_src_0 ,OPR_REG& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_LD$M$R$8 : public UOP_BASE{
public:
  MOV_MEM_LD$M$R$8():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_MEM& opr_m_src_0 ,OPR_REG& opr_x_des_0);
};///////////////////////////////////////////////////////////////



class MOV_MEM_ST$R$M$9 : public UOP_BASE{
public:
  MOV_MEM_ST$R$M$9():UOP_BASE(){};
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta(OPR_REG& opr_r_src_0 ,OPR_MEM& opr_m_des_0);
};
#endif