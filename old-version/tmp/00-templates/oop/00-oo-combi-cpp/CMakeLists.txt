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
    main.cpp
    simple-rectangle-in.cpp
    simple-rectangle-out.cpp
    simple-triangle-in.cpp
    simple-triangle-out.cpp
    simple-figure-in.cpp
    simple-container-constr.cpp
    simple-container-in.cpp
    simple-container-out.cpp

    coord-rectangle-in.cpp
    coord-rectangle-out.cpp
    coord-triangle-in.cpp
    coord-triangle-out.cpp
    coord-figure-in.cpp
    coord-container-constr.cpp
    coord-container-in.cpp
    coord-container-out.cpp

)

add_executable(evo-demo ${SOURCE_FILES})

