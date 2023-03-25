#include"x86_mop.h"
#include"../../../../inst_model/rt_instr.h"





void MOP_ADD_R_M::genUop(vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_relativeName1 = new UOP_LD();
     var_relativeName1->addMeta(((LD_OPERAND*)(srcPool[1]))->getMeta(), T1);
     results.push_back(var_relativeName1);
     auto var_relativeName2 = new UOP_ADD();
     var_relativeName2->addMeta(((REG_OPERAND*)(srcPool[0]))->getMeta(), T1, ((REG_OPERAND*)(desPool[0]))->getMeta());
     results.push_back(var_relativeName2);



     ///------------------------connect uop temp variable dep 
     var_relativeName2->addTemDep(var_relativeName1);
}