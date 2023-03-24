//
// Created by tanawin on 2/3/2566.
//

#ifndef TRACEBUILDER_RESULTFED_GEMLAGACY_H
#define TRACEBUILDER_RESULTFED_GEMLAGACY_H

#include "../resultFed.h"
#include "ioHelp/protoHelp/protoio.hh"
#include "ioHelp/protoHelp/inst_dep_record.pb.h"

class RESULT_FRONT_END_GEM_LAGACY : public RESULT_FRONT_END{

private:
    ProtoOutputStream* protoStream;

public:

    RESULT_FRONT_END_GEM_LAGACY(const string& filePath);

    void onGetUopsResult(vector<UOP_BASE*>& uops,
                         RT_INSTR*          rt_instr
    );

};

#endif //TRACEBUILDER_RESULTFED_GEMLAGACY_H
