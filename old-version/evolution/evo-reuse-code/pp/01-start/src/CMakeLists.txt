# set minimum cmake version
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    rectangle.h
    triangle.h
    figure.h
    container.h

    #sources
    rectangle-in.c
    rectangle-out.c
    triangle-in.c
    triangle-out.c
    figure-in.c
    figure-out.c
    container-constr.c
    container-in.c
    container-out.c
    main.c
)

add_executable(01-start ${SOURCE_FILES})

