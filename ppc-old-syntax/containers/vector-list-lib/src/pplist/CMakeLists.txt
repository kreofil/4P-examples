# set minimum cmake version
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

# Установка переменной со списком исходников
set(SOURCE_LIB
    # headers

    #sources
    pplist.c
    ppgeneral.c
)

# Для того, чтобы clang понимал файлы с другим расширением (ppc, например)
# set_source_files_properties(
#     ${SOURCE_FILES}
#     PROPERTIES
#     LANGUAGE C
# )

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)

add_library(pplist STATIC ${SOURCE_LIB})   # Создание статической библиотеки
