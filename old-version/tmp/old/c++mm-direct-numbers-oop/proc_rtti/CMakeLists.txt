# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(numbers)               # Название проекта
SET(CMAKE_CPP_COMPILER c++)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    number.h
    int.h
    double.h

    #sources
    main.cpp
    int.cpp
    double.cpp
    minus.cpp
)

add_executable(numbers ${SOURCE_FILES})
