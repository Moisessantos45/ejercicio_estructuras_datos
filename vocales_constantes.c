#include <stdio.h>
#include <stdbool.h>

int contador(char cadena[], int *cont, int indice);
bool verificar(char caracter);

int main()
{
	char palabra[80];
	int vocales = 0;
	int constantes;
	scanf("%s", palabra);
	constantes = contador(palabra, &vocales, 0);
	printf("%d %d", constantes, vocales);
	return 0;
}

int contador(char cadena[], int *cont, int indice)
{
	if (cadena[indice] == '\0')
	{
		return 0;
	}
	
	if (verificar(cadena[indice]))
	{
		(*cont)++;
		return contador(cadena, cont, indice + 1);
	}
	else
	{
		return 1 + contador(cadena, cont, indice + 1);
	}
}

bool verificar(char caracter)
{
	return (caracter == 'A' || caracter == 'E' || caracter == 'I' || caracter == 'O' || caracter == 'U');
}
