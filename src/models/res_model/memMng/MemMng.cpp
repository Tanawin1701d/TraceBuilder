//
// Created by tanawin on 8/1/2566.
//

#include "MemMng.h"
#include "../../../stat/statPool.h"

namespace traceBuilder::model {


    bool isADASoverlap(const ADAS &a, const ADAS &b) {

        return ((a.addr >= b.addr) && (a.addr < (b.addr + b.size))) ||
               ((b.addr >= a.addr) && (b.addr < (a.addr + a.size)));

    }


    MEM_MNG::MEM_MNG(ADDR _pageBit,
                     ADDR _alignBit,
                     ADDR _ramSize, /// in byte
                     ADDR _phyStartAddr) :
            phyStartAddr(_phyStartAddr),
            nextphyStartAddr(_phyStartAddr),
            phySize(_ramSize) {

        pageAlignBit = _pageBit;
        pageAlignSize = ((ADDR) 1) << pageAlignBit;
        assert(pageAlignSize < phySize);

        cacheAlignBit = _alignBit;
        cacheAlignmentSize = ((ADDR) 1) << cacheAlignBit;
        assert(pageAlignBit >= cacheAlignBit);

    }

    ADDR MEM_MNG::v2pConvertSingle(ADDR _vaddr) {
        auto vPageAlignedAddr = pageAlign(_vaddr);

        if (!isAllocated(vPageAlignedAddr)) {
            allocate(vPageAlignedAddr);
        }
        auto finder = pageMap.find(vPageAlignedAddr);
        assert(finder != pageMap.end());

        ////                     v------ parenthesis is crucial due to overflow prevention
        return finder->second + (_vaddr - vPageAlignedAddr);
    }

    bool MEM_MNG::isAllocated(ADDR _a_vaddr) {
        return pageMap.find(_a_vaddr) != pageMap.end();
    }

    void MEM_MNG::allocate(ADDR _a_vaddr) {
        pageMap.insert({_a_vaddr, nextphyStartAddr});
        nextphyStartAddr += pageAlignSize;
    }

    ADDR MEM_MNG::pageAlign(ADDR _vaddr) {
        return _vaddr & (~((((ADDR) 1) << pageAlignBit) - 1));
    }

    void MEM_MNG::v2pConvert(ADDR _vaddr, int _size, std::vector<ADAS> &results) {

        assert(_size > 0);
        ADDR cur_vir_addr = _vaddr;
        ADDR last_vir_addr = _vaddr + _size;

        do {
            ADDR next_vir_block_addr = (cur_vir_addr + cacheAlignmentSize) & (~((((ADDR) 1) << cacheAlignBit) - 1));
            ADDR size_for_in_sec = std::min(last_vir_addr, next_vir_block_addr) - cur_vir_addr;
            ///// we assume that cache block line is aligned with page size
            results.push_back({v2pConvertSingle(cur_vir_addr), size_for_in_sec});
            cur_vir_addr += size_for_in_sec;
        } while (cur_vir_addr < last_vir_addr);

    }

}



