# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# project name and language
project(lib-tests)
SET(CMAKE_C_COMPILER ppclang)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BUILD_DIR}/../lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${BUILD_DIR}/../lib")

#set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type is Release" FORCE)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

#add_executable(smile main.cpp)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(BEFORE
    src/body
)
link_directories(./lib)

add_subdirectory(src/launcher)
add_subdirectory(src/body)
