#ifndef X86_MOPL_H
#define X86_MOPL_H
#include"../../../dep.h"
#include"../../../mop_base.h"
#include"../uop/x86_uop.h"




class MOP_ADD_R_M : MOP_BASE{
public:

   vector<UOP_BASE*> genUop() override;
};
#endif
