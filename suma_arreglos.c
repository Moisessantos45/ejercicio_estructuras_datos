#include <stdio.h>
#define Max 100

void llenarArreglo(int secuencia[], int tamanio);
void sumar(int secuencia1[], int secuencia2[], int tamanio);
void imprimir(int caja[], int tamanio);

int main() {
	int caja[Max], caja2[Max];
	int tamanio,iguales;
	scanf("%d", &tamanio);
	llenarArreglo(caja, tamanio);
	llenarArreglo(caja2, tamanio);	
	sumar(caja, caja2, tamanio);
	imprimir(caja,tamanio);
	
	return 0;
}

void llenarArreglo(int secuencia[], int tamanio) {
	for (int i = 0; i < tamanio; i++) {
		scanf("%d", &secuencia[i]);
	}
}

void sumar(int secuencia1[], int secuencia2[], int tamanio) {
	for (int i = 0; i < tamanio; i++) {
		secuencia1[i]+=secuencia2[i];
	}
}

void imprimir(int caja[], int tamanio)
{
	for (int i = 0; i < tamanio; i++)
	{
		printf("%d ", caja[i]);
	}
}
