//
// Created by tanawin on 28/12/2565.
//
#include "rt_instr.h"
#include <utility>

//////////////// public method

RT_INSTR::RT_INSTR(RT_INSTR& host) :
    rt_instr_id(host.rt_instr_id),
    mnemonic(host.mnemonic),
    opc(host.opc),
    addr(host.addr),
    size(host.size),
    srcRegOperands(host.srcRegOperands),
    srcLdOperands(host.srcLdOperands),
    srcImmOperands(host.srcImmOperands),
    desRegOperands(host.desRegOperands),
    desStOperands(host.desStOperands)
{}

RT_INSTR::RT_INSTR() {
    //// we might use dummy opcode
}

void
RT_INSTR::interpretSt(const vector<string>& st_raw) {
    for (auto& opr_raw: st_raw){
        vector<string> opr_tokens;
        splitNstrip(opr_raw, opr_tokens);
        assert(opr_tokens.size() > 2);
        ///// check operand type and interpret them
        if (opr_tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_REG){
            interpretRegOperand(opr_tokens);
        }else if (opr_tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_LD){
            interpretLOperand(opr_tokens);
        }else if (opr_tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_ST){
            interpretSOperand(opr_tokens);
        }else if (opr_tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_IMM){
            interpretImmOperand(opr_tokens);
        }else if (opr_tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_FETCH){
            interpretFetch(opr_tokens);
        }else{
            throw invalid_argument("there is no operand or any indicator : " + opr_tokens[ST_IDX_COMPO_TYP]);
        }
    }

}


void
RT_INSTR::fillDynData(convertedDynData& cvtDynData){

    ////////// fill physical address of each load operand
    for (int ldIdx = 0 ;
             (ldIdx < maxMemOpPerLS)  &&
             (cvtDynData.loadMemOpNum[ldIdx] != DUMMY_MEM_OP_NUM);
             ldIdx++
        ){
        assert(cvtDynData.loadMemOpNum[ldIdx] < srcLdOperands.size());
        ////// for backward compatability
        /////// we assume that memop may be reordered arbitrary.
        srcLdOperands[ cvtDynData.loadMemOpNum[ldIdx] ].setPhyAddr(cvtDynData.phyLoadAddr[ldIdx]);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////
    ////////// fill physical address of each store operand
    for (int stIdx = 0 ;
         (stIdx < maxMemOpPerLS)  &&
         (cvtDynData.storeMemOpNum[stIdx] != DUMMY_MEM_OP_NUM);
         stIdx++
            ){
        assert(cvtDynData.storeMemOpNum[stIdx] < desStOperands.size());
        ////// for backward compatability
        /////// we assume that memop may be reordered arbitrary.
        desStOperands[ cvtDynData.storeMemOpNum[stIdx]].setPhyAddr(cvtDynData.phyStoreAddr[stIdx]);
    }

}
//////////////// internal method
void
RT_INSTR::interpretRegOperand(vector<string> &tokens) {
    assert(tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_REG);
    assert(tokens.size() == ST_IDX_REG_AMT);

    //// check direction of the operand whether it is store or
    bool isSrc = tokens[ST_IDX_DIRO] == ST_VAL_DIRO_SRC;
    bool isDes = tokens[ST_IDX_DIRO] == ST_VAL_DIRO_DES;
    REGNUM newRegName = regMapAutoAdd(tokens[ST_IDX_REG_R]);

    if (isSrc){
        srcRegOperands.emplace_back(newRegName);
        srcPoolOperands.push_back(&(*srcRegOperands.rbegin()));
    }else if ( isDes ){
        desRegOperands.emplace_back(newRegName);
        desPoolOperands.push_back(&(*desRegOperands.rbegin()));
    }else{
        throw std::invalid_argument(
                "invalid static trace for reg operand " + tokens[ST_IDX_DIRO]
                );
    }
}

/// TODO for now load and store operand share same raw format so we will use pool function instead
void
RT_INSTR::interpretLSOperand(vector<string> &tokens, bool isLoad) {
    //// check direction of the operand whether it is store or
    bool isSrc = tokens[ST_IDX_DIRO] == ST_VAL_DIRO_SRC;
    bool isDes = tokens[ST_IDX_DIRO] == ST_VAL_DIRO_DES;
    ///please reminde that register for load and store instruction may be unused which mean it will return as -1
    //// index base register
    REGNUM baseReg  = (tokens[ST_IDX_LOAD_RB] != ST_VAL_LD_UNSED_REG) ? regMapAutoAdd(tokens[ST_IDX_LOAD_RB])
                                                                      : unusedReg;
    REGNUM indexReg = (tokens[ST_IDX_LOAD_RI] != ST_VAL_LD_UNSED_REG) ? regMapAutoAdd(tokens[ST_IDX_LOAD_RI])
                                                                      : unusedReg;
    /// TODO scale is hard wired to 4 byte
    int scale = 4;
    /// TODO displacement is hard wired to 0
    int displacement = 0;
    int size  = stoi(tokens[ST_IDX_LOAD_SZ]);
    int memopNum = stoi(tokens[ST_IDX_LOAD_MON]);
    ///build operand
    if (isLoad) {
        srcLdOperands.emplace_back(baseReg, indexReg, scale, displacement, size, memopNum);
        srcPoolOperands.push_back(&(*srcLdOperands.rbegin()));
    }
    else { // store
        desStOperands.emplace_back(baseReg, indexReg, scale, displacement, size, memopNum);
        desPoolOperands.push_back(&(*desStOperands.rbegin()));
    }
}

void
RT_INSTR::interpretLOperand(vector<string> &tokens) {
    assert(tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_LD);
    assert(tokens.size() == ST_IDX_LOAD_AMT);
    assert(tokens[ST_IDX_DIRO] == ST_VAL_DIRO_SRC);
    interpretLSOperand(tokens, true);

}

void
RT_INSTR::interpretSOperand(vector<string> &tokens) {
    assert(tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_ST);
    assert(tokens.size() == ST_IDX_STORE_AMT);
    assert(tokens[ST_IDX_DIRO] == ST_VAL_DIRO_DES);
    interpretLSOperand(tokens, false);

}

void
RT_INSTR::interpretImmOperand(vector<string>& tokens) {
    assert(tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_IMM);
    assert(tokens.size() == ST_IDX_IMM_AMT);
    assert(tokens[ST_IDX_DIRO] == ST_VAL_DIRO_SRC);
    IMM imm = stoull(tokens[ST_IDX_IMM_IMM]);

    srcImmOperands.emplace_back(imm);
    srcPoolOperands.push_back(&(*srcImmOperands.rbegin()));

}

void
RT_INSTR::interpretFetch(vector<string> &tokens) {
    assert(tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_IMM);
    assert(tokens.size() == ST_IDX_FETCH_AMT);
    assert(tokens[ST_IDX_DIRO] == ST_VAL_DIRO_SRC);

    rt_instr_id = stoull(tokens[ST_IDX_FETCH_ID]);
    addr        = stoull(tokens[ST_IDX_FETCH_VADDR]);
    size        = stoi(tokens[ST_IDX_FETCH_SZ]);
    mnemonic    = tokens[ST_IDX_FETCH_MNEUMIC];
}

///// getter


uint64_t RT_INSTR::getRtInstrId() const {
    return rt_instr_id;
}

const string &RT_INSTR::getMnemonic() const {
    return mnemonic;
}

OPCODE RT_INSTR::getOpc() const {
    return opc;
}

ADDR RT_INSTR::getAddr() const {
    return addr;
}

int RT_INSTR::getSize() const {
    return size;
}
