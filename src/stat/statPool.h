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
#include "ioHelp/strHelp.h"



class  STAT{
private:
    /// for now we support only uint64 stat for convinient use
    bool    valueIsUsed;
    int64_t value;
    std::unordered_map<std::string, STAT*> chainStat;

public:
    explicit STAT();
    int64_t  operator+  (int64_t rhs) { setValued();                    return value + rhs; };
    int64_t  operator-  (int64_t rhs) { setValued();                    return value - rhs; };
    int64_t& operator=  (int64_t rhs) { setValued(); value  = rhs;      return value;       };
    int64_t& operator+= (int64_t rhs) { setValued(); value += rhs;      return value;       };
    int64_t& operator-= (int64_t rhs) { setValued(); value -= rhs;      return value;       };
    int64_t& operator++ (int)         { setValued(); operator+=(1); return value;       };
    int64_t& operator-- (int)         { setValued(); operator-=(1); return value;       };
    STAT&    operator[] (std::string key);

    int64_t getVal()   const {return value;      };
    bool    isValued() const {return valueIsUsed;};
    void    setValued() {valueIsUsed = true;}
    std::unordered_map<std::string, STAT*>& getChainStat(){return chainStat;};


};

///////////////////////////////////////
///////////////////////////////////////
static STAT     MAIN_STAT;
///////////////////////////////////////
///////////////////////////////////////

class STAT_MNG{
    size_t maxLength = 0;
    std::vector<std::string> keys;
    std::vector<int64_t>     values;
public:
    void preparePrint(std::vector<std::string>& prefixs,
               STAT* stat = &MAIN_STAT
               );

    void print();
};

///////////////////////////////////////
///////////////////////////////////////
static STAT_MNG MAIN_STAT_MNG;
///////////////////////////////////////
///////////////////////////////////////


#endif //TRACEBUILDER_STATPOOL_H
