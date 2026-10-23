#ifndef __pplist_interface__
#define __pplist_interface__

//==============================================================================
// interface.h
// Интерфейс списка, используемый при программировании
//==============================================================================

// Начальная инициализация списка
void ppList_init(ppList* l);

// Определение текущего размера списка
uint32_t ppList_size(ppList* l);

// Установка нового значения в существующий текущий элемент списка
// из значения, находящегося в специализации
void ppList_replace_current(ppList* l);

// Занесение в хвост списка значения, размещенного в специализированной переменной.
// Предварительно значение должно быть занесено в специализацию
void ppList_push_back(ppList* l);

// Вставка нового узла после текущего
void ppList_push_after_current(ppList* l);

// Вставка нового узла перед текущим
void ppList_push_before_current(ppList* l);

// Смещение указателя текущего элемента на следующий элемент списка
_Bool ppList_next_current(ppList* l);

// Смещение указателя текущего элемента на предыдущий элемент списка
_Bool ppList_prev_current(ppList* l);

// Установка первого узла текущим
void ppList_front_current(ppList* l);

// Установка последнего узла текущим
void ppList_back_current(ppList* l);

// Проверка текущего на первый элемент списка
_Bool ppList_is_head(ppList* l);

// Проверка текущего на последний элемент списка
_Bool ppList_is_tail(ppList* l);

// Фиксация в основе специализации значения первого элемента списка
void ppList_front(ppList* l);

// Фиксация в основе специализации значения последнего элемента списка
void ppList_back(ppList* l);

// Фиксация в основе специализации значения текущего элемента списка
void ppList_current(ppList* l);

// Удаление последнего элемента списка
void ppList_pop_back(ppList* l);

// Удаление первого элемента списка
void ppList_pop_front(ppList* l);

// Удаление текущего элемента списка
void ppList_pop_current(ppList* l);

// Очистка списка от данных
void ppList_clear(ppList* l);

// Обмен содержимым между двумя однотипными списками
void ppList_swap(ppList* l1, ppList* l2);

// Пересылка данных из одного списка в другой. Списки однотипные
void ppList_move(ppList* dest, ppList* src);

// Копирование данных из одного списка в другой. Списки однотипные
void ppList_copy(ppList* dest, ppList* src);

#endif // __pplist_interface__
