# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
# SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

# set(BUILD_DIR "${CMAKE_BINARY_DIR}")
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    ../../01-start/src/figure.h
    ../../01-start/src/rectangle.h
    ../../01-start/src/figure-rectangle.h
    ../../01-start/src/triangle.h
    ../../01-start/src/figure-triangle.h
    ../../01-start/src/container.h

    #sources
    ../../01-start/src/figure-in.c
    ../../01-start/src/figures-input.c
    ../../01-start/src/figure-out.c
    ../../01-start/src/figure-rectangle-in.c
    ../../01-start/src/figure-rectangle-out.c
    ../../01-start/src/figure-triangle-in.c
    ../../01-start/src/figure-triangle-out.c
    ../../01-start/src/rectangle-in.c
    ../../01-start/src/rectangle-out.c
    ../../01-start/src/triangle-in.c
    ../../01-start/src/triangle-out.c
    multimethod.c
    ../../01-start/src/container-constr.c
    ../../01-start/src/container-in.c
    ../../01-start/src/container-out.c
    container-mm-out.c
    main.c
)

add_executable(06-mm ${SOURCE_FILES})

# Линковка программы с библиотекой body
target_link_libraries(06-mm
  -Wl,--whole-archive
  ppvector
  -Wl,--no-whole-archive
)
