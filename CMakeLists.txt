#cmake_minimum_required(VERSION 3.23)
#project(traceBuilder)
#
#set(CMAKE_CXX_STANDARD 17)
#
#FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
#INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
#
## Find the Protocol Buffers library
#find_package(Protobuf REQUIRED)
#
## Generate C++ code from the .proto file
#protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS my_proto_file.proto)
#
#add_executable(traceBuilder
#        main.cpp
#        tracers/tracer.cpp
#        tracers/tracer.h
#        components/regMap/regMapper.h
#        components/regMap/regMapper.cpp
#        components/inst/instr.cpp
#        components/inst/instr.h
#        components/memMap/memMap.h
#        components/memMap/memMap.cpp
#        tracers/statPool.h
#        tracers/statPool.cpp
##        ${PROTO_SRCS}  # Add the generated code to the project
##        ${PROTO_HDRS}
#        )
#
#TARGET_LINK_LIBRARIES( traceBuilder PRIVATE protobuf::libprotobuf ${Boost_LIBRARIES} )

cmake_minimum_required(VERSION 3.23)
project(traceBuilder)
set(CMAKE_CXX_STANDARD 17)

include(FindProtobuf)
find_package(Protobuf REQUIRED)
find_package(Threads REQUIRED)

include_directories(${PROTOBUF_INCLUDE_DIR})

message("${Protobuf_LIBRARIES} dssssdddd")

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_LIBRARIES} )

add_executable(traceBuilder
        main.cpp
        tracers/tracer.cpp
        tracers/tracer.h
        components/regMap/regMapper.h
        components/regMap/regMapper.cpp
        components/inst/instr.cpp
        components/inst/instr.h
#        components/memMap/memMap.h
#        components/memMap/memMap.cpp
        tracers/statPool.h
        tracers/statPool.cpp
        components/inst/instr_model.cpp
        components/inst/instr_model.h
        ioHelp/strHelp.cpp
        ioHelp/strHelp.h
        tracers/instrWd.cpp
        components/memMap/MemMng.cpp
        components/memMap/MemMng.h
        ioHelp/protoHelp/protoio.hh
        ioHelp/protoHelp/protobuf.cc
        ioHelp/protoHelp/protoio.cc
####### protobuf file
        ioHelp/protoHelp/inst_dep_record.pb.cc
        ioHelp/protoHelp/inst_dep_record.pb.h

        ioHelp/protoHelp/packet.pb.cc
        ioHelp/protoHelp/packet.pb.h

        )



TARGET_LINK_LIBRARIES( traceBuilder PRIVATE ${Boost_LIBRARIES} Threads::Threads ${PROTOBUF_LIBRARY}  )
