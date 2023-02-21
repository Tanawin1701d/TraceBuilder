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

class RT_INSTR{
private:
    /////// id and identifier
    uint64_t              rt_instr_id;
    /////// for debug and provide information
    string              mnemonic;
    /////// instruction metadata
    [[maybe_unused]]
    OPCODE              opc;
    ADDR                addr;
    int                 size;
    /////// src operand data and metadata
        /// for now we assume that order is matter to unify instruction
    vector<REG_OPERAND> srcRegOperands;
    vector<LD_OPERAND>  srcLdOperands;
    vector<IMM_OPERAND> srcImmOperands;
    vector<OPERAND*>    srcPoolOperands; /// pool the  src operand for macroop will get it and fill into micro-op
    /////// des operand data and metadata
        /// for now we assume that order is matter to classify instruction and micro-op
    vector<REG_OPERAND> desRegOperands;
    vector<ST_OPERAND>  desStOperands;
    vector<OPERAND*>    desPoolOperands;/// pool the  des operand for macroop will get it and fill into micro-op
    /////// micro op
    //TODO store for micro-op

    /// index interpreter for raw file


protected:

    /// interpret operand for each type from raw data that recieve from pintool
    virtual void interpretRegOperand(vector<string>& tokens);
    virtual void interpretLOperand (vector<string>& tokens);
    virtual void interpretSOperand (vector<string>& tokens);
    virtual void interpretLSOperand (vector<string>& tokens, bool isLoad);
    virtual void interpretImmOperand(vector<string>& tokens);
    virtual void interpretFetch  (vector<string>& tokens);

public:
    /// interpret instruction
    RT_INSTR( RT_INSTR& host);
    RT_INSTR(); // static trace raw
    void     interpretSt(const vector<string>& st_raw); // interpret from raw static tracer
    void     fillDynData(convertedDynData& cvtDynData);
    /// getter
    uint64_t getRtInstrId() const;
    const string &getMnemonic() const;
    OPCODE getOpc() const;
    ADDR getAddr() const;
    int getSize() const;
    ////// get method
    vector<REG_OPERAND>& getSrcRegOperands()    { return srcRegOperands;};
    vector<LD_OPERAND>& getSrcLdOperands()      { return srcLdOperands ;};
    vector<IMM_OPERAND>& getSrcImmOperands()    { return srcImmOperands;};
    vector<OPERAND*>& getSrcPoolOperands()      { return srcPoolOperands;};
    vector<REG_OPERAND>& getDesRegOperands()    { return desRegOperands;};
    vector<ST_OPERAND>& getDesStOperands()      { return desStOperands ;};
    vector<OPERAND*>& getDesPoolOperands()      { return desPoolOperands;};
    ////// count method
    int countSrcRegOperands() const { return srcRegOperands.size();};
    int countSrcLdOpeands() const   { return srcLdOperands .size();};
    int countSrcImmOperands() const { return srcImmOperands.size();};
    int countDesRegOperands() const { return desRegOperands.size();};
    int countDesStOperands() const  { return desStOperands .size();};

};


#endif //TRACEBUILDER_RT_INSTR_H
