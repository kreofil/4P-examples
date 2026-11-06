//==============================================================================
// figures-input.c - функция содания ввода всех альтернативных фигур.
// Реализована как централизованная. Единственная, требующая модификации
// при вводе данных. Но можно тоже сделать эволюционно расширяемой.
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "figure.h"

void FigureIn<Figure *f>(FILE* file);

//------------------------------------------------------------------------------
// Ввод параметров одноф из фигур из файла
void FigureCreateAndIn(Figure* f, FILE* ifst) {
  int k = 0;
  Figure.rect* pfr;
  Figure.trian* pft;
  Figure.circ* pfc;
  // Фигура находится снаружи и задается областью памяти,
  // которую нужно заполнить
  fscanf(ifst, "%d", &(k));
  switch(k) {
  case 1:
    pfr = (Figure.rect*)f;
    init_spec(Figure.rect, pfr);
    break;
  case 2:
    pft = (Figure.trian*)f;
    init_spec(Figure.trian, pft);
    break;
  case 3:
    pfc = (Figure.circ*)f;
    init_spec(Figure.circ, pfc);
    break;
  default:
    perror("Incorrect figure tag\n");
    exit(13);
  }
  FigureIn<f>(ifst);
}
