cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
project(MultiDirSharedLibExample)

# Set build type
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)

# Enable position-independent code globally
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_C_COMPILER ppclang)

# Add subdirectories
add_subdirectory(LibDirectory)
add_subdirectory(AppDirectory)