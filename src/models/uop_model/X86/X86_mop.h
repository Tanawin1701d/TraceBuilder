#ifndef X86_MOPL_H
#define X86_MOPL_H
#include"models/uop_model/dep_simple.h"
#include"models/uop_model/mop_base.h"
#include"X86_uop.h"




namespace traceBuilder::model {



class RT_INSTR;


class IntAlu$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntAlu$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntMult$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class IntDiv$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatAdd$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatMult$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class FloatDiv$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdAlu$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdMult$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdDiv$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatAlu$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatMult$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$I_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_R$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_R$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_R$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_R$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_I$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_I$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_I$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_I$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_M$R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_M$R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_M$M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_M$M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class SimdFloatDiv$M_M$M : public MOP_BASE{
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