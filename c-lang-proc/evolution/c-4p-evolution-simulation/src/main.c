//==============================================================================
// Моделирование обобщений, специализаций и их обработчиков на языке C.
// Первоначальный вариант, когда все в одном файле для отработки идеи.
//==============================================================================
#include <stdlib.h>
#include <stdio.h>

#include "figure.h"
#include "figure_rectangle.h"
#include "figure_triangle.h"
#include "print_figure.h"
#include "multimethod_figure.h"

//------------------------------------------------------------------------------
// Тестовая часть программы, проверяющая корректность реализации модели
//------------------------------------------------------------------------------

figure_rectangle r = {.tail.x=10, .tail.y=20};
// Конструктор, обеспечивающий инициализацию тега переменной r
void  __attribute__ ((constructor(401))) init_figure_rectangle_r() {
    printf("%s\n", __FUNCTION__);   // тестовый вывод конструктора
    init_figure_rectangle(&r);
}

figure_triangle t = {.tail.a=10, .tail.b=20, .tail.c = 20};
// Конструктор, обеспечивающий инициализацию тега переменной r
void  __attribute__ ((constructor(401))) init_figure_triangle_t() {
    printf("%s\n", __FUNCTION__);   // тестовый вывод конструктора
    init_figure_triangle(&t);
}

int main() {
    printf("Begin %s\n", __FUNCTION__);   // тестовый вывод конструктора
    figure *p_f = (figure*)&r;
    // Печать фигуры с использованим ППП
    print_figure(p_f);

    figure_rectangle r2 = {.tail.x=1, .tail.y=2};
    init_figure_rectangle(&r2);
    p_f = (figure*)&r2;
    print_figure(p_f);

    // Использование динамической памяти под специализацию
    // Прямоугольник
    p_f = (figure*)malloc(sizeof(figure_rectangle));
    init_figure_rectangle((figure_rectangle*)p_f);
    ((figure_rectangle*)p_f)->tail.x = 100;
    ((figure_rectangle*)p_f)->tail.y = 200;
    print_figure(p_f);
    free(p_f);

    // Треугольник
    figure *p_t = (figure*)malloc(sizeof(figure_triangle));
    init_figure_triangle((figure_triangle*)p_t);
    ((figure_triangle*)p_t)->tail.a = 300;
    ((figure_triangle*)p_t)->tail.b = 400;
    ((figure_triangle*)p_t)->tail.c = 500;
    print_figure(p_t);
    free(p_t);

    // Тестирование вариантов мультиметода
    p_f = (figure*)&r;
    p_t = (figure*)&t;
    multimethod_figure(p_f, p_f);
    multimethod_figure(p_f, p_t);
    multimethod_figure(p_t, p_f);
    multimethod_figure(p_t, p_t);


    printf("End %s\n", __FUNCTION__);   // тестовый вывод конструктора
    return 0;
}
