// main.c
#include <stdio.h>
#include "array.h"

typedef struct Int {int x;} Int;

// Добавление специализации в виде целочисленных значений
// Value + <int;>;
Value + <Int;>;

// Обработчик специализации для целочисленных значений
void OutValue<Value.Int* value>(FILE* file) {
  fprintf(file, "value = %d", value->@x);
}
// void OutValue<Value<int>* value>(FILE* file) {
//   fprintf(file, "value = %d", value->@);
// }

int main(void) {
  // Формирование пустого списка
  Array  array;
  InitArray(&array);
  OutArrayValues(stdout, &array);
  printf("\n");

  // Создание нового значения
  struct Value.Int v1;
  v1.@x = 10;
  // OutValue<&v1>(stdout);

  // Добавление элемента в список и вывод списка
  // AppendArray(&array, &v1);
  // OutArrayValues(stdout, &array);

  // Динамическое создание нового элемента
  struct Value.Int* pvInt;
  pvInt = create_spec(Value.Int);
  pvInt->@x = 20;
  struct Value* pv = pvInt;
  // OutValue<pv>(stdout);

  // Добавление элемента в список и вывод списка
  AppendArray(&array, pv);
  OutArrayValues(stdout, &array);
  printf("\n");

  // Динамическое создание нового элемента
  pvInt = create_spec(Value.Int);
  pvInt->@x = 30;
  // OutValue<pvInt>(stdout);

  // Добавление элемента в список и вывод списка
  AppendArray(&array, pvInt);
  OutArrayValues(stdout, &array);
  printf("\n");

  // Динамическое создание нового элемента
  pvInt = create_spec(Value.Int);
  pvInt->@x = 40;
  // OutValue<pvInt>(stdout);

  // Добавление элемента в список и вывод списка
  AppendArray(&array, pvInt);
  OutArrayValues(stdout, &array);
  printf("\n");

  // Динамическое создание нового элемента
  pvInt = create_spec(Value.Int);
  pvInt->@x = v1.@x;
  // OutValue<pvInt>(stdout);

  // Добавление элемента в список и вывод списка
  AppendArray(&array, pvInt);
  OutArrayValues(stdout, &array);
  printf("\n");

  // Удаление элемента из головы списка
  pv = DeleteTailOfArray(&array);
  // OutValue<pv>(stdout);
  OutArrayValues(stdout, &array);
  printf("\n");

  // Очистка списка
  EmptyArray(&array);
  OutArrayValues(stdout, &array);
  printf("\n");

  return 0;
} // end main

