# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# project name and language
project(sem-model)
SET(CMAKE_C_COMPILER ppclang)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BUILD_DIR}/../lib")

#set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type is Release" FORCE)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(BEFORE
    src/rectangle
    src/triangle
    src/figure
    src/container
)
link_directories(./lib)

add_subdirectory(src/rectangle)
add_subdirectory(src/triangle)
add_subdirectory(src/figure)
add_subdirectory(src/launcher)
add_subdirectory(src/container)
