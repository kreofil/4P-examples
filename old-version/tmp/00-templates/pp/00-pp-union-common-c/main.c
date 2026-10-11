//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>

#include "simple-container.h"
#include "coord-container.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void SimpleContainerInit(SimpleContainer* c) ;
void SimpleContainerClear(SimpleContainer* c);

void SimpleContainerIn(SimpleContainer* c, FILE* ifst) ;
void SimpleContainerOut(SimpleContainer* c, FILE* ofst) ;

void CoordContainerInit(CoordContainer* c) ;
void CoordContainerClear(CoordContainer* c);

void CoordContainerIn(CoordContainer* c, FILE* ifst) ;
void CoordContainerOut(CoordContainer* c, FILE* ofst) ;

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  if(argc !=4) {
    printf(
      "incorrect command line! Wated: command infile1 infile2 outfile\n"
    );
    return 1;
  }
  FILE* ifst_simple = fopen(argv[1], "r");
  FILE* ifst_coord = fopen(argv[2], "r");
  FILE* ofst = fopen(argv[3], "w");

  printf("Start\n");

  SimpleContainer c1;
  SimpleContainerInit(&c1);
  SimpleContainerIn(&c1, ifst_simple);
  fclose(ifst_simple);

  SimpleContainerOut(&c1, stdout);

  fprintf(ofst, "Filled container.\n");
  SimpleContainerOut(&c1, ofst);

  SimpleContainerClear(&c1);
  fprintf(ofst, "Empty container.\n");
  SimpleContainerOut(&c1, ofst);
  // fclose(ofst);

  CoordContainer c2;
  CoordContainerInit(&c2);
  CoordContainerIn(&c2, ifst_coord);
  fclose(ifst_coord);

  fprintf(ofst, "Filled container.\n");
  CoordContainerOut(&c2, ofst);
  fprintf(stdout, "Filled container.\n");

  CoordContainerOut(&c2, stdout);

  CoordContainerClear(&c2);
  fprintf(ofst, "Empty container.\n");
  CoordContainerOut(&c2, ofst);
  fclose(ofst);

  printf("Stop\n");
  return 0;
}