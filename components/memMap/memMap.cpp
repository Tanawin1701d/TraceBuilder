//
// Created by tanawin on 28/12/2565.
//

#include <cassert>
#include "memMap.h"

ADDR mapMem(ADDR hostAddr){
    for (auto& blk : memmap){
        if (hostAddr >= blk.st_blk && hostAddr <= blk.ls_blk){
            return (hostAddr - blk.st_blk) + blk.st_gemBlk;
        }
    }
    getstatPoolCount("count_memMapIgnore")++;
    return 0;
}
void initMemMap(){
    ADDR ans = 0;
    for (auto& blk : memmap){
        blk.st_gemBlk = ans;
        ans = blk.ls_blk - blk.st_blk + 1 + ans;
    }
}

vector<ADAS>
memMapperAndSplit(ADDR startAddr, int size){
    ADDR curPhyAddr = mapMem(startAddr);
    ADDR startPhyAddr = curPhyAddr;
    ADDR endPhyAddr   = startPhyAddr + size;
    vector<ADAS> results;
    assert(size != 0);


    do{
        ADDR nextBlkAddr = ((curPhyAddr + cacheBlockSize) / cacheBlockSize) * cacheBlockSize;
        results.push_back({curPhyAddr,
                           static_cast<int>(min(nextBlkAddr, endPhyAddr) - curPhyAddr)}
                         );
        curPhyAddr = nextBlkAddr;
    }while( curPhyAddr < endPhyAddr );

    return results;
}
