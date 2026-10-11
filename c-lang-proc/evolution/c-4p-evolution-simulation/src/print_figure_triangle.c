//------------------------------------------------------------------------------
// Реализация обработчиков специализаций.
// Каждый обработчик может быть размещен в своей единице компиляции
//------------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>

#include "figure.h"
#include "figure_triangle.h"
#include "print_figure.h"

// Вывод содержимого специализированного прямоугольника
static void print_figure_triangle(figure* p_f) {
    figure_triangle* p_fr = (figure_triangle*)p_f;
    printf("triangle: a = %d, b = %d, c = %d\n",
           p_fr->tail.a, p_fr->tail.b, p_fr->tail.c);
}

// Регистрация обработчика специализированного прямоугольника
// в обработчике обобщений
void  __attribute__ ((constructor(301))) register_print_figure_triangle() {
    printf("%s\n", __FUNCTION__);   // тестовый вывод конструктора
    printf("  figure-triangle tag = %u\n", get_figure_triangle_tag());
    _print_figure_spec_register(get_figure_triangle_tag,
                                print_figure_triangle);
}

