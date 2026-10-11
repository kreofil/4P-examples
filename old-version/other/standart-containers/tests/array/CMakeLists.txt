# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(array-test)               # project name
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BUILD_DIR}/../../lib")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
link_directories(../../lib)

add_executable(test-stat-array-lib main.c)

# Линковка программы с библиотекой body
target_link_libraries(test-stat-array-lib
    -Wl,--whole-archive
    containers
    -Wl,--no-whole-archive
)

