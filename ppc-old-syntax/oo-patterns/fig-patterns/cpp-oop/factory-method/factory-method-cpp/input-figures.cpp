//------------------------------------------------------------------------------
// input-figures.cpp - статический метод ввода параметров фигур из файлов
//------------------------------------------------------------------------------

#include <iostream>
#include "figure-container.h"
#include "simple-rectangle-creator.h"
#include "simple-triangle-creator.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из стандартного потока ввода
// Для создания фигур используется фабричный метод
void Figure::In(std::ifstream &ifst, FigureContainer* pfc) {
  SimpleRectangleCreator rectangleCreator;
  SimpleTriangleCreator triangleCreator;
  Figure* pf;
  int k;
  while(!ifst.eof())
  {
    ifst >> k;
    switch(k) {
    case 1:
      pf = rectangleCreator.CreateFigure();
      break;
    case 2:
      pf = triangleCreator.CreateFigure();
      break;
    default:
      std::cout << "Incorrect key of figure!!!\n";
      exit(-1);
    }
    pf->InData(ifst);
    pfc->Append(pf);
  }
}
