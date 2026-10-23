//------------------------------------------------------------------------------
// simple-rectangle-creator.cpp - реализация фабричного метода
// для прямоугольника
//------------------------------------------------------------------------------

// #include <iostream>
#include "simple-rectangle.h"
#include "simple-rectangle-creator.h"

// Переопределение метода Create на создание прямоугольников.
Figure* SimpleRectangleCreator::CreateFigure(int key) {
  if(key == mark)
    return new SimpleRectangle;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Создание фабрики прямоугольников
namespace {
  SimpleRectangleCreator rf;
}

