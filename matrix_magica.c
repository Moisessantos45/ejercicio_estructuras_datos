#include <stdio.h>
#define FILA 10
#define COLUM 10

int verificar(int valor_a, int valor_b);
int esSemimagica(int matrix[FILA][COLUM], int fila, int col,int valor_a, int valor_b);

int main() {
	int matrix[FILA][COLUM];
	int fila, col;
	int diagonal_a=0, diagonal_b=0;
	scanf("%d %d", &fila, &col);
	
	for(int i=0; i<fila;i++){
		for(int j=0;j<col;j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	
	for(int i=0; i<fila; i++){
		diagonal_a+=matrix[i][i];
		diagonal_b+=matrix[fila-1-i][i];
	}
	
	if(verificar(diagonal_a, diagonal_b)!=0){
		if(esSemimagica(matrix,fila,col,diagonal_a, diagonal_b)!=0){
			printf("La matrix si es semimagica");
		}
	}
	
	return 0;
}

int verificar(int valor_a, int valor_b){
	if(valor_a!=valor_b){
		printf("Las diagonales no son iguales");
		return 0;
	}
	return 1;
}
	
	int esSemimagica(int matrix[FILA][COLUM], int fila, int col, int valor_a, int valor_b){
		int columna, filas;
		for(int i=0; i<fila; i++){
			filas=0;
			columna=0;
			for(int j=0;j<col; j++){
				filas+=matrix[i][j];
				columna+=matrix[j][i];
			}
			if(verificar(filas, valor_a)==0 || verificar(columna, valor_b)==0){
				printf("\nNo conciden los valores");
				return 0;
			}
		}
		return 1;
	}

