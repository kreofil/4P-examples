# set minimum cmake version
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

# project name and language
project(containers)
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_C_STANDARD 17)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BUILD_DIR}/../lib")

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(BEFORE
    src/include
)
link_directories(./lib)

add_subdirectory(src/ppvector)
add_subdirectory(src/pplist)

add_subdirectory(tests/ppvector-common)
add_subdirectory(tests/pplist-common)

# add_subdirectory(examples/ppvector-sum-int)
# add_subdirectory(examples/ppvector-sum-double)
# add_subdirectory(examples/ppvector-sum-int-ptr)
# add_subdirectory(examples/ppvector-figures)

# add_subdirectory(examples/pplist-sum-int)
