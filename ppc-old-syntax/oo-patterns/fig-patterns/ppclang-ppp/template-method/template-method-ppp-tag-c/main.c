//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>
#include <stdlib.h>

#include "action.h"
#include "container.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void FigureOut<struct Figure* s>(FILE* ofst);

void ContainerInit(Container* c) ;
void ContainerClear(Container* c);

// void ContainerIn(Container* c, FILE* ifst) ;
void ContainerAppend(Container* c, struct Figure * figure);
void ContainerOut(Container* c, FILE* ofst) ;

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  // if(argc !=2) {
  //   printf("incorrect command line!\nWaited: command infile outfile\n");
  //   return 1;
  // }
  // FILE* ifst = fopen(argv[1], "r");
  // FILE* ofst = fopen(argv[1], "w");

  printf("Start\n");

  Container c;
  ContainerInit(&c);
  // ContainerIn(&c, ifst);
  // fclose(ifst);

  struct Action.rectangle actRect;
  struct Action.triangle actTrian;

  Figure* pf = InputConcreteFigure<(Action*)&actRect>("../data/rect-01.txt");
  if(pf == NULL) {
    printf("Incorrect InputConcreteFigure\n");
  } else {
    FigureOut<pf>(stdout);
    ContainerAppend(&c, pf);
    // free(pf);
    // pf = NULL;
  }

  pf = InputConcreteFigure<(Action*)&actTrian>("../data/trian-01.txt");
  if(pf == NULL) {
    printf("Incorrect InputConcreteFigure\n");
  } else {
    FigureOut<pf>(stdout);
    ContainerAppend(&c, pf);
    // free(pf);
    // pf = NULL;
  }
  fprintf(stdout, "Filled container.\n");
  ContainerOut(&c, stdout);

  // fprintf(ofst, "Filled container.\n");
  // ContainerOut(&c, ofst);

  ContainerClear(&c);

  fprintf(stdout, "Empty container.\n");
  ContainerOut(&c, stdout);

  // fprintf(ofst, "Empty container.\n");
  // ContainerOut(&c, ofst);
  // fclose(ofst);

  printf("Stop\n");
  return 0;
}
