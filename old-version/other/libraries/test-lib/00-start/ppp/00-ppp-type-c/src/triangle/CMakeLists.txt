# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
#SET(CMAKE_C_COMPILER ppclang)

# Установка переменной со списком исходников
set(SOURCE_LIB
    # headers
    triangle.h

    #sources
    triangle-in.c
    triangle-out.c
)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

add_library(triangle STATIC ${SOURCE_LIB})   # Создание статической библиотеки
