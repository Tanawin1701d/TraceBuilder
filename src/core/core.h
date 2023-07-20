//
// Created by tanawin on 14/2/2566.
//

#ifndef TRACEBUILDER_CORE_H
#define TRACEBUILDER_CORE_H
#include <pybind11/pybind11.h>
#include "config/fixed_param.h"
#include <unordered_map>
#include "core/tracers/tracer.h"
#include "core/tracerFrontEnd/traceToolFed.h"
#include "core/tracers/tracer.h"
#include "models/res_model/execUnit/execUnit.h"


namespace traceBuilder::core {

    using namespace traceBuilder::model;

    struct SHARED_TRACEINFO{
        std::shared_ptr<MEM_MNG>  memMng; //// smart pointer
        EXEC_UNIT_RES* execUnit_info;
    };

    struct SPECIFIC_TRACEINFO{
        THREAD_ID                             tid;
        UOP_WINDOW*                           uopWindow;
        TRACER_BASE_PTR                       tracer;
        std::shared_ptr<THREAD_MODEL>         threadModel; /// smart pointer
        std::shared_ptr<TRACE_TOOL_FRONT_END> traceToolFed;/// smart pointer
        std::shared_ptr<RESULT_FRONT_END>     resultFed; /// smart pointer
    };

    class CORE {
    private:
        std::unordered_map<THREAD_ID, SPECIFIC_TRACEINFO*> traceWorkers;
        THREAD_ID amountThread{};
        //////// shared model
        SHARED_TRACEINFO sharedInfo{};
        ////////////////////////////////////////////////

    public:
        CORE(const std::shared_ptr<MEM_MNG>& _memMng,
             EXEC_UNIT_RES* _execUnit_info);

        ~CORE();

        void addWorker(const std::shared_ptr<TRACE_TOOL_FRONT_END>& _trace_tool,
                       const std::shared_ptr<RESULT_FRONT_END>&     _result_frontEnd,
                       int _obsSize
        );

        std::shared_ptr<THREAD_MODEL> getThreadModel(THREAD_ID tid);

        int getAmtThread() const;

        void startStaticTrace();

        void startDynTrace();

    };

    ////////////////////////////////////////////////////////////////////////////////////////
    ///////// pybind declaration
    namespace py = pybind11;
    void BIND_CORE(py::module& m);

}




#endif //TRACEBUILDER_CORE_H
