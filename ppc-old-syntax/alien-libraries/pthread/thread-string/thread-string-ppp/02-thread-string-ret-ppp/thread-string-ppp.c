// gcc ex01.c -lpthread
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

void wait_thread (void);

//==============================================================================
// В начале представлена обертка над функциями библиотеки pthread
// аналогичная объектно-ориентированной обертке
//==============================================================================

// Обобщенная структура, используемая для обертки данных,
// передаваемых в поточную функцию, и для возврата результата
// Конкретные данные формируются в специализации для каждого
// отдельного потока
typedef struct ThreadData {pthread_t threadId;}<> ThreadData;

// Обобщенная функция, задающая формат для передачи аргументов
// и подменяемая на соответствующий обработчик специализации.
// Часто он может бытьтолько один
void RunThread <ThreadData* d>() {} //= 0;

// POSIX функция, вызвывающая обработчик обобщения
// подменяемый обработчиком специализации
void* ThreadFunc(void* d) {
  RunThread<(ThreadData*) d>();
  return NULL;
}

// Функция создания и запуска потока
int StartThread(ThreadData* td) {
  return pthread_create(&(td->threadId), NULL, ThreadFunc, td);
}

// Функция ожидания завершения потока
int WaitThread(ThreadData* td) {
  return pthread_join(td->threadId, NULL);
}

//==============================================================================

// Строка для обработки данных
typedef struct String{char* str;} String;

// Специализация для потока, определяющая строку
ThreadData + <str: String;>;

// Обработчик специализации, запускаемый в потоке
// Осуществляет вывод строки
void RunThread<ThreadData.str *string>() {
    for (unsigned int i = 0; i < 20; i++) {
        printf("%d) ", i);
        puts(string->@str);
        wait_thread();
    }
}

//==============================================================================
int main () {
    struct ThreadData.str thread_a;
    thread_a.threadId = 0;
    thread_a.@str = "abcdefghijklmnoprstuvwxyz";

    struct ThreadData.str thread_A;
    thread_A.threadId = 1;
    thread_A.@str = "ABCDEFGHIJKLMNOPRSTUVWXYZ";

    struct ThreadData.str thread_0;
    thread_0.threadId = 1;
    thread_0.@str = "012345678901234567890123456789";

    struct ThreadData.str thread_9;
    thread_9.threadId = 1;
    thread_9.@str = "987654321098765432109876543210";

    return StartThread((ThreadData*)&thread_a)
        || StartThread((ThreadData*)&thread_A)
        || StartThread((ThreadData*)&thread_0)
        || StartThread((ThreadData*)&thread_9)
        || WaitThread((ThreadData*)&thread_a)
        || WaitThread((ThreadData*)&thread_A)
        || WaitThread((ThreadData*)&thread_0)
        || WaitThread((ThreadData*)&thread_9)
             ? EXIT_FAILURE : EXIT_SUCCESS;
    // return 0;
}

//==============================================================================
void wait_thread (void) {
    time_t start_time = time(NULL);
    while(time(NULL) == start_time) {}
}
