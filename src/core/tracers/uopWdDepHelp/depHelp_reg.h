//
// Created by tanawin on 25/5/2566.
//

#ifndef TRACEBUILDER_DEPHELP_REG_H
#define TRACEBUILDER_DEPHELP_REG_H

#include"depHelpBase.h"

namespace traceBuilder::core {


    class DEP_HELP_REG : public DEP_HELP_BASE {
    private:
        ////// last uop that fill data to the regId
        UOP_BASE *lastOwnerReg[MAXMREG_AMT]; /// use regId as index to access array
    public:
        DEP_HELP_REG();

        void onPushToWd(UOP_BASE *uop, UOP_WINDOW*  wd) override;

        void onPopFromWd(UOP_BASE *uop,  UOP_WINDOW* wd) override;

        void assignDepHelp(UOP_BASE *uop, UOP_WINDOW*  wd) override;
    };

}

#endif //TRACEBUILDER_DEPHELP_REG_H
