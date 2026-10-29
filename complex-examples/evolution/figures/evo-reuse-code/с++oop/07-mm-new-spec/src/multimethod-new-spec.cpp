//==============================================================================
// multimethod.cpp - содержит функции, определяющие реализацию мультиметода
// для ОО подхода при наличии прямоугольника и треугольника
//==============================================================================

#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

//------------------------------------------------------------------------------
// Обработчик круга и прямоугольника
std::string  Rectangle::FirstCircle(Circle& circle) {
  return "Circle -  Rectangle Combination\n";
}

//------------------------------------------------------------------------------
// Обработчик круга и треугольника
std::string Triangle::FirstCircle(Circle& circle) {
  return "Circle - Triangle Combination\n";
}

//------------------------------------------------------------------------------
// Мультиметод, определяющий вход в круг
std::string Circle::Multimethod(Figure& fig2) {
  return fig2.FirstCircle(reinterpret_cast<Circle&>(*this));
}

// Обработчик прямоугольника и круга
std::string Circle::FirstRectangle(Rectangle& rect) {
  return "Rectangle - Circle Combination\n";
}

// Обработчик треугольника и круга
std::string Circle::FirstTriangle(Triangle& trian) {
  return "Triangle - Circle Combination\n";
}

// Обработчик двух кругов
std::string Circle::FirstCircle(Circle& circle) {
  return "Circle - Circle Combination\n";
}
