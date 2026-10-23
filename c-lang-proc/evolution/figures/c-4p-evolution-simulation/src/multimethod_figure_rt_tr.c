//------------------------------------------------------------------------------
// Реализация обработчиков специализаций.
// Каждый обработчик может быть размещен в своей единице компиляции
// Но можно и совмещать, если специализации уже разработаны
//------------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>

#include "figure.h"
#include "figure_rectangle.h"
#include "figure_triangle.h"
#include "multimethod_figure.h"

// Мультиметод для прямоугольника и треугольника
static void multimethod_figure_rectangle_triangle(figure* p_f1, figure* p_f2) {
    printf("rectangle + triangle combination\n");
}

// Регистрация мультиметода для прямоугольника и теугольника
// в обработчике обобщений
void  __attribute__
  ((constructor(301))) register_multimethod_figure_rectangle_triangle() {
    printf("%s\n", __FUNCTION__);   // тестовый вывод конструктора
    _multimethod_figure_spec_register(get_figure_rectangle_tag,
                                      get_figure_triangle_tag,
                                      multimethod_figure_rectangle_triangle);
}

// Мультиметод для прямоугольника и треугольника
static void multimethod_figure_triangle_rectangle(figure* p_f1, figure* p_f2) {
  printf("triangle before rectangle\n");
}

// Регистрация мультиметода для прямоугольника и теугольника
// в обработчике обобщений
void  __attribute__
((constructor(301))) register_multimethod_figure_triangle_rectangle() {
  printf("%s\n", __FUNCTION__);   // тестовый вывод конструктора
  _multimethod_figure_spec_register(get_figure_triangle_tag,
                                    get_figure_rectangle_tag,
                                    multimethod_figure_triangle_rectangle);
}
