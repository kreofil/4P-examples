//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include "simple-figure-factory.h"
#include "coord-figure-factory.h"
#include "container.h"

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

  std::cout << "Start\n";

  Container c;

  c.In(ifst_simple, &simpleFactory);
  ofst << "Filled container.\n";
  c.Out(ofst);
  c.Clear();
  ofst << "Empty container.\n";
  c.Out(ofst);

  c.In(ifst_coord, &coordFactory);
  ofst << "Filled container.\n";
  c.Out(ofst);
  c.Clear();
  ofst << "Empty container.\n";
  c.Out(ofst);

  std::cout << "Stop\n";
  return 0;
}