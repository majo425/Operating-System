#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
    // Cambiar el modo de cancelación a asíncrono
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    printf("Hilo en ejecución...\n");

    // Hacer una espera para simular una tarea crítica
    sleep(5);

    printf("Fin de la ejecución del hilo.\n");

    return NULL;
}

int main() {
    pthread_t thread;

    // Crear el hilo
    pthread_create(&thread, NULL, thread_func, NULL);

    // Esperar un tiempo antes de intentar cancelar el hilo
    sleep(2);

    // Intentar cancelar el hilo
    int cancel_status = pthread_cancel(thread);
    if (cancel_status != 0) {
        printf("Error al intentar cancelar el hilo: %d\n", cancel_status);
    } else {
        printf("El hilo fue cancelado de forma asíncrona.\n");
    }

    // Esperar a que el hilo termine
    if (pthread_join(thread, NULL) != 0) {
        printf("Error al esperar el hilo.\n");
        return 1;
    }

    return 0;
}
