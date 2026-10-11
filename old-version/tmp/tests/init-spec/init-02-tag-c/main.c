//==============================================================================
// main-01.c - содержит главную функцию, обеспечивающую простое тестирование
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
void FigureOut<Figure *f>(FILE* ofst);

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
  FigureOut<(Figure*)pfr>(stdout);

  struct Figure.rect* spfr = create_spec(Figure.rect);
  spfr->@ = &r;
  FigureOut<(Figure*)spfr>(stdout);

  // Область памяти для специализации
  struct Figure.rect fr;
  fr.@ = &r;
  FigureOut<(Figure*)&fr>(stdout);

  init_spec(Figure.trian, pfr);
  pfr->@ = (Rectangle*)&t;
  FigureOut<(Figure*)pfr>(stdout);

  init_spec(Figure.trian, spfr);
  spfr->@ = (Rectangle*)&t;
  FigureOut<(Figure*)spfr>(stdout);

  init_spec(Figure.trian, &fr);
  fr.@ = (Rectangle*)&t;
  FigureOut<(Figure*)&fr>(stdout);

  printf("Stop\n");

  return 0;
}
