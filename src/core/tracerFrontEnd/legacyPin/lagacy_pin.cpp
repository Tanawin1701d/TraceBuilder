//
// Created by tanawin on 14/2/2566.
//

#include "lagacy_pin.h"
#include "core/core.h"


////////// lagacy pin tracer

namespace traceBuilder::core {

    LAGACY_PIN_TRACER::LAGACY_PIN_TRACER(std::string _fileName_static,
                                         std::string _fileName_dyn) :
            TRACE_TOOL_FRONT_END() {
        staticFile = new std::ifstream(_fileName_static);
        dynFile = new std::ifstream(_fileName_dyn);
        bufferRtObj = new RT_OBJ[MAX_RT_BUFFER_OBJ];

        assert(staticFile != nullptr);
        assert(dynFile != nullptr);

    }

    LAGACY_PIN_TRACER::~LAGACY_PIN_TRACER() noexcept {
        staticFile->close();
        dynFile->close();
        delete staticFile;
        delete dynFile;
        std::cout << getProgPf(__FILE__, __LINE__) << "closed static and dyn input file" << std::endl;
    }

    void
    LAGACY_PIN_TRACER::startStaticTrace() {

        staticTraceData presentData;

        std::string line;

        while (std::getline(*staticFile, line)) {
            if (!line.empty()) {
                presentData.rawData.push_back(line);
                if (
                        !line.empty() &&
                        line.substr(ST_IDXL_FETCH_TYPE, 1) == ST_VAL_COMPO_FETCH
                        ) {
                    ///// if we get fetch component type so we should send thread model to decode
                    tmd->onGetStTraceValue(presentData);
                    presentData.rawData.clear();
                    maxInstrNumber++;
                }
            }
        }
        std::cout << "[TBD@legacyPin:52] staticIntepret pass!" << std::endl;
    }

    void
    LAGACY_PIN_TRACER::startDynTrace() {

        dynTraceData dynData{};

        //// ask tracer to initialize their runtime instruction
        tracer->onInitialize(maxInstrNumber);
        //// ask tracer to trace each runtime instruction
        dynFile->seekg(0, std::ios_base::end);
        uint64_t fileSize = dynFile->tellg();
        uint64_t readedObj = 0;
        uint64_t neededObj = fileSize / sizeof(RT_OBJ);
        dynFile->seekg(0, std::ios_base::beg);

        //////////////////////// print progress
        std::cout << getProgPf(__FILE__, __LINE__) << "] dynamic tracing got file size " << dynFile->tellg()
                  << std::endl;
        std::cout << getProgPf(__FILE__, __LINE__) << "] dynamic file tracing got " << neededObj << "object"
                  << std::endl;
        if ((fileSize % sizeof(RT_OBJ)) != 0) {
            std::cout << "[legacyPin:73] error alignment is not match" << std::endl;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////
        while (true) {

            uint64_t remainObj = neededObj - readedObj;
            uint64_t currentBatchObj = std::min(remainObj, MAX_RT_BUFFER_OBJ);
            uint64_t currentBatchByte = currentBatchObj * sizeof(RT_OBJ);

            if (!remainObj) {
                std::cout << "finish dynamic tracing" << std::endl;
                break;
            }

            //////// read file from disk
            assert(((long) currentBatchByte) > 0);
            dynFile->read((char *) bufferRtObj, (long) currentBatchByte);
            //////// extract readFile and send to tracer
            for (int rtObjIdx = 0; rtObjIdx < currentBatchObj; rtObjIdx++) {
                dynData.rawData = *(bufferRtObj + rtObjIdx);
                tracer->onGetDynTraceValue(dynData);
            }
            /////// update current state
            readedObj += currentBatchObj;
        }
    }

    void
    LAGACY_PIN_TRACER::start() {
        //// verify before running
        assert(tmd != nullptr);
        assert(tracer != nullptr);
        assert(staticFile != nullptr);
        assert(dynFile != nullptr);

        startStaticTrace();
        startDynTrace();

    }

    void LAGACY_PIN_TRACER::setRes(CORE *_core,
                                   SHARED_TRACEINFO* _sharedInfo,
                                   SPECIFIC_TRACEINFO* _specificInfo) {
        tmd = _specificInfo->threadModel;
        tracer = _specificInfo->tracer;

    }


    void BIND_LAGACY_PIN_TRACER(py::module& m){
        py::class_<LAGACY_PIN_TRACER, TRACE_TOOL_FRONT_END>(m, "LAGACY_PIN_TRACER")
                .def(py::init<std::string, std::string>(),
                     py::arg("fileName_static"),
                     py::arg("fileName_dyn"),
                     "static/dynfile Name"
                );
    }


}