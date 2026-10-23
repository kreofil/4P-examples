//------------------------------------------------------------------------------
// rectangle.cpp - содержит  методы прямоугольника
//------------------------------------------------------------------------------

#include <iostream>
#include "simple-rectangle.h"

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника
void SimpleRectangle::InData(std::ifstream &ifst) {
  ifst >> x >> y;
  // std::cout << "    " << x << ", " << y << "\n";
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника
void SimpleRectangle::Out(std::ofstream &ofst) {
  ofst << "It is Simple Rectangle: x = " << x << ", y = " << y << "\n";
}

//------------------------------------------------------------------------------
// Клонирование
SimpleRectangle* SimpleRectangle::Clone() {
  SimpleRectangle* clone = new SimpleRectangle;
  clone->Init(this);
  return clone;
}

//------------------------------------------------------------------------------
// Инициализация клона данными родителя
void SimpleRectangle::Init(SimpleRectangle* parent) {
  x = parent->GetX();
  y = parent->GetY();
}
