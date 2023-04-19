//
// Created by tanawin on 28/12/2565.
//

#ifndef TRACEBUILDER_STATPOOL_H
#define TRACEBUILDER_STATPOOL_H
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include <cassert>
#include <fstream>

#include "ioHelp/strHelp.h"
#include "statRecType.h"


class  STAT{
private:
    /// for now we support only uint64 stat for convenient use
    std::unordered_map<std::string, STAT*> chainStat;
    STAT_REC_TYPE* recordedValue;
    STAT_TYPE      recordedType;

public:
    explicit STAT();
    STAT&    operator[] (std::string key);
    bool         isValueEmpty();
    std::string  getReport(); /////// please not that this function is assume that there are value @recorder
    int64_t&     asUINT();
    std::string& asSTR();
    std::unordered_map<std::string, STAT*>& getChainStat(){return chainStat;};

};

///////////////////////////////////////
///////////////////////////////////////
extern  STAT     MAIN_STAT;
///////////////////////////////////////
///////////////////////////////////////

class STAT_MNG{
    size_t maxLength = 0;
    std::vector<std::string> keys;
    std::vector<std::string> values;
public:
    void preparePrint(std::vector<std::string>& prefixs,
               STAT* stat = &MAIN_STAT
               );

    void print();
    void saveToFile(const std::string filePath);
    void clearStat();
};

///////////////////////////////////////
///////////////////////////////////////
extern STAT_MNG MAIN_STAT_MNG;
///////////////////////////////////////
///////////////////////////////////////


#endif //TRACEBUILDER_STATPOOL_H
