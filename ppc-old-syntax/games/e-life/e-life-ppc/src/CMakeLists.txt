# set minimum cmake version
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

set(CMAKE_BUILD_TYPE Debug)

# Установка переменной со списком исходников
set(SOURCE_FILES
    # headers
    entity.h
    eworld.h
    feeder.h
    food.h
    map.h

    #sources
    main.ppc
    entity.ppc
    eworld.ppc
    food.ppc
    map.ppc
    )

# Для того, чтобы clang понимал файлы с другим расширением (ppc, например)
set_source_files_properties(
    ${SOURCE_FILES}
    PROPERTIES
    LANGUAGE C
)

add_executable(e-life ${SOURCE_FILES})
