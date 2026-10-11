//==============================================================================
// rectangle-container.c - содержит функции контейнера прямоугольников
//==============================================================================

#include <stdlib.h>
#include <stdio.h>
#include "rectangle-container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void RectangleContainerInit(RectangleContainer *c) {
  c->len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void RectangleContainerClear(RectangleContainer *c) {
  for(int i = 0; i < c->len; i++) {
    free(c->cont[i]);
  }
  RectangleContainerInit(c);
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void RectangleContainerIn(RectangleContainer* c, Rectangle * rectangle) {
  if(c->len < rectangle_max_len) {
    c->cont[c->len++] = rectangle;
  }
}

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void RectangleOut<Rectangle * r>(FILE* ofst);

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void RectangleContainerOut(RectangleContainer *c, FILE* ofst) {
  fprintf(ofst, "Container contains %d elements.\n", c->len);
  for(int i = 0; i < c->len; i++) {
    fprintf(ofst, "%d: " , i);
    RectangleOut<c->cont[i]>(ofst);
  }
}
