// test-pp-list-common.c - тестирование обобщенного списка ppList
#include <stdio.h>
#include "pplist.h"

//==============================================================================
// Все, что сопровождает формируемую специализацию списка
//==============================================================================

ppList+<int;>; // Целочисленная специализация списка

//------------------------------------------------------------------------------
// Обработчик специализации, обеспечивающий вывод целочисленного элемента
// Выводится текущий элемент списка с предварительным переводом
// в область специализации
void ppList_element_print<ppList.int* l>(FILE* f) {//, int index) {
  // ppList_index((ppList*)l, index);
  fprintf(f, "%d\n", l->@);
}

//==============================================================================
// Тестовая функция
//==============================================================================

// Внешний список
struct ppList.int l_int_ext;

//------------------------------------------------------------------------------
int main(void) {
  l_int_ext.foundation_size = sizeof(l_int_ext.@);
  l_int_ext.foundation_addr = &(l_int_ext.@);
  l_int_ext.size = 0;
  l_int_ext.head = NULL;
  l_int_ext.tail = NULL;
  l_int_ext.current = NULL;

  // Вывод параметров настройки l_int_ext
  printf("l_int_ext.(foundation_size = %u, foundation_addr = %p, size = %u)\n",
         l_int_ext.foundation_size,
         l_int_ext.foundation_addr,
         l_int_ext.size);

  ppList_VAR(int, l_int)
  printf("Empty l_int:\n");
  ppList_print(stdout, (ppList*)&l_int);

  // Вывод параметров настройки l_int
  // printf("l_int.(foundation_size = %u, foundation_addr = %p, size = %u)\n",
         // l_int.foundation_size, l_int.foundation_addr, l_int.size);

  ppList_PUSH_BACK(l_int_ext, 666);
  ppList_PUSH_BACK(l_int_ext, 777);
  ppList_PUSH_BACK(l_int_ext, 888);
  ppList_PUSH_BACK(l_int_ext, 999);
  ppList_print(stdout, (ppList*)&l_int_ext);

  printf("Empty l_int_ext after clean:\n");
  ppList_clear((ppList*)&l_int_ext);
  ppList_print(stdout, (ppList*)&l_int_ext);

  // Занесение значений в список
  for(int i = 0; i < 10; ++i) {
    ppList_PUSH_BACK(l_int, i+1)
  }
  printf("l_int:\n");
  ppList_print(stdout, (ppList*)&l_int);

  // printf("Empty l_int after clean:\n");
  // ppList_clear((ppList*)&l_int);
  // ppList_print(stdout, (ppList*)&l_int);

  for(int i = 20; i > 15; --i) {
     ppList_PUSH_BACK(l_int_ext, i)
  }
  printf("l_int_ext:\n");
  ppList_print(stdout, (ppList*)&l_int_ext);

  // Получение и вывод первого элемента списка
  ppList_front((ppList*)&l_int);
  printf("front element = %d\n", l_int.@);

  // Получение и вывод последнего элемента списка
  ppList_back((ppList*)&l_int);
  printf("back element = %d\n", l_int.@);

  // Получение и вывод первого элемента списка через макрос
  int front_value; ppList_GET_FRONT_VAL(front_value, l_int)
  printf("FRONT element = %d\n", front_value);

  // Получение и вывод первого элемента списка через макрос
  int back_value; ppList_GET_BACK_VAL(back_value, l_int)
  printf("BACK element = %d\n", back_value);

  // Получение и вывод текущего элемента списка через макрос
  ppList_prev_current((ppList*)&l_int);
  ppList_prev_current((ppList*)&l_int);
  ppList_prev_current((ppList*)&l_int);
  int current_value; ppList_GET_CURRENT_VAL(current_value, l_int)
  printf("CURRENT element = %d\n", current_value);

  l_int.@ = 111;
  ppList_replace_current((ppList*)&l_int);
  l_int.@ = 222;
  ppList_push_after_current((ppList*)&l_int);
  ppList_front_current((ppList*)&l_int);
  l_int.@ = 444;
  ppList_push_before_current((ppList*)&l_int);
  l_int.@ = 666;
  ppList_push_after_current((ppList*)&l_int);
  ppList_back_current((ppList*)&l_int);
  l_int.@ = 333;
  ppList_push_after_current((ppList*)&l_int);
  l_int.@ = 555;
  ppList_back_current((ppList*)&l_int);
  ppList_push_before_current((ppList*)&l_int);
  ppList_front_current((ppList*)&l_int);
  ppList_push_after_current((ppList*)&l_int);

  printf("l_int:\n");
  ppList_print(stdout, (ppList*)&l_int);
  // printf("size = %u\n", l_int.size);

  // Удаление последнего элемента списка
  ppList_pop_back((ppList*)&l_int);
  printf("back element = %d\n", l_int.@);
  // Тестовый вывод элементов списка
  ppList_print(stdout, (ppList*)&l_int);

  // Удаление первого элемента списка
  ppList_pop_front((ppList*)&l_int);
  printf("front element = %d\n", l_int.@);
  // Тестовый вывод элементов списка
  ppList_print(stdout, (ppList*)&l_int);

  // Сдвиг на 2 шага и удаление текущего элемента
  ppList_front_current((ppList*)&l_int);
  ppList_next_current((ppList*)&l_int);
  ppList_next_current((ppList*)&l_int);
  ppList_pop_current((ppList*)&l_int);
  // Тестовый вывод элементов списка
  ppList_print(stdout, (ppList*)&l_int);

  // ppList_swap((ppList*)&v_int, (ppList*)&v_int_ext);
  // printf("v_int_ext:\n");
  // ppList_print(stdout, (ppList*)&v_int_ext);
  // printf("value = %d; size = %u; capacity = %u\n",
  //        v_int_ext.@,
  //        ppList_size((ppList*)&v_int_ext),
  //        ppList_capacity((ppList*)&v_int_ext)
  // );
  // printf("v_int:\n");
  // ppList_print(stdout, (ppList*)&v_int);
  // printf("value = %d; size = %u; capacity = %u\n",
  //        v_int.@,
  //        ppList_size((ppList*)&v_int),
  //        ppList_capacity((ppList*)&v_int)
  // );
  //
  // ppList_move((ppList*)&v_int, (ppList*)&v_int_ext);
  // printf("v_int_ext:\n");
  // ppList_print(stdout, (ppList*)&v_int_ext);
  // printf("value = %d; size = %u; capacity = %u\n",
  //        v_int_ext.@,
  //        ppList_size((ppList*)&v_int_ext),
  //        ppList_capacity((ppList*)&v_int_ext)
  // );
  // printf("v_int:\n");
  // ppList_print(stdout, (ppList*)&v_int);
  // printf("value = %d; size = %u; capacity = %u\n",
  //        v_int.@,
  //        ppList_size((ppList*)&v_int),
  //        ppList_capacity((ppList*)&v_int)
  // );
  //
  // ppList_reserve((ppList*)&v_int, 16);
  // ppList_copy((ppList*)&v_int_ext, (ppList*)&v_int);
  // printf("v_int_ext:\n");
  // ppList_print(stdout, (ppList*)&v_int_ext);
  // printf("value = %d; size = %u; capacity = %u\n",
  //        v_int_ext.@,
  //        ppList_size((ppList*)&v_int_ext),
  //        ppList_capacity((ppList*)&v_int_ext)
  // );
  // printf("v_int:\n");
  // ppList_print(stdout, (ppList*)&v_int);
  // printf("value = %d; size = %u; capacity = %u\n",
  //        v_int.@,
  //        ppList_size((ppList*)&v_int),
  //        ppList_capacity((ppList*)&v_int)
  // );

  // ppList_destroy((ppList*)&v_int_ext);
  // ppList_print(stdout, (ppList*)&v_int);
  // printf("value = %d; size = %u; capacity = %u\n",
  //        v_int.@,
  //        ppList_size((ppList*)&v_int),
  //        ppList_capacity((ppList*)&v_int)
  // );

  return 0;
} // end main

