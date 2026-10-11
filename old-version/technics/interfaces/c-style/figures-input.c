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
Figure* InOutCreate() {
  struct Figure *in;
  struct Figure.rect *inRect;
  struct Figure.trian *inTrian;
  int k = 0;
  printf("Input figure type (1 - rectangle, 2 - triangle): ");
  scanf("%d", &(k));
  switch(k) {
  case 1:
    inRect = create_spec(Figure.rect);
    inRect->@ = (Rectangle*)malloc(sizeof(Rectangle));
    in = (Figure*)inRect;
    break;
  case 2:
    inTrian = create_spec(Figure.trian);
    inTrian->@ = (Triangle*)malloc(sizeof(Triangle));
    in = (Figure*)inTrian;
    break;
  default:
    printf("Incorrect figure type/ Taf = %d\n", k);
    exit(-1);
  }
  In<in>();
  return in;
}
