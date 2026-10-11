//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>

#include "inout.h"
#include "geometry.h"

//------------------------------------------------------------------------------
// Создание и ввод параметров одной из фигур
Figure* InOutCreate();

//------------------------------------------------------------------------------
int main() {
  Rectangle r = {.x = 10, .y = 20};
  struct Figure.rect iRect;
  iRect.@ = &r;
  Out<(Figure*)&iRect>();
  printf("Perimeter = %lf\n", Perimeter<(Figure*)&iRect>());
  printf("Area = %lf\n", Area<(Figure*)&iRect>());

  struct Figure *piFig;
  piFig = InOutCreate();
  Out<piFig>();
  printf("Perimeter = %lf\n", Perimeter<(Figure*)piFig>());
  printf("Area = %lf\n", Area<(Figure*)piFig>());

  return 0;
}
