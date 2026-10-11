//==============================================================================
// figures-input.c - функция содания ввода всех альтернативных фигур.
// Реализована как централизованная. Единственная, требующая модификации
// при вводе данных. Но можно тоже сделать эволюционно расширяемой.
//==============================================================================

#include <stdio.h>
#include "objects.h"

//------------------------------------------------------------------------------
// Ввод параметров одной из фигур из файла
O* FigureCreateAndIn(FILE* ifst) {
  O* po;
  int k = 0;
  fscanf(ifst, "%d", &(k));
  switch(k) {
  case 1:
    po = create_spec(O.Rectangle);
    // printf("size of O.Rectangle = %ld\n", sizeof(struct O.Rectangle));
    break;
  case 2:
    po = create_spec(O.Triangle);
    // printf("size of O.Triangle = %ld\n", sizeof(struct O.Triangle));
    break;
  default:
    return 0;
  }
  Input<po>(ifst);
  // Print<po>(stdout);
  return po;
}
