#include <stdio.h>
#include <string.h>
#define MAX 1000

int contador(char cadena[], int indice);

int main()
{
	char instructores[MAX];
	int cantidad;
	fgets(instructores, sizeof(instructores), stdin);
	cantidad = contador(instructores, 0);
	printf("%d", cantidad);
}

int contador(char cadena[], int indice)
{
	if (indice < strlen(cadena))
	{
		if (cadena[indice] == ' ' && cadena[indice - 1] != ' ')
		{
			return 1 + contador(cadena, indice + 1);
		}
		return contador(cadena, indice + 1);
	}
	
	if (cadena[strlen(cadena) - 1] != ' ')
	{
		return 1;
	}
	
	return 0;
}


