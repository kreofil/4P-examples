//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>

#include "inout-rectangle.h"
#include "inout-triangle.h"
#include "geometry-rectangle.h"
#include "geometry-triangle.h"
#include "cover.h"

//------------------------------------------------------------------------------
// Создание и ввод параметров одной из фигур
InOut* InOutCreate();

//------------------------------------------------------------------------------
int main() {
  RectangleCover rc = {.r.x = 5, .r.y = 10};
  AddInterfacesToRectangleCover(&rc);
  Out<(InOut*)rc.io>();
  printf("Perimeter = %lf\n", Perimeter<(Geometry*)rc.g>());
  printf("Area = %lf\n", Area<(Geometry*)rc.g>());
  ClearInterfacesFromRectangleCover(&rc);

  RectangleCover *prc = NewRectangleCover();
  prc->r.x = 13;
  prc->r.y = 20;
  Out<(InOut*)(prc->io)>();
  printf("Perimeter = %lf\n", Perimeter<(Geometry*)(prc->g)>());
  printf("Area = %lf\n", Area<(Geometry*)(prc->g)>());
  DeleteRectangleCover(prc);

  return 0;
}
