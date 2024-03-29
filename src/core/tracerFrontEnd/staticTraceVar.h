//
// Created by tanawin on 7/2/2566.
//

#ifndef TRACEBUILDER_STATICTRACEVAR_H
#define TRACEBUILDER_STATICTRACEVAR_H
#include<iostream>
#include <vector>

namespace traceBuilder::core {


///// this is used for define and explain static trace file

/// this file is used track for each line of static trace outcome whatever architecture
//// global index
    static const int ST_IDX_COMPO_TYP = 0; // static trace component type
    static const int ST_IDX_DIRO = 1; // static trace direction
//// register operand index
    static const int ST_IDX_REG_R = 2; // static trace register name
    static const int ST_IDX_REG_AMT = 3; // static trace amount of token for interpret reg operand
//// load operand
    static const int ST_IDX_LOAD_RS  = 2; // static trace segment register name
    static const int ST_IDX_LOAD_RB  = 3; // static trace base register name
    static const int ST_IDX_LOAD_RI  = 4; // static trace index register name
    static const int ST_IDX_LOAD_SZ  = 5; // staticc trace load operand type
    static const int ST_IDX_LOAD_MON = 6; // static trace memory op number
    static const int ST_IDX_LOAD_AMT = 7; // static trace amount of token for interpret load operand

//// store operand
    static const int ST_IDX_STORE_RS  = 2; // static trace segment register name
    static const int ST_IDX_STORE_RB  = 3; // static trace base register name
    static const int ST_IDX_STORE_RI  = 4; // static trace index register name
    static const int ST_IDX_STORE_SZ  = 5; // staticc trace store operand type
    static const int ST_IDX_STORE_MON = 6; // static trace memory op number // when pool load and memory together
    static const int ST_IDX_STORE_AMT = 7; // static trace amount of token for interpret store operand
//// imm operand
    static const int ST_IDX_IMM_IMM = 2; // static trace index of immediate value
    static const int ST_IDX_IMM_AMT = 3; // static trace amount of index for immediate operand

//// fetch metadata
    static const int ST_IDXL_FETCH_TYPE = 0;
    static const int ST_IDX_FETCH_ID = 2; // instruction io (uniq for each program but may be same in different program)
    static const int ST_IDX_FETCH_VADDR = 3; // virtual address of the instruction
    static const int ST_IDX_FETCH_SZ = 4; // instruction size
    static const int ST_IDX_FETCH_MNEUMIC = 5; // mnuemic id
    static const int ST_IDX_FETCH_AMT = 6; // static trace amount of token for interpret fetch operand

//// debug metadata
    static const int ST_IDX_DEBUG_DECKEY = 1; // decode key to match with decoder
    static const int ST_IDX_DEBUG_INSTR = 2; // index that pintool actually recorded
    static const int ST_IDX_DEBUG_AMT = 3; // minimum amount of token in debug line string

/////////////////////////////////////////////////////////////////////////////////////
/// this section is used to identify the each tokens
//// direction
    static const std::string ST_VAL_DIRO_SRC = "S";
    static const std::string ST_VAL_DIRO_DES = "D";
//// component type
    static const std::string ST_VAL_COMPO_REG = "R";
    static const std::string ST_VAL_COMPO_LD = "L";
    static const std::string ST_VAL_COMPO_ST = "S";
    static const std::string ST_VAL_COMPO_IMM = "I";
    static const std::string ST_VAL_COMPO_FETCH = "F";
    static const std::string ST_VAL_COMPO_DEC = "N"; ///pintool also generates decoder key but we do not use it
    static const std::string ST_VAL_COMPO_SPT = "---------------------------------"; ///pintool also generates seperator for static trace but we not use it
//// markunused for load store operand
    static const std::string ST_VAL_LD_UNSED_REG = "-1";

/////////////////////////////////////////////////////////////////////////////////////
//// this is used for call static tracer
    struct staticTraceData {
        std::vector<std::string> rawData;
        ////// this is used for each instruction
        ///// others data that we reccord from dynamic pintool will be filled here.
    };


}
#endif //TRACEBUILDER_STATICTRACEVAR_H
