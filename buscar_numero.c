#include <stdio.h>
#define MAX 1000

void agrega(int caja[], int *tamanio);
int buscarNum(int caja[], int tamanio, int buscar);

int main()
{
	int caja[MAX];
	int tamanio, buscar, resultado;
	agrega(caja, &tamanio);
	scanf("%d", &buscar);
	resultado = buscarNum(caja, tamanio, buscar);
	printf("%d",resultado);
	return 0;
}

void agrega(int caja[], int *tamanio)
{
	scanf("%d", &*tamanio);
	for (int i = 0; i < *tamanio; i++)
	{
		scanf("%d", &caja[i]);
	}
}

int buscarNum(int caja[], int tamanio, int buscar)
{
	int cont = 0;
	for (int i = 0; i < tamanio; i++)
	{
		if (caja[i] == buscar)
		{
			cont++;
		}
	}
	return cont;
}
