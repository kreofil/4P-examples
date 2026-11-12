# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CMAKE_C_COMPILER ppchibicc CACHE FILEPATH "Компилятор C")
project(evo-demo)               # Название проекта


# set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)
set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type is Release" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(HEADERS_FILES
    # headers
    figure.h
    circle.h
    rectangle.h
    triangle.h
    container.h
)

set(SOURCE_FILES
    #sources
    figure-in.c
    figures-input.c
    figure-out.c
    figure-perimeter.c
    figure-circle-in.c
    figure-circle-out.c
    figure-rectangle-in.c
    figure-rectangle-out.c
    figure-triangle-in.c
    figure-triangle-out.c
    circle-in.c
    circle-out.c
    rectangle-in.c
    rectangle-out.c
    triangle-in.c
    triangle-out.c
    container-constr.c
    container-in.c
    container-out.c
    container-perimeter-out.c
    main.c
)

add_executable(evo-demo ${SOURCE_FILES})

# Основной режим компиляции: LLVM с уровнем O2.
target_compile_options(evo-demo PRIVATE --backend=llvm -O2)
target_link_options(evo-demo PRIVATE --backend=llvm)

# enable_testing()
# add_test(NAME figures-run
#     COMMAND evo-demo "${CMAKE_CURRENT_SOURCE_DIR}/data/input1.txt"
#                      "${CMAKE_CURRENT_BINARY_DIR}/output1.txt")
# add_test(NAME figures-output
#     COMMAND "${CMAKE_COMMAND}" -E compare_files
#             "${CMAKE_CURRENT_SOURCE_DIR}/data/output1.txt"
#             "${CMAKE_CURRENT_BINARY_DIR}/output1.txt")
# set_tests_properties(figures-output PROPERTIES DEPENDS figures-run)
