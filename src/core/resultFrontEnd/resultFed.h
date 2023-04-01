//
// Created by tanawin on 14/2/2566.
//

#ifndef TRACEBUILDER_RESULTFED_H
#define TRACEBUILDER_RESULTFED_H

#include <vector>
#include "models/inst_model/rt_instr.h"
#include "models/arch/uop_base.h"

class RESULT_FRONT_END{
friend class TRACER_BASE;
protected:
    ////////// please remind that this UOP_BASE pointer will be deleted later
    ///////////////// (when uop window discard it, uop will be deleted)
    virtual void onGetUopsResult(std::vector<UOP_BASE*>& results,
                                 RT_INSTR*          rt_instr
    ) = 0;

};


#endif //TRACEBUILDER_RESULTFED_H
