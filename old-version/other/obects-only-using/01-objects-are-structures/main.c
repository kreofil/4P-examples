//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>
#include "objects.h"

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  if(argc !=3) {
    printf("incorrect command line!\nWaited: command infile outfile\n");
    return 1;
  }
  FILE* ifst = fopen(argv[1], "r");
  FILE* ofst = fopen(argv[2], "w");

  printf("Start\n");

  struct O.Container c;
  Init<(O*)&c>();
  Input<(O*)&c>(ifst);
  fclose(ifst);

  fprintf(stdout, "Filled container.\n");
  Print<(O*)&c>(stdout);

  fprintf(ofst, "Filled container.\n");
  Print<(O*)&c>(ofst);

  Сomplete<(O*)&c>();

  fprintf(stdout, "Empty container.\n");
  Print<(O*)&c>(stdout);

  fprintf(ofst, "Empty container.\n");
  Print<(O*)&c>(ofst);
  fclose(ofst);

  printf("Stop\n");
  return 0;
}
