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
    figure-container.h

    simple-rectangle.h
    simple-triangle.h

    builder.h
    applique-collector.h
    simple-figures-builder.h
    figures-counter-builder.h

    #sources
    main.cpp
    simple-rectangle.cpp
    simple-triangle.cpp
    figure-container.cpp

    applique-collector.cpp
    simple-figures-builder.cpp
    figures-counter-builder.cpp
)

add_executable(builder ${SOURCE_FILES})

