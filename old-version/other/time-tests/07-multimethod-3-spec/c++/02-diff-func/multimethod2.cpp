//==============================================================================
// multimethod2.cpp - содержит функции, определяющие реализацию мультиметода
// для ОО подхода при добавлении круга
//==============================================================================

#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

//------------------------------------------------------------------------------
// Обработчик круга и прямоугольника
void Rectangle::FirstCircle(Circle& circ, std::ofstream &ofst) {
  ofst << "Circle -  Rectangle Combination\n";
}

//------------------------------------------------------------------------------
// Обработчик круга и треугольника
void Triangle::FirstCircle(Circle& circ, std::ofstream &ofst) {
  ofst << "Circle - Triangle Combination\n";
}

//------------------------------------------------------------------------------
// Мультиметод, определяющий вход в круг
void Circle::Multimethod(Figure& fig2, std::ofstream &ofst) {
    fig2.FirstCircle(reinterpret_cast<Circle&>(*this), ofst);
}

// Обработчик прямоугольника и круга
void Circle::FirstRectangle(Rectangle& rect, std::ofstream &ofst) {
    ofst << "Rectangle - Circle Combination\n";
}

// Обработчик треугольника и круга
void Circle::FirstTriangle(Triangle& trian, std::ofstream &ofst) {
    ofst << "Triangle - Circle Combination\n";
}

// Обработчик двух кругов
void Circle::FirstCircle(Circle& circ, std::ofstream &ofst) {
    ofst << "Circle - Circle Combination\n";
}


//==============================================================================
// Тестовый мультиметод, осуществляющий вычисление для периметров
//==============================================================================

//------------------------------------------------------------------------------
// Обработчик круга и прямоугольника
int Rectangle::FirstCircleDifFunc(Circle& circ) {
  // Разность между диаметром круга и суммой двух сторон прямоугольника
  return 2 * circ.GetR() - (x + y);
}

//------------------------------------------------------------------------------
// Обработчик круга и треугольника
int Triangle::FirstCircleDifFunc(Circle& circ) {
  // Сумма радиуса круга и периметра треугольника
  return circ.GetR() * (a + b + c);
}

//------------------------------------------------------------------------------
// Мультиметод, определяющий вход в круг
int Circle::MultimethodDifFunc(Figure& fig2) {
  return fig2.FirstCircleDifFunc(reinterpret_cast<Circle&>(*this));
}

// Обработчик прямоугольника и круга
int Circle::FirstRectangleDifFunc(Rectangle& rect) {
  // Возвращает разность между произведениями прямоугольника и радиусом круга
  return (rect.GetX() * rect.GetY()) - (r * r);
}

// Обработчик треугольника и круга
int Circle::FirstTriangleDifFunc(Triangle& trian) {
  // Возвращает разность между периметром треугольника и диаметром круга
  return (trian.GetA() + trian.GetB() + trian.GetC()) - 2 * r;
}

// Обработчик двух кругов
int Circle::FirstCircleDifFunc(Circle& circ) {
  // Произведение радиусов кругов
  return circ.GetR() * r;
}
