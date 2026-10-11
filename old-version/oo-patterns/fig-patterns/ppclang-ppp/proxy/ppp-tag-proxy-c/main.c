//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>

#include "container.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void ContainerInit(Container* c) ;
void ContainerClear(Container* c);

void ContainerIn(Container* c, FILE* ifst) ;
void ContainerOut(Container* c, FILE* ofst) ;
// Ввод в прокси фигуры, расположенные в контейнере, фигур, указанных в прокси
void ProxyContainerIn(Container *c);

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  if(argc !=3) {
    printf("incorrect command line!\nWaited: command infile outfile\n");
    return 1;
  }
  FILE* ifst = fopen(argv[1], "r");
  FILE* ofst = fopen(argv[2], "w");

  printf("Start\n");

  Container c;
  ContainerInit(&c);
  ContainerIn(&c, ifst);
  fclose(ifst);

  fprintf(stdout, "Filled container.\n");
  ContainerOut(&c, stdout);
  fprintf(ofst, "Filled container.\n");
  ContainerOut(&c, ofst);

  // Ввод в прокси фигур
  ProxyContainerIn(&c);

  fprintf(stdout, "Container with Proxy Figures.\n");
  ContainerOut(&c, stdout);
  fprintf(ofst, "Container with Proxy Figures.\n");
  ContainerOut(&c, ofst);


  ContainerClear(&c);

  fprintf(stdout, "Empty container.\n");
  ContainerOut(&c, stdout);

  fprintf(ofst, "Empty container.\n");
  ContainerOut(&c, ofst);

  fclose(ofst);

  printf("Stop\n");
  return 0;
}
