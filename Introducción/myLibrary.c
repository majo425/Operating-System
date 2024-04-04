#include <stdio.h>
#include "myLibrary.h"

/* Función para imprimir matriz */
void imprimirMatriz (int filas, int columnas){
  int k = 0;
  for (int i=0; i<filas; i++){
    for (int j=0; j<columnas; j++){
      printf(" %i ", i+k);
      k++;
    }
    printf("\n");
  }
}

/* Función para calcular el volumen de un cilindro */
float volumenCilindro(float radio, float altura){
  return 3.1416*radio*radio*altura;
}

/* Función para calcular el area de un cuadrado */
int areaCuadrado (int lado){
  if (lado == 0 || lado < 0){
    printf("\nEl valor del lado digitado es incorrecto\n");
    return 0;
  }else {
    return lado * lado;  
  }  
}
