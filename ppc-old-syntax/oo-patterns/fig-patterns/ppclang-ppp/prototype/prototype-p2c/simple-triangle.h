#ifndef __simple_triangle__
#define __simple_triangle__

//==============================================================================
// simple-triangle.h - описание треугольника
//==============================================================================

#include <stdio.h>

//------------------------------------------------------------------------------
// треугольник
typedef struct SimpleTriangle {
  double a, b, c; // стороны треугольника
} SimpleTriangle;

//------------------------------------------------------------------------------
// Ввод параметров треугольника из потока
void SimpleTriangleIn(SimpleTriangle *t, FILE* ifst);
// Вывод параметров треугольника в поток
void SimpleTriangleOut(SimpleTriangle *t, FILE *ofst);

#endif // __simple_triangle__