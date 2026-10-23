//==============================================================================
// figures-input.c - функция содания ввода всех альтернативных фигур.
// Реализована как централизованная. Единственная, требующая модификации
// при вводе данных. Но можно тоже сделать эволюционно расширяемой.
//==============================================================================

#include <stdio.h>
#include "figure-rectangle.h"
#include "figure-triangle.h"

void FigureIn<Figure *f>(FILE* file);

//------------------------------------------------------------------------------
// Ввод параметров одноф из фигур из файла
Figure* FigureCreateAndIn(FILE* ifst) {
  Figure *sp;
  int k = 0;
  fscanf(ifst, "%d", &(k));
  switch(k) {
  case 1:
    sp = create_spec(Figure.rect);
    break;
  case 2:
    sp = create_spec(Figure.trian);
    break;
  default:
    return 0;
  }
  FigureIn<sp>(ifst);
  return sp;
}
