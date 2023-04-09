//
// Created by tanawin on 28/12/2565.
//
#include "statPool.h"


////// defined extern variable
STAT MAIN_STAT;
STAT_MNG MAIN_STAT_MNG;
/////////////////////////////


///////// stat worker

STAT::STAT(): valueIsUsed(false), value(0)
{}


STAT& STAT::operator[](std::string key) {
    auto finder = chainStat.find(key);

    if (finder == chainStat.end()){
        finder = chainStat.insert({key, new STAT()}).first;
    }

    return * finder->second;
}


///////// stat manager

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

}

void STAT_MNG::saveToFile(const std::string filePath) {
    std::cout << getProgPf(__FILE__, __LINE__) << " writing stat data" << std::endl;
    std::ofstream outFile(filePath);

    if (!outFile){
        std::cout << "error to open stat file. skipping ..." << std::endl;
        return;
    }

    for (size_t idx = 0; idx < keys.size(); idx++){
        outFile << keys[idx] << genRepeatStr(maxLength - keys[idx].size(), " ") << std::to_string(values[idx]) << '\n';
    }
    outFile.close();

}

void STAT_MNG::clearStat() {
    keys.clear();
    values.clear();
    maxLength = 0;
}