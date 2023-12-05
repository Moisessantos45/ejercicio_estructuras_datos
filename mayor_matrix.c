#include <stdio.h>

void llenaArreglo(int matrix[10][10], int fila, int col, int indice_i, int indice_j);
int mayor(int matrix[10][10], int fila, int col, int indice_i, int indice_j, int *posicion_fila, int *posicion_col, int mayor_matrix);

int main() {
	int matrix[10][10];
	int fila, col;
	int posicion_fila, posicion_col, resultado;
	scanf("%d %d", &fila, &col);
	
	llenaArreglo(matrix, fila, col, 0, 0);
	resultado = mayor(matrix, fila, col, 0, 0, &posicion_fila, &posicion_col,matrix[0][0]);
	printf("%d %d %d", resultado, posicion_fila+1, posicion_col+1);
	printf("\n");
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

void llenaArreglo(int matrix[10][10], int fila, int col, int indice_i, int indice_j) {
	if (indice_i == fila) {
		return;
	}
	
	if (indice_j == col) {
		llenaArreglo(matrix, fila, col, indice_i + 1, 0);
		return;
	}
	
	scanf("%d", &matrix[indice_i][indice_j]);
	llenaArreglo(matrix, fila, col, indice_i, indice_j + 1);
}

int mayor(int matrix[10][10], int fila, int col,int indice_i,int indice_j,int *posicion_fila,int *posicion_col,int mayor_matrix){
	if(indice_i==fila){
		return mayor_matrix;
	}
	if(indice_j==col){
		return mayor(matrix,fila,col ,indice_i+1 ,0,posicion_fila,posicion_col,mayor_matrix);
	}
	if(mayor_matrix<matrix[indice_i][indice_j]){
		mayor_matrix=matrix[indice_i][indice_j];
		*posicion_fila=indice_i;
		*posicion_col=indice_j;
	}
	return mayor(matrix,fila,col ,indice_i ,indice_j+1,posicion_fila,posicion_col,mayor_matrix);
}
	
