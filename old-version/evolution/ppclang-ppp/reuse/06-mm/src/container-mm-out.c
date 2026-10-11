//==============================================================================
// container-mm-out.c - содержит функцию
// вывода всех пар, контейнера, применяя к каждой мультиметод
//==============================================================================

#include <stdio.h>
#include "container.h"

//------------------------------------------------------------------------------
// Сигнатура мультиметода
void Multimethod<Figure* f1, Figure* f2>(FILE* ofst);

//------------------------------------------------------------------------------
// Вывод пар элементов контейнера в указанный поток через вызов мультиметода
void ContainerMultimethodOut(struct ppVector.fig* c, FILE* ofst) {
  uint32_t len = ppVector_size((ppVector*)c);
  fprintf(ofst, "Container contains %d elements.\n", len);
  for(uint32_t i = 0; i < len; i++) {
    for(uint32_t j = 0; j < len; j++) {
      fprintf(ofst, "[%u,%u]: " , i, j);
      struct Figure* f1; ppVector_GET_VAL_INDEX(f1, (*c), i)
      struct Figure* f2; ppVector_GET_VAL_INDEX(f2, (*c), j)
      Multimethod<f1, f2>(ofst);
    }
  }
}
