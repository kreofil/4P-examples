//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>
#include "use-container.h"

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  if(argc !=3) {
    printf("incorrect command line! Wated: command infile outfile\n");
    return 1;
  }

  char *inFileName = argv[1];
  char *outFileName = argv[2];

  printf("Start\n");

  // Заполнение контейнера из файла с заданным именем
  struct FigureContainer *c = FigureContainerInFromFile(inFileName);

  // Вывод содержимого контейнера в указанный файл
  fprintf(stdout, "Filled container.\n");
  FigureContainerOutToFile(c, outFileName);

  // Очистка и удаление использованного контейнера
  FigureContainerDelete(c);

  printf("Stop\n");
  return 0;
}
