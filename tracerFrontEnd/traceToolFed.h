//
// Created by tanawin on 14/2/2566.
//

#ifndef TRACEBUILDER_TRACETOOLFED_H
#define TRACEBUILDER_TRACETOOLFED_H

//#include "staticTraceVar.h"
//#include "dynTraceVar.h"
#include <fstream>
#include <cassert>


class TRACER_BASE;
class THREAD_MODEL;

///// for now we assume that stream front-end and file front end share same input trace function
class TRACE_TOOL_FRONT_END{
protected:
    THREAD_MODEL*    tmd; // for static trace to send static instruction to build runtime instruction
    TRACER_BASE*     tracer; // for runtime trace; the runtime data will be integrate with
    // runtime instruction to generate precise micro op


public:

    TRACE_TOOL_FRONT_END();

    void setListenners(THREAD_MODEL* _tmd, TRACER_BASE* _tracer);

    virtual ~TRACE_TOOL_FRONT_END() = 0;

    virtual void start() = 0;

};

class LAGACY_PIN_TRACER : public TRACE_TOOL_FRONT_END{

private:
    std::string fileName_static; // file name to opend static trace
    std::string fileName_dyn; // file name to open
    std::ifstream* staticFile;
    std::ifstream* dynFile;

    void startStaticTrace();
    void startDynTrace();

public:
    LAGACY_PIN_TRACER(
                      std::string _fileName_static,
                      std::string _fileName_dyn
                      );

    ~LAGACY_PIN_TRACER() override;

    void start();

};

#endif //TRACEBUILDER_TRACETOOLFED_H
