//==============================================================================
// Реализация клиентского кода, геометрические вычисления
//==============================================================================

#include <math.h>
#include "client-geometry.h"
#include "rectangle.h"
#include "triangle.h"

//------------------------------------------------------------------------------
// Вычисление периметров
void ClientGeometry::CalcPerimeters(std::ofstream &ofst) {
  // container.PerimeterOut(ofst);
  ofst << "Perimeters of figures:\n";
  for(int i = 0; i < container.len; i++) {
    ofst << i << ": " << CalcFigurePerimeter(container.cont[i], ofst) << "\n";
  }
}

//------------------------------------------------------------------------------
// Вычисление периметра фигуры
double ClientGeometry::CalcFigurePerimeter(Figure* f, std::ofstream &ofst) {
  Rectangle* r;
  Triangle* t;
  if((r = dynamic_cast<Rectangle*>(f)) != nullptr) {
    return (double)(2*(r->x + r->y));
  } else if((t = dynamic_cast<Triangle*>(f)) != nullptr) {
    return (double)(t->a + t->b + t->c);
  }
  ofst << "Unknown Figure Perimeter\n";
  return 0.0;
}

//------------------------------------------------------------------------------
// Вычисление площадей
void ClientGeometry::CalcAreas(std::ofstream &ofst) {
  // container.AreaOut(ofst);
  ofst << "Areas of figures:\n";
  for(int i = 0; i < container.len; i++) {
    ofst << i << ": " << CalcFigureArea(container.cont[i], ofst) << "\n";
  }
}

//------------------------------------------------------------------------------
// Вычиcление площади фигуры
double ClientGeometry::CalcFigureArea(Figure* f, std::ofstream &ofst) {
  Rectangle* r;
  Triangle* t;
  if((r = dynamic_cast<Rectangle*>(f)) != nullptr) {
    return (double)(r->x * r->y);
  } else if((t = dynamic_cast<Triangle*>(f)) != nullptr) {
    double p = double(t->a + t->b + t->c) / 2.0;
    return sqrt(p * (p - t->a) * (p - t->b) * (p - t->c));
  }
  ofst << "Unknown Figure Perimeter\n";
  return 0.0;
}
