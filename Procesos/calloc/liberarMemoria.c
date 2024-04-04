#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *function(char *p);

int main() {
  char *a = NULL;
  char *b = NULL;
  
  a = function("Hi, It's fun to learn");
  b = function("systems engineer");
  printf("Desde el main: %s %s\n", a, b);

  free(a);
  free(b);
  return 0;
}

char *function(char *p) {
  char *q = malloc(strlen(p) + 1); // Asignar memoria dinámica
  strcpy(q, p);
  printf("Desde q: la cadena es %s\n", q);
  
  return q;
}
