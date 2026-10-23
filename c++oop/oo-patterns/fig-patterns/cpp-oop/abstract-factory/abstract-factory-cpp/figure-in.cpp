//------------------------------------------------------------------------------
// figure-in.cpp - статический метод ввода параметров фигур из файлов
//------------------------------------------------------------------------------

#include <iostream>
#include "figure.h"

//------------------------------------------------------------------------------
#include "figure-factory.h"
#include "rectangle-container.h"
#include "triangle-container.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из стандартного потока ввода
// Для создания фигур используется фабричный метод
void Figure::In(std::ifstream &ifst, FigureFactory* factory,
                RectangleContainer* prc, TriangleContainer* ptc) {
  Rectangle *pr;
  Triangle  *pt;
  int k;
  while(!ifst.eof())
  {
    ifst >> k;
    switch(k) {
    case 1:
      pr = factory->CreateRectangle();
      pr->InData(ifst);
      prc->In(pr);
      break;
    case 2:
      pt = factory->CreateTriangle();
      pt->InData(ifst);
      ptc->In(pt);
      break;
    default:
      std::cout << "Incorrect key of figure!!!\n";
      exit(-1);
    }
  }
}
