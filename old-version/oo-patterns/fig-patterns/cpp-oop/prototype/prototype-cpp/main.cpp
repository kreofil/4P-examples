//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include "simple-container.h"

//------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
  if(argc !=3) {
    std::cout << "incorrect command line! Wated: command infile outfile\n";
    return 1;
  }

  std::ifstream ifst(argv[1]);
  std::ofstream ofst(argv[2]);

  std::cout << "Start\n";

  SimpleContainer c;
  c.InData(ifst);
  ofst << "Filled container.\n";
  c.Out(ofst);

  //========

  SimpleContainer* pc;
  pc = c.Clone();
  ofst << "Filled cloned container.\n";
  pc->Out(ofst);

  c.Clear();
  ofst << "Empty container.\n";
  c.Out(ofst);

  pc->Clear();
  ofst << "Empty cloned container.\n";
  pc->Out(ofst);

  delete pc;

  std::cout << "Stop\n";
  return 0;
}