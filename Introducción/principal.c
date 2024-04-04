#include <stdio.h>
#include "myLibrary.h"

int main(){
  int c = 5, f = 5;
  int l = -1;
  float r = 12, a = 7.6;
  //printf("Hello World\n");
  //imprimirMatriz(c, f);
  volumenCilindro(r,a);
  float v = volumenCilindro(r,a);
  printf("El volumen del cilindro de radio: %f y altura: %f, es = %f\n", r,a,v);
  int ar = areaCuadrado(l);
  printf("El area para el cuadrado con lado %i, es = %i\n", l,ar);
  return 0;
}
