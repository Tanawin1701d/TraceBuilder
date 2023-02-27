//
// Created by tanawin on 28/12/2565.
//

#ifndef TRACEBUILDER_RT_INSTR_H
#define TRACEBUILDER_RT_INSTR_H


////// runtime instr it like dynamic instruction in gem5

#include "operand.h"
#include "opcode.h"

#include"../../core/tracers/tracer.h"
#include "../../core/tracerFrontEnd/staticTraceVar.h"
#include "../../ioHelp/strHelp.h"
#include "../arch/mop_base.h"

class RT_INSTR{
private:
    const string DEC_REG_OPR = "R";
    const string DEC_LD_OPR  = "L";
    const string DEC_ST_OPR  = "S";
    const string DEC_IMM_OPR = "I";
    const string DEC_DILEM   = "$";


    /////// id and identifier
    uint64_t              rt_instr_id{};
    /////// for debug and provide information
    string              mnemonic;
    string              srcDecodeKey;
    string              desDecodeKey;
    /////// instruction metadata
    [[maybe_unused]]
    OPCODE              opc;
    ADDR                addr{};
    int                 size{};
    /////// src operand data and metadata
    vector<REG_OPERAND> srcRegOperands;
    vector<LD_OPERAND>  srcLdOperands;
    vector<IMM_OPERAND> srcImmOperands;
    /////// pool operand to allow macro-op access in correct order
    vector<OPERAND*>    srcMacroPoolOperands; /// pool the  src operand for macroop will get it and fill into micro-op


    /////// des operand data and metadata
    /// for now we assume that order is matter to classify instruction and micro-op
    vector<REG_OPERAND> desRegOperands;
    vector<ST_OPERAND>  desStOperands;
    /////// pool operand to allow macro-op access in correct order
    vector<OPERAND*>    desMacroPoolOperands;/// pool the  des operand for macroop will get it and fill into micro-op
    /////// macro-op
    MOP_BASE*           macroop{};


protected:

    /// interpret operand for each type from raw data that recieve from pintool
    virtual void interpretRegOperand(vector<string>& tokens, size_t& lstSrcMacroIdx, size_t& lstDesMacroIdx);
    virtual void interpretLOperand (vector<string>& tokens, size_t& lstSrcMacroIdx, size_t& lstDesMacroIdx);
    virtual void interpretSOperand (vector<string>& tokens, size_t& lstSrcMacroIdx, size_t& lstDesMacroIdx);
    virtual void interpretLSOperand (vector<string>& tokens, bool isLoad, size_t& lstSrcMacroIdx, size_t& lstDesMacroIdx);
    virtual void interpretImmOperand(vector<string>& tokens);
    virtual void interpretFetch  (vector<string>& tokens);

public:
    /// interpret instruction
    RT_INSTR( RT_INSTR& host);
    virtual ~RT_INSTR() = default;
    RT_INSTR(); // static trace raw
    void     interpretSt(const vector<string>& st_raw); // interpret from raw static tracer
    void     fillDynData(convertedDynData& cvtDynData);
    void     genUOPS(vector<UOP_BASE*>& results);
    /// getter
    uint64_t getRtInstrId() const;
    const string &getMnemonic() const;
    OPCODE getOpc() const;
    ADDR getAddr() const;
    int getSize() const;
    string getDecodeKey();
    ////// get method
    vector<REG_OPERAND>& getSrcRegOperands()    { return srcRegOperands;};
    vector<LD_OPERAND>& getSrcLdOperands()      { return srcLdOperands ;};
    vector<IMM_OPERAND>& getSrcImmOperands()    { return srcImmOperands;};
    vector<OPERAND*>& getSrcMacroPoolOperands()      { return srcMacroPoolOperands;};
    vector<REG_OPERAND>& getDesRegOperands()    { return desRegOperands;};
    vector<ST_OPERAND>& getDesStOperands()      { return desStOperands ;};
    vector<OPERAND*>& getDesMacroPoolOperands()      { return desMacroPoolOperands;};
    ////// count method
    int countSrcRegOperands() const { return srcRegOperands.size();};
    int countSrcLdOpeands() const   { return srcLdOperands .size();};
    int countSrcImmOperands() const { return srcImmOperands.size();};
    int countDesRegOperands() const { return desRegOperands.size();};
    int countDesStOperands() const  { return desStOperands .size();};
    /// set method
    void setMacroop(MOP_BASE* _macroop) { macroop = _macroop; }

};


#endif //TRACEBUILDER_RT_INSTR_H
