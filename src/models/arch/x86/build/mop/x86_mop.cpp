#include"x86_mop.h"
#include"../../../../inst_model/rt_instr.h"





void MOP_MOV_M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_M_R"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_loader = new UOP_GEN_MEM_LD_T();
          var_loader->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_loader);
     auto var_regStorer = new UOP_GEN_MOV_T_R();
          var_regStorer->addMeta(&T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_regStorer);



     ///------------------------connect uop temp variable dep 
     var_regStorer->addTemDep(var_loader);
}
 void MOP_MOV_I_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_I_R"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_loaderi = new UOP_GEN_LD_IMM();
          var_loaderi->addMeta(&T1);
          results.push_back(var_loaderi);
     auto var_regStorer = new UOP_GEN_MOV_T_R();
          var_regStorer->addMeta(&T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_regStorer);



     ///------------------------connect uop temp variable dep 
     var_regStorer->addTemDep(var_loaderi);
}
 void MOP_MOV_R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_R_R"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();



     ///------------------------create uop 
     auto var_mover = new UOP_GEN_MOV_R_R();
          var_mover->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(desPool[0]));
          results.push_back(var_mover);



     ///------------------------connect uop temp variable dep 
}
 void MOP_MOV_I_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_I_M"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_loaderi = new UOP_GEN_LD_IMM();
          var_loaderi->addMeta(&T1);
          results.push_back(var_loaderi);
     auto var_storer = new UOP_GEN_MEM_ST_T();
          var_storer->addMeta(&T1, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_storer);



     ///------------------------connect uop temp variable dep 
     var_storer->addTemDep(var_loaderi);
}
 void MOP_MOV_R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_R_M"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_regloader = new UOP_GEN_MOV_R_T();
          var_regloader->addMeta((REG_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_regloader);
     auto var_storer = new UOP_GEN_MEM_ST_T();
          var_storer->addMeta(&T1, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_storer);



     ///------------------------connect uop temp variable dep 
     var_storer->addTemDep(var_regloader);
}
 void MOP_JMP__R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_JMP__R_R"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();



     ///------------------------create uop 
     auto var_ldAndSetRip = new UOP_ST_RIP_1R();
          var_ldAndSetRip->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(desPool[0]));
          results.push_back(var_ldAndSetRip);



     ///------------------------connect uop temp variable dep 
}
 void MOP_JMP__I_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_JMP__I_R"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_ldImm = new UOP_GEN_LD_IMM();
          var_ldImm->addMeta(&T1);
          results.push_back(var_ldImm);
     auto var_writeRip = new UOP_ST_RIP_1T();
          var_writeRip->addMeta(&T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_writeRip);



     ///------------------------connect uop temp variable dep 
     var_writeRip->addTemDep(var_ldImm);
}
 void MOP_JMP__M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_JMP__M_R"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_ldMem = new UOP_GEN_MEM_LD_T();
          var_ldMem->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_ldMem);
     auto var_writeRip = new UOP_ST_RIP_1T();
          var_writeRip->addMeta(&T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_writeRip);



     ///------------------------connect uop temp variable dep 
     var_writeRip->addTemDep(var_ldMem);
}
 void MOP_JMP_R_R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_JMP_R_R_R"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();



     ///------------------------create uop 
     auto var_ldAndSetRip = new UOP_ST_RIP_2R();
          var_ldAndSetRip->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(srcPool[1]), (REG_OPERAND*)(desPool[0]));
          results.push_back(var_ldAndSetRip);



     ///------------------------connect uop temp variable dep 
}
 void MOP_JMP_R_I_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_JMP_R_I_R"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2;



     ///------------------------create uop 
     auto var_ldRip = new UOP_LD_RIP();
          var_ldRip->addMeta((REG_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_ldRip);
     auto var_loader = new UOP_GEN_LD_IMM();
          var_loader->addMeta(&T2);
          results.push_back(var_loader);
     auto var_writeRip = new UOP_ST_RIP_2T();
          var_writeRip->addMeta(&T1, &T2, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_writeRip);



     ///------------------------connect uop temp variable dep 
     var_writeRip->addTemDep(var_loader);
     var_writeRip->addTemDep(var_ldRip);
}
 void MOP_JMP_R_M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_JMP_R_M_R"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2;



     ///------------------------create uop 
     auto var_ldRip = new UOP_LD_RIP();
          var_ldRip->addMeta((REG_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_ldRip);
     auto var_loader = new UOP_GEN_MEM_LD_T();
          var_loader->addMeta((MEM_OPERAND*)(srcPool[1]), &T2);
          results.push_back(var_loader);
     auto var_writeRip = new UOP_ST_RIP_2T();
          var_writeRip->addMeta(&T1, &T2, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_writeRip);



     ///------------------------connect uop temp variable dep 
     var_writeRip->addTemDep(var_loader);
     var_writeRip->addTemDep(var_ldRip);
}
 void MOP_COMP_R_I_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_R_I_R"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_myImm = new UOP_GEN_LD_IMM();
          var_myImm->addMeta(&T1);
          results.push_back(var_myImm);
     auto var_alu = new UOP_GEN_COMP_R_T_R();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), &T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myImm);
}
 void MOP_COMP_R_R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_R_R_R"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();



     ///------------------------create uop 
     auto var_alu = new UOP_GEN_COMP_R_R_R();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(srcPool[1]), (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
}
 void MOP_COMP_R_M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_R_M_R"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_myMem = new UOP_GEN_MEM_LD_T();
          var_myMem->addMeta((MEM_OPERAND*)(srcPool[1]), &T1);
          results.push_back(var_myMem);
     auto var_alu = new UOP_GEN_COMP_R_T_R();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), &T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myMem);
}
 void MOP_COMP_M_R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_M_R_R"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_myMem = new UOP_GEN_MEM_LD_T();
          var_myMem->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_myMem);
     auto var_alu = new UOP_GEN_COMP_R_T_R();
          var_alu->addMeta((REG_OPERAND*)(srcPool[1]), &T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myMem);
}
 void MOP_COMP_M_M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_M_M_R"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2;



     ///------------------------create uop 
     auto var_loader1 = new UOP_GEN_MEM_LD_T();
          var_loader1->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_loader1);
     auto var_loader2 = new UOP_GEN_MEM_LD_T();
          var_loader2->addMeta((MEM_OPERAND*)(srcPool[1]), &T2);
          results.push_back(var_loader2);
     auto var_alu = new UOP_GEN_COMP_T_T_R();
          var_alu->addMeta(&T1, &T2, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_loader2);
     var_alu->addTemDep(var_loader1);
}
 void MOP_COMP_M_I_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_M_I_R"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2;



     ///------------------------create uop 
     auto var_loaderi = new UOP_GEN_LD_IMM();
          var_loaderi->addMeta(&T1);
          results.push_back(var_loaderi);
     auto var_loader2 = new UOP_GEN_MEM_LD_T();
          var_loader2->addMeta((MEM_OPERAND*)(srcPool[0]), &T2);
          results.push_back(var_loader2);
     auto var_alu = new UOP_GEN_COMP_T_T_R();
          var_alu->addMeta(&T1, &T2, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_loader2);
     var_alu->addTemDep(var_loaderi);
}
 void MOP_COMP_R_I_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_R_I_M"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM TX,T1;



     ///------------------------create uop 
     auto var_myImm = new UOP_GEN_LD_IMM();
          var_myImm->addMeta(&T1);
          results.push_back(var_myImm);
     auto var_alu = new UOP_GEN_COMP_R_T_T();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), &T1, &TX);
          results.push_back(var_alu);
     auto var_store = new UOP_GEN_MEM_ST_T();
          var_store->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myImm);
     var_store->addTemDep(var_alu);
}
 void MOP_COMP_R_R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_R_R_M"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM TX;



     ///------------------------create uop 
     auto var_alu = new UOP_GEN_COMP_R_R_T();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(srcPool[1]), &TX);
          results.push_back(var_alu);
     auto var_store = new UOP_GEN_MEM_ST_T();
          var_store->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store);



     ///------------------------connect uop temp variable dep 
     var_store->addTemDep(var_alu);
}
 void MOP_COMP_R_M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_R_M_M"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM TX,T1;



     ///------------------------create uop 
     auto var_myMem = new UOP_GEN_MEM_LD_T();
          var_myMem->addMeta((MEM_OPERAND*)(srcPool[1]), &T1);
          results.push_back(var_myMem);
     auto var_alu = new UOP_GEN_COMP_R_T_T();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), &T1, &TX);
          results.push_back(var_alu);
     auto var_store = new UOP_GEN_MEM_ST_T();
          var_store->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myMem);
     var_store->addTemDep(var_alu);
}
 void MOP_COMP_M_R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_M_R_M"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM TX,T1;



     ///------------------------create uop 
     auto var_myMem = new UOP_GEN_MEM_LD_T();
          var_myMem->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_myMem);
     auto var_alu = new UOP_GEN_COMP_R_T_T();
          var_alu->addMeta((REG_OPERAND*)(srcPool[1]), &T1, &TX);
          results.push_back(var_alu);
     auto var_store = new UOP_GEN_MEM_ST_T();
          var_store->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myMem);
     var_store->addTemDep(var_alu);
}
 void MOP_COMP_M_M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_M_M_M"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM TX,T1,T2;



     ///------------------------create uop 
     auto var_loader1 = new UOP_GEN_MEM_LD_T();
          var_loader1->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_loader1);
     auto var_loader2 = new UOP_GEN_MEM_LD_T();
          var_loader2->addMeta((MEM_OPERAND*)(srcPool[1]), &T2);
          results.push_back(var_loader2);
     auto var_alu = new UOP_GEN_COMP_T_T_T();
          var_alu->addMeta(&T1, &T2, &TX);
          results.push_back(var_alu);
     auto var_store = new UOP_GEN_MEM_ST_T();
          var_store->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_loader2);
     var_alu->addTemDep(var_loader1);
     var_store->addTemDep(var_alu);
}
 void MOP_COMP_M_I_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_M_I_M"]++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM TX,T1,T2;



     ///------------------------create uop 
     auto var_loaderi = new UOP_GEN_LD_IMM();
          var_loaderi->addMeta(&T1);
          results.push_back(var_loaderi);
     auto var_loader2 = new UOP_GEN_MEM_LD_T();
          var_loader2->addMeta((MEM_OPERAND*)(srcPool[0]), &T2);
          results.push_back(var_loader2);
     auto var_alu = new UOP_GEN_COMP_T_T_T();
          var_alu->addMeta(&T1, &T2, &TX);
          results.push_back(var_alu);
     auto var_store = new UOP_GEN_MEM_ST_T();
          var_store->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_loader2);
     var_alu->addTemDep(var_loaderi);
     var_store->addTemDep(var_alu);
}