//------------------------------------------------------------------------------
// coord-figure-factory.cpp - содержит реализации методов фабрики,
// порождающей фигуры, задаваемые координатами
//------------------------------------------------------------------------------

#include "coord-figure-factory.h"
#include "coord-rectangle.h"
#include "coord-triangle.h"

//------------------------------------------------------------------------------
// Порождение прямоугольника
Rectangle* CoordFigureFactory::CreateRectangle() {
  return new CoordRectangle();
}

//------------------------------------------------------------------------------
// Порождение треугольника
Triangle* CoordFigureFactory::CreateTriangle() {
  return new CoordTriangle();
}
