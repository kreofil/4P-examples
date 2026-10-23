# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# project name and language
project(e-life)
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_C_STANDARD 17)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

add_subdirectory(src)
