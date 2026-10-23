//------------------------------------------------------------------------------
// Область реализации специализации хранит общий тег и содержит
// функции, осуществляющие его установку и получение значения
//------------------------------------------------------------------------------
#include <stdio.h>

#include "figure.h"
#include "figure_rectangle.h"

// Значение признака специализации хранится в статической переменной
// и доступно через интерфейсные функции
static unsigned _figure_rectangle_tag = -1; // в начале неинициализирован

// Установщик признака, передаваемый регистратору
void set_figure_rectangle_tag(unsigned tag) {
    _figure_rectangle_tag = tag;
}

// Получение признака специализации. Необходимо в процессе регистрации фигуры
unsigned get_figure_rectangle_tag() {
    return _figure_rectangle_tag;
}

// Инициализация признака специализации перед использованием
void init_figure_rectangle(figure_rectangle *p_fr) {
    p_fr->tag = _figure_rectangle_tag;
}

//------------------------------------------------------------------------------
// Конструктор, обеспечивающий создание признака специализации
void  __attribute__ ((constructor(101))) register_figure_rectangle_tag() {
    printf("%s\n", __FUNCTION__);   // тестовый вывод конструктора
    _figure_spec_register(set_figure_rectangle_tag);
}
