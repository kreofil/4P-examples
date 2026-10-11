# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(enum)               # Название проекта
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers

    #sources
    main.ppc
)

# Для того, чтобы clang понимал файлы с другим расширением (ppc, например)
set_source_files_properties(
    ${SOURCE_FILES}
    PROPERTIES
    LANGUAGE C
)

add_executable(enum ${SOURCE_FILES} )
# target_link_libraries(extend-method m)

