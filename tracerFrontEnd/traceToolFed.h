//
// Created by tanawin on 14/2/2566.
//

#ifndef TRACEBUILDER_TRACETOOLFED_H
#define TRACEBUILDER_TRACETOOLFED_H

#include "staticTraceVar.h"
#include "dynTraceVar.h"
#include "../components/thread_model/thread_model.h"

class TRACER_BASE;
class CORE;

typedef void (CORE::*sendStTraceData)         (staticTraceData, THREAD_ID);
typedef void (TRACER_BASE::*sendDynTraceData) (dynTraceData);


///// for now we assume that stream front-end and file front end share same input trace function
class TRACE_TOOL_FRONT_END{
private:
TRACER_BASE*     tracer;
CORE*            core;
sendStTraceData  staticTraceListener;
sendDynTraceData dynTraceListener;
public:

void setStaticTraceCallBack( sendStTraceData _staticTraceListener,
                             CORE*           _corelistener);
void setDynTraceCallBadck  (sendDynTraceData _dynTraceListener,
                            TRACER_BASE*     _tracer);

};

#endif //TRACEBUILDER_TRACETOOLFED_H
