# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    # figure.h
    # circlt.h
    # rectangle.h
    # triangle.h
    # container.h

    #sources
    ../../01-start/src/rectangle-in.cpp
    ../../01-start/src/rectangle-out.cpp
    ../../01-start/src/triangle-in.cpp
    ../../01-start/src/triangle-out.cpp
    ../../01-start/src/container-constr.cpp
    ../../01-start/src/container-in.cpp
    ../../01-start/src/container-out.cpp
    ../../01-start/src/figure-factory.cpp
    ../../01-start/src/rectangle-factory.cpp
    ../../01-start/src/triangle-factory.cpp
    ../../02-new-spec/src/circle-in.cpp
    ../../02-new-spec/src/circle-out.cpp
    ../../02-new-spec/src/circle-factory.cpp
    ../../06-mm/src/multimethod.cpp
    ../../06-mm/src/container-mm-out.cpp
    ../../06-mm/src/main.cpp
    multimethod-new-spec.cpp
)

add_executable(07-mm-new-spec ${SOURCE_FILES})
