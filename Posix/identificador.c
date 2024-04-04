#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
    pthread_t tid = pthread_self();
    printf("Soy un nuevo hilo con identificador: %lu\n", tid);
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);
    pthread_join(thread, NULL);
    printf("Hilo principal con identificador: %lu\n", pthread_self());
    return 0;
}
