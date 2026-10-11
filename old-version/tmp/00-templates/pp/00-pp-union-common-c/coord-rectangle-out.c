//==============================================================================
// coord-rectangle-out.c - содержит процедуру
// вывода параметров прямоугольника
//==============================================================================

#include <stdio.h>
#include "coord-rectangle.h"

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void CoordRectangleOut(CoordRectangle *r, FILE* ofst) {
  fprintf(ofst,
          "It is Coord Rectangle: top left = (%.3lf,%.3lf),"
          " down right = (%.3lf,%.3lf)\n",
          r->top_left.x, r->top_left.y, r->down_right.x, r->down_right.y);
}
