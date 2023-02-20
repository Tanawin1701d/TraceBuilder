//
// Created by tanawin on 24/12/2565.
//

#ifndef TRACEBUILDER_TRACER_H
#define TRACEBUILDER_TRACER_H

#include "../../components/thread_model/thread_model.h"
#include "uop_wd.h"
#include "../resMng/memMng/MemMng.h"
#include "../tracerFrontEnd/dynTraceVar.h"
#include "../../components/uop/decoder.h"

class TRACE_MANAGER;


class TRACER_BASE{
private:
    THREAD_ID tid;
    ///// trace owner
    TRACE_MANAGER* traceMng;
    /* thread frontend */
    /* result front end call back*/
    ////////// instruction window
    UOP_WINDOW* uopWindow;
    ////////// resource manager
    MEM_MNG* memMng;
    ////////// decoder
    DECODER* decoder;
    ////////// thread model
    THREAD_MODEL* threadModel;
public:
    TRACER_BASE(THREAD_ID tid,
                TRACE_MANAGER *traceMng,
                UOP_WINDOW *uopWindow,
                MEM_MNG *memMng,
                DECODER *decoder,
                THREAD_MODEL *threadModel);

    void onGetDynTraceValue(dynTraceData dyndata);

};

#endif //TRACEBUILDER_TRACER_H
