# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

# Установка переменной со списком исходников
set(SOURCE_LIB
    # headers
    constant.h
    constant-spec.h

    #sources
    constant-spec.c
)

add_library(smodel STATIC ${SOURCE_LIB})   # Создание статической библиотеки

