//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>
#include "container.h"
#include "new-generalization.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void ContainerInit(struct ppVector.fig* c) ;
void ContainerClear(struct ppVector.fig* c);

void ContainerIn(struct ppVector.fig* c, FILE* ifst);
void ContainerOut(struct ppVector.fig* c, FILE* ofst);

void ContainerPerimeterOut(struct ppVector.fig* c, FILE* ofst) ;

void AddNewGeneralization(ContainerOfPerimeters* fpc, struct ppVector.fig* c);
void ContainerNewPerimeterOut(ContainerOfPerimeters* fpc, FILE* ofst);

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  if(argc !=3) {
    printf("incorrect command line!\nWaited: command infile outfile\n");
    return 1;
  }
  FILE* ifst = fopen(argv[1], "r");
  FILE* ofst = fopen(argv[2], "w");

  printf("Start\n");

  // Container c;
  // ContainerInit(&c);
  ppVector_VAR(fig, c)
  ContainerIn(&c, ifst);
  fclose(ifst);

  fprintf(stdout, "Filled container.\n");
  ContainerOut(&c, stdout);
  ContainerPerimeterOut(&c, stdout);

  fprintf(ofst, "Filled container.\n");
  ContainerOut(&c, ofst);
  ContainerPerimeterOut(&c, ofst);

  // New generalization container
  ContainerOfPerimeters pc;
  AddNewGeneralization(&pc, &c);
  ContainerNewPerimeterOut(&pc, stdout);

  ContainerClear(&c);

  fprintf(stdout, "Empty container.\n");
  ContainerOut(&c, stdout);

  fprintf(ofst, "Empty container.\n");
  ContainerOut(&c, ofst);
  fclose(ofst);

  printf("Stop\n");
  return 0;
}
