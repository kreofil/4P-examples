//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "container.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void ContainerInit(Container* c) ;
void ContainerClear(Container* c);

void ContainerIn(Container* c, FILE* ifst) ;
void ContainerOut(Container* c, FILE* ofst) ;

// Многопоточное вычисление периметров фигур, расположенных в контейнере
double CalcFigurePerimetersInContainer(Container *c);
// Вывод содержимого контейнера в указанный поток
void ContainerPerimeterOut(Container *c, FILE* ofst);
// Вывод пар элементов контейнера в указанный поток через вызов мультиметода
void TreadContainerMultimethodOut(Container *c, FILE* ofst);

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  if(argc !=3) {
    printf("incorrect command line!\nWaited: command infile outfile\n");
    return 1;
  }
  FILE* ifst = fopen(argv[1], "r");
  FILE* ofst = fopen(argv[2], "w");
  srand(time(NULL));

  printf("Start\n");

  Container c;
  ContainerInit(&c);
  ContainerIn(&c, ifst);
  fclose(ifst);

  fprintf(stdout, "Filled container.\n");
  ContainerOut(&c, stdout);
  // ContainerPerimeterOut(&c, stdout);
  double commonPerimeter = CalcFigurePerimetersInContainer(&c);
  // printf("Common Result Perimeter = %lf\n", commonPerimeter);

  fprintf(ofst, "Filled container.\n");
  ContainerOut(&c, ofst);
  ContainerPerimeterOut(&c, ofst);

  fprintf(stdout, "Multimethod out.\n");
  // ContainerMultimethodOut(&c, stdout);
  TreadContainerMultimethodOut(&c, stdout);

  ContainerClear(&c);

  fprintf(stdout, "Empty container.\n");
  ContainerOut(&c, stdout);

  fprintf(ofst, "Empty container.\n");
  ContainerOut(&c, ofst);
  fclose(ofst);

  printf("Stop\n");
  return 0;
}
