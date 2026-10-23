//==============================================================================
// multimethod.cpp - содержит функции, определяющие реализацию мультиметода
// для ОО подхода при наличии прямоугольника и треугольника
//==============================================================================

#include "rectangle.h"
#include "triangle.h"

//------------------------------------------------------------------------------
// Мультиметод, определяющий вход в прямоугольник
void Rectangle::Multimethod(Figure& fig2, std::ofstream &ofst) {
  fig2.FirstRectangle(reinterpret_cast<Rectangle&>(*this), ofst);
}

// Обработчик двух прямоугольников
void Rectangle::FirstRectangle(Rectangle& rect, std::ofstream &ofst) {
  ofst << "Rectangle - Rectangle Combination\n";
}

// Обработчик треугольника и прямоугольника
void Rectangle::FirstTriangle(Triangle& trian, std::ofstream &ofst) {
  ofst << "Triangle -  Rectangle Combination\n";
}

//------------------------------------------------------------------------------
// Мультиметод, определяющий вход в треугольник
void Triangle::Multimethod(Figure& fig2, std::ofstream &ofst) {
  fig2.FirstTriangle(reinterpret_cast<Triangle&>(*this), ofst);
}

// Обработчик прямоугольника и треугольника
void Triangle::FirstRectangle(Rectangle& rect, std::ofstream &ofst) {
  ofst << "Rectangle - Triangle Combination\n";
}

// Обработчик двух треугольников
void Triangle::FirstTriangle(Triangle& trian, std::ofstream &ofst) {
  ofst << "Triangle - Triangle Combination\n";
}
