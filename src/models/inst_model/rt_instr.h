//
// Created by tanawin on 28/12/2565.
//

#ifndef TRACEBUILDER_RT_INSTR_H
#define TRACEBUILDER_RT_INSTR_H


////// runtime instr it like dynamic instruction in gem5

#include "operand.h"

#include "core/tracerFrontEnd/staticTraceVar.h"
#include "core/tracerFrontEnd/dynTraceVar.h"
#include "ioHelp/strHelp.h"
#include "models/arch/mop_base.h"

typedef uint64_t RT_INSTR_ID;

///////////////// !=====IMPORTANT=====!
////////////////////// every class member must be
////////////////////// referred in copy constructor to prevent data missing

class RT_INSTR{
private:
    const std::string DEC_REG_OPR = "R";
    const std::string DEC_LD_OPR  = "M";
    const std::string DEC_ST_OPR  = "M";
    const std::string DEC_IMM_OPR = "I";
    const std::string DEC_DILEM   = "$";


    /////// id and identifier
    uint64_t              rt_instr_id{};
    /////// for debug and provide information
    std::string              mnemonic;
    std::string              srcDecodeKey;
    std::string              desDecodeKey;
    std::string              debugDecodeKey;
    std::string              debugName; //// the instruction that obtain from raw data
    /////// instruction metadata
    //[[maybe_unused]]
    ADDR                addr{};
    int                 size{};
    /////// src operand data and metadata
    std::vector<REG_OPERAND> srcRegOperands;
    std::vector<LD_OPERAND>  srcLdOperands;
    std::vector<IMM_OPERAND> srcImmOperands;
    /////// pool operand to allow macro-op access in correct order
    std::vector<OPERAND*>    srcMacroPoolOperands; /// pool the  src operand for macroop will get it and fill into micro-op
    /////// des operand data and metadata
    /// for now we assume that order is matter to classify instruction and micro-op
    std::vector<REG_OPERAND> desRegOperands;
    std::vector<ST_OPERAND>  desStOperands;
    /////// pool operand to allow macro-op access in correct order
    std::vector<OPERAND*>    desMacroPoolOperands;/// pool the  des operand for macroop will get it and fill into micro-op
    /////// macro-op
    MOP_BASE*                macroop{};


protected:

    /// interpret operand for each type from raw data that recieve from pintool
    virtual void interpretRegOperand(std::vector<std::string>& tokens, size_t& lstSrcMacroIdx, size_t& lstDesMacroIdx);
    virtual void interpretLOperand  (std::vector<std::string>& tokens, size_t& lstSrcMacroIdx, size_t& lstDesMacroIdx);
    virtual void interpretSOperand  (std::vector<std::string>& tokens, size_t& lstSrcMacroIdx, size_t& lstDesMacroIdx);
    virtual void interpretLSOperand (std::vector<std::string>& tokens, bool isLoad, size_t& lstSrcMacroIdx, size_t& lstDesMacroIdx);
    virtual void interpretImmOperand(std::vector<std::string>& tokens);
    virtual void interpretFetch     (std::vector<std::string>& tokens);
    virtual void interpretDebugStr  (std::vector<std::string>& tokens);

public:
    RT_INSTR ( RT_INSTR& host); ///copy constructor
    RT_INSTR (); /// vanila constructor
    virtual ~RT_INSTR() = default;
    ///////// entry point to interpret single instruction
    void     interpretStaticTracedData(const std::vector<std::string>& st_raw); // interpret from raw static tracer
    ///////// fill dynamic data tracing
    void     fillDynData(CVT_RT_OBJ& cvtDynData);
    ///////// generate uop    /////// HOTSPOT
    void     genUOPS(std::vector<UOP_BASE*>& results);

    uint64_t           getRtInstrId()      const {return rt_instr_id;};
    const std::string& getMnemonic()       const {return mnemonic;};
    const std::string  getDebugDecodeKey() const {return debugDecodeKey;};
    const std::string  getDebugName()      const {return debugName;};
    ADDR               getAddr()           const {return addr;};
    int                getSize()           const {return size;};
    std::string        getDecodeKey();
    ////// get method
    std::vector<REG_OPERAND>& getSrcRegOperands()       { return srcRegOperands;};
    std::vector<LD_OPERAND>&  getSrcLdOperands()        { return srcLdOperands ;};
    std::vector<IMM_OPERAND>& getSrcImmOperands()       { return srcImmOperands;};
    std::vector<OPERAND*>&    getSrcMacroPoolOperands() { return srcMacroPoolOperands;};
    std::vector<REG_OPERAND>& getDesRegOperands()       { return desRegOperands;};
    std::vector<ST_OPERAND>&  getDesStOperands()        { return desStOperands ;};
    std::vector<OPERAND*>&    getDesMacroPoolOperands() { return desMacroPoolOperands;};
    MOP_BASE*                 getMacroop()              { return macroop;};



    ////// count method
    int countSrcRegOperands() const { return (int)srcRegOperands.size();};
    int countSrcLdOpeands() const   { return (int)srcLdOperands .size();};
    int countSrcImmOperands() const { return (int)srcImmOperands.size();};
    int countDesRegOperands() const { return (int)desRegOperands.size();};
    int countDesStOperands() const  { return (int)desStOperands .size();};
    /// set method
    void setMacroop(MOP_BASE* _macroop) { macroop = _macroop; }

};


#endif //TRACEBUILDER_RT_INSTR_H
