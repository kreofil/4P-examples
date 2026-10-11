//==============================================================================
// multimethod.c - содержит функции, опрделяющие реализацию мультиметода
// для чистого процедурного подхода с использованием для фигуры объединения
//==============================================================================

#include <stdio.h>
#include "figure-rectangle.h"
#include "figure-triangle.h"

//------------------------------------------------------------------------------
// Обобщающая функция, задающая абстрактный мультиметод
void Multimethod<Figure* f1, Figure* f2>(FILE* ofst) {} //= 0;

//------------------------------------------------------------------------------
// Обработчик специализации для двух прямоугольников
void Multimethod<Figure.rect* r1, Figure.rect* r2>(FILE* ofst) {
  fprintf(ofst, "Rectangle - Rectangle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для прямоугольника и треугольника
void Multimethod<Figure.rect* r1, Figure.trian* t2>(FILE* ofst) {
  fprintf(ofst, "Rectangle - Triangle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для треугольника и прямоугольника
void Multimethod<Figure.trian* t1, Figure.rect* r2>(FILE* ofst) {
  fprintf(ofst, "Triangle - Rectangle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для двух треугольников
void Multimethod<Figure.trian* t1, Figure.trian* t2>(FILE* ofst) {
  fprintf(ofst, "Triangle - Triangle Combination\n");
}

//==============================================================================
// Вычисление периметров в качестве нагрузки мультиметода
// Хотя в целом их можно было распознать и без мультиметода.
//==============================================================================
double RectanglePerimeter(Rectangle *r);
double TrianglePerimeter(Triangle *t);

//------------------------------------------------------------------------------
// Обобщающая функция, задающая абстрактный мультиметод
double MultimethodPerimeter<Figure* f1, Figure* f2>() {
  return 0.0;
} //= 0;

//------------------------------------------------------------------------------
// Обработчик специализации для двух прямоугольников
double MultimethodPerimeter<Figure.rect* r1, Figure.rect* r2>() {
  return RectanglePerimeter(&(r1->@)) * RectanglePerimeter(&(r2->@));
}

//------------------------------------------------------------------------------
// Обработчик специализации для прямоугольника и треугольника
double MultimethodPerimeter<Figure.rect* r1, Figure.trian* t2>() {
  return RectanglePerimeter(&(r1->@)) + TrianglePerimeter(&(t2->@));
}

//------------------------------------------------------------------------------
// Обработчик специализации для треугольника и прямоугольника
double MultimethodPerimeter<Figure.trian* t1, Figure.rect* r2>() {
  return TrianglePerimeter(&(t1->@)) / RectanglePerimeter(&(r2->@));
}

//------------------------------------------------------------------------------
// Обработчик специализации для двух треугольников
double MultimethodPerimeter<Figure.trian* t1, Figure.trian* t2>() {
  return TrianglePerimeter(&(t1->@)) * TrianglePerimeter(&(t2->@)) * 2.0;
}

