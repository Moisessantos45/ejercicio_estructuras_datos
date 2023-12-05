#include <stdio.h>
#include <string.h>

void llenaArreglo(int tabla[4][4], int fila, int col);
void llenarMatrix(char platos[][3], int tamanio);

int main() {
	int tabla[4][4];
	char platos[10][3];
	int total = 0, fila, col, tamanio;
	int cont = 0;
	llenaArreglo(tabla, 4, 4);
	scanf("%d", &tamanio);
	llenarMatrix(platos, tamanio);
	char valor = platos[0][0];
	
	for (int i = 0; i < tamanio; i++) {
		char letra = platos[i][0];
		char numero = platos[i][1];
		total += tabla[letra - 'A'][numero - '1'];
		if (letra == valor) {
			cont++;
		}
	}
	
	if (cont == tamanio) {
		total -= 10;
	}
	
	printf("%d\n", total);
	
	return 0;
}

void llenaArreglo(int tabla[4][4], int fila, int col) {
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d", &tabla[i][j]);
		}
	}
}

void llenarMatrix(char platos[][3], int tamanio) {
	for (int i = 0; i < tamanio; i++) {
		scanf("%s", platos[i]);
	}
}
