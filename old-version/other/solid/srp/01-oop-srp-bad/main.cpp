//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include "container.h"
#include "client-draw.h"
#include "client-geometry.h"

int main(int argc, char* argv[]) {
  if(argc !=3) {
    std::cout << "incorrect command line! Wated: command infile outfile\n";
    return 1;
  }
  std::ifstream ifst(argv[1]);
  std::ofstream ofst(argv[2]);

  std::cout << "Start\n";
  Container c;
  c.In(ifst);

  // Вывод контейнера рисующим клиентом
  ClientDraw clientDraw(c);
  std::cout << "ClientDraw draws container\n";
  clientDraw.DrawContainer(ofst);

  // Организация вычислений геометрическим клиентом
  ClientGeometry clientGeometry(c);
  std::cout << "ClientGeometry calcs perimeters\n";
  clientGeometry.CalcPerimeters(ofst);

  std::cout << "ClientGeometry calcs areas\n";
  clientGeometry.CalcAreas(ofst);

  c.Clear();
  ofst << "ClientDraw draws empty container.\n";
  // Вывод контейнера рисующим клиентом
  clientDraw.DrawContainer(ofst);

  std::cout << "Stop\n";
  return 0;
}
