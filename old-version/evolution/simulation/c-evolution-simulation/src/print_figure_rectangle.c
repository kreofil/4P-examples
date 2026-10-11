//------------------------------------------------------------------------------
// Реализация обработчиков специализаций.
// Каждый обработчик может быть размещен в своей единице компиляции
//------------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>

#include "figure.h"
#include "figure_rectangle.h"
#include "print_figure.h"

// Вывод содержимого специализированного прямоугольника
static void print_figure_rectangle(figure* p_f) {
    figure_rectangle* p_fr = (figure_rectangle*)p_f;
    printf("rectangle: x= %d, y = %d\n", p_fr->tail.x, p_fr->tail.y);
}

// Регистрация обработчика специализированного прямоугольника
// в обработчике обобщений
void  __attribute__ ((constructor(301))) register_print_figure_rectangle() {
    printf("%s\n", __FUNCTION__);   // тестовый вывод конструктора
    printf("  figure-rectangle tag = %u\n", get_figure_rectangle_tag());
    _print_figure_spec_register(get_figure_rectangle_tag,
                                print_figure_rectangle);
}
