//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include "container.h"

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

  ofst << "Filled container.\n";
  c.Out(ofst);

  c.Clear();
  ofst << "Empty container.\n";
  c.Out(ofst);

  std::cout << "Stop\n";
  return 0;
}
