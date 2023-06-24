
cmake_minimum_required(VERSION 3.23)
project(traceBuilder)
set(CMAKE_CXX_STANDARD 17)


#add_definitions(-Ddebug)
add_definitions(-DX86)
add_definitions(-DMINI_GEN)
set(CMAKE_BUILD_TYPE Debug)
add_compile_options(-O3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-attributes")
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

include(FindProtobuf)
FIND_PACKAGE(Protobuf REQUIRED)
FIND_PACKAGE(Threads REQUIRED)
FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )

ADD_SUBDIRECTORY(lib/pybind11)

INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})
INCLUDE_DIRECTORIES( ${Boost_LIBRARIES} )
INCLUDE_DIRECTORIES(${Python_INCLUDE_DIRS})
INCLUDE_DIRECTORIES( ./src )

# generate x86 uop model
add_custom_target(
        x86UopsModel ALL
        COMMAND python3 ${CMAKE_SOURCE_DIR}/src/models/uop_model/pyMach/gen_main.py
        COMMENT "generating the x86 model"
)

# generate proto buffer file for result front end support
add_custom_target(
        protoGen ALL
        COMMAND python3 ${CMAKE_SOURCE_DIR}/src/ioHelp/protoHelp/protoGen.py
        COMMENT "generating the protobuffer"
)


FILE(GLOB_RECURSE SRC_BASE     RELATIVE ${CMAKE_SOURCE_DIR} "src/base/*.cpp")
FILE(GLOB_RECURSE SRC_CORE     RELATIVE ${CMAKE_SOURCE_DIR} "src/core/*.cpp")
FILE(GLOB_RECURSE SRC_PYBIND   RELATIVE ${CMAKE_SOURCE_DIR} "src/pyBind/*.cpp")
FILE(GLOB_RECURSE SRC_MODEL    RELATIVE ${CMAKE_SOURCE_DIR} "src/models/*.cpp" EXCLUDE "src/models/uop_model/X86/*") # it may be changed due to architecture specification
FILE(GLOB_RECURSE SRC_STAT     RELATIVE ${CMAKE_SOURCE_DIR} "src/stat/*.cpp")
FILE(GLOB_RECURSE SRC_IOH      RELATIVE ${CMAKE_SOURCE_DIR} "src/ioHelp/*.cpp")  # stand for io helper
FILE(GLOB_RECURSE SRC_IOHCC    RELATIVE ${CMAKE_SOURCE_DIR} "src/ioHelp/*.cc")
FILE(GLOB_RECURSE SRC_ARCH_X86 RELATIVE ${CMAKE_SOURCE_DIR} "src/models/uop_model/X86/*.cpp")
FILE(GLOB_RECURSE SRC_EXAMPLE  RELATIVE ${CMAKE_SOURCE_DIR} "src/example/*.cpp")

pybind11_add_module(traceBuilder
                    src/main.cpp
                    ${SRC_BASE}
                    ${SRC_CORE}
                    ${SRC_PYBIND}
                    ${SRC_MODEL}
                    ${SRC_STAT}
                    ${SRC_IOH}
                    ${SRC_IOHCC}
                    ${SRC_ARCH_X86}
                    ${SRC_EXAMPLE}

        )

TARGET_LINK_LIBRARIES( traceBuilder PRIVATE ${Boost_LIBRARIES} Threads::Threads ${PROTOBUF_LIBRARY} )

ADD_DEPENDENCIES(traceBuilder x86UopsModel)
ADD_DEPENDENCIES(traceBuilder protoGen)