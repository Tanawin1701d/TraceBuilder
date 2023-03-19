//
// Created by tanawin on 2/3/2566.
//

#ifndef TRACEBUILDER_TRACE_MANAGER_H
#define TRACEBUILDER_TRACE_MANAGER_H

#include "tracerFrontEnd/traceToolFed.h"
#include "resultFrontEnd/resultFed.h"
#include "tracers/uop_wd.h"
#include "tracers/tracer.h"
#include "resMng/memMng/MemMng.h"

#include "../models/thread_model/thread_model.h"


class TRACE_MANAGER{
private:

    /////////////////// end point
    ////////// trace tool
    TRACE_TOOL_FRONT_END* traceTool;
    ////////// result front-end
    RESULT_FRONT_END* resFed;
    /////////////////// resource director
    ////////// resource manager
    MEM_MNG* memMng;
    /////////////////// trace worker component
    ////////// tracer
    TRACER_BASE* tracer;
    ////////// instruction window
    UOP_WINDOW* uopWindow;
    ////////// thread model
    THREAD_MODEL* threadModel;

public:

    TRACE_MANAGER(
            THREAD_ID             _tid,
            TRACE_TOOL_FRONT_END* _traceTool,
            RESULT_FRONT_END*     _resFed,
            MEM_MNG*              _memMng,
            int                   _obsSize);

    ~TRACE_MANAGER();

    void start();


};

#endif //TRACEBUILDER_TRACE_MANAGER_H
