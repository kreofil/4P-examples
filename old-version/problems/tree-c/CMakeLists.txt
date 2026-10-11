# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(bin-tree)               # Название проекта
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    value.h
    pair.h
    tree.h

    #sources
    nametable.c
    value.c
    pair.c
    tree.c

    main.c
)

add_executable(bin-tree ${SOURCE_FILES} )
# target_link_libraries(extend-method m)

