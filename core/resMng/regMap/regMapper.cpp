//
// Created by tanawin on 28/12/2565.
//
#include "regMapper.h"

REGNUM
regMapAutoAdd(const std::string& regName){
    assert(!regName.empty());
    auto finder = regmap.find(regName);
    if ( finder != regmap.end()){
        return finder->second;
    }
    ///we have new unrecorded register
    lastRegName++;

    regmap.insert(make_pair(regName, lastRegName));
    cout << "[warning] detect new register : " << regName << " assign to " << lastRegName << endl;

    getstatPoolCount("count_regMapNewCreate")++;

    return lastRegName;
}