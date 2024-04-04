#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  int *ptr;
  
  ptr = malloc(15 * sizeof(*ptr)); /* Memoria dinámica para almacenar 15 enteros */
  
  if (ptr != NULL) {
    *(ptr + 5) = 480; /* Asigna 480 en la posición 6ta */
    printf("Value of the 6th integer is %d\n", *(ptr + 5)); /* Imprimir el valor de 6to entero */
    free(ptr); /* Liberar memoria */
  }else{
    /* Manejar validación en caso que se asigne la memoria incorrectamente */
    perror("No se puede asignar espacio");
    exit(1);
  }
  
  return 0;
}
