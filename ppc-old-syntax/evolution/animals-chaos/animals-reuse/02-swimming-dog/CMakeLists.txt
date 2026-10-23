# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(animals)               # Название проекта
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../../bin")

include_directories(BEFORE
    ../01-start
)

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    ../01-start/animals.pph
    swimming-dog.pph

    #sources
    ../01-start/animals.ppc
    swimming-dog.ppc

    main.ppc
)

# Для того, чтобы clang понимал файлы с другим расширением (ppc, например)
set_source_files_properties(
    ${SOURCE_FILES}
    PROPERTIES
    LANGUAGE C
)

add_executable(02-swimming-dog ${SOURCE_FILES})
