//
// Created by tanawin on 14/2/2566.
//

#ifndef TRACEBUILDER_INSTRWD_H
#define TRACEBUILDER_INSTRWD_H

#endif //TRACEBUILDER_INSTRWD_H

#include<deque>
#include "../../models/arch/uop_base.h"
#include "core/resMng/regMap/regMapper.h"
#include "core/tracers/uopWdDepHelp/depHelp_reg.h"
#include "core/tracers/uopWdDepHelp/depHelp_issBarier.h"

enum DEP_HELP_IDX {
    HELP_REG,
    HELP_ISS_BAR,
    HELP_SIZE

};


class UOP_WINDOW{
private:
    std::deque<UOP_BASE*> uop_window;
    int window_size;
    std::vector<DEP_HELP_BASE*> depHelperPool;
    bool isFull();
    void tryPopFromQ();
    /////// dependency helper
public:
    UOP_WINDOW(int _window_size, EXEC_UNIT_RES* exeUnit_pool);
    void addUop(UOP_BASE* newUop);
    std::deque<UOP_BASE*>* getUopwindow() { return &uop_window;}
    ////// represent an proxy function
    void assignRegDep(UOP_BASE* uop)  { depHelperPool[DEP_HELP_IDX::HELP_REG    ]->assignDepHelp(uop, this);}
    void assignExecDep(UOP_BASE* uop) { depHelperPool[DEP_HELP_IDX::HELP_ISS_BAR]->assignDepHelp(uop, this);}

};