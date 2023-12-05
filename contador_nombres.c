#include <stdio.h>
#include <string.h>

int contador(char cadena[], int indice);

int main()
{
	char palabra[100];
	int cantidad = 0;
	gets(palabra);
	cantidad = contador(palabra, 0);
	printf("%s %d",palabra, cantidad);
	return 0;
}

int contador(char cadena[], int indice)
{
	if (indice < strlen(cadena))
	{
		if (cadena[indice] == ' ')
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
