# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(srp)               # Название проекта
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    figure.h
    rectangle.h
    triangle.h
    container.h

    client-draw.h
    client-geometry.h

    #sources
    main.cpp

    rectangle.cpp
    triangle.cpp
    figure-in.cpp
    container.cpp

    client-draw.cpp
    client-geometry.cpp
)

add_executable(srp ${SOURCE_FILES})
