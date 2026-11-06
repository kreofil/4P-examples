//==============================================================================
// figure-perimeter.c - содержит абстрактную функцию вычисления периметра
// для произвольной геометрической фигуры
//==============================================================================

#include <stdio.h>
#include "figure.h"

//------------------------------------------------------------------------------
// Вычисление периметра для текущей фигуры
double FigurePerimeter<Figure *f>() {return 0.0;} //= 0;


//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника
double RectanglePerimeter(Rectangle *r);
// Вычисление периметра треугольника
double TrianglePerimeter(Triangle *t);
//------------------------------------------------------------------------------
// Вычисление периметра для фигуры с использованием "нулевой стоимости"
double FigurePerimeterZero(Figure *f) {
  if(get_subtype_index(Figure.rect) == get_spec_var_index(f)) {
    return RectanglePerimeter(&(((Figure.rect*)f)->rect));
  } else if(get_subtype_index(Figure.trian) == get_spec_var_index(f)) {
    return TrianglePerimeter(&(((Figure.trian*)f)->trian));
  } else {
    return 0.0;
  }
}
