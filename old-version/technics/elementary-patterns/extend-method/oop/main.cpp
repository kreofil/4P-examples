//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

// #include <iostream>
#include "rectangle.h"
#include "triangle.h"

int main(int argc, char* argv[]) {
  Figure *pf = nullptr;

  Rectangle r;
  r.In();
  pf = &r;
  pf->Out();

  Triangle t;
  t.In();
  pf = &t;
  pf->Out();

  return 0;
}
