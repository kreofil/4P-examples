// pplist.c - определения функций, реализующих операции над обобщенным списком

// #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pplist.h"

//==============================================================================
// Реализация интерфейса обобщенного списка, используемого при программировании
//==============================================================================

//------------------------------------------------------------------------------
// Начальная инициализация списка
void ppList_init(ppList* l) {
  l->size = 0;
  l->head = NULL;
  l->tail = NULL;
  l->current = NULL;
}

//------------------------------------------------------------------------------
// Определение текущего размера списка
uint32_t ppList_size(ppList* l) {
  return l->size;
}

//------------------------------------------------------------------------------
// Установка нового значения в существующий текущий элемент списка
// из значения, находящегося в специализации
void ppList_replace_current(ppList* l) {
  // Перенос значения из специализации в текущий узел
  memcpy(l->current->data, l->foundation_addr, l->foundation_size);
}

//------------------------------------------------------------------------------
// Занесение в хвост списка значения, размещенного в специализированной переменной.
// Предварительно значение должно быть занесено в специализацию
void ppList_push_back(ppList* l) {
  // Создание элемента списка под данные размером в основу специализации
  ppListNode* node = malloc(sizeof(ppListNode) + l->foundation_size);
  if(node == NULL) {
    printf("Incorrect node creation in ppList_push_back function\n");
    exit(-1);
  }
  // Перенос значения из специализации в узел
  memcpy(node->data, l->foundation_addr, l->foundation_size);
  // Прикрепление созданного узла к концу двунаправленного линейного списка
  if(l->head==NULL) { // Занесение в пустой список
    l->head = node;
    l->tail = node;
    // Формирование пустых концов
    node->next = node->prev = NULL;
  } else { // В противном случае формируемый элемент заносится в хвост списка
    node->next = NULL;
    node->prev = l->tail;
    l->tail->next = node;
    l->tail = node;
  }
  l->current = node;    // добавляемый узел становится текущим
  ++(l->size);          // на один элемент стало больше
}

//------------------------------------------------------------------------------
// Вставка нового узла после текущего
void ppList_push_after_current(ppList* l) {
  if(l->current == NULL) {
    printf("Incorrect current value in ppList_push_after_current function\n");
    exit(-1);
  }
  // Создание элемента списка под данные размером в основу специализации
  ppListNode* node = malloc(sizeof(ppListNode) + l->foundation_size);
  if(node == NULL) {
    printf("Incorrect node creation in ppList_push_after_current function\n");
    exit(-1);
  }
  // Перенос значения из специализации в узел
  memcpy(node->data, l->foundation_addr, l->foundation_size);
  // Прикрепление созданного узла после текущего
  node->next = l->current->next;
  node->prev = l->current;
  l->current->next = node;
  if(l->tail == l->current) { // Для последнего элемента нужно перемещение
    l->tail = node;
  } else { // связь следующего узла с создаваемым
    node->next->prev = node;
  }
  l->current = node;    // добавляемый узел становится текущим
  ++(l->size);          // на один элемент стало больше
}

//------------------------------------------------------------------------------
// Вставка нового узла перед текущим
void ppList_push_before_current(ppList* l) {
  if(l->current == NULL) {
    printf("Incorrect current value in ppList_push_before_current function\n");
    exit(-1);
  }
  // Создание элемента списка под данные размером в основу специализации
  ppListNode* node = malloc(sizeof(ppListNode) + l->foundation_size);
  if(node == NULL) {
    printf("Incorrect node creation in ppList_push_before_current function\n");
    exit(-1);
  }
  // Перенос значения из специализации в узел
  memcpy(node->data, l->foundation_addr, l->foundation_size);
  // Прикрепление созданного узла перед текущим
  node->prev = l->current->prev;
  node->next = l->current;
  l->current->prev = node;
  if(l->head == l->current) { // Для последнего элемента нужно перемещение
    l->head = node;
  } else { // связь предыдущего узла с создаваемым
    node->prev->next = node;
  }
  l->current = node;    // добавляемый узел становится текущим
  ++(l->size);          // на один элемент стало больше
}

//------------------------------------------------------------------------------
// Смещение указателя текущего элемента на следующий элемент списка
_Bool ppList_next_current(ppList* l) {
  // Если осуществляется вызов для пустого указателя, то ошибка
  // Поэтому перед вызовом стоит делать проверку на последний элемент.
  if(l->current == l->tail) { // Шаг приводит к ошибки и не делается
    return 0;
  }
  l->current = l->current->next;
  return 1; // Шаг успешно сделан
}

//------------------------------------------------------------------------------
// Смещение указателя текущего элемента на предыдущий элемент списка
_Bool ppList_prev_current(ppList* l) {
  // Если осуществляется вызов для пустого указателя, то ошибка
  // Поэтому перед вызовом стоит делать проверку на первый элемент.
  if(l->current == l->head) { // Шаг приводит к ошибки и не делается
    return 0;
  }
  l->current = l->current->prev;
  return 1; // Шаг успешно сделан
}

//------------------------------------------------------------------------------
// Установка первого узла текущим
void ppList_front_current(ppList* l) {
  l->current = l->head;
}

//------------------------------------------------------------------------------
// Установка последнего узла текущим
void ppList_back_current(ppList* l) {
  l->current = l->tail;
}

