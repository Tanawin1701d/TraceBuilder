//
// Created by tanawin on 14/2/2566.
//

#include "resultFed.h"
#include "core/core.h"

namespace traceBuilder::core {

    void BIND_RESULT_FRONT_END(py::module& m){
        py::class_<RESULT_FRONT_END, std::shared_ptr<RESULT_FRONT_END>>(m, "RESULT_FRONT_END")
                .def(py::init<>());
    }
}