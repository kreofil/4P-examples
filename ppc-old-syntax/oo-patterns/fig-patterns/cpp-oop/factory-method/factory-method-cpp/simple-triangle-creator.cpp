//------------------------------------------------------------------------------
// simple-triangle-creator.cpp - реализация фабричного метода для треугольника
//------------------------------------------------------------------------------

// #include <iostream>
#include "simple-triangle.h"
#include "simple-triangle-creator.h"

Figure* SimpleTriangleCreator::CreateFigure() {
  return new SimpleTriangle;
}
