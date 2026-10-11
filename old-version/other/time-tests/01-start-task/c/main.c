//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>
#include <time.h>

#include "container.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void ContainerInit(Container* c) ;
void ContainerClear(Container* c);

void ContainerIn(Container* c, FILE* ifst) ;
void ContainerOut(Container* c, FILE* ofst) ;
void ContainerPerimeterOut(Container* c, FILE* ofst) ;
double ContainerPerimeter(Container* c) ;

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

  printf("Filled container.\n");
  ContainerOut(&c, stdout);
  ContainerPerimeterOut(&c, stdout);
  printf("Common perimeter = %lf\n", ContainerPerimeter(&c));

  fprintf(ofst, "Filled container.\n");
  ContainerOut(&c, ofst);
  ContainerPerimeterOut(&c, ofst);
  fprintf(ofst, "Common perimeter = %lf\n", ContainerPerimeter(&c));

  // Тестовый фрагмент для вычисления скорости вычисления периметра.
  clock_t startTime = clock();
  for(int i = 0; i < 100000000; ++i) {
    ContainerPerimeter(&c);
  }
  clock_t endTime = clock();

  ContainerClear(&c);
  fprintf(ofst, "Empty container.\n");
  ContainerOut(&c, ofst);

  printf("Delta time = %lf\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);
  fprintf(ofst, "Delta time = %lf\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);
  fclose(ofst);

  printf("Stop\n");

  return 0;
}
