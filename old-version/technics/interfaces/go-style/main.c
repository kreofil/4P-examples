//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>

#include "inout-rectangle.h"
#include "inout-triangle.h"
#include "geometry-rectangle.h"
#include "geometry-triangle.h"

//------------------------------------------------------------------------------
// Создание и ввод параметров одной из фигур
InOut* InOutCreate();

//------------------------------------------------------------------------------
int main() {
  Rectangle r = {.x = 10, .y = 20};
  struct InOut.rect iRect;
  iRect.@ = &r;
  Out<(InOut*)&iRect>();
  printf("Perimeter = %lf\n", Perimeter<(Geometry*)&iRect>());
  printf("Area = %lf\n", Area<(Geometry*)&iRect>());

  struct InOut *piFig;
  piFig = InOutCreate();
  Out<piFig>();
  printf("Perimeter = %lf\n", Perimeter<(Geometry*)piFig>());
  printf("Area = %lf\n", Area<(Geometry*)piFig>());

  return 0;
}
