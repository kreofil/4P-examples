# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(evo-demo)               # Название проекта
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    rectangle_atd.h
    shape_atd.h
    triangle_atd.h

    #sources
    container_Out.cpp
    rectangle_In.cpp
    shape_In.cpp
    triangle_In.cpp
    container_Area.cpp
    main.cpp
    rectangle_Out.cpp
    shape_Out.cpp
    triangle_Out.cpp
    container_atd.h
    rectangle_Area.cpp
    shape_Area.cpp
    triangle_Area.cpp
    container_Constr.cpp
    container_In.cpp
    rectangle_Constr.cpp
    shape_Constr.cpp
    triangle_Constr.cpp
)

add_executable(evo-demo ${SOURCE_FILES})
