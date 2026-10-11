//------------------------------------------------------------------------------
// Обобщенная функция печати фигур.
// Может быть построена на различных принципах
// В примере используется построение массива указателей
// Для разряженных решений возможно использование списков или операторов switch
//------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#include "figure.h"
#include "multimethod_figure.h"

// Одномерный параметрический массив, формируемый для указателей на
// обработчики специализаций. Создается в динамической памяти
// после регистрации всех специализаций.
static multimethod_figure_pointer *_multimethod_figure_array;

// Обобщающая функция, осуществляющая обращение к массиву указателей
// на обработчики специализаций
void multimethod_figure(figure* p_f1, figure* p_f2) {
  multimethod_figure_pointer spec =
    _multimethod_figure_array[get_figure_number()*p_f1->tag + p_f2->tag];
  spec(p_f1, p_f2);
}

// Обработчик по умолчанию, вызываемый в случаях,
// Когда обработчик специализации отсутствует.
static void multimethod_figure_default(figure* p_f1, figure* p_f2) {
  printf("WARNING: Multimethod not implemented for this shape combination!\n");
  // exit(1);
}

// Конструктор, обеспечивающий создание массива указателей
// на обработчики специализаций
void  __attribute__ ((constructor(201))) register_multimethod_figure_array() {
  unsigned figure_number = get_figure_number();
  // Формируется матрица
  unsigned multimethod_array_size = figure_number * figure_number;
  // тестовый вывод конструктора
  printf("%s: array size = %u\n", __FUNCTION__, multimethod_array_size);
  _multimethod_figure_array =
  malloc(multimethod_array_size * sizeof(multimethod_figure_pointer));
  for(unsigned i = 0; i < multimethod_array_size; ++i) {
    _multimethod_figure_array[i] = multimethod_figure_default;
  }
}

// Деструктор, обеспечивающий создание памяти, выделенной
// под массив указателей на обработчики специализаций
void  __attribute__ ((destructor(201))) delete_multimethod_figure_array() {
  // тестовый вывод деструктора
  printf("%s\n", __FUNCTION__);
  free(_multimethod_figure_array);
}

// Регистрация обработчика специализации в массиве обработчиков
void _multimethod_figure_spec_register(unsigned (*get_spec_tag1)(),
                                       unsigned (*get_spec_tag2)(),
                                       multimethod_figure_pointer spec) {
  // printf("start _print_figure_spec_register\n");
  // Передаваемый указатель на функцию фиксируется в массиве указателей
  unsigned tag = get_figure_number() * get_spec_tag1() + get_spec_tag2();
  _multimethod_figure_array[tag] = spec;
}
