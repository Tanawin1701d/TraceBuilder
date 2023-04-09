//
// Created by tanawin on 28/12/2565.
//
#include "regMapper.h"



////// define extern variable
std::map<std::string, REGNUM> regmap = {

        { "rax", 0 }, {"eax" , 0 },{"ax",   0 },{"al"  , 0 },{"ah"  , 0 },
        { "rcx", 1 }, {"ecx" , 1 },{"cx",   1 },{"cl"  , 1 },{"ch"  , 1 },
        { "rdx", 2 }, {"edx" , 2 },{"dx",   2 },{"dl"  , 2 },{"dh"  , 2 },
        { "rbx", 3 }, {"ebx" , 3 },{"bx",   3 },{"bl"  , 3 },{"bh"  , 3 },
        { "rsi", 4 }, {"esi" , 4 },{"si",   4 },{"sil" , 4 },{"sih" , 4 },
        { "rdi", 5 }, {"edi" , 5 },{"di",   5 },{"dil" , 5 },{"dih" , 5 },
        { "rsp", 6 }, {"esp" , 6 },{"sp",   6 },{"spl" , 6 },{"sph" , 6 },
        { "rbp", 7 }, {"ebp" , 7 },{"bp",   7 },{"bpl" , 7 },{"bph" , 7 },
        { "r8" , 8 }, {"r8d" , 8 },{"r8w" , 8 },{"r8b" , 8 },
        { "r9" , 9 }, {"r9d" , 9 },{"r9w" , 9 },{"r9b" , 9 },
        { "r10", 10}, {"r10d", 10},{"r10w", 10},{"r10b", 10},
        { "r11", 11}, {"r11d", 11},{"r11w", 11},{"r11b", 11},
        { "r12", 12}, {"r12d", 12},{"r12w", 12},{"r12b", 12},
        { "r13", 13}, {"r13d", 13},{"r13w", 13},{"r13b", 13},
        { "r14", 14}, {"r14d", 14},{"r14w", 14},{"r14b", 14},
        { "r15", 15}, {"r15d", 15},{"r15w", 15},{"r15b", 15},
        //xmm register
        { "ymm0" ,16}, {"xmm0" , 16},
        { "ymm1" ,17}, {"xmm1" , 17},
        { "ymm2" ,18}, {"xmm2" , 18},
        { "ymm3" ,19}, {"xmm3" , 19},
        { "ymm4" ,20}, {"xmm4" , 20},
        { "ymm5" ,21}, {"xmm5" , 21},
        { "ymm6" ,22}, {"xmm6" , 22},
        { "ymm7" ,23}, {"xmm7" , 23},
        { "ymm8" ,24}, {"xmm8" , 24},
        { "ymm9" ,25}, {"xmm9" , 25},
        { "ymm10",26}, {"xmm10", 26},
        { "ymm11",27}, {"xmm11", 27},
        { "ymm12",28}, {"xmm12", 28},
        { "ymm13",29}, {"xmm13", 29},
        { "ymm14",30}, {"xmm14", 30},
        { "ymm15",31}, {"xmm15", 31},
        { "ymm16",32}, {"xmm16", 32},
        { "ymm17",33}, {"xmm17", 33},
        { "ymm18",34}, {"xmm18", 34},
        { "ymm19",35}, {"xmm19", 35},
        { "ymm20",36}, {"xmm20", 36},
        { "ymm21",37}, {"xmm21", 37},
        { "ymm22",38}, {"xmm22", 38},
        { "ymm23",39}, {"xmm23", 39},
        { "ymm24",40}, {"xmm24", 40},
        { "ymm25",41}, {"xmm25", 41},
        { "ymm26",42}, {"xmm26", 42},
        { "ymm27",43}, {"xmm27", 43},
        { "ymm28",44}, {"xmm28", 44},
        { "ymm29",45}, {"xmm29", 45},
        { "ymm30",46}, {"xmm30", 46},
        { "ymm31",47}, {"xmm31", 47},
        { "rflags", 48},
        { "rip"   , 49}
};

int lastRegName = 49;


REGNUM
regMapAutoAdd(const std::string& regName){
    assert(!regName.empty());

    if (regName == unusedRegStr){
        return unusedReg;
    }

    auto finder = regmap.find(regName);
    if ( finder != regmap.end()){
        return finder->second;
    }
    ///we have new unrecorded register
    lastRegName++;
    assert(lastRegName < MAXREG_AMT);

    regmap.insert(make_pair(regName, lastRegName));
    std::cout << "[warning] detect new register : " << regName << " assign to " << lastRegName << std::endl;

    ////////////////////////////////////////
    ////////////////////////////////////////
    MAIN_STAT["count_regMapNewCreate"]++;
    ////////////////////////////////////////
    ////////////////////////////////////////

    return lastRegName;
}