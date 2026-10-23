//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <ctime>
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
  c.PerimeterOut(ofst);
  ofst << "Common perimeter = " << c.Perimeter() << "\n";

  std::cout << "Common perimeter = " << c.Perimeter() << "\n";

  // ofst << "Multimethod out.\n";
  // c.MultimethodOut(ofst);

  // Тестовый фрагмент для вычисления скорости вычисления периметра.
  int p = 0;
  clock_t startTime = clock();
  for(int i = 0; i < 10000000; ++i) {
    p = c.MultimethodDifFunc();
  }
  clock_t endTime = clock();
  std::cout << "p = " << p << "\n";

  c.Clear();
  ofst << "Empty container.\n";
  c.Out(ofst);

  std::cout << "Delta time = "
            << (double)(endTime - startTime) / CLOCKS_PER_SEC
            << "\n";

  std::cout << "Stop\n";
  return 0;
}
