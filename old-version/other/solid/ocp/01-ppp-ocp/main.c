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
void ContainerPerimeterOut(Container* c, FILE* ofst) ;
void ContainerAreaOut(Container* c, FILE* ofst) ;

// Те же функции, но через интерфес для рисования
#include "drawing-client.h"
#include "geometry-client.h"

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

  //============================================================================
  // Использование ограниченных интерфейсов клиентов
  //============================================================================

  fprintf(stdout, "\nDraw client.\n");
  Draw(&c, stdout);
  fprintf(ofst, "\nDraw client.\n");
  Draw(&c, ofst);

  fprintf(stdout, "\nCalulation of Perimeter by Geometry client.\n");
  CalcPerimeter(&c, stdout);
  fprintf(ofst, "\nCalulation of Perimeter by Geometry client.\n");
  CalcPerimeter(&c, ofst);

  fprintf(stdout, "\nCalulation of Area by Geometry client.\n");
  CalcArea(&c, stdout);
  fprintf(ofst, "\nCalulation of Area by Geometry client.\n");
  CalcArea(&c, ofst);

  ContainerClear(&c);

  fprintf(stdout, "Empty container.\n");
  ContainerOut(&c, stdout);

  fprintf(ofst, "Empty container.\n");
  ContainerOut(&c, ofst);
  fclose(ofst);

  printf("Stop\n");
  return 0;
}
