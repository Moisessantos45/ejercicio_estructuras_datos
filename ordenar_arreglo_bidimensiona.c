#include <stdio.h>
#include <stdlib.h>

#define FILAS 3
#define COLUMNAS 3

void ordenarArreglo(int arr[], int n) {
	int i, j, temp;
	for (i = 0; i < n-1; i++) {     
		for (j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main() {
	int arreglo[FILAS][COLUMNAS];
	
	// Llenar el arreglo con números aleatorios y ordenar cada fila
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			scanf("%d",&arreglo[i][j]);
		}
		ordenarArreglo(arreglo[i], COLUMNAS);
	}
	
	// Imprimir el arreglo
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			printf("%d ", arreglo[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
