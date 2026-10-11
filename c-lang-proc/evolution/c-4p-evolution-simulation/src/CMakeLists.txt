# set minimum cmake version
cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

#set(BUILD_DIR "${CMAKE_BINARY_DIR}")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Установка переменной со списком исходников
set(SOURCE_FILES
  # headers
  figure.h
  figure_rectangle.h
  figure_triangle.h
  print_figure.h
  multimethod_figure.h

  #sources
  main.c
  figure.c
  figure_rectangle.c
  figure_triangle.c
  print_figure.c
  print_figure_rectangle.c
  print_figure_triangle.c
  multimethod_figure.c
  multimethod_figure_rectangle.c
  multimethod_figure_triangle.c
  multimethod_figure_rt_tr.c
)

add_executable(c-evolution_example ${SOURCE_FILES})
