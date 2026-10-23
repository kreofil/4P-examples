#ifndef __simple_rectangle__
#define __simple_rectangle__

//==============================================================================
// simple-rectangle.h - содержит описание прямоугольника
//==============================================================================

#include <stdio.h>

//------------------------------------------------------------------------------
// прямоугольник
typedef struct SimpleRectangle {
  double x, y; // ширина, высота
} SimpleRectangle;

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void SimpleRectangleIn(SimpleRectangle *r, FILE* ifst);
// Вывод параметров прямоугольника в форматируемый поток
void SimpleRectangleOut(SimpleRectangle *r, FILE* ofst);

#endif // __simple_rectangle__