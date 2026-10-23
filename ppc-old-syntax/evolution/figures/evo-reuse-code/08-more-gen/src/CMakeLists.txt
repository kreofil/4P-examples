# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    ../../01-start/src/figure.h
    ../../01-start/src/rectangle.h
    ../../01-start/src/figure-rectangle.h
    ../../01-start/src/triangle.h
    ../../01-start/src/figure-triangle.h
    ../../01-start/src/container.h
    new-generalization.h

    #sources
    ../../01-start/src/figure-in.c
    ../../01-start/src/figures-input.c
    ../../01-start/src/figure-out.c
    ../../01-start/src/figure-rectangle-in.c
    ../../01-start/src/figure-rectangle-out.c
    ../../01-start/src/figure-triangle-in.c
    ../../01-start/src/figure-triangle-out.c
    ../../01-start/src/rectangle-in.c
    ../../01-start/src/rectangle-out.c
    ../../01-start/src/triangle-in.c
    ../../01-start/src/triangle-out.c
    ../../03-new-func/src/triangle-perimeter.c
    ../../01-start/src/container-constr.c
    ../../01-start/src/container-in.c
    ../../01-start/src/container-out.c
    ../../03-new-func/src/figure-perimeter.c
    ../../03-new-func/src/figure-rectangle-perimeter.c
    ../../03-new-func/src/figure-triangle-perimeter.c
    ../../03-new-func/src/rectangle-perimeter.c
    ../../03-new-func/src/container-perimeter-out.c
    new-generalization.c
    main.c
)

add_executable(08-more-gen ${SOURCE_FILES})
