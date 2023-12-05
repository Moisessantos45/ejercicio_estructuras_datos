#include <stdio.h>
#define Max 100

void llenarArreglo(int secuencia[], int tamanio);
int comparar(int secuencia1[], int secuencia2[], int tamanio);

int main() {
	int caja[Max], caja2[Max];
	int tamanio,iguales;
	scanf("%d", &tamanio);
	llenarArreglo(caja, tamanio);
	llenarArreglo(caja2, tamanio);
	
	iguales = comparar(caja, caja2, tamanio);
	
	printf("%d", iguales);
	
	return 0;
}

void llenarArreglo(int secuencia[], int tamanio) {
	for (int i = 0; i < tamanio; i++) {
		scanf("%d", &secuencia[i]);
	}
}

int comparar(int secuencia1[], int secuencia2[], int tamanio) {
	for (int i = 0; i < tamanio; i++) {
		if (secuencia1[i] != secuencia2[i]) {
			return 0;
		}
	}
	return 1;
}

