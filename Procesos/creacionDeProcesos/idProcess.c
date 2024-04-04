#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  
  int processID = fork(); // Función para duplicar el proceso

  if(processID > 0){
    printf("\n 'Proceso padre'...\n ID: %d\n", getpid());
  }
  else if (processID == 0){
      printf("\n 'Proceso hijo' recien creado \n ID: %d\n: ", getpid());
  }
  else {
      printf("\n Llamada al sistema fork() fallo \n");
  }

  printf("\n\n Imprimiendo...\n");
  for (int i = 0; i < 5; i++){
    printf(" %d ", i);
  }
  printf("\n Fin \n");
  
  return 0;
}
