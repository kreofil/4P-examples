# set minimum cmake version
cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

# project name and language
project(c-evolution_example LANGUAGES C)

#set(CMAKE_C_STANDARD 17)
#set(CMAKE_C_STANDARD_REQUIRED on)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

#set(CMAKE_C_COMPILER "/usr/bin/c")
#set(CMAKE_CXX_COMPILER "/usr/bin/clang")

message(STATUS "Is the C compiler loaded? ${CMAKE_C_COMPILER_LOADED}")
if(CMAKE_CXX_COMPILER_LOADED)
  message(STATUS "The C compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
  message(STATUS "The C compiler version is: ${CMAKE_CXX_COMPILER_VERSION}")
endif()

#set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type is Release" FORCE)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

#add_executable(smile main.cpp)

#target_compile_features(smile PRIVATE cxx_auto_type cxx_range_for)
add_subdirectory(./src)

#target_link_libraries(smile "src/compiler")     # Линковка программы с библиотекой
