#include <stdio.h>
#include <stdlib.h>

#define size 10

int main(int argc, char *argv[]) {
  int *vectorPunteros[3]; // Vector de punteros de tipo int
  int p = 40, q = 80, r = 120;
  
  vectorPunteros[0] = &p; // Apunta a la dirección de p
  vectorPunteros[1] = &q; // Apunta a la dirección de q
  vectorPunteros[2] = &r; // Apunta a la dirección de r

  printf("\nForma de acceso al vector de punteros: \n");
  for(int i = 0; i < 3; i++){
    printf("Para la dirección: %p \t el valor = %d\n",vectorPunteros[i], *vectorPunteros[i]);
  }
  
  return 0;
}
