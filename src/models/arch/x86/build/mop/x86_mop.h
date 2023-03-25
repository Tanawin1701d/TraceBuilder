#ifndef X86_MOPL_H
#define X86_MOPL_H
#include"../../../dep.h"
#include"../../../uop_base.h"
#include"../uop/x86_uop.h"
#include"../../../mop_base.h"




class MOP_ADD_R_M : public MOP_BASE{
public:

   void genUop(vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
#endif
