# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CMAKE_BUILD_TYPE Debug)

# SET(MYCOMPILE_FLAGS "-xc")
# SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${MYCOMPILE_FLAGS}")

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

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g")

add_executable(e-life ${SOURCE_FILES})
