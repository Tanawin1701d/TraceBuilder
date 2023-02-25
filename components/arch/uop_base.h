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
    virtual ~UOP_BASE() = default;
    uint64_t getSeqNum() const;
    void setSeqNum(uint64_t _seqNum);

    //// use to ask successor to check dependecy and store ourself dependency
    virtual void doDepenCheck(UOP_WINDOW* uop_window) = 0;
    //// use to occupy resource when this resource is executed
    virtual void doResOcp() {};

};

//////////// simple compute uop

class UOP_SIMPLE : public UOP_BASE{

public:
    //// for construction uop
    UOP_SIMPLE() = default;
    //// for this uop to ask other in instruction window that it depend on
    void doDepenCheck(UOP_WINDOW* uop_window) override;

};


#endif //TRACEBUILDER_UOP_BASE_H
