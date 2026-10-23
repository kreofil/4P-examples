//==============================================================================
// triangle-container-constr.c - содержит функции контейнера треугольников
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "triangle-container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void TriangleContainerInit(TriangleContainer *c) {
  c->len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void TriangleContainerClear(TriangleContainer *c) {
  for(int i = 0; i < c->len; i++) {
    free(c->cont[i]);
  }
  TriangleContainerInit(c);
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void TriangleContainerIn(TriangleContainer* c, Triangle* triangle) {
  if(c->len < triangle_max_len) {
    c->cont[c->len++] = triangle;
  }
}

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void TriangleOut<Triangle * r>(FILE* ofst);

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void TriangleContainerOut(TriangleContainer *c, FILE* ofst) {
  fprintf(ofst, "Container contains %d elements.\n", c->len);
  for(int i = 0; i < c->len; i++) {
    fprintf(ofst, "%d: " , i);
    TriangleOut<c->cont[i]>(ofst);
  }
}
