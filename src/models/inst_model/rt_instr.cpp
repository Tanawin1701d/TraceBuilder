//
// Created by tanawin on 28/12/2565.
//
#include "rt_instr.h"
//////////////// public method



namespace traceBuilder::model {

    using namespace traceBuilder::core;

    RT_INSTR::RT_INSTR(RT_INSTR &host) :
            rt_instr_id(host.rt_instr_id),
            mnemonic(host.mnemonic),
            srcDecodeKey(host.srcDecodeKey),
            desDecodeKey(host.desDecodeKey),
            debugDecodeKey(host.debugDecodeKey),
            debugName(host.debugName),
            addr(host.addr),
            size(host.size),
            //// src operand
            srcRegOperands(host.srcRegOperands),
            srcLdOperands(host.srcLdOperands),
            srcImmOperands(host.srcImmOperands),

            //// des operand
            desRegOperands(host.desRegOperands),
            desStOperands(host.desStOperands),
            //// mopAgent
            _mopAgentPtr(nullptr)
            {}

    RT_INSTR::RT_INSTR() {
        //// we might use dummy opcode
    }

    RT_INSTR::~RT_INSTR(){
    }

    void
    RT_INSTR::interpretStaticTracedData(const std::vector<std::string> &st_raw) {
        size_t lstSrcMacroIdx = 0;
        size_t lstDesMacroIdx = 0;
        for (auto &opr_raw: st_raw) {
            std::vector<std::string> opr_tokens;
            util::splitNstrip(opr_raw, opr_tokens);
            ///// check operand type and interpret them
            if (opr_tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_REG) {
                interpretRegOperand(opr_tokens, lstSrcMacroIdx, lstDesMacroIdx);
            } else if (opr_tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_LD) {
                interpretLOperand(opr_tokens, lstSrcMacroIdx, lstDesMacroIdx);
            } else if (opr_tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_ST) {
                interpretSOperand(opr_tokens, lstSrcMacroIdx, lstDesMacroIdx);
            } else if (opr_tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_IMM) {
                interpretImmOperand(opr_tokens, lstSrcMacroIdx, lstDesMacroIdx);
            } else if (opr_tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_FETCH) {
                interpretFetch(opr_tokens);
            } else if (opr_tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_DEC) {
                interpretDebugStr(opr_tokens);
            } else if (opr_tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_SPT) {
                /// pass
            } else {
                throw std::invalid_argument("there is no operand or any indicator : " + opr_tokens[ST_IDX_COMPO_TYP]);
            }
        }

        /**make all operand referencable*/
        /** pool operand is not counted here because we add them for each interpret already*/
        srcRegOperandsPtr  = cvtToSharedRef<OPR_REG>(srcRegOperands);
        srcLdOperandsPtr   = cvtToSharedRef<OPR_MEM>(srcLdOperands);
        srcImmOperandsPtr  = cvtToSharedRef<OPR_IMM>(srcImmOperands);

        desRegOperandsPtr  = cvtToSharedRef<OPR_REG>(desRegOperands);
        desStOperandsPtr   = cvtToSharedRef<OPR_MEM>(desStOperands);
        /*************************************************************************************/





    }


    void
    RT_INSTR::fillDynData(RT_OBJ& rawDynData, CVT_RT_OBJ& cvtDynData) {
        ////////// fill physical address of each load operand
        assert(cvtDynData.amt_load == rawDynData.amt_load);
        for (int ldIdx = 0; ldIdx < cvtDynData.amt_load; ldIdx++) {
            ////// for backward compatability
            /////// we assume that memop may be reordered arbitrary.
            srcLdOperands[ldIdx].setPhyAddr(cvtDynData.phyLoadAddr[ldIdx]);
            srcLdOperands[ldIdx].setVirAddr(rawDynData.loadAddr[ldIdx]);////// <--- for virtual address
        }
        //////////////////////////////////////////////////////
        ////////// fill physical address of each store operand
        assert(cvtDynData.amt_store == rawDynData.amt_store);
        for (int stIdx = 0; stIdx < cvtDynData.amt_store; stIdx++) {
            ////// for backward compatability
            /////// we assume that memop may be reordered arbitrary.
            desStOperands[stIdx].setPhyAddr(cvtDynData.phyStoreAddr[stIdx]);
            desStOperands[stIdx].setVirAddr(rawDynData.storeAddr[stIdx]);/////// <--- for virtual address
        }
    }

