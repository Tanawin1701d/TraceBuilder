#ifndef __ANALYSER_SIMD_INSTR_H__
#define __ANALYSER_SIMD_INSTR_H__

#include "pin.H"
#include "instlib.H"

#include "writer/writer.h"
#include "analyser/instruFunc.h"


/*** we use instrument shared injector with simple alu 
 * but give the forced mnemonic argument to alu
 */
enum SIMD_LENGTH{
    L64,
    L128,
    L256,
    L512
};
const std::string SIMDL_64  = "V64";
const std::string SIMDL_128 = "V128";
const std::string SIMDL_256 = "V256";
const std::string SIMDL_512 = "V512";


enum SIMD_TYPE{
    INTE, /** operator */
    FLT, /** floating point operantion*/
    MOV, /** data movement*/
    
};
const std::string SIMDT_INT = "INT";
const std::string SIMDT_FLT = "FLT";
const std::string SIMDT_MOV = "MOV";


enum SIMD_OPTYPE{
    ALU,
    MUL,
    DIV,
    OPTYPE_DUMMY  
    //,
    //MOV mov is should not be declared
};
const std::string SIMDOPT_ALU = "ALU";
const std::string SIMDOPT_MUL = "MUL";
const std::string SIMDOPT_DIV = "DIV";
const std::string SIMDOPT_MOV = "MOV";

struct SIMD_INSTR_ARG{
    SIMD_LENGTH length;
    SIMD_TYPE   type;
    SIMD_OPTYPE opType;
    bool        isSimd = false;
    std::string mnemonic;
};

void tryCollectSimdMeta(INS ins, SIMD_INSTR_ARG& result);


#endif