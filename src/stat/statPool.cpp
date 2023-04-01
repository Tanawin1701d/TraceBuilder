//
// Created by tanawin on 28/12/2565.
//
#include "statPool.h"

STAT::STAT(): valueIsUsed(false), value(0)
{}


STAT& STAT::operator[](std::string key) {
    auto finder = chainStat.find(key);

    if (finder == chainStat.end()){
        finder = chainStat.insert({key, new STAT()}).first;
    }

    return * finder->second;
}


void STAT_MNG::preparePrint( std::vector<std::string>& prefixs,
                      STAT *stat) {

    assert(stat != nullptr);

    if (stat->isValued()) {
        std::string myKey = concatVec(prefixs, "::");
        keys.push_back(myKey);
        values.push_back(stat->getVal());
        maxLength = std::max(maxLength, myKey.size());
    }
    for (auto ele: stat->getChainStat()){
        prefixs.push_back(ele.first);
        preparePrint(prefixs, ele.second);
        prefixs.pop_back();
    }

}

void STAT_MNG::print(){
    for (size_t idx = 0; idx < keys.size(); idx++){
        std::cout << keys[idx]
                  << genRepeatStr(maxLength - keys[idx].size(), " ")
                  << std::to_string(values[idx])
                  << "\n";
    }
    keys.clear();
    values.clear();
    maxLength = 0;

}