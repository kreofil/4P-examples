// gcc thread-string-pp.c -lpthread
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

void wait_thread (void);
void* thread_func (void*);

int main () {
    pthread_t thread;
    if (pthread_create(&thread, NULL,thread_func,NULL)) return EXIT_FAILURE;
    for (unsigned int i = 0; i < 20; i++) {
        puts("abcdefghijklmnoprstuvwxyz");
        wait_thread();
    }
    if (pthread_join(thread,NULL)) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void wait_thread (void) {
    time_t start_time = time(NULL);
    while(time(NULL) == start_time) {}
}

void* thread_func (void* vptr_args) {
    for (unsigned int i = 0; i < 20; i++) {
        puts("ABCDEFGHIJKLMNOPRSTUVWXYZ");
        wait_thread();
    }
    return NULL;
}
