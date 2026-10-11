# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(evo-demo)               # Название проекта
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    simple-rectangle.h
    simple-triangle.h
    simple-figure.h
    simple-container.h

    coord-point.h
    coord-rectangle.h
    coord-triangle.h
    coord-figure.h
    coord-container.h

    #sources
    main.c
    simple-rectangle-in.c
    simple-rectangle-out.c
    simple-triangle-in.c
    simple-triangle-out.c
    simple-figure-in.c
    simple-figure-out.c
    simple-container-constr.c
    simple-container-in.c
    simple-container-out.c

    coord-rectangle-in.c
    coord-rectangle-out.c
    coord-triangle-in.c
    coord-triangle-out.c
    coord-figure-in.c
    coord-figure-out.c
    coord-container-constr.c
    coord-container-in.c
    coord-container-out.c
)

add_executable(evo-demo ${SOURCE_FILES})

