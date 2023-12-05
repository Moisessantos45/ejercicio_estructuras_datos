#include <stdio.h>
#define MAX 1000

void llenar_arreglo(int caja[],int tamanio,int indice);
void invertir(int caja[], int tamanio, int indice);
void imprimir(int caja[], int tamanio, int indice);

int main() {
	int caja[MAX];
	int numero;
	scanf("%d",&numero);	
	llenar_arreglo(caja,numero,0);
	invertir(caja,0, numero-1);
	if(numero>2){
		invertir(caja, numero / 2, numero - 1);
		invertir(caja, 0, numero / 2 - 1);
		
	}
	imprimir(caja,numero,0);
/*	caja_derecha[numero-numero/2];*/
/*	caja_izquierda[numero/2];*/
	return 0;
}

void llenar_arreglo(int caja[],int tamanio,int indice){
	if(indice==tamanio){
		return;
	}	
	scanf("%d",&caja[indice]);
	llenar_arreglo(caja,tamanio,indice+1);
}

void invertir(int caja[], int tamanio, int indice) {
		if (tamanio >= indice)
			return;
		int temp = caja[tamanio];
		caja[tamanio] = caja[indice];
		caja[indice] = temp;
		invertir(caja, tamanio + 1,indice - 1);
}

void imprimir(int caja[], int tamanio, int indice){
	if(indice==tamanio){
		return;
	}
	printf("%d ", caja[indice]);
	imprimir(caja, tamanio, indice+1);
}
