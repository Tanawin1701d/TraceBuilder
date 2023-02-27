cmake_minimum_required(VERSION 3.23)
project(traceBuilder)
set(CMAKE_CXX_STANDARD 17)
#add_definitions(-Ddebug)
include(FindProtobuf)
find_package(Protobuf REQUIRED)
find_package(Threads REQUIRED)

include_directories(${PROTOBUF_INCLUDE_DIR})

#message("${Protobuf_LIBRARIES} dssssdddd")

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_LIBRARIES} )

add_executable(traceBuilder
        main.cpp
        core/tracers/tracer.cpp
        core/tracers/tracer.h
        core/resMng/regMap/regMapper.h
        core/resMng/regMap/regMapper.cpp
        components/inst_model/rt_instr.cpp
        components/inst_model/rt_instr.h
        stat/statPool.h
        stat/statPool.cpp
        components/thread_model/thread_model.cpp
        components/thread_model/thread_model.h
        ioHelp/strHelp.cpp
        ioHelp/strHelp.h
        core/tracers/uop_wd.cpp
        core/resMng/memMng/MemMng.cpp
        core/resMng/memMng/MemMng.h
####### protohelp
        ioHelp/protoHelp/protoio.hh
        ioHelp/protoHelp/protobuf.cc
        ioHelp/protoHelp/protoio.cc
        ioHelp/protoHelp/inst_dep_record.pb.h
        ioHelp/protoHelp/inst_dep_record.pb.cc
        ioHelp/protoHelp/packet.pb.h
        ioHelp/protoHelp/packet.pb.cc
####### pin input file
        ioHelp/pinIoSh/pinIo.h
        ioHelp/pinIoSh/pinIo.cpp
        components/inst_model/operand.cpp
        components/inst_model/operand.h
        components/inst_model/opcode.h
        core/tracerFrontEnd/staticTraceVar.h
        components/arch/uop_base.cpp
        components/arch/uop_base.h
        components/arch/dep.cpp
        components/arch/dep.h
        components/arch/decoder.cpp
        components/arch/decoder.h
        core/tracers/uop_wd.h
        core/tracerFrontEnd/dynTraceVar.h
        core/core.h
        core/tracerFrontEnd/traceToolFed.cpp
        core/tracerFrontEnd/traceToolFed.h
        core/tracerFrontEnd/legacyPin/lagacy_pin.cpp
        core/tracerFrontEnd/legacyPin/lagacy_pin.h
        core/resultFrontEnd/resultFed.cpp
        core/resultFrontEnd/resultFed.h
        components/arch/x86/build/uop/x86_uop.h
        components/arch/x86/build/uop/x86_uop.cpp
        components/arch/mop_base.cpp
        components/arch/mop_base.h
        components/arch/x86/build/mop/x86_mop.h
        components/arch/x86/build/mop/x86_mop.cpp
        components/arch/x86/build/decoder/x86_dec.h
        components/arch/x86/build/decoder/x86_dec.cpp)



TARGET_LINK_LIBRARIES( traceBuilder PRIVATE ${Boost_LIBRARIES} Threads::Threads ${PROTOBUF_LIBRARY}  )
