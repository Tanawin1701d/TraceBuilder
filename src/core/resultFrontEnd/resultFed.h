//
// Created by tanawin on 14/2/2566.
//

#ifndef TRACEBUILDER_RESULTFED_H
#define TRACEBUILDER_RESULTFED_H

#include <pybind11/pybind11.h>
#include <vector>
#include "models/inst_model/rt_instr.h"
#include "models/uop_model/uop_base.h"


namespace traceBuilder::core {

    using namespace traceBuilder::model;

    struct SHARED_TRACEINFO;
    struct SPECIFIC_TRACEINFO;
    class  CORE;

    class RESULT_FRONT_END {
        friend class TRACER_BASE;

    protected:
        ////////// please remind that this UOP_BASE pointer will be deleted later
        ///////////////// (when uop window discard it, uop will be deleted)
        virtual void onGetUopsResult(std::vector<UOP_BASE *> &results,
                                     RT_INSTR *rt_instr) {assert(false);};

    public:
        virtual void setRes(CORE* _core,
                            SHARED_TRACEINFO* _sharedInfo,
                            SPECIFIC_TRACEINFO* _specificInfo) {assert(false);};

    };

    ////////////////////////////////////////////////////////////////////////////////////////
    ///////// pybind declaration
    namespace py = pybind11;
    void BIND_RESULT_FRONT_END(py::module& m);

}



#endif //TRACEBUILDER_RESULTFED_H
