
cmake_minimum_required(VERSION 3.23)
project(traceBuilder)
set(CMAKE_CXX_STANDARD 17)


#add_definitions(-Ddebug)
add_definitions(-DX86)

add_compile_options(-O3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-attributes")

include(FindProtobuf)
FIND_PACKAGE(Protobuf REQUIRED)
FIND_PACKAGE(Threads REQUIRED)
FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )

INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})
INCLUDE_DIRECTORIES( ${Boost_LIBRARIES} )
INCLUDE_DIRECTORIES( ./src )

add_custom_target(
        x86sim ALL
        COMMAND python3 ${CMAKE_SOURCE_DIR}/src/models/arch/x86/template/gen.py
        COMMENT "generating the x86 model"
)



FILE(GLOB_RECURSE SRC_CORE     RELATIVE ${CMAKE_SOURCE_DIR} "src/core/*.cpp")
FILE(GLOB_RECURSE SRC_MODEL    RELATIVE ${CMAKE_SOURCE_DIR} "src/models/*.cpp" EXCLUDE "src/models/arch/X86/*") # it may be changed due to architecture specification
FILE(GLOB_RECURSE SRC_STAT     RELATIVE ${CMAKE_SOURCE_DIR} "src/stat/*.cpp")
FILE(GLOB_RECURSE SRC_IOH      RELATIVE ${CMAKE_SOURCE_DIR} "src/ioHelp/*.cpp")  # stand for io helper
FILE(GLOB_RECURSE SRC_IOHCC    RELATIVE ${CMAKE_SOURCE_DIR} "src/ioHelp/*.cc")
FILE(GLOB_RECURSE SRC_ARCH_X86 RELATIVE ${CMAKE_SOURCE_DIR} "src/models/arch/X86/*.cpp")
FILE(GLOB_RECURSE SRC_EXAMPLE  RELATIVE ${CMAKE_SOURCE_DIR} "src/example/*.cpp")

add_executable(
        traceBuilder
        src/main.cpp
        ${SRC_CORE}
        ${SRC_MODEL}
        ${SRC_STAT}
        ${SRC_IOH}
        ${SRC_IOHCC}
        ${SRC_ARCH_X86}
        ${SRC_EXAMPLE}
        )

TARGET_LINK_LIBRARIES( traceBuilder PRIVATE ${Boost_LIBRARIES} Threads::Threads ${PROTOBUF_LIBRARY} )

ADD_DEPENDENCIES(traceBuilder x86sim)