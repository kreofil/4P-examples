#include <stdio.h>
#include "string-thread.h"

//==============================================================================
// Функция задержки, имитирующая работу
void wait_thread (void) {
    time_t start_time = time(NULL);
    while(time(NULL) == start_time) {}
}

// Обработчик специализации, запускаемый в потоке
// Осуществляет вывод строки
void RunThread<ThreadData.str *string>() {
    for (unsigned int i = 0; i < 20; i++) {
        printf("%d) ", i);
        puts(string->@str);
        wait_thread();
    }
}

