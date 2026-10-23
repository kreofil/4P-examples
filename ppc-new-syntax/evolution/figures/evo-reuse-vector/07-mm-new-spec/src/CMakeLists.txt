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
    ../../02-new-spec/src/circle.h
    ../../02-new-spec/src/figure-circle.h
    ../../01-start/src/rectangle.h
    ../../01-start/src/figure-rectangle.h
    ../../01-start/src/triangle.h
    ../../01-start/src/figure-triangle.h
    ../../01-start/src/container.h

    #sources
    ../../01-start/src/figure-in.c
    ../../01-start/src/figures-input.c
    ../../01-start/src/figure-out.c
    ../../02-new-spec/src/figure-circle-in.c
    ../../02-new-spec/src/figure-circle-out.c
    ../../01-start/src/figure-rectangle-in.c
    ../../01-start/src/figure-rectangle-out.c
    ../../01-start/src/figure-triangle-in.c
    ../../01-start/src/figure-triangle-out.c
    ../../02-new-spec/src/circle-in.c
    ../../02-new-spec/src/circle-out.c
    ../../01-start/src/rectangle-in.c
    ../../01-start/src/rectangle-out.c
    ../../01-start/src/triangle-in.c
    ../../01-start/src/triangle-out.c
    ../../06-mm/src/multimethod.c
    multimethod-continue.c
    ../../01-start/src/container-constr.c
    ../../01-start/src/container-in.c
    ../../01-start/src/container-out.c
    ../../06-mm/src/container-mm-out.c
    ../../06-mm/src/main.c
)

add_executable(07-mm-new-spec ${SOURCE_FILES})

# Линковка программы с библиотекой body
target_link_libraries(07-mm-new-spec
  -Wl,--whole-archive
  ppvector
  -Wl,--no-whole-archive
)
