#include <stdio.h>
void imprimirEspacios(int espacio);
void imprimirArrobas(int arrobas);

int main() {
	int altura;
	scanf("%d",&altura);
	for(int i=1; i<=altura;i++){
		imprimirEspacios(altura-i);
		imprimirArrobas(2*i-1);
		printf("\n");
	}
	return 0;
}

void imprimirEspacios(int espacio){
	for(int i=0;i<espacio;i++){
		printf(" ");
	}
}

void imprimirArrobas(int arrobas){
	for(int i=0;i<arrobas;i++){
		printf("@");
	}
}

