# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    ../../01-start/src/figure.h
    ../../01-start/src/rectangle.h
    # ../../01-start/src/figure-rectangle.h
    ../../01-start/src/triangle.h
    # ../../01-start/src/figure-triangle.h
    ../../01-start/src/container.h
    figure-color.h


    #sources
    ../../01-start/src/figure-in.c
    ../../01-start/src/figures-input.c
    ../../01-start/src/figure-out.c
    # ../../01-start/src/figure-rectangle-in.c
    # ../../01-start/src/figure-rectangle-out.c
    # ../../01-start/src/figure-triangle-in.c
    # ../../01-start/src/figure-triangle-out.c
    ../../01-start/src/rectangle-in.c
    ../../01-start/src/rectangle-out.c
    ../../01-start/src/triangle-in.c
    ../../01-start/src/triangle-out.c
    ../../01-start/src/container-constr.c
    ../../01-start/src/container-in.c
    ../../01-start/src/container-out.c
    ../../01-start/src/main.c
    figure-color-in.c
    figure-color-out.c
)

add_executable(04-new-field ${SOURCE_FILES})