    void
    RT_INSTR::genUOPS(std::vector<UOP_BASE *> &results) {
        assert(_mopAgentPtr != nullptr);
        //std::cout << "instr Id " << getRtInstrId() << "  got " << _mopAgentPtr->getUopCount() << std::endl;
        results = _mopAgentPtr->genUops();
    }

//////////////// internal method
    void
    RT_INSTR::interpretRegOperand(std::vector<std::string> &tokens, size_t &lstSrcMacroIdx, size_t &lstDesMacroIdx) {
        assert(tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_REG);
        assert(tokens.size() == ST_IDX_REG_AMT);

        //// check direction of the operand whether it is store or
        bool isSrc = tokens[ST_IDX_DIRO] == ST_VAL_DIRO_SRC;
        bool isDes = tokens[ST_IDX_DIRO] == ST_VAL_DIRO_DES;
        AREGNUM newRegName = regMapAutoAdd(tokens[ST_IDX_REG_R]);

        if (newRegName == UNUSED_AREG){
            return;
        }
        //std::shared_ptr<OPERAND>((OPERAND*)(&oprPtr));
        if (isSrc) {
            srcRegOperands.emplace_back(newRegName, lstSrcMacroIdx++);
            srcDecodeKey.push_back(DEC_REG_OPR);
        } else if (isDes) {
            desRegOperands.emplace_back(newRegName, lstDesMacroIdx++);
            desDecodeKey.push_back(DEC_REG_OPR);
        } else {
            throw std::invalid_argument(
                    "invalid static trace for reg operand " + tokens[ST_IDX_DIRO]
            );
        }
    }

/// TODO for now load and store operand share same raw format so we will use pool function instead
    void
    RT_INSTR::interpretLSOperand(std::vector<std::string> &tokens, bool isLoad, size_t &lstSrcMacroIdx,
                                 size_t &lstDesMacroIdx) {
        //// check direction of the operand whether it is store or
        bool isSrc = tokens[ST_IDX_DIRO] == ST_VAL_DIRO_SRC;
        bool isDes = tokens[ST_IDX_DIRO] == ST_VAL_DIRO_DES;
        /// for now load store indexing use the same id
        ///please reminde that register for load and store instruction may be unused which mean it will return as -1
        //// index base register
        AREGNUM segReg  = (tokens[ST_IDX_LOAD_RS] != ST_VAL_LD_UNSED_REG) ? regMapAutoAdd(tokens[ST_IDX_LOAD_RB]):
                                                                           UNUSED_AREG;

        AREGNUM baseReg = (tokens[ST_IDX_LOAD_RB] != ST_VAL_LD_UNSED_REG) ? regMapAutoAdd(tokens[ST_IDX_LOAD_RB])
                                                                         : UNUSED_AREG;
        AREGNUM indexReg = (tokens[ST_IDX_LOAD_RI] != ST_VAL_LD_UNSED_REG) ? regMapAutoAdd(tokens[ST_IDX_LOAD_RI])
                                                                          : UNUSED_AREG;
        /// TODO scale is hard wired to 4 byte
        int scale = 4;
        /// TODO displacement is hard wired to 0
        ADDR displacement = 0;
        ADDR opr_eff_size = stoi(tokens[ST_IDX_LOAD_SZ]);
        int memopNum = stoi(tokens[ST_IDX_LOAD_MON]);
        ///build operand

        MEM_META memMeta = {
                {0, opr_eff_size},
                {0, opr_eff_size},
                opr_eff_size,
                segReg,
                baseReg,
                indexReg,
                scale,
                0,
                false
        };

        if (isLoad) {

            srcLdOperands.emplace_back(memMeta, O_MEM_LD, lstSrcMacroIdx++);
            srcDecodeKey.push_back(DEC_LD_OPR);

        } else { // store
            desStOperands.emplace_back(memMeta, O_MEM_ST, lstDesMacroIdx++);
            desDecodeKey.push_back(DEC_ST_OPR);
        }
    }

///// intepret load operand
    void
    RT_INSTR::interpretLOperand(std::vector<std::string> &tokens, size_t &lstSrcMacroIdx, size_t &lstDesMacroIdx) {
        assert(tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_LD);
        assert(tokens.size() == ST_IDX_LOAD_AMT);
        assert(tokens[ST_IDX_DIRO] == ST_VAL_DIRO_SRC);
        interpretLSOperand(tokens, true, lstSrcMacroIdx, lstDesMacroIdx);

    }

///// intepret store operand
    void
    RT_INSTR::interpretSOperand(std::vector<std::string> &tokens, size_t &lstSrcMacroIdx, size_t &lstDesMacroIdx) {
        assert(tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_ST);
        assert(tokens.size() == ST_IDX_STORE_AMT);
        assert(tokens[ST_IDX_DIRO] == ST_VAL_DIRO_DES);
        interpretLSOperand(tokens, false, lstSrcMacroIdx, lstDesMacroIdx);

    }

