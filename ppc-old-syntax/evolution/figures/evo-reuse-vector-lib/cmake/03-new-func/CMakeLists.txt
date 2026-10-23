# set minimum cmake version
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

# project name and language
project(03-new-func)
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_C_STANDARD 17)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../../../bin")

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(BEFORE
    ../../vector-lib/include
    ../../01-start/src
    ../../03-new-func/src
)
link_directories(../../lib)

add_subdirectory("../../03-new-func/src" "bin")