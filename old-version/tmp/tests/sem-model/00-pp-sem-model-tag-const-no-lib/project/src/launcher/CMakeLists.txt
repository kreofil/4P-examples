# set minimum cmake version
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
set(CMAKE_C_COMPILER ppclang)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type is Debug" FORCE)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

set(SOURCE_FILES
    # headers
    ../smodel/constant.h
    ../smodel/constant-spec.h

    #sources
    ../smodel/constant-spec.c
)

add_executable(sem-model main.c ${SOURCE_FILES})

# Линковка программы с библиотеками
# target_link_libraries(sem-model
#     -Wl,--whole-archive
#     smodel
#     -Wl,--no-whole-archive
# )
