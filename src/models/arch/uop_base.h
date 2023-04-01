//
// Created by tanawin on 12/2/2566.
//

#ifndef TRACEBUILDER_UOP_BASE_H
#define TRACEBUILDER_UOP_BASE_H


#include "dep.h"
#include "models/inst_model/operand.h"
#include "stat/statPool.h"

class RT_INSTR;
class UOP_WINDOW;

enum UOP_TYPE{
    UOP_COMP,
    UOP_LOAD,
    UOP_STORE,
    UOP_IMM,
    UOP_DUMMY
};

class UOP_BASE: public REG_DEP, public MEM_DEP, public EXE_DEP, public TEM_DEP{
private:
    uint64_t seqNum;// sequence number of uop in each thread
public:
    UOP_TYPE uop_type;
public:
    UOP_TYPE getUopType() const;

    void setUopType(UOP_TYPE uopType);

public:
    UOP_BASE(UOP_TYPE _uop_type);
    virtual  ~UOP_BASE() = default;
    uint64_t getSeqNum() const;
    void     setSeqNum(uint64_t _seqNum);

    //// use to ask successor to check dependecy and store ourself dependency
    virtual void doDepenCheck(UOP_WINDOW* uop_window) = 0;

};

//////////// simple compute uop

class UOP_SIMPLE : public UOP_BASE{

public:
    //// for construction uop
    UOP_SIMPLE(UOP_TYPE _uop_type) : UOP_BASE(_uop_type) {};
    //// for this uop to ask other in instruction window that it depend on
    void doDepenCheck(UOP_WINDOW* uop_window) override;

};


#endif //TRACEBUILDER_UOP_BASE_H
