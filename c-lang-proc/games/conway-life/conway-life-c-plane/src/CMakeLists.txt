# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
set(CMAKE_BUILD_TYPE Debug)

# set(BUILD_DIR "${CMAKE_BINARY_DIR}")
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    eworld.h
    map.h

    #sources
    main.c
    eworld.c
    map.c
    )

add_executable(conway-life ${SOURCE_FILES})
