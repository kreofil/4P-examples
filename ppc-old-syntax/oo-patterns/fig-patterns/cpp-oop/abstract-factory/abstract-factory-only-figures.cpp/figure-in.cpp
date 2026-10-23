//------------------------------------------------------------------------------
// figure-in.cpp - статический метод ввода параметров фигур из файлов
//------------------------------------------------------------------------------

#include <iostream>
#include "figure.h"

//------------------------------------------------------------------------------
#include "figure-factory.h"
#include "rectangle.h"
#include "triangle.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из стандартного потока ввода
// Для создания фигур используется фабричный метод
void FiguresInOut::InOut(FigureFactory* factory,
                   std::ifstream &ifst,
                   std::ofstream &ofst)
{
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
      pr->Out(ofst);
      delete pr;
      break;
    case 2:
      pt = factory->CreateTriangle();
      pt->InData(ifst);
      pt->Out(ofst);
      delete pt;
      break;
    default:
      std::cout << "Incorrect key of figure!!!\n";
      exit(-1);
    }
  }
}
