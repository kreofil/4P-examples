//==============================================================================
// figures-input.c - функция содания ввода всех альтернативных фигур.
// Реализована как централизованная. Единственная, требующая модификации
// при вводе данных. Но можно тоже сделать эволюционно расширяемой.
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "figure.h"
// #include "figure-rectangle.h"
// #include "figure-triangle.h"

void FigureIn<Figure *f>(FILE* file);
Figure* FigureCreateUseTag<EnumFig *pEnumFig>(int k);

//------------------------------------------------------------------------------
// Ввод параметров одной из фигур из файла
Figure* FigureCreateAndIn(FILE* ifst) {
  int figSpecSize = get_spec_size(Figure);
  // printf("figSpecSize = %d\n", figSpecSize);
  Figure *sp;
  int k = 0;
  fscanf(ifst, "%d", &(k));
  for(int i = 1; i <= figSpecSize; i++) {
    EnumFig* pEnumFig = get_spec_ptr(EnumFig, i);
    sp = FigureCreateUseTag<pEnumFig>(k);
    if(sp != NULL) break;
  }
  if(sp == NULL) {
    printf("Incorrect pointer to input figure\n");
    exit(13);
  }
  FigureIn<sp>(ifst);
  return sp;
}

