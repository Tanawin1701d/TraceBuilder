//
// Created by tanawin on 28/12/2565.
//
#include "statPool.h"

namespace traceBuilder::stat {

////// defined extern variable
    STAT MAIN_STAT;
    STAT_MNG MAIN_STAT_MNG;
/////////////////////////////


///////// stat worker

    STAT::STAT() :
            recordedValue(nullptr),
            recordedType(STAT_T_EMPTY) {}

    bool
    STAT::isValueEmpty() {
        return recordedType == STAT_T_EMPTY;
    }

    std::string
    STAT::getReport() {
        assert(recordedValue != nullptr);
        return recordedValue->printReport();
    }

    int64_t &
    STAT::asUINT() {
        assert(recordedType == STAT_T_UINT64 || recordedType == STAT_T_EMPTY);
        if (isValueEmpty()) {
            ///// create state recorder and change tracking state
            recordedValue = new STAT_REC_TYPE_UINT();
            recordedType = STAT_T_UINT64;
        }
        return ((STAT_REC_TYPE_UINT *) recordedValue)->getRef();
    }

    std::string &
    STAT::asSTR() {
        assert(recordedType == STAT_T_STR || recordedType == STAT_T_EMPTY);
        if (isValueEmpty()) {
            ///// create state recorder and change tracking state
            recordedValue = new STAT_REC_TYPE_STR();
            recordedType = STAT_T_STR;
        }
        return ((STAT_REC_TYPE_STR *) recordedValue)->getRef();

    }

    STAT &STAT::operator[](std::string key) {
        auto finder = chainStat.find(key);

        if (finder == chainStat.end()) {
            finder = chainStat.insert({key, new STAT()}).first;
        }

        return *finder->second;
    }


///////// stat manager

    using namespace traceBuilder::util;

    void STAT_MNG::preparePrint(std::vector<std::string> &prefixs, STAT *stat) {

        assert(stat != nullptr);
        isKV_finalized = true;

        if (!stat->isValueEmpty()) {
            std::string myKey = concatVec(prefixs, "::");
            keys.push_back(myKey);
            values.push_back(stat->getReport());
            maxLength = std::max(maxLength, myKey.size());
        }
        for (auto[new_prefix, recur_stat]: stat->getChainStat()) {
            prefixs.push_back(new_prefix);
            preparePrint(prefixs, recur_stat);
            prefixs.pop_back();
        }

    }

    std::pair<std::vector<std::string>, std::vector<std::string>>
    STAT_MNG::getStat(){
        return {keys, values};
    }

    void STAT_MNG::print() {
        for (size_t idx = 0; idx < keys.size(); idx++) {
            std::cout << keys[idx]
                      << genRepeatStr(maxLength - keys[idx].size(), " ")
                      << " "
                      << values[idx]
                      << "\n";
        }

    }

    void STAT_MNG::saveToFile(const std::string& filePath) {
        std::cout << getProgPf(__FILE__, __LINE__) << " writing stat data" << std::endl;
        std::ofstream outFile(filePath);

        if (!outFile) {
            std::cout << "error to open stat file. skipping ..." << std::endl;
            return;
        }

        for (size_t idx = 0; idx < keys.size(); idx++) {
            outFile << keys[idx] << genRepeatStr(maxLength - keys[idx].size(), " ") << " " << values[idx] << '\n';
        }
        outFile.close();

    }

    void STAT_MNG::clearStat() {
        keys.clear();
        values.clear();
        maxLength = 0;
    }

///////// stat wrapper

    void BIND_STAT(py::module& m){
        ////// bring MAIN_STAT as key and value then save it to key value list
        m.def("finalizeStat", [](){
            ///// we must prepare keys and values first
            std::vector<std::string> prefixs; //// reserve
            ///// we must prepare keys and values first
            MAIN_STAT_MNG.preparePrint(prefixs, &MAIN_STAT);
        });
        ////// get stat as pair of keys(list of string) and value (list of string)
        m.def("getStat", [](){
            assert(MAIN_STAT_MNG.isReady());
            return MAIN_STAT_MNG.getStat();
        }, "get stat as list of key and value");
        ////// save stat as pair of keys(list of string) and value (list of string)
        m.def("saveStat", [](const std::string& savePath){
            MAIN_STAT_MNG.saveToFile(savePath);
        });
        /////// clear stat from MAIN_STAT_MNG
        m.def("clearStat", [](){
            MAIN_STAT_MNG.clearStat();
        });

    }

}