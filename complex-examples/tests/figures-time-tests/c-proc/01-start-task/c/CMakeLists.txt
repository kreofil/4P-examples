# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# set(CMAKE_C_COMPILER ppchibicc CACHE FILEPATH "Компилятор C")
project(evo-demo)               # Название проекта

# set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)
set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type is Release" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(HEADERS_FILES
    # headers
    rectangle.h
    triangle.h
    figure.h
    container.h
)

set(SOURCE_FILES
   #sources
    main.c
    rectangle-in.c
    rectangle-out.c
    rectangle-perimeter.c
    triangle-in.c
    triangle-out.c
    triangle-perimeter.c
    figure-in.c
    figure-out.c
    figure-perimeter.c
    container-constr.c
    container-in.c
    container-out.c
    container-perimeter-out.c
)

add_executable(evo-demo ${SOURCE_FILES})

target_compile_options(evo-demo PRIVATE
    $<$<CONFIG:Release>:-O2>
    $<$<CONFIG:Debug>:-O0 -g>
)

# Основной режим компиляции: LLVM с уровнем O2.
# target_compile_options(evo-demo PRIVATE --backend=llvm -O2)
# target_link_options(evo-demo PRIVATE --backend=llvm)

