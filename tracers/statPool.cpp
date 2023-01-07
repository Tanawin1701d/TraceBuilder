//
// Created by tanawin on 28/12/2565.
//
#include "statPool.h"

using namespace std;

void printStat(){
    int keyMax = 0;
    for (auto& pa: statPoolCount){
        keyMax = max((int)pa.first.size(), keyMax);
    }

    for (auto& pa: statPoolCount){
        cout << pa.first;
        for (int i = 0; i < (keyMax-pa.first.size()); i++) cout << " ";
        cout << " : " << pa.second << endl;
    }

}

uint64_t& getstatPoolCount(string name){
    auto finder = statPoolCount.find(name);
    if (finder != statPoolCount.end()){
        return finder->second;
    }

    cout << "[warning] no stat with " << name << " is named."<< endl;
    return dummyStatCount;
}