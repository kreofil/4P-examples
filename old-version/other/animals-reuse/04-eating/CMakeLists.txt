# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(animals)               # Название проекта
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../../bin")

include_directories(BEFORE
    ../01-start/
    ../02-swimming-dog/
    ../03-diving-penguin/
)

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    ../01-start/animals.pph
    ../02-swimming-dog/swimming-dog.pph
    ../03-diving-penguin/diving.pph
    eating.pph

    #sources
    ../01-start/animals.ppc
    ../02-swimming-dog/swimming-dog.ppc
    ../03-diving-penguin/diving.ppc
    eating.ppc

    main.ppc
)

# Для того, чтобы clang понимал файлы с другим расширением (ppc, например)
set_source_files_properties(
    ${SOURCE_FILES}
    PROPERTIES
    LANGUAGE C
)

add_executable(04-eating ${SOURCE_FILES})
