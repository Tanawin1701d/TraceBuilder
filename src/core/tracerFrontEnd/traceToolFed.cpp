//
// Created by tanawin on 14/2/2566.
//

#include "traceToolFed.h"
#include "core/core.h"



namespace traceBuilder::core {


    TRACE_TOOL_FRONT_END::TRACE_TOOL_FRONT_END() {}

    TRACE_TOOL_FRONT_END::~TRACE_TOOL_FRONT_END() {}

    void TRACE_TOOL_FRONT_END::startStaticTrace() {
        assert(false);
    }

    void TRACE_TOOL_FRONT_END::startDynTrace() {
        assert(false);
    }

    void TRACE_TOOL_FRONT_END::setRes(CORE* _core,
                SHARED_TRACEINFO* _sharedInfo,
                SPECIFIC_TRACEINFO* _specificInfo){
        assert(false);
    }

    void BIND_TRACE_TOOL_FRONT_END(py::module& m){
        py::class_<TRACE_TOOL_FRONT_END, std::shared_ptr<TRACE_TOOL_FRONT_END>>(m, "TRACE_TOOL_FRONT_END")
                .def(py::init<>());
    }


}