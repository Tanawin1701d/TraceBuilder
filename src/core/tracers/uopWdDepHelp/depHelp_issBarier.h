//
// Created by tanawin on 25/5/2566.
//

#ifndef TRACEBUILDER_DEPHELP_ISSBARIER_H
#define TRACEBUILDER_DEPHELP_ISSBARIER_H

#include"depHelpBase.h"
#include<deque>

class DEP_HELP_ISS_BARIER: DEP_HELP_BASE{
private:
    std::deque<UOP_BASE*> units[MAX_UNIT_ID];
    EXEC_UNIT_RES* exe_unit_info;
public:
    explicit DEP_HELP_ISS_BARIER(EXEC_UNIT_RES* _exe_unit_info);
    void onPushToWd   (UOP_BASE* uop, UOP_WINDOW* wd) override;
    void onPopFromWd  (UOP_BASE* uop, UOP_WINDOW* wd) override;
    void assignDepHelp(UOP_BASE* uop, UOP_WINDOW* wd) override;
};

#endif //TRACEBUILDER_DEPHELP_ISSBARIER_H
