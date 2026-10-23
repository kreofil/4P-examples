// pp-vector-test.c - тестирование обобщенного вектора ppVector
#include <stdio.h>
#include "ppvector.h"

//==============================================================================
// Все, что сопровождает формируемую специализацию вектора
//==============================================================================

ppVector+<int;>; // Целочисленная специализация вектора

//------------------------------------------------------------------------------
// Обработчик специализации, обеспечивающий вывод целочисленного элемента
void ppVector_element_print<ppVector.int* v>(FILE* f) {//, int index) {
  // ppVector_index((ppVector*)v, index);
  fprintf(f, "%d\n", v->@);
}

//==============================================================================
// Тестовая функция
//==============================================================================

// Внешний вектор
struct ppVector.int v_int_ext;

//------------------------------------------------------------------------------
int main(void) {
  v_int_ext.foundation_size = sizeof(v_int_ext.@);
  v_int_ext.foundation_addr = &(v_int_ext.@);
  v_int_ext.size = 0;
  v_int_ext.capacity = 0;
  v_int_ext.vec_memory = NULL;

  // struct ppVector.int v_int = {sizeof(v_int.@),&(v_int.@)};
  // ppVector_VAR(int, v_int)
  struct ppVector.int v_int;
  v_int.foundation_size = sizeof(v_int.@);
  v_int.foundation_addr = &(v_int.@);
  v_int.size = 0;
  v_int.capacity = 0;
  v_int.vec_memory = NULL;

  // ppVector_reserve((ppVector*)&v_int, 10);

  // Занесение значения в буфер вектора
  for(int i = 0; i < 10; ++i) {
    ppVector_PUSH_BACK(v_int, i+1)
  }
  printf("v_int:\n");
  ppVector_print(stdout, (ppVector*)&v_int);

  for(int i = 20; i > 15; --i) {
    ppVector_PUSH_BACK(v_int_ext, i)
  }
  printf("v_int_ext:\n");
  ppVector_print(stdout, (ppVector*)&v_int_ext);

  // Тестовый вывод элементов вектора
  ppVector_print(stdout, (ppVector*)&v_int);

  // Получение и вывод первого элемента вектора
  ppVector_front((ppVector*)&v_int);
  printf("front element = %d\n", v_int.@);

  // Получение и вывод последнего элемента вектора
  ppVector_back((ppVector*)&v_int);
  printf("back element = %d\n", v_int.@);

  // Получение указателя на начало динамического массива с данным
  // и вывод элементов этого массива
  // int* vec_ptr = (int*)ppVector_data((ppVector*)&v_int);
  // for(int i = 0; i < ppVector_size((ppVector*)&v_int); ++i) {
    // printf("element[%d] = %d\n", i, *(vec_ptr + i));
  // }

  // Получение и вывод первого элемента вектора через макрос
  // int front_value; ppVector_GET_FRONT_VAL(front_value, v_int)
  // printf("FRONT element = %d\n", front_value);

  // Получение и вывод первого элемента вектора через макрос
  // int back_value; ppVector_GET_BACK_VAL(back_value, v_int)
  // printf("BACK element = %d\n", back_value);

  // Тестирование вставки элемента в вектор
  v_int.@ = 666;
  ppVector_insert_index((ppVector*)&v_int, 9);
  ppVector_insert_index((ppVector*)&v_int, 2);
  ppVector_insert_index((ppVector*)&v_int, 12);
  ppVector_insert_index((ppVector*)&v_int, 1);
  v_int.@ = 777;
  ppVector_insert_index((ppVector*)&v_int, 14);
  ppVector_insert_index((ppVector*)&v_int, 8);
  ppVector_insert_index((ppVector*)&v_int, 5);
  // for(int i = 0; i < ppVector_size((ppVector*)&v_int); ++i) {
  //   printf("element[%d] = %d\n", i, *(vec_ptr + i));
  // }
  // Тестовый вывод элементов вектора
  // ppVector_print(stdout, (ppVector*)&v_int);
  ppVector_pop_back((ppVector*)&v_int);
  // printf("value = %d; size = %u; capacity = %u\n",
  //        v_int.@,
  //        ppVector_size((ppVector*)&v_int),
  //        ppVector_capacity((ppVector*)&v_int)
  // );

  // Удаление последнего элемента вектора
  ppVector_pop_back((ppVector*)&v_int);
  printf("back element = %d\n", v_int.@);
  // Тестовый вывод элементов вектора
  // ppVector_print(stdout, (ppVector*)&v_int);
  // printf("value = %d; size = %u; capacity = %u\n",
  //        v_int.@,
  //        ppVector_size((ppVector*)&v_int),
  //        ppVector_capacity((ppVector*)&v_int)
  // );

  v_int.@ = 888;
  ppVector_insert_index((ppVector*)&v_int, ppVector_size((ppVector*)&v_int));
  // Тестовый вывод элементов вектора
  ppVector_print(stdout, (ppVector*)&v_int);
  printf("value = %d; size = %u; capacity = %u\n",
         v_int.@,
         ppVector_size((ppVector*)&v_int),
         ppVector_capacity((ppVector*)&v_int)
  );

  // ppVector_erase((ppVector*)&v_int, 3, ppVector_size((ppVector*)&v_int));
  ppVector_erase((ppVector*)&v_int, 1, 1);
  ppVector_erase((ppVector*)&v_int, 2, 2);
  ppVector_erase((ppVector*)&v_int, 3, 3);
  ppVector_erase((ppVector*)&v_int, 6, 6);
  ppVector_erase((ppVector*)&v_int, 9, 9);
  ppVector_erase((ppVector*)&v_int, 10, 10);
  ppVector_print(stdout, (ppVector*)&v_int);
  printf("value = %d; size = %u; capacity = %u\n",
         v_int.@,
         ppVector_size((ppVector*)&v_int),
         ppVector_capacity((ppVector*)&v_int)
  );

  ppVector_resize((ppVector*)&v_int, 35);
  ppVector_print(stdout, (ppVector*)&v_int);
  printf("value = %d; size = %u; capacity = %u\n",
         v_int.@,
         ppVector_size((ppVector*)&v_int),
         ppVector_capacity((ppVector*)&v_int)
  );
  ppVector_erase((ppVector*)&v_int, 10, ppVector_size((ppVector*)&v_int));
  // ppVector_clear((ppVector*)&v_int);
  ppVector_print(stdout, (ppVector*)&v_int);
  printf("value = %d; size = %u; capacity = %u\n",
         v_int.@,
         ppVector_size((ppVector*)&v_int),
         ppVector_capacity((ppVector*)&v_int)
  );

  ppVector_shrink_to_fit((ppVector*)&v_int);
  ppVector_print(stdout, (ppVector*)&v_int);
  printf("value = %d; size = %u; capacity = %u\n",
         v_int.@,
         ppVector_size((ppVector*)&v_int),
         ppVector_capacity((ppVector*)&v_int)
  );

  ppVector_swap((ppVector*)&v_int, (ppVector*)&v_int_ext);
  printf("v_int_ext:\n");
  ppVector_print(stdout, (ppVector*)&v_int_ext);
  printf("value = %d; size = %u; capacity = %u\n",
         v_int_ext.@,
         ppVector_size((ppVector*)&v_int_ext),
         ppVector_capacity((ppVector*)&v_int_ext)
  );
  printf("v_int:\n");
  ppVector_print(stdout, (ppVector*)&v_int);
  printf("value = %d; size = %u; capacity = %u\n",
         v_int.@,
         ppVector_size((ppVector*)&v_int),
         ppVector_capacity((ppVector*)&v_int)
  );

  ppVector_move((ppVector*)&v_int, (ppVector*)&v_int_ext);
  printf("v_int_ext:\n");
  ppVector_print(stdout, (ppVector*)&v_int_ext);
  printf("value = %d; size = %u; capacity = %u\n",
         v_int_ext.@,
         ppVector_size((ppVector*)&v_int_ext),
         ppVector_capacity((ppVector*)&v_int_ext)
  );
  printf("v_int:\n");
  ppVector_print(stdout, (ppVector*)&v_int);
  printf("value = %d; size = %u; capacity = %u\n",
         v_int.@,
         ppVector_size((ppVector*)&v_int),
         ppVector_capacity((ppVector*)&v_int)
  );

  ppVector_reserve((ppVector*)&v_int, 16);
  ppVector_copy((ppVector*)&v_int_ext, (ppVector*)&v_int);
  printf("v_int_ext:\n");
  ppVector_print(stdout, (ppVector*)&v_int_ext);
  printf("value = %d; size = %u; capacity = %u\n",
         v_int_ext.@,
         ppVector_size((ppVector*)&v_int_ext),
         ppVector_capacity((ppVector*)&v_int_ext)
  );
  printf("v_int:\n");
  ppVector_print(stdout, (ppVector*)&v_int);
  printf("value = %d; size = %u; capacity = %u\n",
         v_int.@,
         ppVector_size((ppVector*)&v_int),
         ppVector_capacity((ppVector*)&v_int)
  );

  // ppVector_destroy((ppVector*)&v_int_ext);
  // ppVector_print(stdout, (ppVector*)&v_int);
  // printf("value = %d; size = %u; capacity = %u\n",
  //        v_int.@,
  //        ppVector_size((ppVector*)&v_int),
  //        ppVector_capacity((ppVector*)&v_int)
  // );

  return 0;
} // end main

