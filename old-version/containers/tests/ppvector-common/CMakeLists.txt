# set minimum cmake version
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers

    #sources
    test-ppvector-common.c
)

# Для того, чтобы clang понимал файлы с другим расширением (ppc, например)
# set_source_files_properties(
#     ${SOURCE_FILES}
#     PROPERTIES
#     LANGUAGE C
# )

add_executable(test-ppvector-common ${SOURCE_FILES})

# Линковка программы с библиотекой body
target_link_libraries(test-ppvector-common
  -Wl,--whole-archive
  ppvector
  -Wl,--no-whole-archive
)
