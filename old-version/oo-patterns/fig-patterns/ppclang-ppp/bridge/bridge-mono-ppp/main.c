//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>

#include "container.h"
#include "figure-factory.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void ContainerInit(Container* c) ;
void ContainerClear(Container* c);
void ContainerIn(Container* c, FILE* ifst, FigureFactory* factory);
void ContainerOut(Container* c, FILE* ofst);

//------------------------------------------------------------------------------
int main() {
  // В демонстрационном примере данные для формирования семейств фигур
  // размещеены в конкретных файлов с явным указанием путей
  char simpleFigureFile[] = "../data/simple-input1.txt";
  char coordFigureFile[] = "../data/coord-input1.txt";
  char resultFigureFile[] = "../data/output1.txt";

  FILE* ifst_simple = fopen(simpleFigureFile, "r");
  FILE* ifst_coord = fopen(coordFigureFile, "r");
  FILE* ofst = fopen(resultFigureFile, "w");

  struct FigureFactory.simple simpleFactory;
  struct FigureFactory.coord  coordFactory;

  printf("Start\n");

  Container c;
  ContainerInit(&c);

  ContainerIn(&c, ifst_simple, (FigureFactory*)&simpleFactory);
  fclose(ifst_simple);

  fprintf(stdout, "Simple Figures Filled Container.\n");
  ContainerOut(&c, stdout);

  fprintf(ofst, "Simple Figures Filled Container.\n");
  ContainerOut(&c, ofst);

  ContainerClear(&c);

  fprintf(stdout, "Empty Container.\n");
  ContainerOut(&c, stdout);

  fprintf(ofst, "Empty Container.\n");
  ContainerOut(&c, ofst);

  ContainerIn(&c, ifst_coord, (FigureFactory*)&coordFactory);
  fclose(ifst_coord);

  fprintf(stdout, "Coord Figures Filled Container.\n");
  ContainerOut(&c, stdout);

  fprintf(ofst, "Coord Figures Filled Container.\n");
  ContainerOut(&c, ofst);

  ContainerClear(&c);

  fprintf(stdout, "Empty Container.\n");
  ContainerOut(&c, stdout);

  fprintf(ofst, "Empty container.\n");
  ContainerOut(&c, ofst);

  fclose(ofst);

  printf("Stop\n");
  return 0;
}