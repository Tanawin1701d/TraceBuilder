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

    typedef IMM    IMM_META;

    typedef MREGNUM MREG_META;

    typedef TREGNUM TREG_META;

    struct MEM_META {
        ADAS v_area;
        ADAS p_area;
        ADDR size;
        AREGNUM baseReg;
        AREGNUM indexReg;
        int    scaleFactor;
        IMM    displacement;
        bool   is_v_area_set = false;
        bool   is_p_area_set = false;

    };

}

#endif //TRACEBUILDER_METATYPE_H
