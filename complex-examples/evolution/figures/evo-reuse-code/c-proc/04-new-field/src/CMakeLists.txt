# set minimum cmake version
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    ../../01-start/src/rectangle.h
    ../../01-start/src/triangle.h
    ../../01-start/src/container.h
    figure.h

    #sources
    ../../01-start/src/rectangle-in.c
    ../../01-start/src/rectangle-out.c
    ../../01-start/src/triangle-in.c
    ../../01-start/src/triangle-out.c
    ../../01-start/src/container-constr.c
    ../../01-start/src/container-in.c
    ../../01-start/src/container-out.c
    ../../01-start/src/main.c
    figure-in.c
    figure-out.c
    figure-color-in.c
    figure-color-out.c
)

add_executable(04-new-field ${SOURCE_FILES})

