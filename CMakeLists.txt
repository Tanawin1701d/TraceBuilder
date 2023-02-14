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
        tracers/tracer.cpp
        tracers/tracer.h
        resMng/regMap/regMapper.h
        resMng/regMap/regMapper.cpp
        components/inst_model/rt_instr.cpp
        components/inst_model/rt_instr.h
        stat/statPool.h
        stat/statPool.cpp
        components/thread_model/thread_model.cpp
        components/thread_model/thread_model.h
        ioHelp/strHelp.cpp
        ioHelp/strHelp.h
        tracers/uop_wd.cpp
        resMng/memMng/MemMng.cpp
        resMng/memMng/MemMng.h
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
        tracerFrontEnd/staticTraceVar.h
        components/uop/uop_base.cpp
        components/uop/uop_base.h
        components/uop/dep.cpp
        components/uop/dep.h
        components/uop/decoder.cpp
        components/uop/decoder.h
        tracers/uop_wd.h
        tracerFrontEnd/dynTraceVar.h
        core/core.h
        tracerFrontEnd/traceToolFed.cpp tracerFrontEnd/traceToolFed.h)



TARGET_LINK_LIBRARIES( traceBuilder PRIVATE ${Boost_LIBRARIES} Threads::Threads ${PROTOBUF_LIBRARY}  )
