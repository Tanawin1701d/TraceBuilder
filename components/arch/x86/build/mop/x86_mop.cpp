#include"x86_mop.h"
#include"../../../../inst_model/rt_instr.h"
void MOP_ADD_R_M::genUop(vector<UOP_BASE*>& results){
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_UOP_LD = new UOP_LD();
     var_UOP_LD->addMeta(((LD_OPERAND*)(srcPool[1]))->getMeta(), T1);
     results.push_back(var_UOP_LD);
     auto var_UOP_ADD = new UOP_ADD();
     var_UOP_ADD->addMeta(((REG_OPERAND*)(srcPool[0]))->getMeta(), T1, ((REG_OPERAND*)(desPool[0]))->getMeta());
     results.push_back(var_UOP_ADD);



     ///------------------------connect uop temp variable dep 
     var_UOP_ADD->addTemDep(var_UOP_LD);
}