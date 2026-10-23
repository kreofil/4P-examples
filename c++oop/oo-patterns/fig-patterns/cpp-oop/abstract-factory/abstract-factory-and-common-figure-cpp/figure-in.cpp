//------------------------------------------------------------------------------
// figure-in.cpp - статический метод ввода параметров фигур из файлов
//------------------------------------------------------------------------------

#include <iostream>
#include "figure.h"

//------------------------------------------------------------------------------
// #include "rectangle.h"
// #include "triangle.h"
#include "figure-factory.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из стандартного потока ввода
// Для создания фигур используется фабричный метод
Figure* Figure::In(std::ifstream &ifst, FigureFactory* factory) {
  Figure *pf;
  int k;
  ifst >> k;
  switch(k) {
  case 1:
    pf = factory->CreateRectangle();
    break;
  case 2:
    pf = factory->CreateTriangle();
    break;
  default:
    std::cout << "Incorrect key of figure!!!\n";
    exit(-1);
  }
  // std::cout << k << "\n";
  // Заполнение полей фигуры
  pf->InData(ifst);
  return pf;
}
