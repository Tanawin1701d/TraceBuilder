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

class UOP_WINDOW{
private:
    std::deque<UOP_BASE*> uop_window;
    int window_size;
    DEP_HELP_REG depHelpReg;
    DEP_HELP_ISS_BARIER depHelpIssBar;
    std::vector<DEP_HELP_BASE*> depHelperPool;
    bool isFull();
    void tryPopFromQ();
    /////// dependency helper
public:
    UOP_WINDOW(int _window_size, EXEC_UNIT_RES* exeUnit_pool);
    void addUop(UOP_BASE* newUop);
    std::deque<UOP_BASE*>* getUopwindow() { return &uop_window;}
    ////// represent an proxy function
    void assignRegDep(UOP_BASE* uop)  { depHelpReg.assignDepHelp(uop, this);}
    void assignExecDep(UOP_BASE* uop) { depHelpIssBar.assignDepHelp(uop, this);}

};