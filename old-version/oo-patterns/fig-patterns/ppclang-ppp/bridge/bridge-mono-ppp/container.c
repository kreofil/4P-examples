//==============================================================================
// container-constr.c - содержит функции обратотки контейнера
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "figure-factory.h"
#include "container.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void FigureOut<struct Figure* s>(FILE* ofst);
struct Figure *FigureCreateAndIn(FILE* ifst, struct FigureFactory* factory);

//------------------------------------------------------------------------------
// Инициализация контейнера
void ContainerInit(Container *c) {
  c->len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void ContainerClear(Container *c) {
  for(int i = 0; i < c->len; i++) {
    free(c->cont[i]);
  }
  ContainerInit(c);
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void ContainerIn(Container* c, FILE* ifst, FigureFactory* factory) {
  while(!feof(ifst))  {
    // printf("ContainerIn. Loop in container\n");
    if((c->cont[c->len] = FigureCreateAndIn(ifst, factory)) != 0) {
      c->len++;
    }
  }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void ContainerOut(Container *c, FILE* ofst) {
  fprintf(ofst, "Container contains %d elements.\n", c->len);
  for(int i = 0; i < c->len; i++) {
    // printf("%d: Loop in container\n", i);
    fprintf(ofst, "%d: " , i);
    FigureOut<c->cont[i]>(ofst);
  }
}
