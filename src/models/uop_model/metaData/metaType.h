//
// Created by tanawin on 4/7/2566.
//

#ifndef TRACEBUILDER_METATYPE_H
#define TRACEBUILDER_METATYPE_H

#include "models/res_model/regMap/regMapper.h"
#include "models/res_model/memMng/MemMng.h"

namespace traceBuilder::model {
/** mem meta data*/

    typedef unsigned long long IMM;

    typedef REGNUM REG_META;

    typedef TREGNUM TREG_META;

    struct MEM_META {
        ADAS v_area;
        ADAS p_area;
        ADDR size;
        REGNUM baseReg;
        REGNUM indexReg;
        int    scaleFactor;
        IMM    displacement;

    };

}

#endif //TRACEBUILDER_METATYPE_H
