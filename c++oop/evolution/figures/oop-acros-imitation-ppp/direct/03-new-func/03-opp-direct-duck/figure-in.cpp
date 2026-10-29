//------------------------------------------------------------------------------
// figure-in.cpp - содержит процедуру ввода параметров
// для уже созданной любой фигуры
//------------------------------------------------------------------------------

// #include <iostream>
#include "figure.h"

//------------------------------------------------------------------------------
// Необходима подключить информацию обо всех имеющихся
// геометрических фигурах
#include "rectangle.h"
#include "triangle.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из стандартного потока ввода
Figure* Figure::In(std::ifstream &ifst) {
  Figure *sp;
  Any *anyFigure;
  int k;
  ifst >> k;
  switch(k) {
    case 1:
      anyFigure = new Rectangle;
      break;
    case 2:
      anyFigure = new Triangle;
      break;
    default:
      return 0;
  }
  sp = new Figure;
  sp->specObject = anyFigure;
  sp->InFP(ifst);
  return sp;
}
