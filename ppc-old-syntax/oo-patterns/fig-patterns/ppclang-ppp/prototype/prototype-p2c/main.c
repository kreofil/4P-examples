//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "simple-figure.h"

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  if(argc !=3) {
    printf("incorrect command line!\nWaited: command infile outfile\n");
    return 1;
  }
  FILE* ifst = fopen(argv[1], "r");
  FILE* ofst = fopen(argv[2], "w");

  printf("Start\n");

  struct SimpleFigure.FigureContainer container;
  FigureContainerInit(&(container.@));

  FigureIn<(SimpleFigure*)&container>(ifst);
  fclose(ifst);

  fprintf(stdout, "Filled Parent container.\n");
  FigureOut<(SimpleFigure*)&container>(stdout);

  fprintf(ofst, "Filled Parent container.\n");
  FigureOut<(SimpleFigure*)&container>(ofst);

  //========

  struct SimpleFigure.FigureContainer *pc;
  pc = (struct SimpleFigure.FigureContainer*)FigureClone<(SimpleFigure*)&container>();

  fprintf(stdout, "Filled Cloned container.\n");
  FigureOut<(SimpleFigure*)&container>(stdout);

  fprintf(ofst, "Filled Cloned container.\n");
  FigureOut<(SimpleFigure*)&container>(ofst);

  FigureContainerClear(&(container.@));
  fprintf(ofst, "Empty Parent container.\n");
  FigureOut<(SimpleFigure*)&container>(ofst);

  FigureContainerClear(&(pc->@));
  fprintf(ofst, "Empty Cloned container.\n");
  FigureOut<(SimpleFigure*)&container>(ofst);

  fclose(ofst);
  free(pc);

  printf("Stop\n");
  return 0;
}