//==============================================================================
// figures-input.c - функция содания ввода всех альтернативных фигур.
// Реализована как централизованная. Единственная, требующая модификации
// при вводе данных. Но можно тоже сделать эволюционно расширяемой.
//==============================================================================

#include <stdio.h>
#include <stdlib.h>

#include "inout-rectangle.h"
#include "inout-triangle.h"

//------------------------------------------------------------------------------
// Создание и ввод параметров одной из фигур
InOut* InOutCreate() {
  struct InOut *in;
  struct InOut.rect *inRect;
  struct InOut.trian *inTrian;
  int k = 0;
  printf("Input figure type (1 - rectangle, 2 - triangle): ");
  scanf("%d", &(k));
  switch(k) {
  case 1:
    inRect = create_spec(InOut.rect);
    inRect->@ = (Rectangle*)malloc(sizeof(Rectangle));
    in = (InOut*)inRect;
    break;
  case 2:
    inTrian = create_spec(InOut.trian);
    inTrian->@ = (Triangle*)malloc(sizeof(Triangle));
    in = (InOut*)inTrian;
    break;
  default:
    printf("Incorrect figure type/ Taf = %d\n", k);
    exit(-1);
  }
  In<in>();
  return in;
}
