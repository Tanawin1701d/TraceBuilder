//
// Created by tanawin on 14/2/2566.
//

#ifndef TRACEBUILDER_LAGACY_PIN_H
#define TRACEBUILDER_LAGACY_PIN_H

#include <istream>
#include "../traceToolFed.h"
#include "../staticTraceVar.h"
#include "../dynTraceVar.h"
#include "models/thread_model/thread_model.h"

namespace traceBuilder::core {

    using namespace traceBuilder::util;

    class LAGACY_PIN_TRACER : public TRACE_TOOL_FRONT_END {

    private:
        std::string fileName_static; // file name to opend static trace
        std::string fileName_dyn; // file name to open
        std::ifstream *staticFile;
        std::ifstream *dynFile;
        uint64_t MAX_RT_BUFFER_OBJ = ((uint64_t) 1) << 24;
        RT_OBJ *bufferRtObj;
        uint64_t maxInstrNumber = 0;



    public:
        LAGACY_PIN_TRACER(
                std::string _fileName_static,
                std::string _fileName_dyn
        );

        ~LAGACY_PIN_TRACER() override;

        void startStaticTrace() override;

        void startDynTrace() override;

        void setRes(CORE* _core,
                    SHARED_TRACEINFO* _sharedInfo,
                    SPECIFIC_TRACEINFO* _specificInfo) override;

    };

    ////////////////////////////////////////////////////////////////////////////////////////
    ///////// pybind declaration
    namespace py = pybind11;
    void BIND_LAGACY_PIN_TRACER(py::module& m);
}

#endif //TRACEBUILDER_LAGACY_PIN_H
