//
// Created by tanawin on 6/1/2566.
//

#ifndef TRACEBUILDER_THREAD_MODEL_H
#define TRACEBUILDER_THREAD_MODEL_H

#include "models/inst_model/rt_instr.h"
#include <sstream>
#include "models/res_model/regMap/regMapper.h"
//// [WARN] please beware about circular link
#include "core/tracerFrontEnd/staticTraceVar.h"
#include "core/tracerFrontEnd/dynTraceVar.h"

namespace traceBuilder::model {

    using namespace traceBuilder::core;

    typedef int THREAD_ID;

    class THREAD_MODEL {

    private:

        std::vector<RT_INSTR*> instrPool;


    public:
        explicit THREAD_MODEL();

        ~THREAD_MODEL();

        /////// get runtime instruction that not decoded to generate micro-op or added with
        ////////////// runtime data
        RT_INSTR* getRtInstr(uint64_t instr_id);

        uint64_t getAmountInstr(){return instrPool.size();}

        void decodeInstr(uint64_t instrId, MOP_AGENT* mopAgent);

        //////// when tracer collect raw static instruction token which we will decoded it
        void onGetStTraceValue(const staticTraceData& stData); // for only per instruction

    };

    namespace py = pybind11;
    void BIND_THREAD_MODEL(py::module& m);

}


#endif //TRACEBUILDER_THREAD_MODEL_H
