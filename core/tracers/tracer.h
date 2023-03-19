//
// Created by tanawin on 24/12/2565.
//

#ifndef TRACEBUILDER_TRACER_H
#define TRACEBUILDER_TRACER_H

#include "uop_wd.h"
#include "core/resMng/memMng/MemMng.h"
#include "core/tracerFrontEnd/dynTraceVar.h"
#include "core/resultFrontEnd/resultFed.h"
////// models include
#include "models/arch/decoder.h"
#include "models/thread_model/thread_model.h"
#include "models/inst_model/rt_instr.h"
#include "models/arch/decoder.h"
#include "models/arch/mop_base.h"
#include "models/arch/uop_base.h"


class TRACE_MANAGER;


class TRACER_BASE{
private:
    THREAD_ID tid;
    ///// trace owner
    TRACE_MANAGER* traceMng;
    ///// result front-end for tracer to inform the result
    RESULT_FRONT_END* resFed;
    ////////// instruction window
    UOP_WINDOW* uopWindow;
    ////////// resource manager
    MEM_MNG* memMng;
    ////////// thread model
    THREAD_MODEL* threadModel;
    ///////// run time instruction cache map
    unordered_map<RT_INSTR_ID, RT_INSTR*> rt_instr_cache;
    ///////// current uop that being generated from uops
    vector<UOP_BASE*> inflight_uops;
public:
    TRACER_BASE(THREAD_ID          _tid,
                TRACE_MANAGER*     _traceMng,
                RESULT_FRONT_END*  _resFed,
                UOP_WINDOW*        _uopWindow,
                MEM_MNG*           _memMng,
                THREAD_MODEL*      _threadModel);

    void onGetDynTraceValue(dynTraceData dyndata) ;

};

#endif //TRACEBUILDER_TRACER_H
