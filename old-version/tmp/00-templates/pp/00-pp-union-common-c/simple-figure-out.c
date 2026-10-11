//==============================================================================
// simple-figure-out.c - содержит процедуру вывода параметров
// для произвольной геометрической фигуры
//==============================================================================

#include <stdio.h>
#include "simple-figure.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void SimpleRectangleOut(SimpleRectangle *r, FILE* ofst);
void SimpleTriangleOut(SimpleTriangle *t, FILE *ofst);

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void SimpleFigureOut(SimpleFigure *s, FILE* ofst)
{
  switch(s->k) {
  case SIMPLE_RECTANGLE:
    SimpleRectangleOut(&(s->r), ofst);
    break;
  case SIMPLE_TRIANGLE:
    SimpleTriangleOut(&(s->t), ofst);
    break;
  default:
    fprintf(ofst, "Incorrect figure!\n");
  }
}
