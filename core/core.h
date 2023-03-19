//
// Created by tanawin on 14/2/2566.
//

#ifndef TRACEBUILDER_CORE_H
#define TRACEBUILDER_CORE_H


#include "trace_manager.h"

class CORE{
private:
    THREAD_ID last_tid;
    vector<TRACE_MANAGER> traceWorkers;
    MEM_MNG* memMng;

public:
    CORE(MEM_MNG* _memMng);
    void addTraceWorker(TRACE_TOOL_FRONT_END* _trace_tool,
                        RESULT_FRONT_END*     _result_frontEnd,
                        int                   _obsSize
                        );
    void start(bool parallel);

};


#endif //TRACEBUILDER_CORE_H
