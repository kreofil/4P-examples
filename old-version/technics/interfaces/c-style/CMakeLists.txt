# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(interface)               # Название проекта
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    figure.h
    rectangle.h
    triangle.h
    inout-rectangle.h
    inout-triangle.h
    geometry-rectangle.h
    geometry-triangle.h

    #sources
    inout.c
    inout-rectangle.c
    inout-triangle.c
    rectangle-inout.c
    triangle-inout.c

    geometry.c
    geometry-rectangle.c
    geometry-triangle.c
    rectangle-geometry.c
    triangle-geometry.c
    figures-input.c
    main.c
)

add_executable(interface ${SOURCE_FILES} )
target_link_libraries(interface m)

