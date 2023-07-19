//
// Created by tanawin on 14/2/2566.
//

#ifndef TRACEBUILDER_TRACETOOLFED_H
#define TRACEBUILDER_TRACETOOLFED_H
#include <pybind11/pybind11.h>
#include <fstream>
#include <cassert>
#include "core/tracers/tracer.h"
#include "models/thread_model/thread_model.h"

namespace traceBuilder::core {


///// for now we assume that stream front-end and file front end share same input trace function
    class TRACE_TOOL_FRONT_END {
    protected:
        THREAD_MODEL *tmd; // for static trace to send static instruction to build runtime instruction
        TRACER_BASE *tracer; // for runtime trace; the runtime data will be integrate with
        // runtime instruction to generate precise micro op

    public:

        TRACE_TOOL_FRONT_END();

        void setListenners(THREAD_MODEL *_tmd, TRACER_BASE *_tracer);

        virtual ~TRACE_TOOL_FRONT_END();

        virtual void startStaticTrace();

        virtual void startDynTrace();

        virtual void setRes(CORE* _core,
                            SHARED_TRACEINFO* _sharedInfo,
                            SPECIFIC_TRACEINFO* _specificInfo);

    };

    ////////////////////////////////////////////////////////////////////////////////////////
    ///////// pybind declaration
    namespace py = pybind11;
    void BIND_TRACE_TOOL_FRONT_END(py::module& m);

}

#endif //TRACEBUILDER_TRACETOOLFED_H
