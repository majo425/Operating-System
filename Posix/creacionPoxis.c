#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
    while (1) {
        printf("Hilo en ejecución...\n");
        usleep(1000000); // Espera de 1 segundo
    }
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, thread_func, NULL);
    usleep(3000000); // Esperar 3 segundos
    int cancel_status = pthread_cancel(thread);
    if (cancel_status == 0) {
        printf("Hilo cancelado.\n");
    } else {
        printf("Error al cancelar el hilo.\n");
    }

    return 0;
}
