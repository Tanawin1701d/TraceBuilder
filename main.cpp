#include <iostream>
#include "tracers/tracer.h"
#include "tracers/statPool.h"
#include "components/inst/instr_model.h"
int main() {

    auto instr_md_mng = INSTR_MODEL_MANAGER("/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/rawFile/tracer_trace.out");

    auto tracer = ETRACER("/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/rawFile/testOp2",
                          "/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/generatedFile/dynamicData.txt",
                          "/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/generatedFile/instrBeta.txt",
                          64,
                          &instr_md_mng
            );
    tracer.step();
    printStat();
    return 0;
}