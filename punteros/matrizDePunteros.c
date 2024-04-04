#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int rows, cols, i, j;
  int **matrix;

  printf("Ingrese el número de filas y columnas de la matriz: ");
  if (scanf("%d %d", &rows, &cols) != 2) {
      printf("Error al leer las dimensiones de la matriz.\n");
      return 1;
  }
  
  // Asiganación de memoria para la Matriz
  matrix = (int **)malloc(rows*sizeof(int *));
  for (i = 0; i < rows; i++){
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }

  // Llenado de matriz con valores iniciales
  for (i = 0; i < rows; i++){
    for (j = 0; j < cols; j++){
      matrix[i][j] = i * j;
    }
  }

  // Impresión de matriz
  for (i = 0; i < rows; i++){
    for (j = 0; j < cols; j++){
      printf("%d", matrix[i][j]);
    }
    printf("\n");
  }

  // Liberación o entrega de memoria al SO
  for (i = 0; i < rows; i++){
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}
