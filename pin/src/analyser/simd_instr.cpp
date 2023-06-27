#include "analyser/simd_instr.h"


void tryCollectSimdMeta(INS ins, SIMD_INSTR_ARG& result){
    xed_category_enum_t category = (xed_category_enum_t)INS_Category(ins);

    result.isSimd = true;

    if (category == XED_CATEGORY_MMX){
        result.length = L64;
        result.mnemonic = "V64";
    }else if (category == XED_CATEGORY_AVX){
        result.length = L128;
        result.mnemonic = "V128";

    }else if (category == XED_CATEGORY_AVX2){
        result.length = L256;
        result.mnemonic = "V256";
    }else if (category == XED_CATEGORY_AVX512){
        result.length = L512;
        result.mnemonic = "V512";
    }else{
        result.isSimd = false;
        return;
    }

    /*** check wheather it is floating point*/
    const std::string MOV = "MOV";
    const std::string FLT  ="PS";
    std::string raw_mnemonic = INS_Mnemonic(ins);

    /*** check type*/
    if (raw_mnemonic.find(MOV) != std::string::npos){
        /** we found mov instruction 555*/
        result.type = SIMD_TYPE::MOV;
        result.mnemonic += "_" + SIMDT_MOV;
    }else if (raw_mnemonic.size() >= 2 && 
              (raw_mnemonic.substr(raw_mnemonic.size()-2, 2) == FLT)
              ){
        result.type = SIMD_TYPE::FLT;
        result.mnemonic += "_" + SIMDT_FLT;
    }else{
        result.type = SIMD_TYPE::INTE;
        result.mnemonic += "_" + SIMDT_INT;
    }


    const std::string MUL = "MUL";
    const std::string DIV = "DIV";


    /** check optype*/
    if (raw_mnemonic.find(MUL) != std::string::npos){
        result.opType = SIMD_OPTYPE::MUL;
        result.mnemonic += "_" + SIMDOPT_MUL;
    }else if (raw_mnemonic.find(DIV) != std::string::npos){
        result.opType = SIMD_OPTYPE::DIV;
        result.mnemonic += "_" + SIMDOPT_DIV;
    }else if (result.type == SIMD_TYPE::MOV){
        result.opType = SIMD_OPTYPE::OPTYPE_DUMMY;
    }else{
        result.opType = SIMD_OPTYPE::ALU;
        result.mnemonic += "_" + SIMDOPT_ALU;
    }

}