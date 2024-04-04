#include <stdio.h>
#include <stdlib.h>

#define size 10

int main(int argc, char *argv[]) {
  /*** Suma de dos valores ingresados por pantalla usando punteros ***/
  int vector[] = {40, 80, 120, 230};
  int *ptrV1;
  ptrV1 = vector;

  printf("\nImpresión por indices\n");
  printf("----------------------\n");
  for(int i = 0; i < 4; i++){
    printf("Por indices: El valor del vector[%d] = %d\n", i, ptrV1[i]);
  }
  
  printf("\nImpresión por sucesor\n");
  printf("----------------------\n");
  for(int i = 0; i < 4; i++){
    printf("Por sucesor: El valor del vector[%d] = %d\n", i, *ptrV1);
    ptrV1++;
  }
  
  return 0;
}
