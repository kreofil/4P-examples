#ifndef __string_thread__
#define __string_thread__

#include "ppp-thread.h"

//==============================================================================
// Строка для обработки данных
typedef struct String{char* str;} String;

// Специализация для потока, определяющая строку
ThreadData + <String;>;

//==============================================================================
// Функция задержки, имитирующая работу
void wait_thread (void);

// Обработчик специализации, запускаемый в потоке
// Осуществляет вывод строки
void RunThread<ThreadData.String *string>();

#endif // __string_thread__