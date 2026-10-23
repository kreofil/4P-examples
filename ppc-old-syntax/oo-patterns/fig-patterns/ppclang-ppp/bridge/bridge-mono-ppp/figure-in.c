//==============================================================================
// figure-out.c - функция, осуществляющая вывод для одной
// альтернативных фигур. Вывод реализован полиморфно.
// Этот обобщенный тип не является частью паттерна Абстрактная фабрика, а
// используется для демонстрации тестовых ввода-вывода при работе
// с общим для всех фигур контейнером.
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "figure.h"

// static void test_type_tag_Figure(struct Figure* X) {
//   printf("Figure Tag = %d\n", X->__pp_specialization_type);
// }
//
// static void test_type_tag_SimpleFigure(struct SimpleFigure* X) {
//   printf("SimpleFigure Tag = %d\n", X->__pp_specialization_type);
// }

//------------------------------------------------------------------------------
// Прототипы функций ввода семейств фигур
void SimpleFigureIn<SimpleFigure *f>(FILE* ifst);
void CoordFigureIn<CoordFigure *f>(FILE* ifst);

//------------------------------------------------------------------------------
// Обобщенная функция ввода любой фигуры
void FigureIn<Figure *f>(FILE* ifst) {
  printf("FigureIn: Incorrect link to generalized function\n");
  exit(3);
} //= 0;

//------------------------------------------------------------------------------
// Обработчик, осуществляющий ввод простой фигуры
void FigureIn<Figure.simple *f>(FILE* ifst) {
  struct SimpleFigure* pf = &(f->@);
  SimpleFigureIn<pf>(ifst);
}

//------------------------------------------------------------------------------
// Обработчик, осуществляющий ввод фигуры, заданной координатами
void FigureIn<Figure.coord *f>(FILE* ifst) {
  CoordFigure* pf = &(f->@);
  CoordFigureIn<pf>(ifst);
}
