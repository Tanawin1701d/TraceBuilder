#include"x86_mop.h"
#include"../../../../inst_model/rt_instr.h"





void MOP_MOV_V128_M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_V128_M_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_loader1 = new UOP_VEC_MEM_LD_T();
          var_loader1->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_loader1);
     auto var_loader1A = new UOP_VEC_MEM_LD_T();
          var_loader1A->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_loader1A);
     auto var_regStorer = new UOP_VEC_MOV_T_R();
          var_regStorer->addMeta(&T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_regStorer);



     ///------------------------connect uop temp variable dep 
     var_regStorer->addTemDep(var_loader1A);
     var_regStorer->addTemDep(var_loader1);
}
 void MOP_MOV_V128_I_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_V128_I_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_loaderi = new UOP_VEC_LD_IMM();
          var_loaderi->addMeta(&T1);
          results.push_back(var_loaderi);
     auto var_regStorer = new UOP_VEC_MOV_T_R();
          var_regStorer->addMeta(&T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_regStorer);



     ///------------------------connect uop temp variable dep 
     var_regStorer->addTemDep(var_loaderi);
}
 void MOP_MOV_V128_R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_V128_R_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();



     ///------------------------create uop 
     auto var_mover = new UOP_VEC_MOV_R_R();
          var_mover->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(desPool[0]));
          results.push_back(var_mover);



     ///------------------------connect uop temp variable dep 
}
 void MOP_MOV_V128_I_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_V128_I_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_loaderi = new UOP_VEC_LD_IMM();
          var_loaderi->addMeta(&T1);
          results.push_back(var_loaderi);
     auto var_storer1 = new UOP_VEC_MEM_ST_T();
          var_storer1->addMeta(&T1, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_storer1);
     auto var_storer1A = new UOP_VEC_MEM_ST_T();
          var_storer1A->addMeta(&T1, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_storer1A);



     ///------------------------connect uop temp variable dep 
     var_storer1->addTemDep(var_loaderi);
     var_storer1A->addTemDep(var_loaderi);
}
 void MOP_MOV_V128_R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_V128_R_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_regloader = new UOP_VEC_MOV_R_T();
          var_regloader->addMeta((REG_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_regloader);
     auto var_storer1 = new UOP_VEC_MEM_ST_T();
          var_storer1->addMeta(&T1, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_storer1);
     auto var_storer1A = new UOP_VEC_MEM_ST_T();
          var_storer1A->addMeta(&T1, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_storer1A);



     ///------------------------connect uop temp variable dep 
     var_storer1->addTemDep(var_regloader);
     var_storer1A->addTemDep(var_regloader);
}
 void MOP_MOV_M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_M_R"].asUINT()++;
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
     MAIN_STAT["mopGen"]["MOP_MOV_I_R"].asUINT()++;
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
     MAIN_STAT["mopGen"]["MOP_MOV_R_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();



     ///------------------------create uop 
     auto var_mover = new UOP_GEN_MOV_R_R();
          var_mover->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(desPool[0]));
          results.push_back(var_mover);



     ///------------------------connect uop temp variable dep 
}
 void MOP_MOV_I_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_I_M"].asUINT()++;
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
     MAIN_STAT["mopGen"]["MOP_MOV_R_M"].asUINT()++;
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
     MAIN_STAT["mopGen"]["MOP_JMP__R_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();



     ///------------------------create uop 
     auto var_ldAndSetRip = new UOP_ST_RIP_1R();
          var_ldAndSetRip->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(desPool[0]));
          results.push_back(var_ldAndSetRip);



     ///------------------------connect uop temp variable dep 
}
 void MOP_JMP__I_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_JMP__I_R"].asUINT()++;
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
     MAIN_STAT["mopGen"]["MOP_JMP__M_R"].asUINT()++;
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
     MAIN_STAT["mopGen"]["MOP_JMP_R_R_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();



     ///------------------------create uop 
     auto var_ldAndSetRip = new UOP_ST_RIP_2R();
          var_ldAndSetRip->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(srcPool[1]), (REG_OPERAND*)(desPool[0]));
          results.push_back(var_ldAndSetRip);



     ///------------------------connect uop temp variable dep 
}
 void MOP_JMP_R_I_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_JMP_R_I_R"].asUINT()++;
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
     var_writeRip->addTemDep(var_ldRip);
     var_writeRip->addTemDep(var_loader);
}
 void MOP_JMP_R_M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_JMP_R_M_R"].asUINT()++;
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
     var_writeRip->addTemDep(var_ldRip);
     var_writeRip->addTemDep(var_loader);
}
 void MOP_COMP_V128_R_I_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V128_R_I_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_myImm = new UOP_VEC_LD_IMM();
          var_myImm->addMeta(&T1);
          results.push_back(var_myImm);
     auto var_alu = new UOP_VEC_COMP_R_T_R();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), &T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myImm);
}
 void MOP_COMP_V128_R_R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V128_R_R_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();



     ///------------------------create uop 
     auto var_alu = new UOP_VEC_COMP_R_R_R();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(srcPool[1]), (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
}
 void MOP_COMP_V128_R_M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V128_R_M_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_myMem1 = new UOP_VEC_MEM_LD_T();
          var_myMem1->addMeta((MEM_OPERAND*)(srcPool[1]), &T1);
          results.push_back(var_myMem1);
     auto var_myMem1A = new UOP_VEC_MEM_LD_T();
          var_myMem1A->addMeta((MEM_OPERAND*)(srcPool[1]), &T1);
          results.push_back(var_myMem1A);
     auto var_alu = new UOP_VEC_COMP_R_T_R();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), &T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myMem1A);
     var_alu->addTemDep(var_myMem1);
}
 void MOP_COMP_V128_M_R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V128_M_R_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_myMem1 = new UOP_VEC_MEM_LD_T();
          var_myMem1->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_myMem1);
     auto var_myMem1A = new UOP_VEC_MEM_LD_T();
          var_myMem1A->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_myMem1A);
     auto var_alu = new UOP_VEC_COMP_R_T_R();
          var_alu->addMeta((REG_OPERAND*)(srcPool[1]), &T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myMem1A);
     var_alu->addTemDep(var_myMem1);
}
 void MOP_COMP_V128_M_M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V128_M_M_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2;



     ///------------------------create uop 
     auto var_loader1 = new UOP_VEC_MEM_LD_T();
          var_loader1->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_loader1);
     auto var_loader1A = new UOP_VEC_MEM_LD_T();
          var_loader1A->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_loader1A);
     auto var_loader2 = new UOP_VEC_MEM_LD_T();
          var_loader2->addMeta((MEM_OPERAND*)(srcPool[1]), &T2);
          results.push_back(var_loader2);
     auto var_loader2A = new UOP_VEC_MEM_LD_T();
          var_loader2A->addMeta((MEM_OPERAND*)(srcPool[1]), &T2);
          results.push_back(var_loader2A);
     auto var_alu = new UOP_VEC_COMP_T_T_R();
          var_alu->addMeta(&T1, &T2, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_loader1A);
     var_alu->addTemDep(var_loader2);
     var_alu->addTemDep(var_loader1);
     var_alu->addTemDep(var_loader2A);
}
 void MOP_COMP_V128_M_I_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V128_M_I_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2;



     ///------------------------create uop 
     auto var_loaderi = new UOP_VEC_LD_IMM();
          var_loaderi->addMeta(&T1);
          results.push_back(var_loaderi);
     auto var_loader1 = new UOP_VEC_MEM_LD_T();
          var_loader1->addMeta((MEM_OPERAND*)(srcPool[0]), &T2);
          results.push_back(var_loader1);
     auto var_loader1A = new UOP_VEC_MEM_LD_T();
          var_loader1A->addMeta((MEM_OPERAND*)(srcPool[0]), &T2);
          results.push_back(var_loader1A);
     auto var_alu = new UOP_VEC_COMP_T_T_R();
          var_alu->addMeta(&T1, &T2, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_loader1A);
     var_alu->addTemDep(var_loaderi);
     var_alu->addTemDep(var_loader1);
}
 void MOP_COMP_V128_R_I_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V128_R_I_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,TX;



     ///------------------------create uop 
     auto var_myImm = new UOP_VEC_LD_IMM();
          var_myImm->addMeta(&T1);
          results.push_back(var_myImm);
     auto var_alu = new UOP_VEC_COMP_R_T_T();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), &T1, &TX);
          results.push_back(var_alu);
     auto var_store1 = new UOP_VEC_MEM_ST_T();
          var_store1->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store1);
     auto var_store1A = new UOP_VEC_MEM_ST_T();
          var_store1A->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store1A);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myImm);
     var_store1->addTemDep(var_alu);
     var_store1A->addTemDep(var_alu);
}
 void MOP_COMP_V128_R_R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V128_R_R_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM TX;



     ///------------------------create uop 
     auto var_alu = new UOP_VEC_COMP_R_R_T();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(srcPool[1]), &TX);
          results.push_back(var_alu);
     auto var_store1 = new UOP_VEC_MEM_ST_T();
          var_store1->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store1);
     auto var_store1A = new UOP_VEC_MEM_ST_T();
          var_store1A->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store1A);



     ///------------------------connect uop temp variable dep 
     var_store1->addTemDep(var_alu);
     var_store1A->addTemDep(var_alu);
}
 void MOP_COMP_V128_R_M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V128_R_M_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2,TX;



     ///------------------------create uop 
     auto var_myMem1 = new UOP_VEC_MEM_LD_T();
          var_myMem1->addMeta((MEM_OPERAND*)(srcPool[1]), &T1);
          results.push_back(var_myMem1);
     auto var_myMem1A = new UOP_VEC_MEM_LD_T();
          var_myMem1A->addMeta((MEM_OPERAND*)(srcPool[1]), &T1);
          results.push_back(var_myMem1A);
     auto var_alu = new UOP_VEC_COMP_R_T_T();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), &T1, &TX);
          results.push_back(var_alu);
     auto var_store1 = new UOP_VEC_MEM_ST_T();
          var_store1->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store1);
     auto var_store1A = new UOP_VEC_MEM_ST_T();
          var_store1A->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store1A);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myMem1A);
     var_alu->addTemDep(var_myMem1);
     var_store1->addTemDep(var_alu);
     var_store1A->addTemDep(var_alu);
}
 void MOP_COMP_V128_M_R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V128_M_R_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,TX;



     ///------------------------create uop 
     auto var_myMem1 = new UOP_VEC_MEM_LD_T();
          var_myMem1->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_myMem1);
     auto var_myMem1A = new UOP_VEC_MEM_LD_T();
          var_myMem1A->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_myMem1A);
     auto var_alu = new UOP_VEC_COMP_R_T_T();
          var_alu->addMeta((REG_OPERAND*)(srcPool[1]), &T1, &TX);
          results.push_back(var_alu);
     auto var_store1 = new UOP_VEC_MEM_ST_T();
          var_store1->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store1);
     auto var_store1A = new UOP_VEC_MEM_ST_T();
          var_store1A->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store1A);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myMem1A);
     var_alu->addTemDep(var_myMem1);
     var_store1->addTemDep(var_alu);
     var_store1A->addTemDep(var_alu);
}
 void MOP_COMP_V128_M_M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V128_M_M_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2,TX;



     ///------------------------create uop 
     auto var_loader1 = new UOP_VEC_MEM_LD_T();
          var_loader1->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_loader1);
     auto var_loader1A = new UOP_VEC_MEM_LD_T();
          var_loader1A->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_loader1A);
     auto var_loader2 = new UOP_VEC_MEM_LD_T();
          var_loader2->addMeta((MEM_OPERAND*)(srcPool[1]), &T2);
          results.push_back(var_loader2);
     auto var_loader2A = new UOP_VEC_MEM_LD_T();
          var_loader2A->addMeta((MEM_OPERAND*)(srcPool[1]), &T2);
          results.push_back(var_loader2A);
     auto var_alu = new UOP_VEC_COMP_T_T_T();
          var_alu->addMeta(&T1, &T2, &TX);
          results.push_back(var_alu);
     auto var_store = new UOP_VEC_MEM_ST_T();
          var_store->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store);
     auto var_storeA = new UOP_VEC_MEM_ST_T();
          var_storeA->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_storeA);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_loader1A);
     var_alu->addTemDep(var_loader2);
     var_alu->addTemDep(var_loader1);
     var_alu->addTemDep(var_loader2A);
     var_store->addTemDep(var_alu);
     var_storeA->addTemDep(var_alu);
}
 void MOP_COMP_V128_M_I_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V128_M_I_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2,TX;



     ///------------------------create uop 
     auto var_loaderi = new UOP_VEC_LD_IMM();
          var_loaderi->addMeta(&T1);
          results.push_back(var_loaderi);
     auto var_loader1 = new UOP_VEC_MEM_LD_T();
          var_loader1->addMeta((MEM_OPERAND*)(srcPool[0]), &T2);
          results.push_back(var_loader1);
     auto var_alu = new UOP_VEC_COMP_T_T_T();
          var_alu->addMeta(&T1, &T2, &TX);
          results.push_back(var_alu);
     auto var_store1A = new UOP_VEC_MEM_ST_T();
          var_store1A->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store1A);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_loaderi);
     var_alu->addTemDep(var_loader1);
     var_store1A->addTemDep(var_alu);
}
 void MOP_CMP_RR::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_CMP_RR"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();



     ///------------------------create uop 
     auto var_loader = new UOP_GEN_CMP_RR();
          var_loader->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(srcPool[1]));
          results.push_back(var_loader);



     ///------------------------connect uop temp variable dep 
}
 void MOP_CMP_RI::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_CMP_RI"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_loader = new UOP_GEN_CMP_RI();
          var_loader->addMeta((REG_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_loader);



     ///------------------------connect uop temp variable dep 
}
 void MOP_CMP_RM::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_CMP_RM"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_loader = new UOP_GEN_CMP_RM();
          var_loader->addMeta((REG_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_loader);



     ///------------------------connect uop temp variable dep 
}
 void MOP_CMP_MI::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_CMP_MI"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2;



     ///------------------------create uop 
     auto var_loader = new UOP_GEN_CMP_MI();
          var_loader->addMeta(&T2, &T1);
          results.push_back(var_loader);



     ///------------------------connect uop temp variable dep 
}
 void MOP_MOV_V64_M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_V64_M_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_loader = new UOP_VEC_MEM_LD_T();
          var_loader->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_loader);
     auto var_regStorer = new UOP_VEC_MOV_T_R();
          var_regStorer->addMeta(&T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_regStorer);



     ///------------------------connect uop temp variable dep 
     var_regStorer->addTemDep(var_loader);
}
 void MOP_MOV_V64_I_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_V64_I_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_loaderi = new UOP_VEC_LD_IMM();
          var_loaderi->addMeta(&T1);
          results.push_back(var_loaderi);
     auto var_regStorer = new UOP_VEC_MOV_T_R();
          var_regStorer->addMeta(&T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_regStorer);



     ///------------------------connect uop temp variable dep 
     var_regStorer->addTemDep(var_loaderi);
}
 void MOP_MOV_V64_R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_V64_R_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();



     ///------------------------create uop 
     auto var_mover = new UOP_VEC_MOV_R_R();
          var_mover->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(desPool[0]));
          results.push_back(var_mover);



     ///------------------------connect uop temp variable dep 
}
 void MOP_MOV_V64_I_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_V64_I_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_loaderi = new UOP_VEC_LD_IMM();
          var_loaderi->addMeta(&T1);
          results.push_back(var_loaderi);
     auto var_storer = new UOP_VEC_MEM_ST_T();
          var_storer->addMeta(&T1, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_storer);



     ///------------------------connect uop temp variable dep 
     var_storer->addTemDep(var_loaderi);
}
 void MOP_MOV_V64_R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_MOV_V64_R_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_regloader = new UOP_VEC_MOV_R_T();
          var_regloader->addMeta((REG_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_regloader);
     auto var_storer = new UOP_VEC_MEM_ST_T();
          var_storer->addMeta(&T1, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_storer);



     ///------------------------connect uop temp variable dep 
     var_storer->addTemDep(var_regloader);
}
 void MOP_COMP_R_I_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_R_I_R"].asUINT()++;
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
     MAIN_STAT["mopGen"]["MOP_COMP_R_R_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();



     ///------------------------create uop 
     auto var_alu = new UOP_GEN_COMP_R_R_R();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(srcPool[1]), (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
}
 void MOP_COMP_R_M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_R_M_R"].asUINT()++;
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
     MAIN_STAT["mopGen"]["MOP_COMP_M_R_R"].asUINT()++;
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
     MAIN_STAT["mopGen"]["MOP_COMP_M_M_R"].asUINT()++;
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
     var_alu->addTemDep(var_loader1);
     var_alu->addTemDep(var_loader2);
}
 void MOP_COMP_M_I_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_M_I_R"].asUINT()++;
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
     var_alu->addTemDep(var_loaderi);
     var_alu->addTemDep(var_loader2);
}
 void MOP_COMP_R_I_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_R_I_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,TX;



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
     MAIN_STAT["mopGen"]["MOP_COMP_R_R_M"].asUINT()++;
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
     MAIN_STAT["mopGen"]["MOP_COMP_R_M_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,TX;



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
     MAIN_STAT["mopGen"]["MOP_COMP_M_R_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,TX;



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
     MAIN_STAT["mopGen"]["MOP_COMP_M_M_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2,TX;



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
     var_alu->addTemDep(var_loader1);
     var_alu->addTemDep(var_loader2);
     var_store->addTemDep(var_alu);
}
 void MOP_COMP_M_I_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_M_I_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2,TX;



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
     var_alu->addTemDep(var_loaderi);
     var_alu->addTemDep(var_loader2);
     var_store->addTemDep(var_alu);
}
 void MOP_COMP_V64_R_I_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V64_R_I_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_myImm = new UOP_VEC_LD_IMM();
          var_myImm->addMeta(&T1);
          results.push_back(var_myImm);
     auto var_alu = new UOP_VEC_COMP_R_T_R();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), &T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myImm);
}
 void MOP_COMP_V64_R_R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V64_R_R_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();



     ///------------------------create uop 
     auto var_alu = new UOP_VEC_COMP_R_R_R();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(srcPool[1]), (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
}
 void MOP_COMP_V64_R_M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V64_R_M_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_myMem = new UOP_VEC_MEM_LD_T();
          var_myMem->addMeta((MEM_OPERAND*)(srcPool[1]), &T1);
          results.push_back(var_myMem);
     auto var_alu = new UOP_VEC_COMP_R_T_R();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), &T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myMem);
}
 void MOP_COMP_V64_M_R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V64_M_R_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1;



     ///------------------------create uop 
     auto var_myMem = new UOP_VEC_MEM_LD_T();
          var_myMem->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_myMem);
     auto var_alu = new UOP_VEC_COMP_R_T_R();
          var_alu->addMeta((REG_OPERAND*)(srcPool[1]), &T1, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myMem);
}
 void MOP_COMP_V64_M_M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V64_M_M_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2;



     ///------------------------create uop 
     auto var_loader1 = new UOP_VEC_MEM_LD_T();
          var_loader1->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_loader1);
     auto var_loader2 = new UOP_VEC_MEM_LD_T();
          var_loader2->addMeta((MEM_OPERAND*)(srcPool[1]), &T2);
          results.push_back(var_loader2);
     auto var_alu = new UOP_VEC_COMP_T_T_R();
          var_alu->addMeta(&T1, &T2, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_loader1);
     var_alu->addTemDep(var_loader2);
}
 void MOP_COMP_V64_M_I_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V64_M_I_R"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2;



     ///------------------------create uop 
     auto var_loaderi = new UOP_VEC_LD_IMM();
          var_loaderi->addMeta(&T1);
          results.push_back(var_loaderi);
     auto var_loader2 = new UOP_VEC_MEM_LD_T();
          var_loader2->addMeta((MEM_OPERAND*)(srcPool[0]), &T2);
          results.push_back(var_loader2);
     auto var_alu = new UOP_VEC_COMP_T_T_R();
          var_alu->addMeta(&T1, &T2, (REG_OPERAND*)(desPool[0]));
          results.push_back(var_alu);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_loaderi);
     var_alu->addTemDep(var_loader2);
}
 void MOP_COMP_V64_R_I_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V64_R_I_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,TX;



     ///------------------------create uop 
     auto var_myImm = new UOP_VEC_LD_IMM();
          var_myImm->addMeta(&T1);
          results.push_back(var_myImm);
     auto var_alu = new UOP_VEC_COMP_R_T_T();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), &T1, &TX);
          results.push_back(var_alu);
     auto var_store = new UOP_VEC_MEM_ST_T();
          var_store->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myImm);
     var_store->addTemDep(var_alu);
}
 void MOP_COMP_V64_R_R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V64_R_R_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM TX;



     ///------------------------create uop 
     auto var_alu = new UOP_VEC_COMP_R_R_T();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), (REG_OPERAND*)(srcPool[1]), &TX);
          results.push_back(var_alu);
     auto var_store = new UOP_VEC_MEM_ST_T();
          var_store->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store);



     ///------------------------connect uop temp variable dep 
     var_store->addTemDep(var_alu);
}
 void MOP_COMP_V64_R_M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V64_R_M_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,TX;



     ///------------------------create uop 
     auto var_myMem = new UOP_VEC_MEM_LD_T();
          var_myMem->addMeta((MEM_OPERAND*)(srcPool[1]), &T1);
          results.push_back(var_myMem);
     auto var_alu = new UOP_VEC_COMP_R_T_T();
          var_alu->addMeta((REG_OPERAND*)(srcPool[0]), &T1, &TX);
          results.push_back(var_alu);
     auto var_store = new UOP_VEC_MEM_ST_T();
          var_store->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myMem);
     var_store->addTemDep(var_alu);
}
 void MOP_COMP_V64_M_R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V64_M_R_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,TX;



     ///------------------------create uop 
     auto var_myMem = new UOP_VEC_MEM_LD_T();
          var_myMem->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_myMem);
     auto var_alu = new UOP_VEC_COMP_R_T_T();
          var_alu->addMeta((REG_OPERAND*)(srcPool[1]), &T1, &TX);
          results.push_back(var_alu);
     auto var_store = new UOP_VEC_MEM_ST_T();
          var_store->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_myMem);
     var_store->addTemDep(var_alu);
}
 void MOP_COMP_V64_M_M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V64_M_M_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2,TX;



     ///------------------------create uop 
     auto var_loader1 = new UOP_VEC_MEM_LD_T();
          var_loader1->addMeta((MEM_OPERAND*)(srcPool[0]), &T1);
          results.push_back(var_loader1);
     auto var_loader2 = new UOP_VEC_MEM_LD_T();
          var_loader2->addMeta((MEM_OPERAND*)(srcPool[1]), &T2);
          results.push_back(var_loader2);
     auto var_alu = new UOP_VEC_COMP_T_T_T();
          var_alu->addMeta(&T1, &T2, &TX);
          results.push_back(var_alu);
     auto var_store = new UOP_VEC_MEM_ST_T();
          var_store->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_loader1);
     var_alu->addTemDep(var_loader2);
     var_store->addTemDep(var_alu);
}
 void MOP_COMP_V64_M_I_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* rt_instr){
     MAIN_STAT["mopGen"]["MOP_COMP_V64_M_I_M"].asUINT()++;
     auto srcPool = rt_instr->getSrcMacroPoolOperands();
     auto desPool = rt_instr->getDesMacroPoolOperands();
     TREGNUM T1,T2,TX;



     ///------------------------create uop 
     auto var_loaderi = new UOP_VEC_LD_IMM();
          var_loaderi->addMeta(&T1);
          results.push_back(var_loaderi);
     auto var_loader2 = new UOP_VEC_MEM_LD_T();
          var_loader2->addMeta((MEM_OPERAND*)(srcPool[0]), &T2);
          results.push_back(var_loader2);
     auto var_alu = new UOP_VEC_COMP_T_T_T();
          var_alu->addMeta(&T1, &T2, &TX);
          results.push_back(var_alu);
     auto var_store = new UOP_VEC_MEM_ST_T();
          var_store->addMeta(&TX, (MEM_OPERAND*)(desPool[0]));
          results.push_back(var_store);



     ///------------------------connect uop temp variable dep 
     var_alu->addTemDep(var_loaderi);
     var_alu->addTemDep(var_loader2);
     var_store->addTemDep(var_alu);
}