//
// Created by tanawin on 12/2/2566.
//

#ifndef TRACEBUILDER_UOP_BASE_H
#define TRACEBUILDER_UOP_BASE_H


#include "dep.h"
#include "../inst_model/operand.h"

class RT_INSTR;
class UOP_WINDOW;


class UOP_BASE: public REG_DEP, public MEM_DEP, public EXE_DEP, public TEM_DEP{
private:
    uint64_t seqNum;// sequence number of uop in each thread
public:
    uint64_t getSeqNum() const;
    void setSeqNum(uint64_t _seqNum);
    virtual void doDepenCheck(UOP_WINDOW* uop_window) = 0;

};

//////////// simple compute uop

class SIMPLE_COMP_REG_UOP : public UOP_BASE{
private:
    vector<REG_OPERAND> srcRegs;
    vector<REG_OPERAND> desRegs;
public:
    //// for construction uop
    SIMPLE_COMP_REG_UOP(vector<REG_OPERAND> _srcRegs, vector<REG_OPERAND> _desRegs );
    //// for successor to ask that is depend on
    bool isdependOnReg(const REGNUM& sucReg) override;
    //// for this uop to ask other in instruction window that it depend on
    void doDepenCheck(/*TODO pass instruction window*/) override;

    //// assign current instruction dependcy
    vector<REG_OPERAND>& getSrcRegs();
    vector<REG_OPERAND>& getDesRegs();

};

//////////// simple load uop

class SIMPLE_LOAD_UOP : public UOP_BASE{
private:
    LD_OPERAND srcLoad;
public:
    //// for construction uop
    SIMPLE_LOAD_UOP(LD_OPERAND _srcLoad );
    //// for successor to ask that is depend on
    bool isdependOnMem(const ADDR& sucAddr, int size, bool isLoad) override;
    //// for this uop to ask other in instruction window that it depend on
    void doDepenCheck(/*TODO pass instruction window*/) override;

    //// assign current instruction dependcy
    LD_OPERAND& getSrcLoad();

};

//////////// simple store uop

class SIMPLE_STORE_UOP : public UOP_BASE{
private:
    ST_OPERAND desStore;
public:
    //// for construction uop
    SIMPLE_STORE_UOP(ST_OPERAND _desStore );
    //// for successor to ask that is depend on
    bool isdependOnMem(const ADDR& sucAddr, int size, bool isLoad) override;
    //// for this uop to ask other in instruction window that it depend on
    void doDepenCheck(/*TODO pass instruction window*/) override;

    //// assign current instruction dependcy
    ST_OPERAND& getDesStore();

};

//////////// simple imm uop

class SIMPLE_IMM_UOP : public UOP_BASE{
private:
    IMM_OPERAND srcImm;
public:
    //// for construction uop
    SIMPLE_IMM_UOP(IMM_OPERAND _srcImm );
    //// there is no successor dependence
    //// for this uop to ask other in instruction window that it depend on
    void doDepenCheck(/*TODO pass instruction window*/) override;

    //// assign current instruction dependcy
    IMM_OPERAND& getSrcImm();

};

#endif //TRACEBUILDER_UOP_BASE_H
