#ifndef X86_MOPL_H
#define X86_MOPL_H
#include"models/arch/dep.h"
#include"models/arch/mop_base.h"
#include"X86_uop.h"




class MOP_COMP$M_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MOP_COMP$M_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MOP_COMP$R_I$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MOP_COMP$R_M$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MOP_COMP$R_R$M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MOP_COMP$M_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MOP_COMP$M_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MOP_COMP$R_I$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MOP_COMP$R_M$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};///////////////////////////////////////////////////////////////



class MOP_COMP$R_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
#endif