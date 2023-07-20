//
// Created by tanawin on 17/6/2566.
//

#ifndef TRACEBUILDER_TBDGEM5ISA_H
#define TRACEBUILDER_TBDGEM5ISA_H

#include "ioHelp/protoHelp/protoio.hh"
#include "ioHelp/protoHelp/mach.pb.h"

#include "core/resultFrontEnd/resultFed.h"
#include "models/res_model/memMng/MemMng.h"

namespace traceBuilder::core {

    class TBD_GEM5_ISA : public RESULT_FRONT_END {
    private:
        ProtoOutputStream*       desFileStream;
        uint64_t                 curInstrNum;
        std::shared_ptr<MEM_MNG> memMng;

    protected:

        void onGetUopsResult(std::vector<UOP_BASE*>& result, RT_INSTR_PTR rt_instr) override;

        void setRes(CORE* core,
                    SHARED_TRACEINFO* sharedInfo,
                    SPECIFIC_TRACEINFO* specificInfo) override;

        static void setArchRegHelper(UOP_BASE* uop_base, ProtoMessage::machRecord* machRec, bool isSrc);
        static void setTempRegHelper(UOP_BASE* uop_base, ProtoMessage::machRecord* machRec, bool isSrc);
        static void setMemHelper (UOP_BASE* uop_base, ProtoMessage::machRecord* machRec, bool isLoad);
        static bool shouldSkipUop(UOP_BASE* uop_base);

    public:
        explicit TBD_GEM5_ISA(const std::string& machProtoFilePath);
        ~TBD_GEM5_ISA(){ delete desFileStream;}

    };

    namespace py = pybind11;
    void BIND_RESULT_FRONT_END_TBDGEMISA(py::module& m);



}

#endif //TRACEBUILDER_TBDGEM5ISA_H
