//==============================================================================
// coord-rectangle-in.c - содержит процедуру ввода параметров
// для уже созданного прямоугольника
//==============================================================================

#include <stdio.h>
#include "coord-rectangle.h"

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void CoordRectangleIn(CoordRectangle *r, FILE* ifst) {
  fscanf(ifst, "%lf", &(r->top_left.x));
  fscanf(ifst, "%lf", &(r->top_left.y));
  fscanf(ifst, "%lf", &(r->down_right.x));
  fscanf(ifst, "%lf", &(r->down_right.y));
}
