//------------------------------------------------------------------------------
// figure.cpp - содержит процедуру ввода параметров
// для уже созданной любой фигуры
//------------------------------------------------------------------------------

#include <iostream>
#include "figure.h"

//------------------------------------------------------------------------------
// Необходима подключить информацию обо всех имеющихся
// геометрических фигурах
#include "rectangle.h"
#include "triangle.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из стандартного потока ввода
SimpleFigure* SimpleFigure::In(std::ifstream &ifst) {
  SimpleFigure *pf;
  int k;
  ifst >> k;
  switch(k) {
  case 1:
    pf = new SimpleRectangle;
    break;
  case 2:
    pf = new SimpleTriangle;
    break;
  default:
    std::cout << "Incorrect key of figure!!!\n";
    exit(-1);
  }
  // std::cout << k << "\n";
  pf->InData(ifst);
  return pf;
}
