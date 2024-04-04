#include <stdio.h>
#include <stdlib.h>

#define size 10

int main(int argc, char *argv[]) {
  /*** Suma de dos valores ingresados por pantalla usando punteros ***/
  int valor1, valor2;
  int *ptrV1, *ptrV2;
  ptrV1 = &valor1;
  ptrV2 = &valor2;

  printf("\nIngrese dos valores a ser sumados: \n");

  // Validar si se leyeron las dos variables
  if (scanf("%d %d", &valor1, &valor2) != 2) {
    printf("Error al leer la entrada.\n");
    return 1; 
  }

  printf("\nLa suma es = %d\n", *ptrV1 + *ptrV2);
  
  return 0;
}
