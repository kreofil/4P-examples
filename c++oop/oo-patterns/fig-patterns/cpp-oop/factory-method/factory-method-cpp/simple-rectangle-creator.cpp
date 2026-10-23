//------------------------------------------------------------------------------
// simple-rectangle-creator.cpp - реализация фабричного метода
// для прямоугольника
//------------------------------------------------------------------------------

// #include <iostream>
#include "simple-rectangle.h"
#include "simple-rectangle-creator.h"

Figure* SimpleRectangleCreator::CreateFigure() {
  return new SimpleRectangle;
}
