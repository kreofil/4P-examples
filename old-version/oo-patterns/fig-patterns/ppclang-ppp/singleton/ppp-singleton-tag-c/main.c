//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>

#include "interface.h"

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  if(argc !=3) {
    printf("incorrect command line!\nWaited: command infile outfile\n");
    return 1;
  }
  FILE* ifst = fopen(argv[1], "r");
  FILE* ofst = fopen(argv[2], "w");

  printf("Start\n");

  struct Container *c1 = ContainerCreate();
  ContainerIn(c1, ifst);
  fclose(ifst);

  fprintf(stdout, "Filled container.\n");
  ContainerOut(c1, stdout);

  fprintf(ofst, "Filled container.\n");
  ContainerOut(c1, ofst);

  ifst = fopen(argv[1], "r");
  struct Container *c2 = ContainerCreate();
  ContainerIn(c2, ifst);
  fclose(ifst);

  fprintf(stdout, "Filled container.\n");
  ContainerOut(c2, stdout);

  fprintf(ofst, "Filled container.\n");
  ContainerOut(c2, ofst);

  fclose(ofst);

  ContainerDelete();

  printf("Stop\n");
  return 0;
}
