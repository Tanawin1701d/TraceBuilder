//
// Created by tanawin on 28/12/2565.
//
#include "rt_instr.h"
//////////////// public method

RT_INSTR::RT_INSTR(RT_INSTR& host) :
    rt_instr_id(host.rt_instr_id),
    mnemonic(host.mnemonic),
    srcDecodeKey(host.srcDecodeKey),
    desDecodeKey(host.desDecodeKey),
    addr(host.addr),
    size(host.size),
    //// src operand
    srcRegOperands(host.srcRegOperands),
    srcLdOperands(host.srcLdOperands),
    srcImmOperands(host.srcImmOperands),

    //// des operand
    desRegOperands(host.desRegOperands),
    desStOperands(host.desStOperands),

    macroop(host.macroop)
{

    //////// macro pool operand need index from self operand class
    /// build src macroPool Operands
    srcMacroPoolOperands.reserve(host.srcMacroPoolOperands.size());
    for (auto& oprPtr: srcRegOperands){
        srcMacroPoolOperands[oprPtr.getMcSideIdx()] = &oprPtr;
    }
    for (auto& oprPtr: srcLdOperands){
        srcMacroPoolOperands[oprPtr.getMcSideIdx()] = &oprPtr;
    }
    /// build des macrPool operand
    desMacroPoolOperands.reserve(host.desMacroPoolOperands.size());
    for (auto& oprPtr: desRegOperands){
        desMacroPoolOperands[oprPtr.getMcSideIdx()] = &oprPtr;
    }
    for (auto& oprPtr: desStOperands){
        desMacroPoolOperands[oprPtr.getMcSideIdx()] = &oprPtr;
    }
    ///////////////////////////////////////////////////////////////////////

}

RT_INSTR::RT_INSTR() {
    //// we might use dummy opcode
}

void
RT_INSTR::interpretSt(const vector<string>& st_raw) {
    size_t lstSrcMacroIdx = 0;
    size_t lstDesMacroIdx = 0;
    for (auto& opr_raw: st_raw){
        vector<string> opr_tokens;
        splitNstrip(opr_raw, opr_tokens);
        assert(opr_tokens.size() > 2);
        ///// check operand type and interpret them
        if (opr_tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_REG){
            interpretRegOperand(opr_tokens, lstSrcMacroIdx, lstDesMacroIdx);
        }else if (opr_tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_LD){
            interpretLOperand(opr_tokens, lstSrcMacroIdx, lstDesMacroIdx);
        }else if (opr_tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_ST){
            interpretSOperand(opr_tokens, lstSrcMacroIdx, lstDesMacroIdx);
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

void
RT_INSTR::genUOPS(vector<UOP_BASE *>& results) {
    assert(macroop != nullptr);
    macroop->genUop(results, this);
}
//////////////// internal method
void
RT_INSTR::interpretRegOperand(vector<string> &tokens, size_t& lstSrcMacroIdx, size_t& lstDesMacroIdx) {
    assert(tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_REG);
    assert(tokens.size() == ST_IDX_REG_AMT);

    //// check direction of the operand whether it is store or
    bool isSrc = tokens[ST_IDX_DIRO] == ST_VAL_DIRO_SRC;
    bool isDes = tokens[ST_IDX_DIRO] == ST_VAL_DIRO_DES;
    REGNUM newRegName = regMapAutoAdd(tokens[ST_IDX_REG_R]);

    if (isSrc){
        srcRegOperands.emplace_back(newRegName, lstSrcMacroIdx++);
        srcMacroPoolOperands.push_back(&(*srcRegOperands.rbegin()));
        srcDecodeKey = srcDecodeKey + DEC_REG_OPR;
    }else if ( isDes ){
        desRegOperands.emplace_back(newRegName, lstDesMacroIdx++);
        desMacroPoolOperands.push_back(&(*desRegOperands.rbegin()));
        desDecodeKey = desDecodeKey + DEC_REG_OPR;
    }else{
        throw std::invalid_argument(
                "invalid static trace for reg operand " + tokens[ST_IDX_DIRO]
                );
    }
}

/// TODO for now load and store operand share same raw format so we will use pool function instead
void
RT_INSTR::interpretLSOperand(vector<string> &tokens, bool isLoad, size_t& lstSrcMacroIdx, size_t& lstDesMacroIdx) {
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
        srcLdOperands.emplace_back(baseReg, indexReg,scale,
                                   displacement, size, memopNum,lstSrcMacroIdx++);
        srcMacroPoolOperands.push_back(&(*srcLdOperands.rbegin()));
        srcDecodeKey = srcDecodeKey + DEC_LD_OPR;
    }
    else { // store
        desStOperands.emplace_back(baseReg, indexReg, scale,
                                   displacement, size, memopNum, lstDesMacroIdx++);
        desMacroPoolOperands.push_back(&(*desStOperands.rbegin()));
        desDecodeKey = desDecodeKey + DEC_ST_OPR;
    }
}

///// intepret load operand
void
RT_INSTR::interpretLOperand(vector<string> &tokens, size_t& lstSrcMacroIdx, size_t& lstDesMacroIdx) {
    assert(tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_LD);
    assert(tokens.size() == ST_IDX_LOAD_AMT);
    assert(tokens[ST_IDX_DIRO] == ST_VAL_DIRO_SRC);
    interpretLSOperand(tokens, true, lstSrcMacroIdx, lstDesMacroIdx);

}

///// intepret store operand
void
RT_INSTR::interpretSOperand(vector<string> &tokens, size_t& lstSrcMacroIdx, size_t& lstDesMacroIdx) {
    assert(tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_ST);
    assert(tokens.size() == ST_IDX_STORE_AMT);
    assert(tokens[ST_IDX_DIRO] == ST_VAL_DIRO_DES);
    interpretLSOperand(tokens, false, lstSrcMacroIdx, lstDesMacroIdx);

}

void
RT_INSTR::interpretImmOperand(vector<string>& tokens) {
    assert(tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_IMM);
    assert(tokens.size() == ST_IDX_IMM_AMT);
    assert(tokens[ST_IDX_DIRO] == ST_VAL_DIRO_SRC);
    IMM imm = stoull(tokens[ST_IDX_IMM_IMM]);

    srcImmOperands.emplace_back(imm);
    srcDecodeKey = srcDecodeKey + DEC_IMM_OPR;
    //// we do not push to MacroPooloperand due to current version regardless about imm
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

string RT_INSTR::getDecodeKey(){
    return mnemonic     + DEC_DILEM  +
           srcDecodeKey + DEC_DILEM  +
           desDecodeKey;
}