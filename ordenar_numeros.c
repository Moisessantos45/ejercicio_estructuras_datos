#include <stdio.h>
#define MAX 1000

void llenarArreglo(int caja[], int tamanio, int indice);
void ordenarSecuencia(int secuencia[], int tamanio); 
int digitos(int num);
void imprimir(int caja[], int tamanio);


int main() {
	int tamanio;
	int secuencia[MAX];
	scanf("%d", &tamanio);
	llenarArreglo(secuencia, tamanio,0);
	ordenarSecuencia(secuencia,tamanio);
	imprimir(secuencia,tamanio);
	return 0;
}

void llenarArreglo(int caja[], int tamanio, int indice){
	if(indice==tamanio){
		return;
	}
	scanf("%d", &caja[indice]);
	llenarArreglo(caja, tamanio,indice+1);
}

void ordenarSecuencia(int secuencia[], int tamanio){
	for (int t = 0; t < tamanio - 1; t++) {
		int posicion = t;
		for (int j = t + 1; j < tamanio; j++) {
			int digitos1 = digitos(secuencia[posicion]);
			int digitos2 = digitos(secuencia[j]);
			if (digitos1 > digitos2 || (digitos1 == digitos2 && secuencia[t] < secuencia[j])) {
				posicion = j;
			}
		}
		int aux = secuencia[t];
		secuencia[t] = secuencia[posicion];
		secuencia[posicion] = aux;
	}
}

int digitos(int num){
	int cont=0;
	if (num == 0) return 1;
	while(num!=0){
		num=num/10;
		cont++;
	}
	return cont;
}

void imprimir(int caja[], int tamanio){
	for (int i = 0; i < tamanio; i++) {
		printf("%d ", caja[i]);
	}	
}

