//==============================================================================
// figure-perimeter.c - содержит абстрактную функцию вычисления периметра
// для произвольной геометрической фигуры
//==============================================================================

#include <stdio.h>
#include "figure.h"

//------------------------------------------------------------------------------
// Вычисление периметра для текущей фигуры через обобщенную функцию
// double FigurePerimeter<Figure *f>() {return 0.0;} //= 0;

const double PI = 3.1415926535;

// Вычисление периметра для текущей фигуры через switch
double FigurePerimeterSwitch(Figure *f) {
  switch(get_spec_var_index(f)) {
    case get_subtype_index(Figure.rect):
      return 2.0 * (((Figure.rect*)f)->rect.x + ((Figure.rect*)f)->rect.y);
    case get_subtype_index(Figure.trian):
      return (double) (((Figure.trian*)f)->trian.a
                     + ((Figure.trian*)f)->trian.b
                     + ((Figure.trian*)f)->trian.c);
    case get_subtype_index(Figure.circ):
      return (double)(2.0 * PI * ((Figure.circ*)f)->circ.r);
    default:
      return 0.0;
  }
} //= 0;
