// rectangle-factory.cpp - реализация методов фабрики прямоугольников

#include "rectangle-factory.h"

// Конструктор, регистрирующий ключ = 1 для прямоугольников
RectangleFactory::RectangleFactory(): key{1} {
  factory[counter++] = this;
}

//------------------------------------------------------------------------------
// Реализация метода проверки и порождения прямоугольника
Figure* RectangleFactory::Test(int k)  {
  if(k == key) {
    return new Rectangle;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Регистратор фабрики прямоугольников
namespace {
  RectangleFactory rf;
}