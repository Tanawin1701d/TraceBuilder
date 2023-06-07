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
    typedef int REGNUM;  ///// reg number

    extern std::map<std::string, REGNUM> regmap;
    extern int lastRegName;
    static const int unusedReg = -1;
    static const int MAXREG_AMT = 1000;
    static const std::string unusedRegStr = "-1";

    REGNUM regMapAutoAdd(const std::string &regName);

}

#endif //TRACEBUILDER_REGMAPPER_H
