//==============================================================================
// coord-figure.c - содержит обработчики для фигур, задаваемых координатами
//==============================================================================

#include <stdio.h>
#include "coord-figure.h"

//------------------------------------------------------------------------------
// Прототипы основ специализаций
void CoordRectangleIn(CoordRectangle *r, FILE* ifst);
void CoordRectangleOut(CoordRectangle *r, FILE* ofst);
void CoordTriangleIn(CoordTriangle *t, FILE* ifst);
void CoordTriangleOut(CoordTriangle *t, FILE* ofst);

//------------------------------------------------------------------------------
// Обобщенная функция ввода фигур с координатами
void CoordFigureIn<CoordFigure *r>(FILE* ifst) {} //= 0;
// Обобщенная функция вывода прямоугольников
void CoordFigureOut<CoordFigure *r>(FILE* ofst) {} //= 0;

//------------------------------------------------------------------------------
// Обработчик специализации, осуществляющий ввод прямоугольников с координатами
void CoordFigureIn<CoordFigure.rect *r>(FILE* ifst) {
  CoordRectangleIn((CoordRectangle*)&(r->@), ifst);
}

//------------------------------------------------------------------------------
// Обработчик, осуществляющий вывод прямоугольников с координатами
void CoordFigureOut<CoordFigure.rect *r>(FILE* ofst) {
  CoordRectangleOut((CoordRectangle*)&(r->@), ofst);
}

//------------------------------------------------------------------------------
// Обработчик специализации, осуществляющий ввод треугольников с координатами
void CoordFigureIn<CoordFigure.trian *t>(FILE* ifst) {
  CoordTriangleIn((CoordTriangle*)&(t->@), ifst);
}

//------------------------------------------------------------------------------
// Обработчик, осуществляющий вывод треугольников с координатами
void CoordFigureOut<CoordFigure.trian *t>(FILE* ofst) {
  CoordTriangleOut((CoordTriangle*)&(t->@), ofst);
}
