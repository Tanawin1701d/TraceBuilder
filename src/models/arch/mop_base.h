//
// Created by tanawin on 21/2/2566.
//

#ifndef TRACEBUILDER_MOP_BASE_H
#define TRACEBUILDER_MOP_BASE_H

#include "uop_base.h"
#include "stat/statPool.h"

class RT_INSTR;

typedef uint64_t MOP_ID;

class MOP_BASE{

public:
    MOP_ID getMopId() const;

    void setMopId(MOP_ID mopId);

public:
    virtual ~MOP_BASE() = default;
    //// results is used to return to micro-op to trace rt_instr
    virtual  void genUop(std::vector<UOP_BASE*>& results,
                         RT_INSTR* _rt_instr) = 0;



};

class MOP_SIMPLE :public MOP_BASE{

public:
    void  genUop(std::vector<UOP_BASE*>& results,
                 RT_INSTR*          rt_instr) override;
};

#endif //TRACEBUILDER_MOP_BASE_H
