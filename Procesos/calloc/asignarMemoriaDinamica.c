#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  int n, i, *ptr, sum = 0;

  /*** Solicitar por consola el número de elementos (Manejar error de lectura) ***/
  printf("Ingresar el número de elementos: ");
  if (scanf("%d", &n) != 1) {
    printf("Error al leer la entrada.\n");
    return 1; 
  }
  
  ptr = (int*) calloc(n, sizeof(int));  /* Almacenar memoria dinámica para almacenar n elementos */
  
  if(ptr == NULL) {
    printf("Error! Memoria no localizada."); /* Manejar error si no se puede asignar la memoria */
    exit(1);
  }

  /*** Solicitar los elementos ***/
  for(i = 0; i < n; ++i) {
    printf("Ingresar elemento %d: ", i+1);
    if (scanf("%d", ptr+i) != 1) {
      printf("Error al leer el elemento %d \n", i+1);
      free(ptr); /* Liberar memoria si no se puede leer el elemento */
      return 1; 
    }  
    sum += *(ptr+i); /* Acumulador */
  }
  printf("Sum = %d\n", sum);
  free(ptr);
  
  return 0;
}
