//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>
#include "word32-spec.h"

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  printf("Start\n");

  struct w32.i iopd1;
  struct w32.i iopd2;
  struct w32.i ires;
  struct w32   unres;

  iopd1.val = 10;
  iopd2.val = 20;
  unres.val = (unsigned int)-1;

  Add<&iopd1, &iopd2>(&ires);
  printf("result = ");
  DebugOut<&ires>();
  // printf("result = %d\n", (int)ires.val);

  iopd2.val = -40;
  Add<&ires, &iopd2>(&ires);
  printf("result = ");
  DebugOut<&ires>();
  // printf("result = %d\n", (int)ires.val);

  iopd1 = iopd2;
  printf("iopd1 = ");
  DebugOut<&iopd1>();
  // printf("iopd1 = %d\n", (int)iopd1.val);

  Add<&ires, &iopd1>(&ires);
  printf("result = ");
  DebugOut<&ires>();
  // printf("result = %d\n", (int)ires.val);

  struct w32.u uopd1;
  struct w32.u uopd2;
  struct w32.u ures;

  uopd1.val = 100;
  uopd2.val = 200;

  Add<&uopd1, &uopd2>(&ures);
  printf("unsigned result = ");
  DebugOut<&ures>();
  // printf("unsigned result = %u\n", (unsigned int)ures.val);

  Add<&iopd1, &uopd2>(&unres);
  printf("incorrect unsigned result = ");
  DebugOut<&unres>();
  // printf("unsigned result = %u\n", (unsigned int)ures.val);

  uopd1.name = "uopd1";
  uopd2.name = "uopd2";
  unres.name = "uresult";

  GenRiskV_Add<&uopd1, &uopd2>(&unres);

  printf("Finish\n");
  return 0;
}
