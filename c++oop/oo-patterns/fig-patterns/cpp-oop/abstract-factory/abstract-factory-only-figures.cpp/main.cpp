//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include "simple-figure-factory.h"
#include "coord-figure-factory.h"

// #include "rectangle-container.h"
// #include "triangle-container.h"

//------------------------------------------------------------------------------
int main()
{
  // В демонстрационном примере данные для формирования семейств фигур
  // размещеены в конкретных файлов с явным указанием путей
  char simpleFigureFile[] = "../data/simple-input1.txt";
  char coordFigureFile[] = "../data/coord-input1.txt";
  char resultFigureFile[] = "../data/output1.txt";

  std::ifstream ifst_simple(simpleFigureFile);
  std::ifstream ifst_coord(coordFigureFile);
  std::ofstream ofst(resultFigureFile);

  SimpleFigureFactory simpleFactory;
  CoordFigureFactory  coordFactory;
  // RectangleContainer rc;
  // TriangleContainer  tc;

  std::cout << "Start\n";

  ofst << "Simple figures input\n";
  FiguresInOut::InOut(&simpleFactory, ifst_simple, ofst);

  ofst << "Coord figures input\n";
  FiguresInOut::InOut(&coordFactory, ifst_coord, ofst);

  std::cout << "Stop\n";
  return 0;
}