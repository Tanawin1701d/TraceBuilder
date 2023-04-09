#include <iostream>
#include <chrono>
#include "example/simplePinGem.h"
#include "stat/statPool.h"

using namespace std::chrono;


int main() {

    auto startTime = high_resolution_clock::now();

    auto test = SIMPLE_PIN_GEM(
                "/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/testStaticOutput/fluidInstr",
                "/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/testDynOutput/fluidData",
                "/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/testProtoOuput/fluid/instr",
                "/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/testProtoOuput/fluid/data"
            );

    test.start();



//    MAIN_STAT["test"  ]["dgdfdf"] = 0;
//    MAIN_STAT["ffdfdf"]["dgdfdf"]["dfdfdffd"]++;
//    Test tt;
//    tt.dosomthing();


    std::vector<std::string> statHelper;
    MAIN_STAT_MNG.preparePrint(statHelper);
    MAIN_STAT_MNG.print();
    MAIN_STAT_MNG.saveToFile("/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/testProtoStat/fluid.stat");
    MAIN_STAT_MNG.clearStat();

    ///////// duration count
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stopTime - startTime);

    std::cout << "tracing take " << duration.count() << std::endl;
}