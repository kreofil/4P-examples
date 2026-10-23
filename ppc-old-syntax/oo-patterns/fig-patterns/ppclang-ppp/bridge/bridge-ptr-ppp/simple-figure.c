//==============================================================================
// simple-figure.c - содержит обработчики для простых фигур
//==============================================================================

#include <stdio.h>
#include "simple-figure.h"

//------------------------------------------------------------------------------
// Прототипы основ специализаций
void SimpleRectangleIn(SimpleRectangle *r, FILE* ifst);
void SimpleRectangleOut(SimpleRectangle *r, FILE* ofst);
void SimpleTriangleIn(SimpleTriangle *t, FILE* ifst);
void SimpleTriangleOut(SimpleTriangle *t, FILE* ofst);

//------------------------------------------------------------------------------
// Обобщенная функция ввода простых фигур
void SimpleFigureIn<SimpleFigure *r>(FILE* ifst) {} //= 0;
// Обобщенная функция вывода прямоугольников
void SimpleFigureOut<SimpleFigure *r>(FILE* ofst) {} //= 0;

//------------------------------------------------------------------------------
// Обработчик специализации, осуществляющий ввод простых прямоугольников
void SimpleFigureIn<SimpleFigure.rect *r>(FILE* ifst) {
  SimpleRectangleIn((SimpleRectangle*)&(r->@), ifst);
}

//------------------------------------------------------------------------------
// Обработчик, осуществляющий вывод простых прямоугольников
void SimpleFigureOut<SimpleFigure.rect *r>(FILE* ofst) {
  SimpleRectangleOut((SimpleRectangle*)&(r->@), ofst);
}

//------------------------------------------------------------------------------
// Обработчик специализации, осуществляющий ввод простых треугольников
void SimpleFigureIn<SimpleFigure.trian *t>(FILE* ifst) {
  SimpleTriangleIn((SimpleTriangle*)&(t->@), ifst);
}

//------------------------------------------------------------------------------
// Обработчик, осуществляющий вывод простых треугольников
void SimpleFigureOut<SimpleFigure.trian *t>(FILE* ofst) {
  SimpleTriangleOut((SimpleTriangle*)&(t->@), ofst);
}
