//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include "simple-figure-factory.h"
#include "coord-figure-factory.h"

#include "rectangle-container.h"
#include "triangle-container.h"

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
  RectangleContainer rc;
  TriangleContainer  tc;

  std::cout << "Start\n";

  Figure::In(ifst_simple, &simpleFactory, &rc, &tc);
  ofst << "Filled Simple Rectangles.\n";
  rc.Out(ofst);
  ofst << "Filled Simple Triangles.\n";
  tc.Out(ofst);

  Figure::In(ifst_coord, &coordFactory, &rc, &tc);
  ofst << "Filled All Rectangles.\n";
  rc.Out(ofst);
  ofst << "Filled All Triangles.\n";
  tc.Out(ofst);

  rc.Clear();
  ofst << "Empty Rectangle Container.\n";
  rc.Out(ofst);
  tc.Clear();
  ofst << "Empty Triangle Container.\n";
  tc.Out(ofst);

  std::cout << "Stop\n";
  return 0;
}