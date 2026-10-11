// main.c
#include <stdio.h>
#include "vector.h"

typedef struct Int {int x;} Int;

// Добавление специализации в виде целочисленных значений
// Value + <int;>;
Value + <i: Int;>;

// Обработчик специализации для целочисленных значений
void OutValue<Value.i* value>(FILE* file) {
  fprintf(file, "value = %d", value->@x);
}
// void OutValue<Value<int>* value>(FILE* file) {
//   fprintf(file, "value = %d", value->@);
// }

int main(void) {
  //----------------------------------------------------------------------------
  // Тестирование векторов с разными специализациями элементов
  //----------------------------------------------------------------------------

  return 0;
} // end main