//------------------------------------------------------------------------------
// Проверка текущего на первый элемент списка
_Bool ppList_is_head(ppList* l) {
  return l->current == l->head;
}

//------------------------------------------------------------------------------
// Проверка текущего на последний элемент списка
_Bool ppList_is_tail(ppList* l) {
  return l->current == l->tail;
}

//------------------------------------------------------------------------------
// Фиксация в основе специализации значения первого элемента списка
void ppList_front(ppList* l) {
  memcpy(l->foundation_addr, l->head->data, l->foundation_size);
}

//------------------------------------------------------------------------------
// Фиксация в основе специализации значения последнего элемента списка
void ppList_back(ppList* l) {
  memcpy(l->foundation_addr, l->tail->data, l->foundation_size);
}

//------------------------------------------------------------------------------
// Фиксация в основе специализации значения текущего элемента списка
void ppList_current(ppList* l) {
  memcpy(l->foundation_addr, l->current->data, l->foundation_size);
}

//------------------------------------------------------------------------------
// Удаление последнего элемента списка
void ppList_pop_back(ppList* l) {
  if(l->tail == NULL) {
    return;
  }
  if(l->size == 1) {
    l->head = NULL;
  }
  l->current = l->tail->prev;
  free(l->tail);
  l->tail = l->current;
  --(l->size);
}

//------------------------------------------------------------------------------
// Удаление первого элемента списка
void ppList_pop_front(ppList* l) {
  if(l->head == NULL) {
    return;
  }
  if(l->size == 1) {
    l->tail = NULL;
  }
  l->current = l->head->next;
  free(l->head);
  l->head = l->current;
  --(l->size);
}

//------------------------------------------------------------------------------
// Удаление текущего элемента списка
void ppList_pop_current(ppList* l) {
  // if(l->current == NULL) {
  //   return;
  // }
  if(l->current == l->head) {
    ppList_pop_front(l);
  } else if(l->current == l->tail) {
    ppList_pop_back(l);
  } else { // где-то в середине
    l->current->prev->next = l->current->next;
    l->current->next->prev = l->current->prev;
    free(l->current);
    l->current = l->head;
    --(l->size);
  }
}

//------------------------------------------------------------------------------
// Очистка списка от всех узлов
void ppList_clear(ppList* l) {
  // l->current = l->tail;
  while(l->size != 0) {
    ppList_pop_back(l);
  }
}

//------------------------------------------------------------------------------
// Обмен содержимым между двумя однотипными списками
void ppList_swap(ppList* l1, ppList* l2) {
  // // Проверка однотипности списоков
  // if(spec_index_cmp(v1, v2) < 1) {
  //   // Или обобщение или специализации не совпадают
  //   printf("Incompatible specializations in swap function\n");
  //   exit(-1);
  // }
  // // Или осуществление обмена
  // uint32_t tmp = v1->size; v1->size = v2->size; v2->size = tmp;
  // tmp = v1->capacity; v1->capacity = v2->capacity; v2->capacity = tmp;
  // void* tmp_memory_ptr = v1->vec_memory;
  // v1->vec_memory = v2->vec_memory;
  // v2->vec_memory = tmp_memory_ptr;
}

//------------------------------------------------------------------------------
// Пересылка данных из одного списка в другой. Списки однотипные
void ppList_move(ppList* dest, ppList* src) {
  // // Проверка однотипности списоков
  // if(spec_index_cmp(dest, src) < 1) {
  //   // Или обобщение или специализации не совпадают
  //   printf("Incompatible specializations in move function\n");
  //   exit(-1);
  // }
  // // Или осуществление пересылки
  // if(dest->vec_memory != NULL) {  // Нужно убрать выделенный массив, если есть.
  //   free(dest->vec_memory);
  // }
  // dest->size = src->size; src->size = 0;
  // dest->capacity = src->capacity; src->capacity = 0;
  // dest->vec_memory = src->vec_memory;
  // src->vec_memory = NULL;
}

//------------------------------------------------------------------------------
// Копирование данных из одного списка в другой. Списки однотипные
void ppList_copy(ppList* dest, ppList* src) {
  // // Проверка однотипности списоков
  // if(spec_index_cmp(dest, src) < 1) {
  //   // Или обобщение или специализации не совпадают
  //   printf("Incompatible specializations in copy function\n");
  //   exit(-1);
  // }
  // // Если массив в источнике отсутствует, то обнулить массив и в приемнике
  // if(src->vec_memory == NULL) {
  //   if(dest->vec_memory != NULL) {
  //     free(dest->vec_memory);
  //     dest->vec_memory = NULL;
  //     dest->size = 0;
  //     dest->capacity = 0;
  //     return;
  //   } else { // Тоже пусто. Нечего копировать.
  //     return;
  //   }
  // }
  // // Или осуществление копирования. В начале релокация приемника
  // dest->vec_memory = reallocarray(dest->vec_memory,
  //                                 src->size, dest->foundation_size);
  // // Копирование данных из источника в приемник.
  // memcpy(dest->vec_memory, src-> vec_memory, src->size * src->foundation_size);
  // dest->size = src->size;
  // dest->capacity = src->size;
}

