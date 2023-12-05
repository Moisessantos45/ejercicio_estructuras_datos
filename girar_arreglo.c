#include <stdio.h>
#define MAX 100

void llenarArreglo(int caja[], int *tamanio, int *giradas);
void llenarCaja(int caja[], int caja2[], int tamanio);
void girar(int caja_girada[], int tamanio, int giradas);
void imprimir(int caja[], int tamanio);

int main()
{
	int caja[MAX], tamanio, giradas;
	int caja_girada[MAX];
	llenarArreglo(caja, &tamanio, &giradas);
	llenarCaja(caja_girada, caja, tamanio);
	girar(caja_girada, tamanio, giradas);
	imprimir(caja_girada, tamanio);
	return 0;
}

void llenarArreglo(int caja[], int *tamanio, int *giradas)
{
	scanf("%d", &*tamanio);
	scanf("%d", &*giradas);
	for (int i = 0; i < *tamanio; i++)
	{
		scanf("%d", &caja[i]);
	}
}

void llenarCaja(int caja[], int caja2[], int tamanio)
{
	for (int i = 0; i < tamanio; i++)
	{
		caja[i] = caja2[i];
	}
}

void girar(int caja_girada[], int tamanio, int giradas)
{
	int temp[MAX];
	int nueva_posicion;

	for (int i = 0; i < tamanio; i++)
	{
		temp[i] = caja_girada[i];
	}

	for (int i = 0; i < tamanio; i++)
	{
		nueva_posicion = (i + giradas) % tamanio;
		caja_girada[nueva_posicion] = temp[i];
	}
}

void imprimir(int caja_girada[], int tamanio)
{
	for (int i = 0; i < tamanio; i++)
	{
		printf("%d ", caja_girada[i]);
	}
}
			

