# set minimum cmake version
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
SET(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    figure.h
    rectangle.h
    figure-rectangle.h
    triangle.h
    figure-triangle.h

    #sources
    figure-out.c
    figure-perimeter.c
    figure-rectangle-out.c
    figure-rectangle-perimeter.c
    figure-triangle-out.c
    rectangle-out.c
    rectangle-perimeter.c
    figure-triangle-perimeter.c
    triangle-out.c
    triangle-perimeter.c

    ppvector-figures.c
)

# Для того, чтобы clang понимал файлы с другим расширением (ppc, например)
# set_source_files_properties(
#     ${SOURCE_FILES}
#     PROPERTIES
#     LANGUAGE C
# )

add_executable(ppvector-figures ${SOURCE_FILES})

# Линковка программы с библиотекой body
target_link_libraries(ppvector-figures
  -Wl,--whole-archive
  ppvector
  -Wl,--no-whole-archive
)
