#include"X86_mop.h"
#include"models/inst_model/rt_instr.h"



void MOP_COMP$M_I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["MOP_COMP$M_I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m1 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i2 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_stdes = * ((OPR_MEM*)desPool[0]);
    OPR_TREG& opr_t1 = * ((OPR_TREG*)new OPR_TREG());
    OPR_TREG& opr_t2 = * ((OPR_TREG*)new OPR_TREG());
    OPR_TREG& opr_rdes = * ((OPR_TREG*)new OPR_TREG());
///////////////////////////////////////////////////////////////////
    auto uop_mov_Uop = new MOV$M$T();
    uop_mov_Uop->addMeta( opr_m1 , opr_t1);
///////////////////////////////////////////////////////////////////
    auto uop_mov_Uop2 = new MOV$I$T();
    uop_mov_Uop2->addMeta( opr_i2 , opr_t2);
///////////////////////////////////////////////////////////////////
    auto uop_alu_uop = new COMP$T_T$T();
    uop_alu_uop->addMeta( opr_t1, opr_t2 , opr_rdes);
    uop_alu_uop->addTemDep(uop_alu_uop);
    uop_alu_uop->addTemDep(uop_alu_uop);
///////////////////////////////////////////////////////////////////
    auto uop_st_uop = new MOV$T$M();
    uop_st_uop->addMeta( opr_rdes , opr_stdes);
    uop_st_uop->addTemDep(uop_st_uop);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void MOP_COMP$M_M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["MOP_COMP$M_M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m1 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_i2 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_stdes = * ((OPR_MEM*)desPool[0]);
    OPR_TREG& opr_t1 = * ((OPR_TREG*)new OPR_TREG());
    OPR_TREG& opr_t2 = * ((OPR_TREG*)new OPR_TREG());
    OPR_TREG& opr_rdes = * ((OPR_TREG*)new OPR_TREG());
///////////////////////////////////////////////////////////////////
    auto uop_mov_Uop = new MOV$M$T();
    uop_mov_Uop->addMeta( opr_m1 , opr_t1);
///////////////////////////////////////////////////////////////////
    auto uop_mov_Uop2 = new MOV$M$T();
    uop_mov_Uop2->addMeta( opr_i2 , opr_t2);
///////////////////////////////////////////////////////////////////
    auto uop_alu_uop = new COMP$T_T$T();
    uop_alu_uop->addMeta( opr_t1, opr_t2 , opr_rdes);
    uop_alu_uop->addTemDep(uop_alu_uop);
    uop_alu_uop->addTemDep(uop_alu_uop);
///////////////////////////////////////////////////////////////////
    auto uop_st_uop = new MOV$T$M();
    uop_st_uop->addMeta( opr_rdes , opr_stdes);
    uop_st_uop->addTemDep(uop_st_uop);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void MOP_COMP$R_I$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["MOP_COMP$R_I$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r1 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i1 = * ((OPR_IMM*)srcPool[1]);
    OPR_MEM& opr_stdes = * ((OPR_MEM*)desPool[0]);
    OPR_TREG& opr_t1 = * ((OPR_TREG*)new OPR_TREG());
    OPR_TREG& opr_rdes = * ((OPR_TREG*)new OPR_TREG());
///////////////////////////////////////////////////////////////////
    auto uop_mov_Uop = new MOV$I$T();
    uop_mov_Uop->addMeta( opr_i1 , opr_t1);
///////////////////////////////////////////////////////////////////
    auto uop_alu_uop = new COMP$R_T$T();
    uop_alu_uop->addMeta( opr_r1, opr_t1 , opr_rdes);
    uop_alu_uop->addTemDep(uop_alu_uop);
///////////////////////////////////////////////////////////////////
    auto uop_st_uop = new MOV$T$M();
    uop_st_uop->addMeta( opr_rdes , opr_stdes);
    uop_st_uop->addTemDep(uop_st_uop);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void MOP_COMP$R_M$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["MOP_COMP$R_M$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r1 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m1 = * ((OPR_MEM*)srcPool[1]);
    OPR_MEM& opr_stdes = * ((OPR_MEM*)desPool[0]);
    OPR_TREG& opr_t1 = * ((OPR_TREG*)new OPR_TREG());
    OPR_TREG& opr_rdes = * ((OPR_TREG*)new OPR_TREG());
///////////////////////////////////////////////////////////////////
    auto uop_mov_Uop = new MOV$M$T();
    uop_mov_Uop->addMeta( opr_m1 , opr_t1);
///////////////////////////////////////////////////////////////////
    auto uop_alu_uop = new COMP$R_T$T();
    uop_alu_uop->addMeta( opr_r1, opr_t1 , opr_rdes);
    uop_alu_uop->addTemDep(uop_alu_uop);
///////////////////////////////////////////////////////////////////
    auto uop_st_uop = new MOV$T$M();
    uop_st_uop->addMeta( opr_rdes , opr_stdes);
    uop_st_uop->addTemDep(uop_st_uop);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void MOP_COMP$R_R$M::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["MOP_COMP$R_R$M"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r1 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r2 = * ((OPR_REG*)srcPool[1]);
    OPR_MEM& opr_stdes = * ((OPR_MEM*)desPool[0]);
    OPR_TREG& opr_rdes = * ((OPR_TREG*)new OPR_TREG());
///////////////////////////////////////////////////////////////////
    auto uop_alu_uop = new COMP$R_R$T();
    uop_alu_uop->addMeta( opr_r1, opr_r2 , opr_rdes);
///////////////////////////////////////////////////////////////////
    auto uop_st_uop = new MOV$T$M();
    uop_st_uop->addMeta( opr_rdes , opr_stdes);
    uop_st_uop->addTemDep(uop_st_uop);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void MOP_COMP$M_I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["MOP_COMP$M_I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m1 = * ((OPR_MEM*)srcPool[0]);
    OPR_IMM& opr_i2 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_rdes = * ((OPR_REG*)desPool[0]);
    OPR_TREG& opr_t1 = * ((OPR_TREG*)new OPR_TREG());
    OPR_TREG& opr_t2 = * ((OPR_TREG*)new OPR_TREG());
///////////////////////////////////////////////////////////////////
    auto uop_mov_Uop = new MOV$M$T();
    uop_mov_Uop->addMeta( opr_m1 , opr_t1);
///////////////////////////////////////////////////////////////////
    auto uop_mov_Uop2 = new MOV$I$T();
    uop_mov_Uop2->addMeta( opr_i2 , opr_t2);
///////////////////////////////////////////////////////////////////
    auto uop_alu_uop = new COMP$T_T$R();
    uop_alu_uop->addMeta( opr_t1, opr_t2 , opr_rdes);
    uop_alu_uop->addTemDep(uop_alu_uop);
    uop_alu_uop->addTemDep(uop_alu_uop);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void MOP_COMP$M_M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["MOP_COMP$M_M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_m1 = * ((OPR_MEM*)srcPool[0]);
    OPR_MEM& opr_i2 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_rdes = * ((OPR_REG*)desPool[0]);
    OPR_TREG& opr_t1 = * ((OPR_TREG*)new OPR_TREG());
    OPR_TREG& opr_t2 = * ((OPR_TREG*)new OPR_TREG());
///////////////////////////////////////////////////////////////////
    auto uop_mov_Uop = new MOV$M$T();
    uop_mov_Uop->addMeta( opr_m1 , opr_t1);
///////////////////////////////////////////////////////////////////
    auto uop_mov_Uop2 = new MOV$M$T();
    uop_mov_Uop2->addMeta( opr_i2 , opr_t2);
///////////////////////////////////////////////////////////////////
    auto uop_alu_uop = new COMP$T_T$R();
    uop_alu_uop->addMeta( opr_t1, opr_t2 , opr_rdes);
    uop_alu_uop->addTemDep(uop_alu_uop);
    uop_alu_uop->addTemDep(uop_alu_uop);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void MOP_COMP$R_I$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["MOP_COMP$R_I$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r1 = * ((OPR_REG*)srcPool[0]);
    OPR_IMM& opr_i1 = * ((OPR_IMM*)srcPool[1]);
    OPR_REG& opr_rdes = * ((OPR_REG*)desPool[0]);
    OPR_TREG& opr_t1 = * ((OPR_TREG*)new OPR_TREG());
///////////////////////////////////////////////////////////////////
    auto uop_mov_Uop = new MOV$I$T();
    uop_mov_Uop->addMeta( opr_i1 , opr_t1);
///////////////////////////////////////////////////////////////////
    auto uop_alu_uop = new COMP$R_T$R();
    uop_alu_uop->addMeta( opr_r1, opr_t1 , opr_rdes);
    uop_alu_uop->addTemDep(uop_alu_uop);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void MOP_COMP$R_M$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["MOP_COMP$R_M$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r1 = * ((OPR_REG*)srcPool[0]);
    OPR_MEM& opr_m1 = * ((OPR_MEM*)srcPool[1]);
    OPR_REG& opr_rdes = * ((OPR_REG*)desPool[0]);
    OPR_TREG& opr_t1 = * ((OPR_TREG*)new OPR_TREG());
///////////////////////////////////////////////////////////////////
    auto uop_mov_Uop = new MOV$M$T();
    uop_mov_Uop->addMeta( opr_m1 , opr_t1);
///////////////////////////////////////////////////////////////////
    auto uop_alu_uop = new COMP$R_T$R();
    uop_alu_uop->addMeta( opr_r1, opr_t1 , opr_rdes);
    uop_alu_uop->addTemDep(uop_alu_uop);
///////////////////////////////////////////////////////////////////

}
///////////////////////////////////////////////////////////////



void MOP_COMP$R_R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["MOP_COMP$R_R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_REG& opr_r1 = * ((OPR_REG*)srcPool[0]);
    OPR_REG& opr_r2 = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_rdes = * ((OPR_REG*)desPool[0]);
///////////////////////////////////////////////////////////////////
    auto uop_alu_uop = new COMP$R_R$R();
    uop_alu_uop->addMeta( opr_r1, opr_r2 , opr_rdes);
///////////////////////////////////////////////////////////////////

}
