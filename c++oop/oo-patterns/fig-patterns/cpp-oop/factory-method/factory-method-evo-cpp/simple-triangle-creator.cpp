//------------------------------------------------------------------------------
// simple-triangle-creator.cpp - реализация фабричного метода для треугольника
//------------------------------------------------------------------------------

// #include <iostream>
#include "simple-triangle.h"
#include "simple-triangle-creator.h"

// Переопределение метода Create на создание треугольников.
Figure* SimpleTriangleCreator::CreateFigure(int key) {
  if(key == mark)
    return new SimpleTriangle;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Создание фабрики треугольников
namespace {
  SimpleTriangleCreator tf;
}
