#ifndef X86_MOPL_H
#define X86_MOPL_H
#include"models/uop_model/dep/dep_simple.h"
#include"models/uop_model/mop_base.h"
#include"X86_uop.h"




namespace traceBuilder::model {



class RT_INSTR;


class MPREFIX$M_R$R : public MOP_BASE{
public:

   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;
};
}

#endif