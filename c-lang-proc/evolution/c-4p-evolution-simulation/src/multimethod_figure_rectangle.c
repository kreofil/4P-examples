//------------------------------------------------------------------------------
// Реализация обработчиков специализаций.
// Каждый обработчик может быть размещен в своей единице компиляции
// Но можно и совмещать, если специализации уже разработаны
//------------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>

#include "figure.h"
#include "figure_rectangle.h"
#include "multimethod_figure.h"

// Мультиметод для двух прямоугольников
static void multimethod_figure_rectangle_rectangle(figure* p_f1, figure* p_f2) {
    printf("rectangle and rectangle\n");
}

// Регистрация мультиметода для двух прямоугольников
// в обработчике обобщений
void  __attribute__
  ((constructor(301))) register_multimethod_figure_rectangle_rectangle() {
    printf("%s\n", __FUNCTION__);   // тестовый вывод конструктора
    _multimethod_figure_spec_register(get_figure_rectangle_tag,
                                      get_figure_rectangle_tag,
                                      multimethod_figure_rectangle_rectangle);
}
