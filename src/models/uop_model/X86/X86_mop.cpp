#include"X86_mop.h"
#include"models/inst_model/rt_instr.h"



namespace traceBuilder::model {



using namespace stat;




void MPREFIX$M_R$R::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){
    MAIN_STAT["mopGen"]["MPREFIX$M_R$R"].asUINT()++;
    auto srcPool = _rt_instr->getSrcMacroPoolOperands();
    auto desPool = _rt_instr->getDesMacroPoolOperands();
    OPR_MEM& opr_loadOpr1 = * ((OPR_MEM*)srcPool[0]);
    OPR_REG& opr_regOprload = * ((OPR_REG*)srcPool[1]);
    OPR_REG& opr_storeOpr1 = * ((OPR_REG*)desPool[0]);
    OPR_TREG opr_loadTemp1 = OPR_TREG(START_TREGID + 0);
///////////////////////////////////////////////////////////////////
    auto uop_testLoadUop = new MOVCXX$M$T$0();
    uop_testLoadUop->addMeta(opr_loadOpr1, opr_loadTemp1, 0, 4, false);
    results.push_back(uop_testLoadUop);
///////////////////////////////////////////////////////////////////
    auto uop_testCompUop = new COMPUOP$T_R$R$0();
    uop_testCompUop->addMeta(opr_loadTemp1, opr_regOprload, opr_storeOpr1, false);
    uop_testCompUop->addDep<DEP_TEMP>(uop_testLoadUop, nullptr);
    results.push_back(uop_testCompUop);
///////////////////////////////////////////////////////////////////

}

}
