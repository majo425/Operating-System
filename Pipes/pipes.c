#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MESSAGESIZE 16
// Punteros para enviar mensajes
char *mensaje01 = "Hola, mundo #1";
char *mensaje02 = "Hola, mundo #2";
char *mensaje03 = "Hola, mundo #3";

int main(int argc, char *argv[]) {
  // Vector de tamaño MESSAGESIZE
  char inbufer[MESSAGESIZE];
  // Dos vectores de  tipo entero (Tuberia de comunicación entre cada de uno de los procesos)
  int p[2],i;
  
  if(pipe(p) < 0)
    exit(1);

  write(p[1], mensaje01, MESSAGESIZE);
  write(p[1], mensaje02, MESSAGESIZE);
  write(p[1], mensaje03, MESSAGESIZE);

  for(i = 0; i < 3; i++){
    read(p[0], inbufer, MESSAGESIZE); // Leer cada una de las tuberias
    printf("%s\n", inbufer);
  }
  return 0;
}
