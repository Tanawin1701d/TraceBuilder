#ifndef X86_MOPL_H
#define X86_MOPL_H
#include"../../../dep.h"
#include"../../../uop_base.h"
#include"../uop/x86_uop.h"
#include"../../../mop_base.h"




class MOP_MOV_V128_M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_MOV_V128_I_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_MOV_V128_R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_MOV_V128_I_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_MOV_V128_R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_MOV_M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_MOV_I_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_MOV_R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_MOV_I_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_MOV_R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_JMP__R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_JMP__I_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_JMP__M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_JMP_R_R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_JMP_R_I_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_JMP_R_M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V128_R_I_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V128_R_R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V128_R_M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V128_M_R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V128_M_M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V128_M_I_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V128_R_I_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V128_R_R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V128_R_M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V128_M_R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V128_M_M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V128_M_I_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_CMP_RR : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_CMP_RI : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_CMP_RM : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_CMP_MI : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_MOV_V64_M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_MOV_V64_I_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_MOV_V64_R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_MOV_V64_I_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_MOV_V64_R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_R_I_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_R_R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_R_M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_M_R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_M_M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_M_I_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_R_I_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_R_R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_R_M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_M_R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_M_M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_M_I_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V64_R_I_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V64_R_R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V64_R_M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V64_M_R_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V64_M_M_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V64_M_I_R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V64_R_I_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V64_R_R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V64_R_M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V64_M_R_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V64_M_M_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
class MOP_COMP_V64_M_I_M : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
#endif
