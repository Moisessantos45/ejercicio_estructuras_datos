#include <stdio.h>
#include <string.h>
#include <ctype.h>

void invertir(char cadena[], int indice_inicio, int indice_final);
int contador(char cadena[],char cadena2[], int indice, int longitud);

int main() {
	char palabra[1000];
	char copia[1000];
	int cont;
	gets(palabra);
	strcpy(copia, palabra);
	int longitud = strlen(palabra);
	invertir(palabra, 0, longitud - 1);
	
	cont=contador(palabra, copia,0,longitud);
	printf("%d", cont);
	
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

int contador(char cadena[],char cadena2[], int indice, int longitud){
	if(indice==longitud){
		return 0;
	}
	if(tolower(cadena[indice])==tolower(cadena2[indice])){
		return 1+contador(cadena, cadena2,indice+1,longitud);
	}else{
		contador(cadena, cadena2,indice+1,longitud);
	}
}
