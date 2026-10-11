# set minimum cmake version
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

# project name and language
project(02-new-spec)
SET(CMAKE_CPP_COMPILER clang++)
# SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_CPP_STANDARD 23)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../../../bin")

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(BEFORE
    ../../01-start/include
    ../../01-start/include/triangle
    ../../01-start/include/factories
    ../../02-new-spec/include/
    ../../02-new-spec/include/factories/
)

add_subdirectory("../../02-new-spec/src" "bin")
