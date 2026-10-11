//==============================================================================
// multimethod.cpp - содержит функции, определяющие реализацию мультиметода
// для ОО подхода при наличии прямоугольника и треугольника
//==============================================================================

#include "rectangle.h"
#include "triangle.h"

//------------------------------------------------------------------------------
// Мультиметод, определяющий вход в прямоугольник
std::string  Rectangle::Multimethod(Figure& fig2) {
  return fig2.FirstRectangle(reinterpret_cast<Rectangle&>(*this));
}

// Обработчик двух прямоугольников
std::string  Rectangle::FirstRectangle(Rectangle& rect) {
  return "Rectangle - Rectangle Combination\n";
}

// Обработчик треугольника и прямоугольника
std::string  Rectangle::FirstTriangle(Triangle& trian) {
  return "Triangle -  Rectangle Combination\n";
}

//------------------------------------------------------------------------------
// Мультиметод, определяющий вход в треугольник
std::string Triangle::Multimethod(Figure& fig2) {
  return fig2.FirstTriangle(reinterpret_cast<Triangle&>(*this));
}

// Обработчик прямоугольника и треугольника
std::string Triangle::FirstRectangle(Rectangle& rect) {
  return "Rectangle - Triangle Combination\n";
}

// Обработчик двух треугольников
std::string Triangle::FirstTriangle(Triangle& trian) {
  return "Triangle - Triangle Combination\n";
}
