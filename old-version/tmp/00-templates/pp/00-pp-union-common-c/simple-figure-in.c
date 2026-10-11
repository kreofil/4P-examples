//==============================================================================
// simple-figure-in.c - содержит процедуру ввода параметров
// и создания произвольной фигуры
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "simple-figure.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void SimpleRectangleIn(SimpleRectangle *r, FILE* ifst);
void SimpleTriangleIn(SimpleTriangle *t, FILE* ifst);

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
SimpleFigure* SimpleFigureIn(FILE* ifst)
{
  SimpleFigure *pf;
  int k;
  fscanf(ifst, "%d", &(k));
  switch(k) {
  case 1:
    pf = malloc(sizeof(SimpleFigure));
    pf->k = SIMPLE_RECTANGLE;
    SimpleRectangleIn(&(pf->r), ifst);
    return pf;
  case 2:
    pf = malloc(sizeof(SimpleFigure));
    pf->k = SIMPLE_TRIANGLE;
    SimpleTriangleIn(&(pf->t), ifst);
    return pf;
  default:
    return 0;
  }
}
