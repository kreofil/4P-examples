// triangle-factory.cpp - реализация методов фабрики треугольников

#include "triangle-factory.h"

// Конструктор, регистрирующий ключ = 2 для треугольников
TriangleFactory::TriangleFactory(): key{2} {
  factory[counter++] = this;
}

//------------------------------------------------------------------------------
// Реализация метода проверки и порождения треугольника
Figure* TriangleFactory::Test(int k)  {
  if(k == key) {
    return new Triangle;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Регистратор фабрики треугольников
namespace {
  TriangleFactory tf;
}
