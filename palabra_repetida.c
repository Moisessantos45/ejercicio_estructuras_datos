#include <stdio.h>
#include <string.h>
#define MAX 100

int palabra_repetida(char cadena[], int indice, char *caracter);
void verificar(char letra, int indice, char cadena[], int *cont);

int main() {
	char palabra[MAX];
	char letra;
	int cantidad;
	fgets(palabra, MAX, stdin);
	cantidad = palabra_repetida(palabra, 0, &letra);
	printf(cantidad ? "'%c' %d" : "No hubo letras repetidas", cantidad ? letra : ' ');
//	char resultado[100];
//	snprintf(resultado, sizeof(resultado), cantidad ? "'%c' %d" : "No hubo letras repetidas", cantidad ? letra : ' ');
//	printf("Resultado: %s\n", resultado);
	return 0;
}

int palabra_repetida(char cadena[], int indice, char *caracter) {
	int cont = 0;
	int resul = 0;
	
	if (cadena[indice] == '\0') {
		return 0;
	}
	
	verificar(cadena[indice], indice + 1, cadena, &cont);
	resul = palabra_repetida(cadena, indice + 1, caracter);
	
	if (cont > resul) {
		*caracter = cadena[indice];
		return cont+1;
	}else{
		*caracter='\0';
		return 0;
	}
	
	return resul;
}

void verificar(char letra, int indice, char cadena[], int *cont) {
	if (cadena[indice] == '\0') {
		return;
	}
	
	if (letra == cadena[indice]) {
		(*cont)++;
	}
	
	verificar(letra, indice + 1, cadena, *&cont);
}
