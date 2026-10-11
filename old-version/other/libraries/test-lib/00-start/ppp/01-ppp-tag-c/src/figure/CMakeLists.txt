# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
#SET(CMAKE_C_COMPILER ppclang)

# Установка переменной со списком исходников
set(SOURCE_LIB
    # headers
    figure.h
    figure-rectangle.h
    figure-triangle.h

    #sources
    figure-in.c
    figures-input.c
    figure-out.c
    figure-rectangle-in.c
    figure-rectangle-out.c
    figure-triangle-in.c
    figure-triangle-out.c
)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

add_library(figure STATIC ${SOURCE_LIB})   # Создание статической библиотеки

# Линковка figure с  rectangle и triangle
target_link_libraries(figure
    rectangle
    triangle
)
