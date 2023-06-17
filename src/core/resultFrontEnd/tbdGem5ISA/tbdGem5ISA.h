//
// Created by tanawin on 17/6/2566.
//

#ifndef TRACEBUILDER_TBDGEM5ISA_H
#define TRACEBUILDER_TBDGEM5ISA_H

#include "ioHelp/protoHelp/protoio.hh"
#include "ioHelp/protoHelp/mach.pb.h"

#include "core/resultFrontEnd/resultFed.h"

namespace traceBuilder::core {

    class TBD_GEM5_ISA : public RESULT_FRONT_END {
    private:
        ProtoOutputStream* desFileStream;

    protected:

        void onGetUopsResult(std::vector<UOP_BASE*>& result, RT_INSTR* rt_instr) override;

        void setRes(CORE* core,
                    SHARED_TRACEINFO* sharedInfo,
                    SPECIFIC_TRACEINFO* specificInfo) override;

    public:
        TBD_GEM5_ISA(const std::string& machProtoFilePath);

    };

}

#endif //TRACEBUILDER_TBDGEM5ISA_H
