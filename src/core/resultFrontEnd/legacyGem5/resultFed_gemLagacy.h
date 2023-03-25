//
// Created by tanawin on 2/3/2566.
//

#ifndef TRACEBUILDER_RESULTFED_GEMLAGACY_H
#define TRACEBUILDER_RESULTFED_GEMLAGACY_H

#include "../resultFed.h"
#include "ioHelp/protoHelp/protoio.hh"
#include "ioHelp/protoHelp/inst_dep_record.pb.h"
#include "ioHelp/protoHelp/packet.pb.h"

class RESULT_FRONT_END_GEM_LAGACY : public RESULT_FRONT_END{

private:
    ProtoOutputStream* dataProtoStream;
    ProtoOutputStream* instrProtoStream;
    uint64_t           lastTick;


public:

    RESULT_FRONT_END_GEM_LAGACY(const std::string& filePath_data,
                                const std::string& filePath_instr);

    void onGetUopsResult(std::vector<UOP_BASE*>& uops,
                         RT_INSTR*          rt_instr
    );

};

#endif //TRACEBUILDER_RESULTFED_GEMLAGACY_H
