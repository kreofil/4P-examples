# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# Установка переменной со списком исходников
set(SOURCE_LIB
    # headers
    #rectangle.h
    #triangle.h
    figure.h
    container.h

    #sources
    #rectangle-in.c
    #rectangle-out.c
    #triangle-in.c
    #triangle-out.c
    figure-in.c
    figure-out.c
    container-constr.c
    container-in.c
    container-out.c
)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

add_library(figure STATIC
    ${SOURCE_LIB}
)   # Создание статической библиотеки

# Линковка figure с  rectangle и triangle
target_link_libraries(figure
    rectangle
    triangle
)

