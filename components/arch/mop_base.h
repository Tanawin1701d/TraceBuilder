//
// Created by tanawin on 21/2/2566.
//

#ifndef TRACEBUILDER_MOP_BASE_H
#define TRACEBUILDER_MOP_BASE_H

#include "uop_base.h"

class RT_INSTR;

class MOP_BASE{
protected:
    RT_INSTR* rt_instr{};
public:
    void set_rt_instr(RT_INSTR* _rt_instr);
    virtual vector<UOP_BASE*> genUop() = 0;

};

class MOP_SIMPLE :public MOP_BASE{

public:
    vector<UOP_BASE*> genUop() override;
};

#endif //TRACEBUILDER_MOP_BASE_H