// circle-factory.cpp - реализация методов фабрики кругов

#include "circle-factory.h"

// Конструктор, регистрирующий ключ = 3 для кругов
CircleFactory::CircleFactory(): key{3} {
  factory[counter++] = this;
}

//------------------------------------------------------------------------------
// Реализация метода проверки и порождения круга
Figure* CircleFactory::Test(int k)  {
  if(k == key) {
    return new Circle;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Синглетон, осуществляющий регистрацию фабрики кругов
namespace {
  CircleFactory cf;
}