#ifndef X86_MOPL_H
#define X86_MOPL_H
#include"models/arch/dep.h"
#include"models/arch/mop_base.h"
#include"X86_uop.h"




class SIM_ALU$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_ALU$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MUL_ALU$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class DIV_ALU$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_MOV$R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_MOV$R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_MOV$I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_MOV$I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_MOV$M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_MOV$M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM256_MOV$R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM256_MOV$R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM256_MOV$I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM256_MOV$I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM256_MOV$M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM256_MOV$M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
#endif