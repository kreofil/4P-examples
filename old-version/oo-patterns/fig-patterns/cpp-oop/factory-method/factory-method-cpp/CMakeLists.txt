# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(factory-method)               # Название проекта
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

    figure-creator.h
    simple-rectangle-creator.h
    simple-triangle-creator.h

    #sources
    main.cpp
    input-figures.cpp

    simple-rectangle.cpp
    simple-triangle.cpp
    figure-container.cpp

    simple-rectangle-creator.cpp
    simple-triangle-creator.cpp
)

add_executable(factory-method ${SOURCE_FILES})

