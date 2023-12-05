#include <stdio.h>
#include <string.h>
#define MAX 100

void llenarCadena(char cadena[][MAX], int tamanio);
void ordenarCadenas(char cadena[][MAX], int tamanio);
void imprimirCadena(char cadena[][MAX],int tamanio);

int main() {
	char nombres[MAX][MAX];
	int tamanio;
	scanf("%d", &tamanio);
	getchar();
	llenarCadena(nombres,tamanio);
	ordenarCadenas(nombres,tamanio);
	imprimirCadena(nombres,tamanio);
	return 0;
}

void llenarCadena(char cadena[][MAX], int tamanio) {
	for (int i = 0; i < tamanio; i++) {
		fgets(cadena[i], MAX, stdin);
		if (cadena[i][strlen(cadena[i]) - 1] == '\n') {
			cadena[i][strlen(cadena[i]) - 1] = '\0';
		}
	}
}

void ordenarCadenas(char cadena[][MAX],int tamanio){
	char nombre[50];
	for(int i=0;i<tamanio-1;i++){
		int posicion = i;
		for(int j=i+1;j<tamanio;j++){
			if(strcmp(cadena[posicion],cadena[j])>0){
				posicion=j;
			}
		}
		strcpy(nombre,cadena[i]);
		strcpy(cadena[i],cadena[posicion]);
		strcpy(cadena[posicion],nombre);      
	}
}

void imprimirCadena(char cadena[][MAX],int tamanio){
	printf("\n");
	for(int i=0;i<tamanio;i++){
		printf("%s\n",cadena[i]);
	}
}
