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
