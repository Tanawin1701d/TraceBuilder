#include <iostream>
#include <chrono>
#include "example/simplePinGem.h"
#include "stat/statPool.h"

using namespace std::chrono;

int main() {

    auto startTime = high_resolution_clock::now();

    auto test = traceBuilder::SIMPLE_PIN_GEM(
                "/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/PinOutput/fluidanimate/static",
                "/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/PinOutput/fluidanimate/dynamic",
                "/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TbOutput/fluidanimate/instr_medium2",
                "/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TbOutput/fluidanimate/data_medium2"
            );

    test.start();

    std::vector<std::string> statHelper;
    traceBuilder::stat::MAIN_STAT_MNG.preparePrint(statHelper);
    traceBuilder::stat::MAIN_STAT_MNG.print();
    traceBuilder::stat::MAIN_STAT_MNG.saveToFile("/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TbOutput/fluidanimate/stat_medium2");
    traceBuilder::stat::MAIN_STAT_MNG.clearStat();

    ///////// duration count
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stopTime - startTime);

    std::cout << "tracing take " << duration.count() << std::endl;
}