//==============================================================================
// simple-rectangle-inout.c - содержит функции ввода-вывода параметров
// простого прямоугольника
//==============================================================================

#include <stdio.h>
#include "simple-rectangle.h"

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void SimpleRectangleIn(SimpleRectangle *r, FILE* ifst) {
  // printf("SimpleRectangleIn.rect start\n");
  fscanf(ifst, "%lf", &(r->x));
  fscanf(ifst, "%lf", &(r->y));
  // printf("SimpleRectangleIn.rect finish\n");
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void SimpleRectangleOut(SimpleRectangle *r, FILE* ofst) {
  fprintf(ofst,
          "It is Simple Rectangle: x = %.3lf, y = %.3lf\n",
          r->x, r->y);
}
