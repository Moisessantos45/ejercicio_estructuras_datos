#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COL 10
#define FILA 10
void llenar_matrix(int matrix[COL][FILA], int col, int fila,int indice_i, int indice_j);
void resultado(int matrix[COL][FILA], int col, int fila);
int numero_rando();

int main() {
	srand(time(0));
	int matrix[COL][FILA];
	int col, fila;
	scanf("%d %d", &col, &fila);
	llenar_matrix(matrix, col, fila,0,0);
/*	printf("\n");*/
/*	for(int i=0; i<col;i++){*/
/*		for(int j=0; j<fila; j++){*/
/*			printf("%d ", matrix[i][j]);*/
/*		}*/
/*		printf("\n");*/
/*	}*/
/*	printf("\n");*/
	resultado(matrix,col, fila);
	
	for(int i=0; i<col;i++){
		for(int j=0; j<fila; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void llenar_matrix(int matrix[COL][FILA], int col, int fila,int indice_i, int indice_j){

	if(indice_i==col){
		return;
	}
	if(indice_j==fila){
		llenar_matrix(matrix, col, fila, indice_i + 1, 0);
		return;
	}
	scanf("%d",&matrix[indice_i][indice_j]);
/*	matrix[indice_i][indice_j]=rand() % 2;*/
	llenar_matrix(matrix, col, fila, indice_i, indice_j + 1);
}
	
void resultado(int matrix[COL][FILA], int col, int fila){
	for(int i=0; i<col;i++){
		for(int j=0; j<fila; j++){
			if(matrix[i][j]==1){
				matrix[i][j]=9;
			}else{
				matrix[i][j]=numero_rando();
			}
		}
	}
}
	
int numero_rando(){
	int random_num;
	do {
		random_num = rand() % 10;
	} while(random_num == 9);
	
	return random_num;
}
		
