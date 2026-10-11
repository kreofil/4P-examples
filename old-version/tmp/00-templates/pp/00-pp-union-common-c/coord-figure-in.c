//==============================================================================
// coord-figure-in.c - содержит процедуру ввода параметров
// и создания произвольной фигуры
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "coord-figure.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void CoordRectangleIn(CoordRectangle *r, FILE* ifst);
void CoordTriangleIn(CoordTriangle *t, FILE* ifst);

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
CoordFigure* CoordFigureIn(FILE* ifst)
{
  CoordFigure *pf;
  int k;
  fscanf(ifst, "%d", &(k));
  switch(k) {
  case 1:
    pf = malloc(sizeof(CoordFigure));
    pf->k = COORD_RECTANGLE;
    CoordRectangleIn(&(pf->r), ifst);
    return pf;
  case 2:
    pf = malloc(sizeof(CoordFigure));
    pf->k = COORD_TRIANGLE;
    CoordTriangleIn(&(pf->t), ifst);
    return pf;
  default:
    return 0;
  }
}
