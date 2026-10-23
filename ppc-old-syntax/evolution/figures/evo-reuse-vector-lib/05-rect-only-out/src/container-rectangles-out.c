//==============================================================================
// container-rectangles-out.c - содержит функцию вывода только прямоугольников,
// находящихся в контейнере, используя обобщенную функцию, проверки
// на прямоугольник
//==============================================================================

#include <stdio.h>
#include "figure-rectangle.h"
#include "container.h"

void FigureOut<Figure* s>(FILE* ofst);

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void  ContainerRectangleOnlyOut(struct ppVector.fig* c, FILE* ofst) {
  int rectCount = 0;
  struct Figure.rect r;
  unsigned  len = ppVector_size((ppVector*)c);
  for(unsigned i = 0; i < len; ++i) {
    ppVector_index((ppVector*)c, i);
    if(spec_index_cmp(&r, c->@) >= 0) {
      FigureOut<c->@>(ofst);
      ++rectCount;
    }
  }
  fprintf(ofst, "Container contains %d rectangles.\n", rectCount);
}
