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
  // FILE* ifst = fopen(argv[1], "r");
  // FILE* ofst = fopen(argv[2], "w");
  struct O.Fstream ifst; FileOpen(&ifst, argv[1], "r");
  struct O.Fstream ofst; FileOpen(&ofst, argv[2], "w");
  struct O.Fstream cout; cout.@f = stdout;

  printf("Start\n");

  struct O.Container c;
  Init<(O*)&c>();
  Input<(O*)&c>(&ifst);
  FileClose(&ifst);

  fprintf(stdout, "Filled container.\n");
  Print<(O*)&c>(&cout);

  fprintf(ofst.@f, "Filled container.\n");
  Print<(O*)&c>(&ofst);

  Сomplete<(O*)&c>();

  fprintf(stdout, "Empty container.\n");
  Print<(O*)&c>(&cout);

  fprintf(ofst.@f, "Empty container.\n");
  Print<(O*)&c>(&ofst);
  FileClose(&ofst);

  printf("Stop\n");
  return 0;
}
