//==============================================================================
// figure-out.c - содержит процедуру вывода параметров
// для произвольной геометрической фигуры
//==============================================================================

#include <stdio.h>
#include "figure.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void RectangleOut(SimpleRectangle *r, FILE* ofst);
void TriangleOut(SimpleTriangle *t, FILE *ofst);

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void FigureOut(SimpleFigure *s, FILE* ofst)
{
  switch(s->k) {
  case SIMPLE_RECTANGLE:
    RectangleOut(&(s->r), ofst);
    break;
  case SIMPLE_TRIANGLE:
    TriangleOut(&(s->t), ofst);
    break;
  default:
    fprintf(ofst, "Incorrect figure!\n");
  }
}
