//------------------------------------------------------------------------------
// simple-figure-factory.cpp - содержит реализации методов фабрики,
// порождающей простые фигуры
//------------------------------------------------------------------------------

#include "simple-figure-factory.h"
#include "simple-rectangle.h"
#include "simple-triangle.h"

//------------------------------------------------------------------------------
// Порождение простого прямоугольника
Rectangle* SimpleFigureFactory::CreateRectangle() {
  return new SimpleRectangle();
}

//------------------------------------------------------------------------------
// Порождение простого треугольника
Triangle* SimpleFigureFactory::CreateTriangle() {
  return new SimpleTriangle();
}
