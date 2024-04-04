#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_RUNTIME_SECONDS 5

void* thread_func(void* arg) {
    // Cambiar el estado de aceptación de cancelación del hilo a DISABLE

    // Ejecutar durante un tiempo determinado
    for (int i = 0; i < THREAD_RUNTIME_SECONDS; ++i) {
        sleep(1);
        printf("Hilo en ejecución...\n");
    }

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
        printf("El hilo no pudo ser cancelado.\n");
    }

    // Esperar a que el hilo termine
    if (pthread_join(thread, NULL) != 0) {
        printf("Error al esperar el hilo.\n");
        return 1;
    }

    return 0;
}
