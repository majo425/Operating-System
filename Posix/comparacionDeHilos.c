#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
    pthread_t tid = pthread_self();
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_func, NULL);
    pthread_create(&thread2, NULL, thread_func, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Hilo 1 con identificador: %lu\n", thread1);
    printf("Hilo 2 con identificador: %lu\n", thread2);

    // Comparar los identificadores de los hilos
    if (pthread_equal(thread1, thread2)) {
        printf("Los identificadores de los hilos son iguales.\n");
    } else {
        printf("Los identificadores de los hilos son diferentes.\n");
    }

    return 0;
}
