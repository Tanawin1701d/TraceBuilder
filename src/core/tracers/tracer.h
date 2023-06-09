//
// Created by tanawin on 24/12/2565.
//

#ifndef TRACEBUILDER_TRACER_H
#define TRACEBUILDER_TRACER_H

#include "uop_wd.h"

#include "core/tracerFrontEnd/dynTraceVar.h"
#include "core/resultFrontEnd/resultFed.h"
///////////////////////////////
//////    models include   ////
///////////////////////////////
#include "models/res_model/memMng/MemMng.h"
#include "models/uop_model/decoder.h"
#include "models/thread_model/thread_model.h"
#include "models/inst_model/rt_instr.h"
#include "models/uop_model/mop_base.h"
#include "models/uop_model/uop_base.h"

#include "stat/statPool.h"
#include "ioHelp/strHelp.h"


namespace traceBuilder::core {

    class TRACER_BASE {
    private:
        SHARED_TRACEINFO* sharedSimEle;
        SPECIFIC_TRACEINFO* specificSimEle;
        ///////// run time instruction cache map
        std::vector<RT_INSTR *> rt_instrs; //// idex is rt_id
        ///////// current uop that being generated from uops
        std::vector<UOP_BASE *> inflight_uops;

    public:
        TRACER_BASE(CORE* _core,
                    SHARED_TRACEINFO* _sharedInfo,
                    SPECIFIC_TRACEINFO* _specificInfo
                    );

        void cvtLoadOrStoreToPhyAddr(RT_OBJ &rt_obj,
                                     RT_INSTR &rt_instr,
                                     CVT_RT_OBJ &results,
                                     bool isLoad);

        void cvt_rtobj_tracable(RT_OBJ &rt_obj,
                                RT_INSTR &rt_instr,
                                CVT_RT_OBJ &results);

        uint64_t genSeqNum_fromIdx(size_t idx);

        /// when trace frontend get runtime tracing value
        void onGetDynTraceValue(dynTraceData dyndata);

        /// when trace frontend need to initialize trace worker
        void onInitialize(uint64_t lastRTinstr); /// it is used when tracefront end was initialized

    };

}

#endif //TRACEBUILDER_TRACER_H