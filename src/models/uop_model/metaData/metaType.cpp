//
// Created by tanawin on 22/7/2566.
//
#include"metaType.h"

namespace traceBuilder::model {

    void BIND_META_TYPE(py::module &m) {
        py::class_<MEM_META>(m, "MEM_META")
        .def_readwrite("v_area", &MEM_META::v_area)
        .def_readwrite("p_area", &MEM_META::p_area)
        .def_readwrite("size", &MEM_META::size)
        .def_readwrite("segReg", &MEM_META::segReg)
        .def_readwrite("baseReg", &MEM_META::baseReg)
        .def_readwrite("indexReg", &MEM_META::indexReg)
        .def_readwrite("scaleFactor", &MEM_META::scaleFactor)
        .def_readwrite("displacement", &MEM_META::displacement)
        .def_readwrite("suppressed", &MEM_META::suppressed);

    }


}