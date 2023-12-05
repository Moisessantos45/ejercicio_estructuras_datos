#include <stdio.h>
#define FILA 10
#define COLUM 10

int main() {
	int fila, col;
	int matrix_bidi[FILA][COLUM];
	int matrix_uni[FILA*COLUM];
	int cont=0, posicion,aux;
	
	scanf("%d %d",&fila, &col);
	for(int i=0; i<fila; i++){
		for(int j=0; j<col; j++){
			scanf("%d",&matrix_bidi[i][j]);
		}
	}
	printf("\n");
	for(int i=0; i<fila; i++){
		for(int j=0; j<col; j++){
			matrix_uni[cont] = matrix_bidi[i][j];
			cont++;
		}
	}
	for(int i=0; i<fila*col; i++){
		for(int j=i+1; j<fila*col; j++){
			
			if(matrix_uni[j]<matrix_uni[i]){
				aux=matrix_uni[i];
				matrix_uni[i]=matrix_uni[j];
				matrix_uni[j]=aux;
			}
		}
	}
	printf("\n");
	for(int i=0; i<fila*col; i++){
		printf("%d ", matrix_uni[i]);
	}
	
	return 0;
}

