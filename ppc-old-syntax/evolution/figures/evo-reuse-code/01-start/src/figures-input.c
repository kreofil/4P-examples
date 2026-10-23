//==============================================================================
// figures-input.c - функция содания ввода всех альтернативных фигур.
// Реализована как централизованная. Единственная, требующая модификации
// при вводе данных. Но можно тоже сделать эволюционно расширяемой.
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "figure.h"

void FigureIn<Figure *f>(FILE* file);
Figure* FigureCreateUseInputTag<Input *pFig>(int k);

//------------------------------------------------------------------------------
// Ввод параметров одной из фигур из файла
Figure* FigureCreateAndIn(FILE* ifst) {
  int inSpecSize = get_spec_size(Input);
  Figure *sp;
  int k = 0;
  fscanf(ifst, "%d", &(k));
  for(int i = 1; i < inSpecSize; i++) {
    Input* pIn = get_spec_ptr(Input, i);
    sp = FigureCreateUseInputTag<pIn>(k);
    if(sp != NULL) break;
  }
  if(sp == NULL) {
    printf("Incorrect pointer to input figure\n");
    exit(13);
  }
  FigureIn<sp>(ifst);
  return sp;
}
