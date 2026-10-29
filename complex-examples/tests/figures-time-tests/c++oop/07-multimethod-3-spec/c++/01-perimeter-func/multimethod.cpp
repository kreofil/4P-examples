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

//==============================================================================
// Тестовый мультиметод, осуществляющий вычисление для периметров
//==============================================================================

//------------------------------------------------------------------------------
// Мультиметод, определяющий вход в прямоугольник
double Rectangle::MultimethodPerimeter(Figure& fig2) {
  return fig2.FirstRectanglePerimeter(reinterpret_cast<Rectangle&>(*this));
}

// Обработчик двух прямоугольников
double Rectangle::FirstRectanglePerimeter(Rectangle& rect) {
  return rect.Perimeter() * Perimeter();
}

// Обработчик треугольника и прямоугольника
double Rectangle::FirstTrianglePerimeter(Triangle& trian) {
  return trian.Perimeter() / Perimeter();
}

//------------------------------------------------------------------------------
// Мультиметод, определяющий вход в треугольник
double Triangle::MultimethodPerimeter(Figure& fig2) {
  return fig2.FirstTrianglePerimeter(reinterpret_cast<Triangle&>(*this));
}

// Обработчик прямоугольника и треугольника
double Triangle::FirstRectanglePerimeter(Rectangle& rect) {
  return rect.Perimeter() + Perimeter();
}

// Обработчик двух треугольников
double Triangle::FirstTrianglePerimeter(Triangle& trian) {
  return trian.Perimeter() * Perimeter() * 2.0;
}
