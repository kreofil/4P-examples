//==============================================================================
// figure-out.c - содержит процедуру вывода параметров
// для произвольной геометрической фигуры
//==============================================================================

#include <stdio.h>
#include "figure.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void RectangleOut(CoordRectangle *r, FILE* ofst);
void TriangleOut(CoordTriangle *t, FILE *ofst);

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void FigureOut(CoordFigure *s, FILE* ofst)
{
  switch(s->k) {
  case COORD_RECTANGLE:
    RectangleOut(&(s->r), ofst);
    break;
  case COORD_TRIANGLE:
    TriangleOut(&(s->t), ofst);
    break;
  default:
    fprintf(ofst, "Incorrect figure!\n");
  }
}
