# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(rect-perimeter)               # Название проекта
SET(CMAKE_C_COMPILER ppclang)
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -xc")
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    ppp-thread.h
    rectangle-thread.h

    #sources
    ppp-thread.c
    rectangle-thread.c

    main.c
)

add_executable(rect-perimeter ${SOURCE_FILES})
