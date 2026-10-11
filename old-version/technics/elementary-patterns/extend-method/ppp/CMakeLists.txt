# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(extend-method)               # Название проекта
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    rectangle.h
    triangle.h
    figure-rectangle.h
    figure-triangle.h

    #sources
    figure.c
    figure-rectangle.c
    figure-triangle.c
    rectangle.c
    triangle.c

    figures-input.c
    main.c
)

add_executable(extend-method ${SOURCE_FILES} )
# target_link_libraries(extend-method m)

