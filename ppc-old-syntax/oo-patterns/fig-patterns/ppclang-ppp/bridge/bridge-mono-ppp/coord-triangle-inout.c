//==============================================================================
// coord-triangle-inout.c - содержит функции ввода-вывода параметров
// треугольника, задаваемого координатами
//==============================================================================

#include <stdio.h>
#include "coord-triangle.h"

//------------------------------------------------------------------------------
// Ввод параметров треугольника из потока
void CoordTriangleIn(CoordTriangle *t, FILE* ifst) {
  // fscanf(ifst, "%d%d%d", &(t->a), &(t->b), &(t->c));
  fscanf(ifst, "%lf", &(t->a.x));
  fscanf(ifst, "%lf", &(t->a.y));
  fscanf(ifst, "%lf", &(t->b.x));
  fscanf(ifst, "%lf", &(t->b.y));
  fscanf(ifst, "%lf", &(t->c.x));
  fscanf(ifst, "%lf", &(t->c.y));
}

//------------------------------------------------------------------------------
// Вывод параметров треугольника в поток
void CoordTriangleOut(CoordTriangle *t, FILE *ofst) {
  fprintf(ofst,
          "It is CoordTriangle: a = (%.3lf, %.3lf), "
          "b = (%.3lf, %.3lf), c = (%.3lf, %.3lf)\n",
          t->a.x, t->a.y, t->b.x, t->b.y, t->c.x, t->c.y);
}
