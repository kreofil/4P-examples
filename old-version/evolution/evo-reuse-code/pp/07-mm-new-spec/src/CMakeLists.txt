# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    ../../01-start/src/rectangle.h
    ../../01-start/src/triangle.h
    ../../01-start/src/container.h
    ../../02-new-spec/src/circle.h
    ../../02-new-spec/src/figure.h

    #sources
    ../../01-start/src/rectangle-in.c
    ../../01-start/src/rectangle-out.c
    ../../01-start/src/triangle-in.c
    ../../01-start/src/triangle-out.c
    ../../01-start/src/container-constr.c
    ../../01-start/src/container-in.c
    ../../01-start/src/container-out.c
    ../../02-new-spec/src/circle-in.c
    ../../02-new-spec/src/circle-out.c
    ../../02-new-spec/src/figure-in.c
    ../../02-new-spec/src/figure-out.c
    ../../06-mm/src/container-mm-out.c
    ../../06-mm/src/main.c
    multimethod.c
)

add_executable(07-mm-new-spec ${SOURCE_FILES})

