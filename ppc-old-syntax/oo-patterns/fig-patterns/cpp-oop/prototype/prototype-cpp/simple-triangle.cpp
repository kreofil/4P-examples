//------------------------------------------------------------------------------
// triangle.cpp - содержит методы треугольника
//------------------------------------------------------------------------------

#include <iostream>
#include "simple-triangle.h"

//------------------------------------------------------------------------------
// Ввод параметров треугольника
void SimpleTriangle::InData(std::ifstream &ifst) {
  ifst >> a >> b >> c;
  // std::cout << "    " << a << ", " << b <<  ", " << c << "\n";
}

//------------------------------------------------------------------------------
// Вывод параметров треугольника
void SimpleTriangle::Out(std::ofstream &ofst) {
  ofst << "It is Simple Triangle: a = "
    << a << ", b = " << b
    << ", c = " << c << "\n";
}

//------------------------------------------------------------------------------
// Клонирование
SimpleTriangle* SimpleTriangle::Clone() {
  SimpleTriangle* clone = new SimpleTriangle;
  clone->Init(this);
  return clone;
}

//------------------------------------------------------------------------------
// Инициализация клона данными родителя
void SimpleTriangle::Init(SimpleTriangle* parent) {
  a = parent->GetA();
  b = parent->GetB();
  c = parent->GetC();
}
