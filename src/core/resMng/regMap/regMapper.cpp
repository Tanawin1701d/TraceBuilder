//
// Created by tanawin on 28/12/2565.
//
#include "regMapper.h"

REGNUM
regMapAutoAdd(const std::string& regName){
    assert(!regName.empty());

    if (regName == unusedRegStr){
        return unusedReg;
    }

    auto finder = regmap.find(regName);
    if ( finder != regmap.end()){
        return finder->second;
    }
    ///we have new unrecorded register
    lastRegName++;

    regmap.insert(make_pair(regName, lastRegName));
    std::cout << "[warning] detect new register : " << regName << " assign to " << lastRegName << std::endl;

    ////////////////////////////////////////
    ////////////////////////////////////////
    MAIN_STAT["count_regMapNewCreate"]++;
    ////////////////////////////////////////
    ////////////////////////////////////////

    return lastRegName;
}