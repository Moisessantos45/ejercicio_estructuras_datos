#include <stdio.h>
#define MAX 100

void agrega(int caja[], int *tamanio);
void buscarNum(int caja[], int tamanio, int buscar);
void imprimir(int caja[], int tamanio);

int main()
{
	int caja[MAX];
	int tamanio, buscar;
	agrega(caja, &tamanio);
	scanf("%d", &buscar);
	buscarNum(caja, tamanio, buscar);
	imprimir(caja, tamanio);
	return 0;
}

void agrega(int caja[], int *tamanio)
{
	scanf("%d", tamanio);
	for (int i = 0; i < *tamanio; i++)
	{
		scanf("%d", &caja[i]);
	}
}

void buscarNum(int caja[], int tamanio, int buscar)
{
	for (int i = 0; i < tamanio; i++)
	{
		if (caja[i] % buscar != 0)
		{
			caja[i] = -1;
		}
	}
}

void imprimir(int caja[], int tamanio)
{
	for (int i = 0; i < tamanio; i++)
	{
		if (caja[i] == -1)
		{
			printf("X");
		}
		else
		{
			printf(" %d ", caja[i]);
		}
	}
}

