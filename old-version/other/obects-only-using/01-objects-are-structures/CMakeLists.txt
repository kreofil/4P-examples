# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(evo-demo)               # Название проекта
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_C_STANDARD 17)
#set(CMAKE_C_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)
# Настройка флагов компиляции
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -xc")

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    constant.h
    parent.h
    objects.h

    #sources
    parent.c
    objects.c
    figures-input.c
    main.c
)

add_executable(evo-demo ${SOURCE_FILES})
