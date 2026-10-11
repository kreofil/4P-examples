//------------------------------------------------------------------------------
// Обобщенная функция печати фигур.
// Может быть построена на различных принципах
// В примере используется построение массива указателей
// Для разряженных решений возможно использование списков или операторов switch
//------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#include "figure.h"
#include "print_figure.h"

// Одномерный параметрический массив, формируемый для указателей на
// обработчики специализаций. Создается в динамической памяти
// после регистрации всех специализаций.
static print_figure_pointer *_print_figure_array;

// Обобщающая функция, осуществляющая обращение к массиву указателей
// на обработчики специализаций
void print_figure(figure* p_f) {
  print_figure_pointer spec = _print_figure_array[p_f->tag];
  spec(p_f);
}

// Обработчик по умолчанию, вызываемый в случаях,
// Когда обработчик специализации отсутствует.
static void print_figure_default(figure* p_f) {
  printf("ERROR: print for figure is absent!\n");
  // exit(1);
}


// Конструктор, обеспечивающий создание массива указателей
// на обработчики специализаций
void  __attribute__ ((constructor(201))) register_print_figure_array() {
  unsigned figure_number = get_figure_number();
  // тестовый вывод конструктора
  printf("%s: array size = %u\n", __FUNCTION__, figure_number);
  _print_figure_array =
  malloc(figure_number * sizeof(print_figure_pointer));
  for(unsigned i = 0; i < figure_number; ++i) {
    _print_figure_array[i] = print_figure_default;
  }
}

// Деструктор, обеспечивающий создание памяти, выделенной
// под массив указателей на обработчики специализаций
void  __attribute__ ((destructor(201))) delete_print_figure_array() {
  // тестовый вывод деструктора
  printf("%s\n", __FUNCTION__);
  free(_print_figure_array);
}

// Регистрация обработчика специализации в массиве обработчиков
void _print_figure_spec_register(
  unsigned (*get_spec_tag)(), print_figure_pointer spec) {
  // printf("start _print_figure_spec_register\n");
  // Передаваемый указатель на функцию фиксируется в массиве указателей
  unsigned tag = get_spec_tag();
  _print_figure_array[tag] = spec;
}
