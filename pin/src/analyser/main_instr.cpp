#include "analyser/main_instr.h"

int cur_fetchId = 0;

int getAndIncFetchId(){
    cur_fetchId++;
    return cur_fetchId-1;
}

// The Instruction function is called for every instruction
VOID MAIN_instrument(INS ins, VOID* v)
{

    std::string preWrite;

    if ( INS_IsNop(ins) ){
        return;
    }

    /** collect simd metadata*/
    SIMD_INSTR_ARG simdMeta;
    tryCollectSimdMeta(ins, simdMeta);

    
    //instruction
    std::string _instrName   = INS_Disassemble(ins);
    ADDRINT instrAddr        = INS_Address(ins);
    UINT32  instrSize        = INS_Size(ins);

    char buffer[32];
    sprintf(buffer, "%lx", instrAddr);
    std::string instrAddrHex(buffer);

    //mem_id counter
    UINT32 memOp = 0;
    UINT32 loaded_amt = 0;
    UINT32 stored_amt = 0;

    //decode string varible
    std::string srcKey;
    std::string desKey;
    std::string resKey;
    UINT32      opr_count = 0;

    // rflags register
    std::string rflagsStr = "rflags";

    ///////////////////////// for compute instruction
    UINT32 numOperands = INS_OperandCount(ins);
    uint32_t maxOprSize = 0;

    if (INS_IsLea(ins)){
        //////// this is conrner case that pintool not verbose anything about source of effective address
        std::string preRegStr;
        ////////////////
        ///////////    memory location = baseReg + (IndexReg * scale) + displacement
        //////// WRITE DES OPERAND
        REG desReg = INS_OperandReg(ins, 0);
        preRegStr += "R "; // source register
        preRegStr += "D "; // source register
        preRegStr += REG_StringShort(static_cast<REG>(desReg));
        preRegStr += "\n";
        desKey += "R";
        opr_count += 1;
        //////// WRITE BASE OPERAND
        REG srcReg1 = INS_OperandMemoryBaseReg(ins, 1);
        if (srcReg1 != REG_INVALID()){
            preRegStr += "R "; // source register
            preRegStr += "S "; // source register
            preRegStr += REG_StringShort(static_cast<REG>(srcReg1));
            preRegStr += "\n";
            srcKey += "R";
            opr_count += 1;
        }
        //////// WRITE Index OPERAND
        REG srcReg2 = INS_OperandMemoryIndexReg(ins, 1);
        if (srcReg2 != REG_INVALID()){
            preRegStr += "R "; // source register
            preRegStr += "S "; // source register
            preRegStr += REG_StringShort(static_cast<REG>(srcReg2));
            preRegStr += "\n";
            srcKey += "R";
            opr_count += 1;
        }
        preWrite += preRegStr;
    }else{

        for (UINT32 opIdx = 0; opIdx < numOperands; opIdx++){
            ////// register operand
            if (INS_OperandIsReg(ins, opIdx)){
                    bool isSrc = INS_OperandRead   (ins, opIdx);
                    bool isDes = INS_OperandWritten(ins, opIdx);
                    REG  reg   = INS_OperandReg    (ins, opIdx);
                    //if (reg != REG_RFLAGS)
                    assert(!INS_OperandIsMemory(ins, opIdx));
                    assert(isSrc || isDes);

                    /*** collect stat of operand type*/
                    if (reg != REG_INVALID()){
                        uint32_t operandSize = REG_Size(reg);
                        maxOprSize = std::max(operandSize, maxOprSize);
                    }

                    std::string preRegStr;

                    //////// WRITE REG OPERAND
                    preRegStr += "R "; // register
                    preRegStr += "X "; // source/des register
                    preRegStr += reg ? REG_StringShort(static_cast<REG>(reg)) : "-1";
                    preRegStr += "\n";

                    std::string regStr = REG_StringShort(static_cast<REG>(reg));

                    /////// flag register is ignore
                    if (isSrc && regStr != rflagsStr){
                        preRegStr[2]  = 'S';
                        preWrite     += preRegStr;
                        srcKey       += "_R";
                        opr_count++; //// this is used to help predict operand type x86
                    }
                    /////// flag register is ignore
                    if (isDes && regStr != rflagsStr){
                        preRegStr[2]  = 'D';
                        preWrite     += preRegStr;
                        desKey       += "_R";
                        opr_count++; //// this is used to help predict operand type x86
                    }
                ////////////////////////////////////////////////////////
                
            }else if (INS_OperandIsMemory(ins, opIdx)){

                ///////// for memory operand
                REG    segReg     = INS_OperandMemorySegmentReg(ins, opIdx); 
                REG    baseReg    = INS_OperandMemoryBaseReg   (ins, opIdx);
                REG    indexReg   = INS_OperandMemoryIndexReg  (ins, opIdx);
                bool   isLoad     = INS_MemoryOperandIsRead    (ins, memOp);
                bool   isStore    = INS_MemoryOperandIsWritten (ins, memOp);
                UINT32 memRefSize = INS_MemoryOperandSize      (ins, memOp);


                std::string preMemMetaStr;
                std::string lsSuffix = (REG_StringShort(static_cast<REG>(baseReg)) == "rip") ? "IP" : "";
                //////// WRITE LOAD STORE
                assert(isLoad || isStore);
                preMemMetaStr += " ";
                preMemMetaStr += segReg   ? REG_StringShort(static_cast<REG>(segReg)) : "-1";
                preMemMetaStr += " ";
                preMemMetaStr += baseReg  ? REG_StringShort(static_cast<REG>(baseReg)) : "-1";
                preMemMetaStr += " ";
                preMemMetaStr += indexReg ? REG_StringShort(static_cast<REG>(indexReg)) : "-1";
                preMemMetaStr += " ";
                preMemMetaStr += std::to_string(memRefSize);
                preMemMetaStr += " ";
                preMemMetaStr += std::to_string(memOp);
                preMemMetaStr += "\n";
                
                if (isLoad){
                    std::string preMemStr;
                    preMemStr  += "L";// +  lsSuffix;
                    preMemStr  += " S";
                    preMemStr  += preMemMetaStr;
                    preWrite   += preMemStr;
                    srcKey     += "_L" + lsSuffix;
                    assert(loaded_amt < maxMemOpPerLS);
                    INS_InsertPredicatedCall(ins, IPOINT_BEFORE, 
                                    (AFUNPTR)L_TRACE,
                                    IARG_MEMORYOP_EA, memOp,
                                    IARG_UINT32, loaded_amt,
                                    IARG_END
                                    );
                    loaded_amt++;
                }
                if (isStore){
                    std::string preMemStr;
                    preMemStr += "S"; // + lsSuffix;
                    preMemStr += " D";
                    preMemStr += preMemMetaStr;
                    preWrite  += preMemStr;
                    desKey    += "_S" + lsSuffix;
                    assert(stored_amt < maxMemOpPerLS);
                    INS_InsertPredicatedCall(ins, IPOINT_BEFORE, 
                                    (AFUNPTR)S_TRACE,
                                    IARG_MEMORYOP_EA, memOp,
                                    IARG_UINT32, stored_amt,
                                    IARG_UINT32, memOp,
                                    IARG_END
                                    );
                    stored_amt++;
                }
                //////////// add operand
                


                memOp++;
                opr_count++; //// this is used to help predict operand type x86
                ////////////////////////////////////////////////////////
             }else if (INS_OperandIsImmediate(ins, opIdx)){
                 /////////////////// immediate operand
                 std::string preImmStr;
                 preImmStr += "I S ";
                 preImmStr += std::to_string(INS_OperandImmediate(ins, opIdx));
                 preImmStr += '\n';
                 preWrite  += preImmStr;
                 srcKey    += "_I";
                 opr_count++;
             }
        }
    
    }
    //////// WRITE decode key and debug string
    resKey = "N " + INS_Mnemonic(ins) + "$" + srcKey + "$" + desKey + "  " + _instrName + " cate: " + xed_category_enum_t2str((xed_category_enum_t)INS_Category(ins)) + " oprSize: " + std::to_string(maxOprSize);
    preWrite += resKey + "\n";

    int INSTRID = getAndIncFetchId();
    ////////////////////////// for insert predicated of the end of instruction
    INS_InsertPredicatedCall(ins, IPOINT_BEFORE, 
                            (AFUNPTR)ButtomEachIntr,
                            IARG_UINT32, INSTRID,
                            IARG_CALL_ORDER, 
                            CALL_ORDER_LAST,
                            IARG_END
                            );

    //////// WRITE FETCH INSTRUCTION
    preWrite += "F S";
    preWrite += " ";
    preWrite += std::to_string(INSTRID);
    preWrite += " ";
    preWrite += "0x" + instrAddrHex;
    preWrite += " ";
    preWrite += std::to_string(instrSize);
    preWrite += " ";
    if (simdMeta.isSimd){
        preWrite += simdMeta.mnemonic;
    }else{
        preWrite += INS_Mnemonic(ins);
    }
    
    preWrite += "\n";
    /** write seperator*/
    preWrite += "---------------------------------\n";


    /*** write to file */
    writeStaticTraceFile(preWrite, true);

    
}