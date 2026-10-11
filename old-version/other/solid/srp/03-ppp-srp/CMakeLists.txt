# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(srp)               # Название проекта
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    figure.h
    rectangle.h
    figure-rectangle.h
    triangle.h
    figure-triangle.h
    container.h
    drawing-client.h
    geometry-client.h

    #sources
    figure-in.c
    figures-input.c
    figure-out.c
    figure-perimeter.c
    figure-area.c
    figure-rectangle-in.c
    figure-rectangle-out.c
    figure-rectangle-perimeter.c
    figure-rectangle-area.c
    figure-triangle-in.c
    figure-triangle-out.c
    figure-triangle-perimeter.c
    figure-triangle-area.c
    rectangle-in.c
    rectangle-out.c
    rectangle-perimeter.c
    rectangle-area.c
    triangle-in.c
    triangle-out.c
    triangle-perimeter.c
    triangle-area.c
    container-constr.c
    container-in.c
    container-out.c
    container-perimeter-out.c
    container-area-out.c
    geometry-client.c

    main.c
)

add_executable(srp ${SOURCE_FILES})

# Линкуем математическую библиотеку к нашему проекту
target_link_libraries(srp PRIVATE m)
