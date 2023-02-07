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
        components/regMap/regMapper.h
        components/regMap/regMapper.cpp
        components/inst/rtInstr.cpp
        components/inst/rtInstr.h
        tracers/statPool.h
        tracers/statPool.cpp
        components/inst/instr_model.cpp
        components/inst/instr_model.h
        ioHelp/strHelp.cpp
        ioHelp/strHelp.h
        tracers/instrWd.cpp
        components/memMap/MemMng.cpp
        components/memMap/MemMng.h
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
        components/inst/operand.cpp components/inst/operand.h)



TARGET_LINK_LIBRARIES( traceBuilder PRIVATE ${Boost_LIBRARIES} Threads::Threads ${PROTOBUF_LIBRARY}  )
