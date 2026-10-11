// pp-vector-sum.c - тестирование ppVector
#include <stdlib.h>
#include <stdio.h>
#include "ppvector.h"

//==============================================================================
// Все, что сопровождает формируемую специализацию вектора
//==============================================================================

ppVector+<double;>; // Cпециализация вектора double

//------------------------------------------------------------------------------
// Обработчик специализации, обеспечивающий вывод целочисленного элемента
void ppVector_element_print<ppVector.double* v>(FILE* f) {//, double index) {
  fprintf(f, "%f\n", v->@);
}

double ppVecor_sum(struct ppVector.double* pv_double) {
  // Суммирование элементов вектора
  double sum = 0;
  for(uint32_t i = 0; i < ppVector_size((ppVector*)pv_double); ++i) {
    ppVector_index((ppVector*)pv_double, i);
    sum += pv_double->@;
  }
  return sum;
}

//------------------------------------------------------------------------------
// Функция, используемая дла сравнения целочисленных элементов
static int cmp_double(const void *a, const void *b) {
  double a1 = *(const double*)a;
  double a2 = *(const double*)b;
  // if (a1 < a2) return -1;
  // if (a1 > a2) return 1;
  // return 0;
  return (int)(a1 - a2);
}

//------------------------------------------------------------------------------
// Обработчик специализации, осуществляющий обработку целочисленного вектора
// void qsort(size_t n, size_t size;
//             void base[n * size], size_t n, size_t size,
//             typeof(int (const void [size], const void [size]))
//             *compar);
void ppVector_sort<ppVector.double* v>()  {
  // Получение указателя на массив целых чисел
  void* v_ptr = ppVector_data((ppVector*)v);
  qsort(v_ptr, ppVector_size((ppVector*)v), sizeof(double), cmp_double);
}

//==============================================================================
// Тестовая функция
//==============================================================================

//------------------------------------------------------------------------------
int main(void) {
  // struct ppVector.double v_int = {sizeof(v_double.@),&(v_double.@)};
  ppVector_VAR(double, v_double)
  // ppVector_reserve((ppVector*)&v_double, 10);
  // Занесение значения в буфер вектора
  for(int i = 10; i > 0; --i) {
    ppVector_PUSH_BACK(v_double, i)
  }
  // Тестовый вывод элементов вектора
  ppVector_print(stdout, (ppVector*)&v_double);

  printf("sum = %f\n", ppVecor_sum(&v_double));

  // Вызов функции сортировки
  ppVector_sort<(ppVector*)&v_double>();
  // Тестовый вывод отсортированного вектора
  ppVector_print(stdout, (ppVector*)&v_double);


  ppVector_destroy((ppVector*)&v_double);
  printf("value = %f; size = %u; capacity = %u\n",
         v_double.@,
         ppVector_size((ppVector*)&v_double),
         ppVector_capacity((ppVector*)&v_double)
  );

  return 0;
} // end main

