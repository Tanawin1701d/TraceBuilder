//
// Created by tanawin on 25/5/2566.
//

#ifndef TRACEBUILDER_DEPHELPBASE_H
#define TRACEBUILDER_DEPHELPBASE_H

#include "models/uop_model/uop_base.h"

namespace traceBuilder::core {

    using namespace traceBuilder::model;

    class UOP_WINDOW;

    class DEP_HELP_BASE {


    public:

        virtual void onPushToWd(UOP_BASE *uop, UOP_WINDOW *wd) = 0;

        virtual void onPopFromWd(UOP_BASE *uop, UOP_WINDOW *wd) = 0;

        virtual void assignDepHelp(UOP_BASE *uop, UOP_WINDOW *wd) = 0;
    };

}

#endif //TRACEBUILDER_DEPHELPBASE_H
