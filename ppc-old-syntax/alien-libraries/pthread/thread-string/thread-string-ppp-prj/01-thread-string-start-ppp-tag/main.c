#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "string-thread.h"

//==============================================================================
int main () {
    struct ThreadData.str thread_a;
    thread_a.threadId = 0;
    thread_a.@str = "abcdefghijklmnoprstuvwxyz";

    struct ThreadData.str thread_A;
    thread_A.threadId = 1;
    thread_A.@str = "ABCDEFGHIJKLMNOPRSTUVWXYZ";

    struct ThreadData.str thread_9;
    thread_9.threadId = 1;
    thread_9.@str = "987654321098765432109876543210";

    // Далее запуск потоков
    StartThread((ThreadData*)&thread_a);
    StartThread((ThreadData*)&thread_A);
    StartThread((ThreadData*)&thread_9);

    for (unsigned int i = 0; i < 20; i++) {
        puts("012345678901234567890123456789");
        wait_thread();
    }

    // Ожидание завершения потоков
    WaitThread((ThreadData*)&thread_a);
    WaitThread((ThreadData*)&thread_A);
    WaitThread((ThreadData*)&thread_9);

    return 0;
}

