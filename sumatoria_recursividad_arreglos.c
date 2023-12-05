#include <stdio.h>
#define MAX 10000

void llenar_arreglo(int caja[], int tamanio, int indice);
int sumar(int caja[],int i,int num);

int main() {
	int num=0,tamanio;
	int valor, caja[MAX];
	scanf("%d", &tamanio);
	llenar_arreglo(caja,tamanio,num);
	valor=sumar(caja,num,tamanio);
	printf("%d", valor);
	return 0;
}

void llenar_arreglo(int caja[], int tamanio, int indice){
	if(indice==tamanio){
		return;
	}
	scanf("%d",&caja[indice]);
	llenar_arreglo(caja, tamanio,indice+1);
}

int sumar(int caja[],int i,int num){
	if(i==num){
		return 0; 
	}	
	int resul=sumar(caja,i+1,num);
	return caja[i]+resul;
}
