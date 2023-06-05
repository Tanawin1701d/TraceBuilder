#include"X86_mop.h"
#include"models/inst_model/rt_instr.h"



void INT_SIM_ALU$R_R$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_R$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_R$R_R$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_r_des_0, opr_r_des_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_R$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_R$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_R$R_T$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_r_des_0, opr_preDes_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_R$R$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_r_des_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_R$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_R$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_R$T_R$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_preDes_0, opr_r_des_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_R$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_R$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_R$T_T$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_preDes_0, opr_preDes_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_R$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_R$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_R$T$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_preDes_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_I$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_I$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_T$R_R$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_I$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_I$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_T$R_T$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_T$R$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_I$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_I$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_T$T_R$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_I$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_I$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_T$T_T$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_T$T$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_M$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_M$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_T$R_R$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_M$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_M$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_T$R_T$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_T$R$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_M$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_M$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_T$T_R$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_M$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_M$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_T$T_T$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$R_M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$R_M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$R_T$T$1();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_R$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_R$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_R$R_R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_R$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_R$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_R$R_T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_R$R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_R$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_R$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_R$T_R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_R$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_R$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_R$T_T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_R$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_R$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_R$T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_I$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_I$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$R_R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_I$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_I$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$R_T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_I$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_I$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$T_R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_I$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_I$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$T_T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_M$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_M$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$R_R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_M$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_M$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$R_T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_M$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_M$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$T_R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_M$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_M$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$T_T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$I_M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$I_M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_R$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_R$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_R$R_R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_R$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_R$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_R$R_T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_R$R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_R$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_R$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_R$T_R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_R$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_R$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_R$T_T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_R$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_R$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_R$T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_I$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_I$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$R_R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_I$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_I$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$R_T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_I$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_I$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$T_R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_I$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_I$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$T_T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_M$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_M$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$R_R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_M$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_M$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$R_T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_M$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_M$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$T_R$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_M$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_M$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$T_T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_SIM_ALU$M_M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_SIM_ALU$M_M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_SIM_ALU$T_T$T$1();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_R$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_R$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_R$R_R$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_r_des_0, opr_r_des_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_R$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_R$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_R$R_T$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_r_des_0, opr_preDes_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_R$R$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_r_des_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_R$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_R$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_R$T_R$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_preDes_0, opr_r_des_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_R$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_R$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_R$T_T$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_preDes_0, opr_preDes_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_R$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_R$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_R$T$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_preDes_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_I$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_I$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_T$R_R$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_I$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_I$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_T$R_T$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_T$R$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_I$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_I$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_T$T_R$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_I$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_I$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_T$T_T$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_T$T$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_M$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_M$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_T$R_R$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_M$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_M$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_T$R_T$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_T$R$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_M$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_M$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_T$T_R$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_M$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_M$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_T$T_T$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$R_M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$R_M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$R_T$T$2();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_R$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_R$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_R$R_R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_R$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_R$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_R$R_T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_R$R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_R$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_R$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_R$T_R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_R$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_R$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_R$T_T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_R$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_R$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_R$T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_I$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_I$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$R_R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_I$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_I$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$R_T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_I$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_I$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$T_R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_I$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_I$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$T_T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_M$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_M$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$R_R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_M$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_M$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$R_T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_M$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_M$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$T_R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_M$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_M$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$T_T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$I_M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$I_M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_R$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_R$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_R$R_R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_R$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_R$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_R$R_T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_R$R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_R$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_R$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_R$T_R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_R$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_R$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_R$T_T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_R$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_R$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_R$T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_I$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_I$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$R_R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_I$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_I$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$R_T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_I$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_I$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$T_R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_I$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_I$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$T_T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_M$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_M$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$R_R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_M$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_M$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$R_T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_M$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_M$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$T_R$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_M$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_M$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$T_T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void INT_MUL_DIV_ALU$M_M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["INT_MUL_DIV_ALU$M_M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new INT_MUL_DIV_ALU$T_T$T$2();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_R$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_R$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_R$R_R$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_r_des_0, opr_r_des_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_R$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_R$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_R$R_T$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_r_des_0, opr_preDes_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_R$R$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_r_des_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_R$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_R$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_R$T_R$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_preDes_0, opr_r_des_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_R$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_R$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_R$T_T$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_preDes_0, opr_preDes_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_R$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_R$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_R$T$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_r_src_1 ,opr_preDes_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_I$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_I$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_T$R_R$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_I$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_I$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_T$R_T$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_T$R$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_I$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_I$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_T$T_R$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_I$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_I$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_T$T_T$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_T$T$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_M$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_M$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_T$R_R$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_M$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_M$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_T$R_T$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_T$R$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_M$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_M$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_T$T_R$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_M$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_M$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_T$T_T$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$R_M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$R_M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$R_T$T$5();
    uop_uop_comp->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_R$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_R$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_R$R_R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_R$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_R$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_R$R_T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_R$R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_R$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_R$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_R$T_R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_R$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_R$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_R$T_T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_R$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_R$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_R$T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_I$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_I$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$R_R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_I$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_I$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$R_T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_I$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_I$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$T_R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_I$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_I$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$T_T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_M$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_M$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$R_R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_M$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_M$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$R_T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_M$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_M$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$T_R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_M$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_M$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$T_T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$I_M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$I_M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_R$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_R$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_R$R_R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_R$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_R$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_R$R_T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_R$R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_R$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_R$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_R$T_R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_R$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_R$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_R$T_T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_R$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_R$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_R$T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_I$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_I$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$R_R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_I$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_I$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$R_T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_I$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_I$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$T_R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_I$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_I$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$T_T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_M$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_M$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$R_R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_M$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_M$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$R_T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_M$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_M$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$T_R$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_r_des_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_M$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_M$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$T_T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0, opr_preDes_1);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_st_1->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM64_ALU$M_M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM64_ALU$M_M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp = new SIM64_ALU$T_T$T$5();
    uop_uop_comp->addMeta(opr_t_0, opr_t_1 ,opr_preDes_0);
    uop_uop_comp->addTemDep(uop_uop_ld_0);
    uop_uop_comp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_comp);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_preDes_0 ,opr_m_des_0);
    uop_uop_st_0->addTemDep(uop_uop_comp);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_R$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_R$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_R$R_R$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_r_src_1 ,opr_r_des_0, opr_r_des_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_R$R_R$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_r_src_1 ,opr_r_des_0, opr_r_des_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_R$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_R$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_R$R_T$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_r_src_1 ,opr_r_des_0, opr_preDes_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_R$R_T$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_r_src_1 ,opr_r_des_0, opr_preDes_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_R$R$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_r_src_1 ,opr_r_des_0);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_R$R$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_r_src_1 ,opr_r_des_0);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_R$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_R$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_R$T_R$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_r_src_1 ,opr_preDes, opr_r_des_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_R$T_R$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_r_src_1 ,opr_preDes, opr_r_des_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_R$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_R$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_preDes;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_R$T_T$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_r_src_1 ,opr_preDes, opr_preDes_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_R$T_T$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_r_src_1 ,opr_preDes, opr_preDes_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_R$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_R$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_R$T$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_r_src_1 ,opr_preDes);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_R$T$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_r_src_1 ,opr_preDes);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_I$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_I$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_T$R_R$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_T$R_R$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_I$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_I$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_T$R_T$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_T$R_T$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_T$R$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_T$R$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_I$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_I$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_T$T_R$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_T$T_R$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_I$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_I$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_T$T_T$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_T$T_T$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_T$T$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_T$T$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_M$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_M$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_T$R_R$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_T$R_R$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_M$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_M$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_T$R_T$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_T$R_T$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_T$R$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_T$R$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_M$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_M$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_T$T_R$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_T$T_R$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_M$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_M$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_T$T_T$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_T$T_T$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$R_M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$R_M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$R_T$T$5();
    uop_uop_comp_0->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$R_T$T$5();
    uop_uop_comp_1->addMeta(opr_r_src_0, opr_t_1 ,opr_preDes);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_R$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_R$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_R$R_R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_R$R_R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_R$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_R$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_R$R_T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_R$R_T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_R$R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_R$R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_R$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_R$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_R$T_R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_R$T_R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_R$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_R$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_R$T_T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_R$T_T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_R$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_R$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_R$T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_R$T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_I$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_I$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$R_R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$R_R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_I$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_I$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$R_T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$R_T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_I$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_I$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$T_R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$T_R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_I$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_I$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$T_T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$T_T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_preDes);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_preDes);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_M$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_M$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$R_R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$R_R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_M$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_M$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$R_T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$R_T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_M$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_M$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$T_R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$T_R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_M$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_M$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$T_T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$T_T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$I_M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$I_M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_preDes);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_preDes);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_R$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_R$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_R$R_R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_R$R_R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_R$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_R$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_R$R_T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_R$R_T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_R$R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_R$R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_r_src_1 ,opr_r_des_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_R$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_R$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_R$T_R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_R$T_R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_R$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_R$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_R$T_T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_R$T_T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_R$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_R$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_R$T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_R$T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_r_src_1 ,opr_preDes);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_I$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_I$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$R_R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$R_R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_I$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_I$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$R_T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$R_T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_I$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_I$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$T_R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$T_R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_I$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_I$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$T_T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$T_T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_preDes);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_preDes);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_M$R_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_M$R_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$R_R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$R_R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_M$R_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_M$R_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$R_T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$R_T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_r_des_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_M$M_R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_M$M_R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_REG& opr_r_des_1 = * ((OPR_REG*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$T_R$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$T_R$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_r_des_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_M$M_M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_M$M_M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_MEM& opr_m_des_1 = * ((OPR_MEM*)desPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
    OPR_TREG opr_preDes_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$T_T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$T_T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_preDes, opr_preDes_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_stl_1->addTemDep(uop_uop_comp_0);
    uop_uop_stl_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_1 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_1->addMeta(opr_preDes_1 ,opr_m_des_1);
    uop_uop_sth_1->addTemDep(uop_uop_comp_0);
    uop_uop_sth_1->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_1);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM128_ALU$M_M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM128_ALU$M_M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
    OPR_TREG opr_preDes;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldh_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ldl_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_0 = new SIM128_ALU$T_T$T$5();
    uop_uop_comp_0->addMeta(opr_t_0, opr_t_1 ,opr_preDes);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_0->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_0->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_comp_1 = new SIM128_ALU$T_T$T$5();
    uop_uop_comp_1->addMeta(opr_t_0, opr_t_1 ,opr_preDes);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_0);
    uop_uop_comp_1->addTemDep(uop_uop_ldh_1);
    uop_uop_comp_1->addTemDep(uop_uop_ldl_1);
    results.push_back(uop_uop_comp_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_0);
    uop_uop_stl_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_preDes ,opr_m_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_0);
    uop_uop_sth_0->addTemDep(uop_uop_comp_1);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM_MOV$R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM_MOV$R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_x_des_0 = * ((OPR_REG*)desPool[0]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_REG$R$R$1();
    uop_uop_st_0->addMeta(opr_r_src_0 ,opr_x_des_0);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM_MOV$R$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM_MOV$R$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_x_des_0 = * ((OPR_MEM*)desPool[0]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$R$M$99();
    uop_uop_st_0->addMeta(opr_r_src_0 ,opr_x_des_0);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM_MOV$I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM_MOV$I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_x_des_0 = * ((OPR_REG*)desPool[0]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$R$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_x_des_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM_MOV$I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM_MOV$I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_x_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_t_0 ,opr_x_des_0);
    uop_uop_st_0->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM_MOV$M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM_MOV$M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_x_des_0 = * ((OPR_REG*)desPool[0]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$R$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_x_des_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM_MOV$M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM_MOV$M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_x_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_st_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_st_0->addMeta(opr_t_0 ,opr_x_des_0);
    uop_uop_st_0->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_st_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM_MOV128$R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM_MOV128$R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_des_0 = * ((OPR_REG*)desPool[0]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_REG$R$R$1();
    uop_uop_sth_0->addMeta(opr_r_src_0 ,opr_r_des_0);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM_MOV128$R$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM_MOV128$R$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_des_0 = * ((OPR_MEM*)desPool[0]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$R$M$99();
    uop_uop_sth_0->addMeta(opr_r_src_0 ,opr_m_des_0);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$R$M$99();
    uop_uop_stl_0->addMeta(opr_r_src_0 ,opr_m_des_0);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM_MOV128$I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM_MOV128$I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_x_des_0 = * ((OPR_REG*)desPool[0]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$R$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_x_des_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM_MOV128$I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM_MOV128$I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_x_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldh_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ldl_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_t_0 ,opr_x_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_ldh_0);
    uop_uop_sth_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_t_0 ,opr_x_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_ldh_0);
    uop_uop_stl_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM_MOV128$M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM_MOV128$M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_x_des_0 = * ((OPR_REG*)desPool[0]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$R$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_x_des_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void SIM_MOV128$M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["SIM_MOV128$M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_x_des_0 = * ((OPR_MEM*)desPool[0]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldh_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldh_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldh_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ldl_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ldl_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ldl_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_sth_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_sth_0->addMeta(opr_t_0 ,opr_x_des_0);
    uop_uop_sth_0->addTemDep(uop_uop_ldh_0);
    uop_uop_sth_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_sth_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_stl_0 = new MOV_MEM_ST$T$M$99();
    uop_uop_stl_0->addMeta(opr_t_0 ,opr_x_des_0);
    uop_uop_stl_0->addTemDep(uop_uop_ldh_0);
    uop_uop_stl_0->addTemDep(uop_uop_ldl_0);
    results.push_back(uop_uop_stl_0);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$R_R$::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["CMP_SIM_ALU$R_R$"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_cmp = new CMP_SIM_ALU$R_R$$1();
    uop_uop_cmp->addMeta(opr_r_src_0, opr_r_src_1 );
    results.push_back(uop_uop_cmp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$R_I$::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["CMP_SIM_ALU$R_I$"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_cmp = new CMP_SIM_ALU$R_T$$1();
    uop_uop_cmp->addMeta(opr_r_src_0, opr_t_1 );
    uop_uop_cmp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_cmp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$R_M$::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["CMP_SIM_ALU$R_M$"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_cmp = new CMP_SIM_ALU$R_T$$1();
    uop_uop_cmp->addMeta(opr_r_src_0, opr_t_1 );
    uop_uop_cmp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_cmp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$I_R$::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["CMP_SIM_ALU$I_R$"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_cmp = new CMP_SIM_ALU$T_R$$1();
    uop_uop_cmp->addMeta(opr_t_0, opr_r_src_1 );
    uop_uop_cmp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_cmp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$I_I$::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["CMP_SIM_ALU$I_I$"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_cmp = new CMP_SIM_ALU$T_T$$1();
    uop_uop_cmp->addMeta(opr_t_0, opr_t_1 );
    uop_uop_cmp->addTemDep(uop_uop_ld_0);
    uop_uop_cmp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_cmp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$I_M$::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["CMP_SIM_ALU$I_M$"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_IMM& opr_i_src_0 = * ((OPR_IMM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_0->addMeta(opr_i_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_cmp = new CMP_SIM_ALU$T_T$$1();
    uop_uop_cmp->addMeta(opr_t_0, opr_t_1 );
    uop_uop_cmp->addTemDep(uop_uop_ld_0);
    uop_uop_cmp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_cmp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$M_R$::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["CMP_SIM_ALU$M_R$"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_r_src_1 = * ((OPR_REG*)srcPool[1]);
    OPR_TREG opr_t_0;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_cmp = new CMP_SIM_ALU$T_R$$1();
    uop_uop_cmp->addMeta(opr_t_0, opr_r_src_1 );
    uop_uop_cmp->addTemDep(uop_uop_ld_0);
    results.push_back(uop_uop_cmp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$M_I$::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["CMP_SIM_ALU$M_I$"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i_src_1 = * ((OPR_IMM*)srcPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LDI$I$T$1();
    uop_uop_ld_1->addMeta(opr_i_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_cmp = new CMP_SIM_ALU$T_T$$1();
    uop_uop_cmp->addMeta(opr_t_0, opr_t_1 );
    uop_uop_cmp->addTemDep(uop_uop_ld_0);
    uop_uop_cmp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_cmp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void CMP_SIM_ALU$M_M$::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["CMP_SIM_ALU$M_M$"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m_src_0 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_m_src_1 = * ((OPR_MEM*)srcPool[1]);
    OPR_TREG opr_t_0;
    OPR_TREG opr_t_1;
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_0 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_0->addMeta(opr_m_src_0 ,opr_t_0);
    results.push_back(uop_uop_ld_0);
///////////////////////////////////////////////////////////////////
    auto uop_uop_ld_1 = new MOV_MEM_LD$M$T$6();
    uop_uop_ld_1->addMeta(opr_m_src_1 ,opr_t_1);
    results.push_back(uop_uop_ld_1);
///////////////////////////////////////////////////////////////////
    auto uop_uop_cmp = new CMP_SIM_ALU$T_T$$1();
    uop_uop_cmp->addMeta(opr_t_0, opr_t_1 );
    uop_uop_cmp->addTemDep(uop_uop_ld_0);
    uop_uop_cmp->addTemDep(uop_uop_ld_1);
    results.push_back(uop_uop_cmp);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void JMP_SIM_ALU$R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["JMP_SIM_ALU$R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r_src_0 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_reg_des_1 = * ((OPR_REG*)desPool[0]);
///////////////////////////////////////////////////////////////////
    auto uop_uop_jmp = new JMP_SIM_ALU$R$R$1();
    uop_uop_jmp->addMeta(opr_r_src_0 ,opr_reg_des_1);
    results.push_back(uop_uop_jmp);
///////////////////////////////////////////////////////////////////

}
