//
// Created by tanawin on 8/1/2566.
//

#ifndef TRACEBUILDER_MEMMNG_H
#define TRACEBUILDER_MEMMNG_H

#include <cstdint>
#include <unordered_map>
#include <vector>
#include <cassert>


typedef unsigned long long ADDR;

struct ADAS{
    ADDR addr;
    ADDR size;
};

bool isADASoverlap(const ADAS& a,const ADAS& b);


///// TODO make it for multicore mapping


class MEM_MNG{
private:
    ADDR phyStartAddr;
    ADDR nextphyStartAddr;

    ADDR phySize;
    //// memory page alignment
    ADDR pageAlignSize;
    ADDR pageAlignBit; ///// addr & ~(pageBit-1) = start page addr
    //// cache block/line alignment
    ADDR cacheAlignmentSize; ///// in byte
    ADDR cacheAlignBit; ///// addr & ~(alignBit-1) = start address
    //// map from virtual address to physical address
    std::unordered_map<ADDR, ADDR> pageMap; ///// map start page of virtual address to start page of phy sical
    //// private method
    ADDR v2pConvertSingle(ADDR _vaddr);
    bool isAllocated(ADDR _a_vaddr); /// page align virtual address as a input
    void allocate(ADDR _a_vaddr); ///// -----^
    ADDR pageAlign(ADDR _vaddr); /// align virtual address to fit page
public:
    explicit MEM_MNG(ADDR _pageBit, ADDR _alignBit, ADDR _ramSize, ADDR _phyStartAddr);
    void     v2pConvert(ADDR _vaddr, int _size, std::vector<ADAS>& results);

};



#endif //TRACEBUILDER_MEMMNG_H
