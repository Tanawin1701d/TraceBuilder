
cmake_minimum_required(VERSION 3.23)
project(traceBuilder)
set(CMAKE_CXX_STANDARD 17)
#add_definitions(-Ddebug)
add_definitions(-DX86)


include(FindProtobuf)
FIND_PACKAGE(Protobuf REQUIRED)
FIND_PACKAGE(Threads REQUIRED)
FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )

INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})
INCLUDE_DIRECTORIES( ${Boost_LIBRARIES} )
INCLUDE_DIRECTORIES( . )


add_custom_target(
        x86sim ALL
        COMMAND python3 ${CMAKE_SOURCE_DIR}/models/x86/template/gen.py
        COMMENT "generating the x86 model"
)



FILE(GLOB_RECURSE SRC_CORE     RELATIVE ${CMAKE_SOURCE_DIR} "core/*.cpp")
FILE(GLOB_RECURSE SRC_MODEL    RELATIVE ${CMAKE_SOURCE_DIR} "models/*.cpp" EXCLUDE "models/arch/x86/*") # it may be changed due to architecture specification
FILE(GLOB_RECURSE SRC_STAT     RELATIVE ${CMAKE_SOURCE_DIR} "stat/*.cpp")
FILE(GLOB_RECURSE SRC_IOH      RELATIVE ${CMAKE_SOURCE_DIR} "ioHelp/*.cpp")  # stand for io helper
FILE(GLOB_RECURSE SRC_ARCH_X86 RELATIVE ${CMAKE_SOURCE_DIR} "models/arch/x86/*.cpp")

add_executable(
        traceBuilder
        main.cpp
        ${SRC_CORE}
        ${SRC_MODEL}
        ${SRC_STAT}
        ${SRC_IOH}
        ${SRC_ARCH_X86}
        example/simplePinGem.cpp example/simplePinGem.h)

TARGET_LINK_LIBRARIES( traceBuilder PRIVATE ${Boost_LIBRARIES} Threads::Threads ${PROTOBUF_LIBRARY} )

ADD_DEPENDENCIES(traceBuilder x86sim)