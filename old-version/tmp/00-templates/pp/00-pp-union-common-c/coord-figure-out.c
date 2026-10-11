//==============================================================================
// coord-figure-out.c - содержит процедуру вывода параметров
// для произвольной геометрической фигуры
//==============================================================================

#include <stdio.h>
#include "coord-figure.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void CoordRectangleOut(CoordRectangle *r, FILE* ofst);
void CoordTriangleOut(CoordTriangle *t, FILE *ofst);

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void CoordFigureOut(CoordFigure *s, FILE* ofst)
{
  switch(s->k) {
  case COORD_RECTANGLE:
    CoordRectangleOut(&(s->r), ofst);
    break;
  case COORD_TRIANGLE:
    CoordTriangleOut(&(s->t), ofst);
    break;
  default:
    fprintf(ofst, "Incorrect figure!\n");
  }
}
