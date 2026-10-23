# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(evo-demo)               # Название проекта
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

    simple-rectangle.h
    simple-triangle.h

    coord-point.h
    coord-rectangle.h
    coord-triangle.h

    figure-factory.h
    simple-figure-factory.h
    coord-figure-factory.h

    #sources
    main.cpp
    figure-in.cpp
    container-constr.cpp
    container-in.cpp
    container-out.cpp

    simple-rectangle-in.cpp
    simple-rectangle-out.cpp
    simple-triangle-in.cpp
    simple-triangle-out.cpp

    coord-rectangle-in.cpp
    coord-rectangle-out.cpp
    coord-triangle-in.cpp
    coord-triangle-out.cpp

    simple-figure-factory.cpp
    coord-figure-factory.cpp
)

add_executable(abstract-factory ${SOURCE_FILES})

