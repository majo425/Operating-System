#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  int *ptr, i , n1, n2;
  /*** Leer el tamaño ***/
  printf("Entrar tamaño: ");
  if (scanf("%d", &n1) != 1) {
    printf("Error al leer la entrada\n");
    return 1; 
  }
  
  ptr = (int*) malloc(n1 * sizeof(int)); /* Asignar memoria para el tamaño ingresado */
  
  printf("Dirección de memoria previamente asignada: ");
  for(i = 0; i < n1; ++i){
    printf("\n\np = %p\n", ptr+i);
  }
  printf("\n Ingresar el nuevo tamaño: ");
  if (scanf("%d", &n2) != 1) {
    printf("Error al leer la entrada\n");
    return 1; 
  }
  
  /* Dirección de memoria previamente asignada */
  ptr = realloc(ptr, n2 * sizeof(int));
  printf("Dirección de memoria recien asignada: ");
  for(i = 0; i < n2; ++i){
    printf("\n\np = %p\n", ptr+i);
  }  
  free(ptr);
  
return 0;
}
