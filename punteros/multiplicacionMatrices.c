#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

/*** Un valor constante global (muy grande) ***/
#define DATA_SIZE (1024*1024*64*8)

/*** Se reserva un espacion de memoria muy grande ***/
static double MEM_CHUNK[DATA_SIZE];

/*** Función para inicializar matrices ***/
void initMatriz(int sz, double *ma, double *mb, double *mc){
  for(int i = 0; i < sz*sz; i++){
    ma[i] = 2.1 +i;
    mb[i] = 1.3 +i;
    mc[i] = 0.0;
  }
}
/*** Función para imprimir matrices ***/
void impresionMatriz(int sz, double *m){
  for(int i = 0; i < sz; i++){ //Recorrer filas
    for(int j = 0; j < sz; j++){ //Recorrer columnas
      printf(" %f ", m[i+j]*sz);
    }
    printf("\n");
  }
  printf("\n ******************************* \n");
}  

/*** Función programa principal ***/
//  argc = cantidad de argumentos desde 0
// argv = vector de los argumentos argumentos
int main(int argc, char *argv[]) {
  int SZ; //Variable para almacenar el tamaño de la matriz
  if (argc > 1) {
      SZ = (int) atof(argv[1]); //capturando el primer valor
  } else {
    printf("Ingreso de parametros erroneo: \n");
    printf("$./eje valor \n");
    return -1;
  }
  //Imprime el tamaño de la matriz
  printf("Matriz[%d][%d] \n", SZ,SZ);
  
  /*** Crear las matrices ***/
  double *Ma, *Mb, *Mc;
  Ma = MEM_CHUNK;
  Mb = Ma + SZ*SZ;
  Mc = Mb + SZ*SZ;
  /*** Inicialización de matrices ***/
  initMatriz(SZ, Ma, Mb, Mc);
  
  /*** Impresión de matriz***/
  impresionMatriz(SZ, Ma);
  impresionMatriz(SZ, Mb);
  impresionMatriz(SZ, Mc);
  
  //Se retorna 0 debido a que la funcion es de tipo entero
  return 0;
}
