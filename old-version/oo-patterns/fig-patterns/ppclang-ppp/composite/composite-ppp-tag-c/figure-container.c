//==============================================================================
// figure-container.c - содержит обработчики, определяющие
// функионирование контейнера как фигуры
//==============================================================================

#include <stdio.h>
// #include <stdlib.h>
#include "figure-container.h"

//------------------------------------------------------------------------------
// Пртотипы функций используемой основы специализации
void ContainerInit(Container *c);
void ContainerClear(Container *c);
void ContainerIn(Container* c, FILE* ifst);
void ContainerOut(Container *c, FILE* ofst);
void ContainerAppend(Container* c, struct Figure * figure);
// Прототип обобщеннай функции ввода фигуры
void FigureIn<Figure *f>(FILE* file);
// Обобщающая функция для вывода параметров фигуры
void FigureOut<Figure *f>(FILE* file);

//------------------------------------------------------------------------------
// Инициализация специализированного контейнера
void FigureContainerInit(struct Figure.cont *c) {
  ContainerInit(&(c->@));
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void FigureContainerClear(struct Figure.cont *c) {
  ContainerClear(&(c->@));
}

//------------------------------------------------------------------------------
// Добавление в контейнер указанной фигуры
void FigureContainerAppend(struct Figure.cont* c, struct Figure * figure) {
  ContainerAppend(&(c->@), figure);
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера-фигуры из указанного потока
void FigureIn<Figure.cont *c>(FILE* ifst) {
  ContainerIn(&(c->@), ifst);
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера-фигуры в указанный поток
void FigureOut<Figure.cont *c>(FILE* ofst) {
  // ContainerOut(&(c->@), ofst);
  fprintf(ofst, "Figure Container contains %d elements.\n", c->@len);
  for(int i = 0; i < c->@len; i++) {
    fprintf(ofst, "%d: " , i);
    FigureOut<c->@cont[i]>(ofst);
  }
}

