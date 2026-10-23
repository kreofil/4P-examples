//------------------------------------------------------------------------------
// simple-figures-builder.cpp - реализация методов строительства простых фигур
//------------------------------------------------------------------------------

#include "simple-figures-builder.h"
#include "simple-rectangle.h"
#include "simple-triangle.h"

// Конструктор, подключающий массив для хранения аппликации
SimpleBuilder::SimpleBuilder(FigureContainer* _container): container{_container}
{}

// Методы, используемые для строительства композиций
void SimpleBuilder::BuildRectangle(double x, double y) {
  SimpleRectangle *rectangle = new SimpleRectangle(x, y);
  // rectangle->SetX(x);
  // rectangle->SetY(y);
  container->Append(rectangle);
}
void SimpleBuilder::BuildTriangle(double a, double b, double c) {
  SimpleTriangle *triangle = new SimpleTriangle(a, b, c);
  // triangle->SetA(a);
  // triangle->SetB(b);
  // triangle->SetC(c);
  container->Append(triangle);
}

// Результат строительства сохраняется в файле
void SimpleBuilder::ResultOut(std::ofstream &ofst) {
  ofst << "Result of building from Simple figures:\n";
  container->Out(ofst);
}
