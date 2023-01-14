#include <iostream>
#include "tracers/tracer.h"
#include "tracers/statPool.h"
#include "components/inst/instr_model.h"
int main() {

    auto instr_md_mng = INSTR_MODEL_MANAGER("/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/rawFile/FluidIN");
    ADDR memSize = ((ADDR)1) << (4 + 30); ///// 16 gigabyte
    auto mem_mng      = MEM_MNG(12, 6, memSize, 0);
            ///// 12 bit means 4 kb page size ///// 6 bit mean 64 byte cache line size
    auto tracer = ETRACER("/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/rawFile/fluidRT",
                          "/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/generatedFile/FluidData",
                          "/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/generatedFile/FluidInstr",
                          120,
                          &instr_md_mng,
                          &mem_mng
            );
    tracer.step();

    printStat();

    return 0;
}