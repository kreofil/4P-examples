// multimethod-continue.c - содержит функции, опрeделяющие реализацию
// мультиметода для добавленного круга
//==============================================================================

#include <stdio.h>
#include "figure-rectangle.h"
#include "figure-triangle.h"
#include "figure-circle.h"

//------------------------------------------------------------------------------
// Обобщающая функция, задающая абстрактный мультиметод
// void Multimethod<Figure* f1, Figure* f2>(FILE* ofst);
// Сигнатура мультиметода для периметров
// double MultimethodPerimeter<Figure* f1, Figure* f2>();
double RectanglePerimeter(Rectangle *r);
double TrianglePerimeter(Triangle *t);
double CirclePerimeter(Circle *t);

//------------------------------------------------------------------------------
// Обработчик специализации для прямоугольника и круга
void Multimethod<Figure.rect* r1, Figure.circ* c2>(FILE* ofst) {
  fprintf(ofst, "Rectangle - Circle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для треугольника и круга
void Multimethod<Figure.trian* r1, Figure.circ* c2>(FILE* ofst) {
  fprintf(ofst, "Triangle - Circle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для круга и прямоугольника
void Multimethod<Figure.circ* c1, Figure.rect* r2>(FILE* ofst) {
  fprintf(ofst, "Circle - Rectangle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для круга и треугольника
void Multimethod<Figure.circ* c1, Figure.trian* t2>(FILE* ofst) {
  fprintf(ofst, "Circle - Triangle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для двух кругов
void Multimethod<Figure.circ* c1, Figure.circ* c2>(FILE* ofst) {
  fprintf(ofst, "Circle - Circle Combination\n");
}

//==============================================================================
// Вычисление периметров в качестве нагрузки мультиметода
// Хотя в целом их можно было распознать и без мультиметода.
//==============================================================================

//------------------------------------------------------------------------------
// Обработчик специализации для прямоугольника и круга
double MultimethodPerimeter<Figure.rect* r1, Figure.circ* c2>() {
  return (RectanglePerimeter(&(r1->@)) - CirclePerimeter(&(c2->@))) * 10.0;
}

//------------------------------------------------------------------------------
// Обработчик специализации для треугольника и круга
double MultimethodPerimeter<Figure.trian* t1, Figure.circ* c2>() {
  return TrianglePerimeter(&(t1->@)) * CirclePerimeter(&(c2->@)) / 3.0;
}

//------------------------------------------------------------------------------
// Обработчик специализации для круга и прямоугольника
double MultimethodPerimeter<Figure.circ* c1, Figure.rect* r2>() {
  return (CirclePerimeter(&(c1->@)) + RectanglePerimeter(&(r2->@))) / 5.0;
}

//------------------------------------------------------------------------------
// Обработчик специализации для круга и треугольника
double MultimethodPerimeter<Figure.circ* c1, Figure.trian* t2>() {
  return CirclePerimeter(&(c1->@)) - TrianglePerimeter(&(t2->@)) * 7.0;
}

//------------------------------------------------------------------------------
// Обработчик специализации для двух кругов
double MultimethodPerimeter<Figure.circ* c1, Figure.circ* c2>() {
  return CirclePerimeter(&(c1->@)) * CirclePerimeter(&(c2->@)) / 13.0;
}

