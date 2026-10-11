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
int Rectangle::MultimethodDifFunc(Figure& fig2) {
  return fig2.FirstRectangleDifFunc(reinterpret_cast<Rectangle&>(*this));
}

// Обработчик двух прямоугольников
int Rectangle::FirstRectangleDifFunc(Rectangle& rect) {
  // Возвращает сумму площадей двух прямоугольников
  return (rect.GetX() * rect.GetY()) + (x * y);
}

// Обработчик треугольника и прямоугольника
int Rectangle::FirstTriangleDifFunc(Triangle& trian) {
  // Возвращает разность между суммами сторон прямоугольника и треугольника
  return (trian.GetA() + trian.GetB() + trian.GetC()) - (x + y);
}

//------------------------------------------------------------------------------
// Мультиметод, определяющий вход в треугольник
int Triangle::MultimethodDifFunc(Figure& fig2) {
  return fig2.FirstTriangleDifFunc(reinterpret_cast<Triangle&>(*this));
}

// Обработчик прямоугольника и треугольника
int Triangle::FirstRectangleDifFunc(Rectangle& rect) {
  // Возвращает общую сумму сторон прямоугольника и треугольника
  return rect.GetX() + rect.GetY() + a + b + c;
}

// Обработчик двух треугольников
int Triangle::FirstTriangleDifFunc(Triangle& trian) {
  // Возвращает произведение сумм сторон двух треугольников
  return (trian.GetA() + trian.GetB() + trian.GetC()) * (a + b + c);
}
