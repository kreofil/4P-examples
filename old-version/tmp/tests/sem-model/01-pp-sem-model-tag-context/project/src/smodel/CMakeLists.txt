# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

# Установка переменной со списком исходников
set(SOURCE_LIB
    # headers
    constant.h
    constant-spec.h
    context.h
    context-spec.h

    #sources
    constant-spec.c
    context-spec.c
)

add_library(smodel STATIC ${SOURCE_LIB})   # Создание статической библиотеки

