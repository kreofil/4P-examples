# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(extend-method)               # Название проекта
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    figure.h
    rectangle.h
    triangle.h

    #sources
    main.cpp

    rectangle.cpp
    triangle.cpp
    figure.cpp
    figures-input.cpp
)

add_executable(extend-method ${SOURCE_FILES})
