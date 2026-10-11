# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
#SET(CMAKE_C_COMPILER ppclang)

# Установка переменной со списком исходников
set(SOURCE_LIB
    # headers
    figure.h
    rectangle.h
    figure-rectangle.h
    triangle.h
    figure-triangle.h
    container.h

    #sources
    figure-in.c
    figures-input.c
    figure-out.c
    figure-rectangle-in.c
    figure-rectangle-out.c
    figure-triangle-in.c
    figure-triangle-out.c
    rectangle-in.c
    rectangle-out.c
    triangle-in.c
    triangle-out.c
    container-constr.c
    container-in.c
    container-out.c
)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

add_library(body STATIC ${SOURCE_LIB})   # Создание статической библиотеки
