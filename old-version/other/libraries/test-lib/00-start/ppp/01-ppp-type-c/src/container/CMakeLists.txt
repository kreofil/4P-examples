# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
#SET(CMAKE_C_COMPILER ppclang)

# Установка переменной со списком исходников
set(SOURCE_LIB
    # headers
    container.h

    #sources
    container-constr.c
    container-in.c
    container-out.c
)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

add_library(container STATIC ${SOURCE_LIB})   # Создание статической библиотеки

# Линковка container с  figure
# target_link_libraries(container
#     -Wl,--whole-archive
#     figure
#     -Wl,--no-whole-archive
# )
