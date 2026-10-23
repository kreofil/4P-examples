#ifndef __ppstring_interface__
#define __ppstring_interface__

//==============================================================================
// interface.h
// Интерфейс строки, используемый при программировании
//==============================================================================

// Начальная инициализация строки
void ppString_init(ppString* v);

// Определение текущего размера строки
uint32_t ppString_size(ppString* v);

// Определение текущей вместимости
uint32_t ppString_capacity(ppString* v);

// Резервирование памяти под заданное количество элементов
void ppString_reserve(ppString* v, uint32_t new_cap);

// Изменение числа элементов в векторе (size)
// Новые элементы не устанавливаются или вектор обрезается
void ppString_resize(ppString* v, uint32_t new_size);

// Освободение памяти до размера size
void ppString_shrink_to_fit(ppString* v);

// Занесение в хвост строки значения, размещенного
// в специализированной переменной.
// Предварительно значение должно быть занесено в специализацию
void ppString_push_back(ppString* v);

// Неконтролируемый доступ к элементу строки по индексу.
// Элемент из строки переносится в основу специализации.
// Оттуда его можно будет забрать, используя знание типа строки, присваиванием.
void ppString_index(ppString* v, uint32_t index);

// Фиксация в основе специализации значения первого элемента строки
void ppString_front(ppString* v);

// Фиксация в основе специализации значения последнего элемента строки
void ppString_back(ppString* v);

// Возврат указателя на текущий вектор элементов в динамической памяти
void* ppString_data(ppString* v);

// Вставка осуществляется по целочисленному индексу. Без итераторов
void ppString_insert_index(ppString* v, uint32_t index);

// Удаление последнего элемента строки
void ppString_pop_back(ppString* v);

// Удаление из строки от одного до нескольких элементов
void ppString_erase(ppString* v, uint32_t first, uint32_t last);

// Очистка строки от данных без изменения вместимости
void ppString_clear(ppString* v);

// Удаление у строки динамчески выделенной памяти.
// Переход в начальное состояние
void ppString_destroy(ppString* v);

// Обмен содержимым между двумя однотипными строкими
void ppString_swap(ppString* v1, ppString* v2);

// Пересылка данных из одного строки в другой. Векторы однотипные
void ppString_move(ppString* dest, ppString* src);

// Копирование данных из одного строки в другой. Векторы однотипные
void ppString_copy(ppString* dest, ppString* src);

#endif // __ppstring_interface__
