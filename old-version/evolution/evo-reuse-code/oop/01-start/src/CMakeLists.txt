# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    # figure.h
    # rectangle.h
    # triangle.h
    # container.h

    #sources
    rectangle-in.cpp
    rectangle-out.cpp
    triangle-in.cpp
    triangle-out.cpp
    figure-factory.cpp
    rectangle-factory.cpp
    triangle-factory.cpp
    container-constr.cpp
    container-in.cpp
    container-out.cpp
    main.cpp
)

add_executable(01-start ${SOURCE_FILES})
