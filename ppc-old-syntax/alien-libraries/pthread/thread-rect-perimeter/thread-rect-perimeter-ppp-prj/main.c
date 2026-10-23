//==============================================================================
// Главная функция, осуществляющая необходимые вычисления
//==============================================================================

// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <pthread.h>
#include "rectangle-thread.h"

int main () {
    // Переменные, передаваемая запускаемому потоку
    // Если инициализация напрямую еще не работает.
    // Ее можно заменить на присваивания.
    // Представлен вариант инициализации не всех полей. Может его и не будет.
    struct ThreadData.RectPerimeter thread1; //= {0}<{3,5,0.0}>;
    thread1.threadId = 0;
    thread1.@r.x = 3;
    thread1.@r.y = 5;
    thread1.@p = 0.0;
    struct ThreadData.RectPerimeter thread2; //= {0}<{7,4,0.0}>;
    thread2.threadId = 1;
    thread2.@r.x = 7;
    thread2.@r.y = 4;
    thread2.@p = 0.0;
    struct ThreadData.RectPerimeter thread3; //= {0}<{6,8,0.0}>;
    thread3.threadId = 2;
    thread3.@r.x = 6;
    thread3.@r.y = 8;
    thread3.@p = 0.0;

    // Далее запуск трех потоков
    StartThread((ThreadData*)&thread1);
    StartThread((ThreadData*)&thread2);
    StartThread((ThreadData*)&thread3);

    // Ожидание завершения потоков
    WaitThread((ThreadData*)&thread1);
    WaitThread((ThreadData*)&thread2);
    WaitThread((ThreadData*)&thread3);

    // Печать периметров
    PrintRectPerimeter(&(thread1.@), "Tread1");
    PrintRectPerimeter(&(thread2.@), "Tread2");
    PrintRectPerimeter(&(thread3.@), "Tread3");

    return 0;
}
