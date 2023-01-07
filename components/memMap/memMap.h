//
// Created by tanawin on 28/12/2565.
//

#ifndef TRACEBUILDER_MEMMAP_H
#define TRACEBUILDER_MEMMAP_H

#include<vector>
#include <cstdint>
#include <string>
#include "../../tracers/statPool.h"

using namespace std;
typedef uintptr_t ADDR;

struct memBlock{
    ADDR st_blk; // first byte in real block
    ADDR ls_blk; // last byte of the block
    ADDR st_gemBlk; // first byte in gem5
};

static int mapIgnoreCount = 0;
static int cacheBlockSize = 64; // cache line size in bytes

static std::vector<memBlock>
        memmap = {{stoull("0x00001000" , nullptr, 16),  stoull("0x00057fff" , nullptr, 16),  0},
                  {stoull("0x00059000" , nullptr, 16),  stoull("0x0009efff" , nullptr, 16),  0},
                  {stoull("0x00100000" , nullptr, 16),  stoull("0xbbe78017" , nullptr, 16),  0},
                  {stoull("0xbbe78018" , nullptr, 16),  stoull("0xbbe85857" , nullptr, 16),  0},
                  {stoull("0xbbe85858" , nullptr, 16),  stoull("0xbbe86017" , nullptr, 16),  0},
                  {stoull("0xbbe86018" , nullptr, 16),  stoull("0xbbea6457" , nullptr, 16),  0},
                  {stoull("0xbbea6458" , nullptr, 16),  stoull("0xbc2c6fff" , nullptr, 16),  0},
                  {stoull("0xbc2ce000" , nullptr, 16),  stoull("0xbc730fff" , nullptr, 16),  0},
                  {stoull("0xbcb80000" , nullptr, 16),  stoull("0xdbb11fff" , nullptr, 16),  0},
                  {stoull("0xdbb13000" , nullptr, 16),  stoull("0xdda8efff" , nullptr, 16),  0},
                  {stoull("0xdefff000" , nullptr, 16),  stoull("0xdeffffff" , nullptr, 16),  0},
                  {stoull("0x100000000", nullptr, 16),  stoull("0x41effffff", nullptr, 16),  0}
};

struct ADAS{
    ADDR effAddr;
    int  effSize;
};

ADDR mapMem(ADDR hostAddr);
void initMemMap();

vector<ADAS>
memMapperAndSplit(ADDR startAddr, int size);


#endif //TRACEBUILDER_MEMMAP_H
