#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *q = NULL;

  q = (char *)malloc(100);
  
  printf("Solicitando espacio para \"Goodbye\" \n");
  q = (char *)malloc(strlen("Goodbye")+1);
  
  if (!q) {
    perror("No se puede asignar espacio");
    exit(1);
  }
  printf("Apunto de copiar \"Goodbye\" a la dirección en q: %p \n", q);
  strcpy(q, "Goodbye");
  printf("Cadena copiada\n");
  printf("%s \n", q);
  
  return 0;
}