    void
    RT_INSTR::interpretImmOperand(std::vector<std::string> &tokens, size_t &lstSrcMacroIdx, size_t &lstDesMacroIdx) {
        assert(tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_IMM);
        assert(tokens.size() == ST_IDX_IMM_AMT);
        assert(tokens[ST_IDX_DIRO] == ST_VAL_DIRO_SRC);
        IMM imm = stoull(tokens[ST_IDX_IMM_IMM]);

        srcImmOperands.emplace_back(imm, lstSrcMacroIdx++);
        srcDecodeKey.push_back(DEC_IMM_OPR);


    }

    void
    RT_INSTR::interpretFetch(std::vector<std::string> &tokens) {
        assert(tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_FETCH);
        assert(tokens.size() >= ST_IDX_FETCH_AMT);
        assert(tokens[ST_IDX_DIRO] == ST_VAL_DIRO_SRC);

        rt_instr_id = stoull(tokens[ST_IDX_FETCH_ID]);
        addr = util::hexStr2uint(tokens[ST_IDX_FETCH_VADDR]);
        //std::cout << addr << std::endl;
        size = stoi(tokens[ST_IDX_FETCH_SZ]);
        /// please remind that we must use upper case for mnemonic
        util::convertToUpperStr(tokens[ST_IDX_FETCH_MNEUMIC]);
        mnemonic = tokens[ST_IDX_FETCH_MNEUMIC];
        /////////////////////////////////////////
        stat::MAIN_STAT["staticTrace"][mnemonic].asUINT()++;
        /////////////////////////////////////////
    }

    void
    RT_INSTR::interpretDebugStr(std::vector<std::string> &tokens) {
        assert(tokens[ST_IDX_COMPO_TYP] == ST_VAL_COMPO_DEC);
        assert(tokens.size() >= ST_IDX_DEBUG_AMT);
        auto preConcatDebugName =
                std::vector<std::string>(tokens.begin() + ST_IDX_DEBUG_INSTR,
                                         tokens.end());
        debugDecodeKey = tokens[ST_IDX_DEBUG_DECKEY];
        debugName = util::concatVec(preConcatDebugName, " ");
    }

    std::string RT_INSTR::getDecodeKey() {
        return mnemonic + DEC_DILEM +
               util::concatVec(srcDecodeKey, DEC_DILEM_OPR) + DEC_DILEM +
               util::concatVec(desDecodeKey, DEC_DILEM_OPR);
    }

    void BIND_RT_INSTR(py::module& m){

        py::class_<RT_INSTR, std::shared_ptr<RT_INSTR>>(m, "INSTR")
                .def(py::init<>())
                .def(GET_RT_INSTR_MNEMONIC_FN_STR    , &RT_INSTR::GET_RT_INSTR_MNEMONIC_FN     )
                .def(GET_RT_INSTR_SRC_REG_OPR_FN_STR , &RT_INSTR::GET_RT_INSTR_SRC_REG_OPR_FN  )
                .def(GET_RT_INSTR_SRC_MEM_OPR_FN_STR , &RT_INSTR::GET_RT_INSTR_SRC_MEM_OPR_FN  )
                .def(GET_RT_INSTR_SRC_IMM_OPR_FN_STR , &RT_INSTR::GET_RT_INSTR_SRC_IMM_OPR_FN  )
                .def(GET_RT_INSTR_SRC_CNT_STR        , &RT_INSTR::GET_RT_INSTR_SRC_CNT         )

                .def(GET_RT_INSTR_DES_REG_OPR_FN_STR , &RT_INSTR::GET_RT_INSTR_DES_REG_OPR_FN  )
                .def(GET_RT_INSTR_DES_MEM_OPR_FN_STR , &RT_INSTR::GET_RT_INSTR_DES_MEM_OPR_FN  )
                .def(GET_RT_INSTR_DES_CNT_STR        , &RT_INSTR::GET_RT_INSTR_DES_CNT         )
                .def("getDecodeKey", &RT_INSTR::getDecodeKey);
    }

}