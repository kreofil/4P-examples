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

struct RectangleCover ext_rc = {.r.x = 15, .r.y = 10};
struct RectangleCover static_ext_rc = {.r.x = 25, .r.y = 20};

//------------------------------------------------------------------------------
int main() {
  RectangleLink(&ext_rc);
  // init_spec(InOut.rect, &(ext_rc.io));
  // init_spec(Geometry.rect, &(ext_rc.g));
  printf("\nExternal variable:\n");
  Out<(InOut*)&(ext_rc.io)>();
  printf("Perimeter = %lf\n", Perimeter<(Geometry*)&(ext_rc.g)>());
  printf("Area = %lf\n", Area<(Geometry*)&(ext_rc.g)>());

  RectangleLink(&static_ext_rc);
  // init_spec(InOut.rect, &(static_ext_rc.io));
  // init_spec(Geometry.rect, &(static_ext_rc.g));
  printf("\nStatic External variable:\n");
  Out<(InOut*)&(static_ext_rc.io)>();
  printf("Perimeter = %lf\n", Perimeter<(Geometry*)&(static_ext_rc.g)>());
  printf("Area = %lf\n", Area<(Geometry*)&(static_ext_rc.g)>());

  RectangleCover rc = {.r.x = 5, .r.y = 10};
  RectangleLink(&rc);
  printf("\nAuto Local variable:\n");
  Out<(InOut*)&(rc.io)>();
  printf("Perimeter = %lf\n", Perimeter<(Geometry*)&(rc.g)>());
  printf("Area = %lf\n", Area<(Geometry*)&(rc.g)>());

  struct RectangleCover static_local_rc = {.r.x = 4, .r.y = 3};
  RectangleLink(&static_local_rc);
  // init_spec(InOut.rect, &(static_local_rc.io));
  // init_spec(Geometry.rect, &(static_local_rc.g));
  printf("\nStatic Local variable:\n");
  Out<(InOut*)&(static_local_rc.io)>();
  printf("Perimeter = %lf\n", Perimeter<(Geometry*)&(static_local_rc.g)>());
  printf("Area = %lf\n", Area<(Geometry*)&(static_local_rc.g)>());

  // Как я понимаю, динамическая память пока не катит?
  printf("\nDynamic memory variable:\n");
  RectangleCover *prc = NewRectangleCover();
  // init_spec(InOut.rect, &(prc->io));
  // init_spec(Geometry.rect, &(prc->g));
  prc->r.x = 13;
  prc->r.y = 20;
  Out<(InOut*)&(prc->io)>();
  printf("Perimeter = %lf\n", Perimeter<(Geometry*)&(prc->g)>());
  printf("Area = %lf\n", Area<(Geometry*)&(prc->g)>());
  DeleteRectangleCover(prc);

  return 0;
}
