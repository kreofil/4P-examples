//==============================================================================
// figures-input.c - функция содания ввода всех альтернативных фигур.
// Реализована как централизованная. Единственная, требующая модификации
// при вводе данных. Но можно тоже сделать эволюционно расширяемой.
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "figure-rectangle.h"
#include "figure-triangle.h"

void FigureIn<Figure *f>(FILE* file);

//------------------------------------------------------------------------------
// Ввод параметров одноф из фигур из файла
void FigureCreateAndIn(Figure* f, FILE* ifst) {
  // Фигура находится снаружи и задается областью памяти,
  // которую нужно заполнить
  Rectangle *pr;  // Для создания прямоугольника
  Triangle  *pt;  // Для создания треугольника
  int k = 0;
  fscanf(ifst, "%d", &(k));
  switch(k) {
  case 1:
    // sp = create_spec(Figure.rect);
    pr = malloc(sizeof(Rectangle));
    struct Figure.rect* pfr = (struct Figure.rect*)f;
    init_spec(Figure.rect, pfr);
    pfr->@ = pr;
    break;
  case 2:
    // sp = create_spec(Figure.trian);
    pt = malloc(sizeof(Triangle));
    struct Figure.trian* pft = (struct Figure.trian*)f;
    init_spec(Figure.trian, pft);
    pft->@ = pt;
    break;
  default:
    perror("Incorrect figure tag\n");
    exit(13);
  }
  FigureIn<f>(ifst);
}
