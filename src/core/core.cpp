//
// Created by tanawin on 2/3/2566.
//

#include "core.h"

namespace traceBuilder::core {

    CORE::CORE(MEM_MNG *_memMng, EXEC_UNIT_RES *_execUnit_info) :
            amountThread(0){
        assert(_memMng != nullptr);
        assert(_execUnit_info != nullptr);

        /////////// set decoder according to architecture
        #ifdef X86
              sharedInfo.decoder = new X86_DECODER();
        #else
              decoder = new DECODER_BASE();
        #endif
        /////////////////////////////////////////////////////
        sharedInfo.memMng = _memMng;
        sharedInfo.execUnit_info = _execUnit_info;

    }

    CORE::~CORE(){
        delete sharedInfo.decoder;
        delete sharedInfo.memMng;
        delete sharedInfo.execUnit_info;


    }


    void
    CORE::addWorker(TRACE_TOOL_FRONT_END *_trace_tool,
                    RESULT_FRONT_END *_result_frontEnd,
                    int _obsSize
    ) {
        assert(_trace_tool != nullptr);
        assert(_result_frontEnd != nullptr);

        /////////////////////////////////////////////////
        //////// set tracing element
        auto* specificInfo = new SPECIFIC_TRACEINFO();

        specificInfo->tid = amountThread;
        specificInfo->uopWindow = new UOP_WINDOW(sharedInfo.execUnit_info);
        specificInfo->threadModel = new THREAD_MODEL();


        specificInfo->traceToolFed = _trace_tool;
        specificInfo->resultFed = _result_frontEnd;
        ///////// tracer
        specificInfo->tracer = new TRACER_BASE(this,
                                              &sharedInfo,
                                              specificInfo);
        ///////// result frontEnd
        _result_frontEnd->setRes(this, &sharedInfo, specificInfo);
        ///////// traceTool
        _trace_tool->setRes(this, &sharedInfo, specificInfo);
        ///////// add Tracer
        traceWorkers.insert({amountThread, specificInfo});
        amountThread++;
    }


    void
    CORE::start(bool parallel) {
        if (parallel) {
            //////TODO make it run in parallel
            assert(false);
        } else {
            for (auto&[tid, specInfo]: traceWorkers) {
                specInfo->traceToolFed->start();
            }
        }
    }

    void BIND_CORE(py::module& m){
        py::class_<CORE>(m, "CORE")
                .def(py::init<MEM_MNG*, EXEC_UNIT_RES*>())
                .def("addWorker", &CORE::addWorker)
                .def("start", &CORE::start);
    }



}
