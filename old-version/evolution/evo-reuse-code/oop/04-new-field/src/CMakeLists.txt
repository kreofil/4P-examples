# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    # figure.h
    # rectangle.h
    # triangle.h
    # decorator.h
    # container.h

    #sources
    ../../01-start/src/rectangle-in.cpp
    ../../01-start/src/rectangle-out.cpp
    ../../01-start/src/triangle-in.cpp
    ../../01-start/src/triangle-out.cpp
    ../../01-start/src/rectangle-factory.cpp
    ../../01-start/src/triangle-factory.cpp
    ../../01-start/src/container-constr.cpp
    ../../01-start/src/container-in.cpp
    ../../01-start/src/container-out.cpp
    ../../01-start/src/main.cpp
    decorator-in.cpp
    decorator-out.cpp
    figure-factory.cpp
)

add_executable(04-new-field ${SOURCE_FILES})
