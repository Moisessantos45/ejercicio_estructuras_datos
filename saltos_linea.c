#include <stdio.h>

void mostrar(char cadena[], int indice);

int main()
{
	char nombre[10];
	scanf("%s", &nombre);
	mostrar(nombre, 0);
}

void mostrar(char cadena[], int indice)
{
	if(cadena[indice]=='\0'){
		return;
	}
	
	printf("%c \n", cadena[indice]);
	mostrar(cadena, indice+1);
}
