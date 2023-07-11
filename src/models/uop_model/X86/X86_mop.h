#ifndef X86_MOPL_H
#define X86_MOPL_H
#include"models/uop_model/dep/dep_simple.h"
#include"models/uop_model/mop_base.h"
#include"X86_uop.h"




namespace traceBuilder::model {



class RT_INSTR;


class COMP_INT$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_INT$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_MUL$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_DIV$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_MUL$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP_FLT_DIV$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_INT$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_MUL$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_DIV$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_MUL$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP128_FLT_DIV$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_INT$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_MUL$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_DIV$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_MUL$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class COMP64_FLT_DIV$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MOV_SIM$R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MOV_SIM$R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MOV_SIM$I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MOV_SIM$I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MOV_SIM$M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MOV_SIM$M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_MOP$R_R$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_MOP$R_I$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_MOP$R_M$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_MOP$I_R$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_MOP$I_I$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_MOP$I_M$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_MOP$M_R$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_MOP$M_I$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CMP_MOP$M_M$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CTRL_ALL$R_R_R$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CTRL_ALL$R_I_R$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CTRL_ALL$R_M_R$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CTRL_ALL$I_R_R$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CTRL_ALL$I_I_R$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CTRL_ALL$I_M_R$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CTRL_ALL$M_R_R$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CTRL_ALL$M_I_R$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class CTRL_ALL$M_M_R$ : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
}

#endif