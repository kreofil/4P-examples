#include <stdlib.h>
#include <stdio.h>
#include "ppvector.h"

//==============================================================================
// Все, что сопровождает формируемую специализацию вектора
//==============================================================================

ppVector+<int;>; // Целочисленная специализация вектора

//------------------------------------------------------------------------------
// Обработчик специализации, обеспечивающий вывод целочисленного элемента
void ppVector_element_print<ppVector.int* v>(FILE* f) {//, int index) {
  fprintf(f, "%d\n", v->@);
}

//------------------------------------------------------------------------------
// Суммирование элементов целочисленного вектора
int ppVecor_sum(struct ppVector.int* pv_int) {
  // Суммирование элементов вектора
  int sum = 0;
  for(uint32_t i = 0; i < ppVector_size((ppVector*)pv_int); ++i) {
    ppVector_index((ppVector*)pv_int, i);
    sum += pv_int->@;
  }
  return sum;
}

//------------------------------------------------------------------------------
// Функция, используемая для сравнения целочисленных элементов
int cmp_int(const void *a, const void *b) {
  int a1 = *(const int*)a;
  int a2 = *(const int*)b;
  // if (a1 < a2) return -1;
  // if (a1 > a2) return 1;
  // return 0;
  return a1-a2;
}

//------------------------------------------------------------------------------
// Обработчик специализации, осуществляющий обработку целочисленного вектора
// void qsort(size_t n, size_t size;
//             void base[n * size], size_t n, size_t size,
//             typeof(int (const void [size], const void [size]))
//             *compar);
void ppVector_sort<ppVector.int* v>()  {
  // Получение указателя на массив целых чисел
  void* v_ptr = ppVector_data((ppVector*)v);
  qsort(v_ptr, ppVector_size((ppVector*)v), sizeof(int), cmp_int);
}

//==============================================================================
// Тестовая функция
//==============================================================================

//------------------------------------------------------------------------------
int main(void) {
  // struct ppVector.int v_int = {sizeof(v_int.@),&(v_int.@)};
  ppVector_VAR(int, v_int)
  // ppVector_reserve((ppVector*)&v_int, 10);
  // Занесение значения в буфер вектора
  for(int i = 10; i > 0; --i) {
    ppVector_PUSH_BACK(v_int, i)
  }
  // Тестовый вывод элементов вектора
  ppVector_print(stdout, (ppVector*)&v_int);

  printf("sum = %d\n", ppVecor_sum(&v_int));

  // Вызов функции сортировки
  ppVector_sort<(ppVector*)&v_int>();
  // Тестовый вывод отсортированного вектора
  ppVector_print(stdout, (ppVector*)&v_int);

  ppVector_destroy((ppVector*)&v_int);
  printf("value = %d; size = %u; capacity = %u\n",
         v_int.@,
         ppVector_size((ppVector*)&v_int),
         ppVector_capacity((ppVector*)&v_int)
  );

  return 0;
} // end main

