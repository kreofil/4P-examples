# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
#SET(CMAKE_C_COMPILER ppclang)
# SET(CMAKE_C_COMPILER clang)
SET(CMAKE_CPP_COMPILER g++)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

#set(BUILD_DIR "${CMAKE_BINARY_DIR}")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")
set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS}")

add_executable(test-stat-lib main.cpp)

# Линковка программы с библиотекой body
target_link_libraries(test-stat-lib
  -Wl,--whole-archive
  body
  -Wl,--no-whole-archive
)
