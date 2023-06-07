#ifndef X86_MOPL_H
#define X86_MOPL_H
#include"models/uop_model/dep.h"
#include"models/uop_model/mop_base.h"
#include"X86_uop.h"




namespace traceBuilder::model {



class RT_INSTR;


class INT_SIM_ALU$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_SIM_ALU$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class INT_MUL_DIV_ALU$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM64_ALU$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM128_ALU$M_M$M : public MOP_BASE{
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



class SIM_MOV128$R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_MOV128$R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_MOV128$I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_MOV128$I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_MOV128$M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SIM_MOV128$M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_SIM_ALU$R_R$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_SIM_ALU$R_I$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_SIM_ALU$R_M$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_SIM_ALU$I_R$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_SIM_ALU$I_I$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_SIM_ALU$I_M$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_SIM_ALU$M_R$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_SIM_ALU$M_I$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_SIM_ALU$M_M$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class JMP_SIM_ALU$R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
}

#endif