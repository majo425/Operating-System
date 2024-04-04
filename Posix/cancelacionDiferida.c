#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
  // Configurar la cancelación diferida (modo predeterminado)
  // pthread_setcancelstate(PTHREAD_CANCEL_DEFERRED, NULL);

    printf("Hilo en ejecución...\n");

    // Simulación de una operación crítica o bloqueante
    int i;
    for (i = 0; i < 7; ++i) {
        printf("Realizando tarea %d...\n", i);
        usleep(500000); // Simula una espera de medio segundo
        // Verificar si hay una solicitud de cancelación pendiente
        pthread_testcancel();
    }

    printf("Tarea finalizada.\n");

    return NULL;
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, thread_func, NULL);

    // Esperar un tiempo antes de intentar cancelar el hilo
    sleep(2);

    // Intentar cancelar el hilo
    if (pthread_cancel(thread) != 0) {
        printf("Error al intentar cancelar el hilo.\n");
        return 1;
    }

    // Esperar a que el hilo termine
    if (pthread_join(thread, NULL) != 0) {
        printf("Error al esperar el hilo.\n");
        return 1;
    }

    printf("El hilo ha sido cancelado.\n");

    return 0;
}
