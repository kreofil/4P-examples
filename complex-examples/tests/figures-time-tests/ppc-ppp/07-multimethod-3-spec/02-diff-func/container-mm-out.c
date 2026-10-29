//==============================================================================
// container-mm-out.c - содержит функцию
// вывода всех пар, контейнера, применяя к каждой мультиметод
//==============================================================================

#include <stdio.h>
#include "container.h"

//------------------------------------------------------------------------------
// Сигнатура мультиметода
void Multimethod<Figure* f1, Figure* f2>(FILE* ofst);
// Сигнатура мультиметода для периметров
int MultimethodDiffFunc<Figure* f1, Figure* f2>();

//------------------------------------------------------------------------------
// Вывод пар элементов контейнера в указанный поток через вызов мультиметода
void ContainerMultimethodOut(Container *c, FILE* ofst) {
  fprintf(ofst, "Container contains %d elements.\n", c->len);
  for(int i = 0; i < c->len; i++) {
    for(int j = 0; j < c->len; j++) {
      fprintf(ofst, "[%d,%d]: " , i, j);
      Multimethod<c->cont[i], c->cont[j]>(ofst);
    }
  }
}

//------------------------------------------------------------------------------
// Вычисление периметра в качестве дополнительной временной нагрузки
// Вместо вывода.
int ContainerMultimethodDiffFunc(Container *c) {
  int p = 0;
  for(int i = 0; i < c->len; i++) {
    for(int j = 0; j < c->len; j++) {
      p += MultimethodDiffFunc<c->cont[i], c->cont[j]>();
    }
  }
  return p;
}
