# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(prototype)               # Название проекта
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    simple-figure-container.h
    simple-figure.h
    simple-rectangle.h
    simple-triangle.h

    #sources
    main.c

    simple-figure-container.c
    simple-figure.c
    simple-rectangle.c
    simple-triangle.c
)

add_executable(prototype ${SOURCE_FILES})
