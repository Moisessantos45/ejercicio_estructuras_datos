#include <stdio.h>
#define COL 10
#define FILA 10
void llenar_matrix(int matrix[COL][FILA], int col, int fila,int indice_i, int indice_j, int cont);
void ordenar(int matrix[COL][FILA], int col, int fila);
/*void ordenar(int matrix[COL][FILA], int col, int fila, int indice_i, int indice_j);*/

int main() {
	int matrix[COL][FILA];
	int col, fila;
	scanf("%d %d", &col, &fila);
	llenar_matrix(matrix, col, fila,0,0,1);
	ordenar(matrix,col, fila-1);
/*	ordenar(matrix,col, fila,0,0);*/
	return 0;
}

void llenar_matrix(int matrix[COL][FILA], int col, int fila,int indice_i, int indice_j, int cont){
	if(indice_i==col){
		return;
	}
	if(indice_j==fila){
		llenar_matrix(matrix, col, fila, indice_i + 1, 0, cont);
		return;
	}

	matrix[indice_i][indice_j]=cont;
	llenar_matrix(matrix, col, fila, indice_i, indice_j + 1, cont+1);
}
	
void ordenar(int matrix[COL][FILA], int col, int fila){
	for(int i=0; i<col;i++){
		if(i%2 == 0){
			for(int j=0; j<=fila; j++){
				printf("%d ", matrix[i][j]);
			}
		} else {
			for(int j=fila; j>=0; j--){
				printf("%d ", matrix[i][j]);
			}
		}
		printf("\n");
	}
}
	
/*void ordenar(int matrix[COL][FILA], int col, int fila, int indice_i, int indice_j){*/
/*		if(indice_i==col){*/
/*			return;*/
/*		}*/
/*		if(indice_i%2 == 0){*/
/*			if(indice_j<=fila){*/
/*				printf("%d ", matrix[indice_i][indice_j]);*/
/*				ordenar(matrix, col, fila, indice_i, indice_j + 1);*/
/*			} else {*/
/*				printf("\n");*/
/*				ordenar(matrix, col, fila, indice_i + 1, 0);*/
/*			}*/
/*		} else {*/
/*			if(indice_j>=0){*/
/*				printf("%d ", matrix[indice_i][indice_j]);*/
/*				ordenar(matrix, col, fila, indice_i, indice_j - 1);*/
/*			} else {*/
/*				printf("\n");*/
/*				ordenar(matrix, col, fila, indice_i + 1, fila);*/
/*			}*/
/*		}*/
/*}*/
		
