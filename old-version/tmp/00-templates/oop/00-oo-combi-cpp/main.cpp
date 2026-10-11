//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include "simple-container.h"
#include "coord-container.h"

//------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
  if(argc !=4) {
    std::cout
      << "incorrect command line! Wated: command infile1 infile2 outfile\n";
    return 1;
  }

  std::ifstream ifst1(argv[1]);
  std::ifstream ifst2(argv[2]);
  std::ofstream ofst(argv[3]);

  std::cout << "Start\n";

  SimpleContainer c1;
  c1.In(ifst1);

  ofst << "Filled Simple container.\n";
  c1.Out(ofst);

  c1.Clear();

  ofst << "Empty Simple container.\n";
  c1.Out(ofst);

  CoordContainer c2;
  c2.In(ifst2);

  ofst << "Filled Coord container.\n";
  c2.Out(ofst);

  c2.Clear();

  ofst << "Empty Coord container.\n";
  c2.Out(ofst);

  std::cout << "Stop\n";
  return 0;
}