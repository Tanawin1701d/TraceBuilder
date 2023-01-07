//
// Created by tanawin on 28/12/2565.
//

#ifndef TRACEBUILDER_STATPOOL_H
#define TRACEBUILDER_STATPOOL_H
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

static std::unordered_map<string, uint64_t> statPoolCount = {
        {"count_robDepFromLoadInstr",  0},
        {"count_robDepFromCompInstr",  0},
        {"count_robDepFromStoreInstr", 0},

        {"count_regDepFromLoadInstr",  0},
        {"count_regDepFromCompInstr",  0},
        {"count_regDepFromStoreInstr", 0},

        {"count_loadInstr" , 0},
        {"count_compInstr" , 0},
        {"count_storeInstr", 0},
        {"count_fetchInstr", 0},
        {"count_fetchSplit", 0},
        {"max_fetchSplit", 0},

        {"count_memMapIgnore", 0},
        {"count_regMapNewCreate", 0}

};

static uint64_t dummyStatCount = 0;


void printStat();

uint64_t& getstatPoolCount(string name);


#endif //TRACEBUILDER_STATPOOL_H
