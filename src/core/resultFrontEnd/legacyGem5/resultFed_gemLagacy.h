//
// Created by tanawin on 2/3/2566.
//

#ifndef TRACEBUILDER_RESULTFED_GEMLAGACY_H
#define TRACEBUILDER_RESULTFED_GEMLAGACY_H

#include "../resultFed.h"
#include "ioHelp/protoHelp/protoio.hh"
#include "ioHelp/protoHelp/inst_dep_record.pb.h"
#include "ioHelp/protoHelp/packet.pb.h"


namespace traceBuilder::core {

    using namespace traceBuilder::util;

    class RESULT_FRONT_END_GEM_LAGACY : public RESULT_FRONT_END {
    private:
        ProtoOutputStream* dataProtoStream;
        ProtoOutputStream* instrProtoStream;
        uint64_t       lastTick;
        EXEC_UNIT_RES* execUnit_info;
        std::shared_ptr<MEM_MNG>       mng;

    public:

        RESULT_FRONT_END_GEM_LAGACY(const std::string &filePath_data,
                                    const std::string &filePath_instr,
                                    const int freq,
                                    const int windowSize); ///// tick per/sec

        ~RESULT_FRONT_END_GEM_LAGACY();

        void onGetUopsResult(std::vector<UOP_BASE *> &uops,
                             RT_INSTR_PTR rt_instr
        ) override;

        void setRes(CORE* _core, SHARED_TRACEINFO* _sharedInfo, SPECIFIC_TRACEINFO* _specificInfo) override;

    };

    ////////////////////////////////////////////////////////////////////////////////////////
    ///////// pybind declaration
    namespace py = pybind11;
    void BIND_RESULT_FRONT_END_GEM_LAGACY(py::module& m);

}

#endif //TRACEBUILDER_RESULTFED_GEMLAGACY_H
