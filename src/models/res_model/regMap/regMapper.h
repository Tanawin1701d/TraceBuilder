//
// Created by tanawin on 27/12/2565.
//

#ifndef TRACEBUILDER_REGMAPPER_H
#define TRACEBUILDER_REGMAPPER_H

#include <iostream>
#include <map>
#include <string>
#include<boost/algorithm/string.hpp>
#include"stat/statPool.h"

namespace traceBuilder::model {


    typedef int TREGNUM; ///// temporal reg number

    struct AREGNUM{ //// architecture register
        int archRegId = -1;
        int maxSubRegId = -1;

        bool operator == (const AREGNUM& rhs) const{
            return archRegId == rhs.archRegId && maxSubRegId == rhs.archRegId;
        }

        bool operator != (const AREGNUM& rhs) const{
            return !(*this == rhs);
        }

    };

    typedef int MREGNUM; ///// micro arch regnum

    extern std::map<std::string, AREGNUM> regmap;
    extern int lastRegName;

    static const int   MAXSUBREG_YMM = 4;
    static const int   MAXSUBREG_XMM = 2;
    static const int   MAXSUBREG_MMX = 1;
    static const int   MAXSUBREG_R    =1;

    static const AREGNUM UNUSED_AREG = {-1,-1};
    static const MREGNUM UNUSED_MREG = -1;
    static const TREGNUM UNUSED_TREG = -1;
    static const int    MAXMREG_AMT = 1000;
    static const int    START_VECREGID = 200;
    static const int    STOP_VECREGID =  263;
    static const int    START_UNREGID = 400;
    static const int    START_TREGID = 300;
    static const std::string unusedRegStr = "-1";

    AREGNUM regMapAutoAdd(const std::string &regName);
    MREGNUM archRegToMReg(AREGNUM reg, int subIdx);

}

#endif //TRACEBUILDER_REGMAPPER_H
