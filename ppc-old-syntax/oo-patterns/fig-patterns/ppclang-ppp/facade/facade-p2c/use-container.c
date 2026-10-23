//==============================================================================
// use-container.c - содержит функции контейнера, образующие фасад.
//==============================================================================

#include "figure-container.h"

//------------------------------------------------------------------------------
// Прототип функии ввода всех фигур
void FigureCreateAndIn(FILE* ifst, FigureContainer* pfc);

//------------------------------------------------------------------------------
// Заполнение контейнера из файла с заданным именем
FigureContainer *FigureContainerInFromFile(char* fileName) {
  FILE* ifst = fopen(fileName, "r");
  FigureContainer *c = malloc(sizeof(FigureContainer));
  FigureContainerInit(c);
  FigureCreateAndIn(ifst, c);
  fclose(ifst);
  return c;
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный файл
void FigureContainerOutToFile(FigureContainer *c, char* fileName) {
  FILE* ofst = fopen(fileName, "w");
  FigureContainerOut(c, ofst);
  fclose(ofst);
}

//------------------------------------------------------------------------------
// Очистка и удаление использованного контейнера
void FigureContainerDelete(FigureContainer* c) {
  FigureContainerClear(c);
  free(c);
}
