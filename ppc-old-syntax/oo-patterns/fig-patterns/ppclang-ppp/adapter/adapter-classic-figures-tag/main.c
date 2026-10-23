//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>

#include "adapter.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void ContainerInit(Container* c) ;
void ContainerClear(Container* c);
void ContainerIn(Container* c, FILE* ifst) ;
void ContainerOut(Container* c, FILE* ofst) ;

// Прототип обобщеннай функции вывода фигуры
void FigureOut<Figure *f>(FILE* ofst);

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
  // Подключение адаптера
  struct Figure.contAdapter contAdapter;
  contAdapter.@container = &c;

  ContainerInit(&c);
  ContainerIn(&c, ifst);
  fclose(ifst);

  fprintf(stdout, "Filled container.\n");
  FigureOut<(Figure*)&contAdapter>(stdout);
  // ContainerOut(&c, stdout);

  fprintf(ofst, "Filled container.\n");
  FigureOut<(Figure*)&contAdapter>(ofst);
  // ContainerOut(&c, ofst);

  ContainerClear(&c);

  fprintf(stdout, "Empty container.\n");
  FigureOut<(Figure*)&contAdapter>(stdout);
  // ContainerOut(&c, stdout);

  fprintf(ofst, "Empty container.\n");
  FigureOut<(Figure*)&contAdapter>(ofst);
  // ContainerOut(&c, ofst);
  fclose(ofst);

  printf("Stop\n");
  return 0;
}
