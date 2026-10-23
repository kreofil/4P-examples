# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CMAKE_BUILD_TYPE Debug)

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    entity.h
    eworld.h
    feeder.h
    food.h
    map.h

    #sources
    main.c
    entity.c
    eworld.c
    #feeder.c
    food.c
    map.c
    )

add_executable(e-life ${SOURCE_FILES})
