#include <stdio.h>

void diagonales(int caja[3][3],int indice, int *valor_a, int *valor_b);

int main() {
	int calificaciones[3][3] = {
	{4,9,2},
	{3,5,7},
	{8,1,6},
	};
	int diagonal_a=0;
	int diagonal_b=0;
	int fila, columna;
	diagonales(calificaciones,0,&diagonal_a,&diagonal_b);
	printf("%d %d", diagonal_a, diagonal_b);
}

void diagonales(int caja[3][3],int indice, int *valor_a, int *valor_b){
	if(indice==3){
		return;
	}
	
	*valor_a+=caja[indice][indice];
	*valor_b+=caja[2-indice][indice];
	diagonales(caja,indice+1,*&valor_a,*&valor_b);
}
