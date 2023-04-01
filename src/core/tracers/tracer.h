//
// Created by tanawin on 24/12/2565.
//

#ifndef TRACEBUILDER_TRACER_H
#define TRACEBUILDER_TRACER_H

#include "uop_wd.h"

#include "core/resMng/memMng/MemMng.h"
#include "core/tracerFrontEnd/dynTraceVar.h"
#include "core/resultFrontEnd/resultFed.h"
///////////////////////////////
//////    models include   ////
///////////////////////////////
#include "models/arch/decoder.h"
#include "models/thread_model/thread_model.h"
#include "models/inst_model/rt_instr.h"
#include "models/arch/decoder.h"
#include "models/arch/mop_base.h"
#include "models/arch/uop_base.h"

#include "stat/statPool.h"


class TRACE_MANAGER;


class TRACER_BASE{
private:
    ////////// thread id
    THREAD_ID tid;
    ////////// result front-end for tracer to inform the result
    RESULT_FRONT_END* resFed;
    ////////// instruction window
    UOP_WINDOW* uopWindow;
    ///////// decoder
    DECODER_BASE* decoder;
    ////////// resource manager
    MEM_MNG* memMng;
    ////////// thread model
    THREAD_MODEL* threadModel;
    ///////// run time instruction cache map
    std::vector<RT_INSTR*> rt_instrs; //// idex is rt_id
    ///////// current uop that being generated from uops
    std::vector<UOP_BASE*> inflight_uops;
    ///////// nextUopId
    uint64_t nextMopId;
public:
    TRACER_BASE(THREAD_ID          _tid,
                RESULT_FRONT_END*  _resFed,
                UOP_WINDOW*        _uopWindow,
                DECODER_BASE*      _decoder,
                MEM_MNG*           _memMng,
                THREAD_MODEL*      _threadModel);

    void cvtLoadOrStoreToPhyAddr(RT_OBJ&           rt_obj,
                                 RT_INSTR&         rt_instr,
                                 CVT_RT_OBJ& results,
                                 bool              isLoad);

    void cvt_rtobj_tracable(RT_OBJ&           rt_obj,
                            RT_INSTR&         rt_instr,
                            CVT_RT_OBJ& results);
    /// when trace frontend get runtime tracing value
    void onGetDynTraceValue(dynTraceData dyndata) ;
    /// when trace frontend need to initialize trace worker
    void onInitialize(uint64_t lastRTinstr); /// it is used when tracefront end was initialized

};

#endif //TRACEBUILDER_TRACER_H