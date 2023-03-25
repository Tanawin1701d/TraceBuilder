//
// Created by tanawin on 14/2/2566.
//

#ifndef TRACEBUILDER_TRACETOOLFED_H
#define TRACEBUILDER_TRACETOOLFED_H

#include <fstream>
#include <cassert>
#include "core/tracers/tracer.h"

class THREAD_MODEL;

///// for now we assume that stream front-end and file front end share same input trace function
class TRACE_TOOL_FRONT_END{
protected:
    THREAD_MODEL*    tmd; // for static trace to send static instruction to build runtime instruction
    TRACER_BASE*     tracer; // for runtime trace; the runtime data will be integrate with
    // runtime instruction to generate precise micro op

public:

    TRACE_TOOL_FRONT_END();

    void setListenners(THREAD_MODEL* _tmd, TRACER_BASE* _tracer);

    virtual ~TRACE_TOOL_FRONT_END();

    virtual void start() = 0;

};

#endif //TRACEBUILDER_TRACETOOLFED_H
