#include <iostream>
#include "example/simplePinGem.h"
#include "stat/statPool.h"

int main() {
    auto test = SIMPLE_PIN_GEM(
                "/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/testStaticOutput/fluidInstr",
                "/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/testDynOutput/fluidData",
                "/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/testProtoOuput/fluid/instr",
                "/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/testProtoOuput/fluid/data"
            );

    test.start();

    std::vector<std::string> statHelper;
    MAIN_STAT_MNG.preparePrint(statHelper);
    MAIN_STAT_MNG.print();
}