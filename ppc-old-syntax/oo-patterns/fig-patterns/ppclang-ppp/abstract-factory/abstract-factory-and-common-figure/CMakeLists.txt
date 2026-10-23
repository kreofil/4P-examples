# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(abstract-factory)               # Название проекта
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    simple-rectangle.h
    simple-triangle.h

    coord-point.h
    coord-rectangle.h
    coord-triangle.h

    rectangle.h
    triangle.h
    figure.h
    container.h

    figure-factory.h

    #sources
    main.c

    simple-rectangle-inout.c
    simple-triangle-inout.c

    coord-rectangle-inout.c
    coord-triangle-inout.c

    figure-factory.c
    figure-out.c
    figures-input.c

    rectangle-inout.c
    triangle-inout.c

    container.c
)

add_executable(abstract-factory ${SOURCE_FILES})

