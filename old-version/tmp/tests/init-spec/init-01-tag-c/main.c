//==============================================================================
// main.c - содержит главную функцию, обеспечивающую простое тестирование
// методов инициализации фигур в выделенном образе памяти
//==============================================================================

#include <stdio.h>
#include <stdlib.h>

#include "figure-rectangle.h"
#include "figure-triangle.h"

//------------------------------------------------------------------------------
// Прототип функции вывода прямоугольника
void RectangleOut(Rectangle *r, FILE* ifst);
// Прототип функции вывода треугольника
void TriangleOut(Triangle *t, FILE* ofst);
// Прототип обобщеннай функции вывода фигуры
// void FigureOut<Figure *f>(FILE* ofst);

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  printf("Start\n");

  //  Память под основы специализаций
  Rectangle r = {5,5};
  RectangleOut(&r, stdout);
  Triangle t = {1, 1, 1};
  TriangleOut(&t, stdout);

  struct Figure.rect* pfr = malloc(sizeof(struct Figure.rect));
  init_spec(Figure.rect, pfr);
  pfr->@ = &r;
  // RectangleOut(pfr->@, stdout); // Не пошло
  Rectangle* pr1 = pfr->@;
  RectangleOut(pr1, stdout);

  struct Figure.rect* spfr = create_spec(Figure.rect);
  spfr->@ = &r;
  // RectangleOut(spfr->@, stdout); // Не пошло
  Rectangle* pr2 = spfr->@;
  RectangleOut(pr2, stdout);

  // Область памяти для специализации
  struct Figure.rect fr;
  fr.@ = &r;
  // RectangleOut(fr.@, stdout); // Не пошло
  Rectangle* pr3 = fr.@;
  RectangleOut(pr3, stdout);

  printf("Stop\n");

  return 0;
}
