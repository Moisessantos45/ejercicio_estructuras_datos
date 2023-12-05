#include <stdio.h>
#include <string.h>

void invertir(char cadena[], int indice_inicio, int indice_final);

int main() {
	char palabra[1000];
	char copia[1000];
	gets(palabra);
	strcpy(copia, palabra);
	int longitud = strlen(palabra);
	invertir(palabra, 0, longitud - 1);
	int resultado = strcmp(copia, palabra);
	char* esPalindromo = (resultado == 0) ? "si" : "no";
	printf("%s", esPalindromo);
	return 0;
}

void invertir(char cadena[], int indice_inicio, int indice_final) {
	if (indice_inicio < indice_final) {
		char temp = cadena[indice_inicio];
		cadena[indice_inicio] = cadena[indice_final];
		cadena[indice_final] = temp;
		invertir(cadena, indice_inicio + 1, indice_final - 1);
	}
	
}

