#include "analyser/simd_instr.h"


void tryCollectSimdMeta(INS ins, SIMD_INSTR_ARG& result){
    //xed_category_enum_t category = (xed_category_enum_t)INS_Category(ins);

    result.isSimd = true;

    // if (category == XED_CATEGORY_MMX){
    //     result.length = L64;
    //     result.mnemonic = "V64";
    // }else if (category == XED_CATEGORY_AVX){
    //     result.length = L128;
    //     result.mnemonic = "V128";

    // }else if (category == XED_CATEGORY_AVX2){
    //     result.length = L256;
    //     result.mnemonic = "V256";
    // }else if (category == XED_CATEGORY_AVX512){
    //     result.length = L512;
    //     result.mnemonic = "V512";
    // }else{
    //     result.isSimd = false;
    //     return;
    // }

    /** check by using operand instead*/
    bool isMMx = false;
    bool isMemRefLowerEq64 = false;
    uint32_t maxOprSize = 0;
    UINT32 numOperands = INS_OperandCount(ins);
    UINT32 memOp       = 0;
    

    for (UINT32 opIdx = 0; opIdx < numOperands; opIdx++){
        if (INS_OperandIsReg(ins, opIdx)){
            REG  reg   = INS_OperandReg    (ins, opIdx);
            if (reg != REG_INVALID()){
                uint32_t operandSize = REG_Size(reg);
                maxOprSize = std::max(operandSize, maxOprSize);
                isMMx = isMMx || REG_is_mm(reg);
            }
        }else if (INS_OperandIsMemory(ins,opIdx)){
            UINT32 memRefSize = INS_MemoryOperandSize(ins, memOp);
            memOp++;

            isMemRefLowerEq64 |= (memRefSize <= REG_64_SIZE);
        }
    }
    /** check operand type*/
    std::string memRefSuffix = isMemRefLowerEq64 ? SIMDL_MREFOVD: "";

    if (maxOprSize >= REG_512_SIZE){
        result.length = L512;
        result.mnemonic = SIMDL_512 + memRefSuffix;
    }else if (maxOprSize >= REG_256_SIZE){
        result.length = L256;
        result.mnemonic = SIMDL_256 + memRefSuffix;
    }else if (maxOprSize >= REG_128_SIZE){
        result.length = L128;
        result.mnemonic = SIMDL_128 + memRefSuffix;
    }else if (isMMx){
        result.length = L64;
        result.mnemonic = SIMDL_64;
    }else{
        result.isSimd = false;
        return;
    }
    /******************************************/

    /*** check wheather it is floating point*/
    const std::vector<string> FLT_SUFFIX  = {"PS$", "PD$", "SS$", "SD$"};
    std::string raw_mnemonic = INS_Mnemonic(ins) + "$";
    bool foundFlt = false;

    /** find suffix*/
    for (const std::string& fltSuffix: FLT_SUFFIX){
        if (raw_mnemonic.find(fltSuffix) != std::string::npos){
            foundFlt = true;
        }
    }

    /*** check type*/
    if (foundFlt){
        result.type = SIMD_TYPE::FLT;
        result.mnemonic += "_" + SIMDT_FLT;
    }else{
        result.type = SIMD_TYPE::INTE;
        result.mnemonic += "_" + SIMDT_INT;
    }


    const std::string MUL = "MUL";
    const std::string DIV = "DIV";
    const std::string MOV = "MOV";


    /** check optype*/
    if (raw_mnemonic.find(MOV) != std::string::npos){
        /** we found mov instruction 555*/
        result.opType = SIMD_OPTYPE::MOV;
        result.mnemonic += "_" + SIMDOPT_MOV;
    }else if (raw_mnemonic.find(MUL) != std::string::npos){
        result.opType = SIMD_OPTYPE::MUL;
        result.mnemonic += "_" + SIMDOPT_MUL;
    }else if (raw_mnemonic.find(DIV) != std::string::npos){
        result.opType = SIMD_OPTYPE::DIV;
        result.mnemonic += "_" + SIMDOPT_DIV;
    }else{
        result.opType = SIMD_OPTYPE::ALU;
        result.mnemonic += "_" + SIMDOPT_ALU;
    }

}