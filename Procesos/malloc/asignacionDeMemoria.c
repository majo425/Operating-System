#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char *p = NULL;
  char *q = NULL;

  // Asignar el espacio de memoria a cada variable
  p = (char *)malloc(100);
  q = (char *)malloc(100);
  
  printf("Dirección de p = %p\n", (char *)p);
  strcpy(p, "Hola, yo soy la mejor en sistemas operativos!!");
  printf("%s\n", p);
  printf("A punto de copiar \"Goodbye\" a q\n");
  strcpy(q, "Goodbye");
  printf("Cadena copiada\n");
  printf("%s\n", q);
  
  return 0;
}
