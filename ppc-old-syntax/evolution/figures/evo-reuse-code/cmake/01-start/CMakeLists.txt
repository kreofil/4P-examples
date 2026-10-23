# set minimum cmake version
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

# project name and language
project(01-start)
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_C_STANDARD 17)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../../../bin")

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(BEFORE
    ../../01-start/src
)

add_subdirectory("../../01-start/src" "bin")
