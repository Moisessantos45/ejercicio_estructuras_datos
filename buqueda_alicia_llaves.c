#include <stdio.h>
#include <math.h>  
#define MAX 100000

void llevar_arreglo(int caja[], int tamanio, int indice);
void buscar_coicidencia(int caja_chapas[], int caja_llaves[], int caja_final[], int tamanio_chapas, int tamanio_llaves);
void imprimir_coicidencias(int caja[], int tamanio, int indice);

int main()
{
	int tamanio_chapas, tamanio_llaves;
	int caja_chapas[MAX], caja_llaves[MAX];
	int caja_correcta[MAX];
	scanf("%d", &tamanio_chapas);
	llevar_arreglo(caja_chapas, tamanio_chapas, 0);
	scanf("%d", &tamanio_llaves);
	llevar_arreglo(caja_llaves, tamanio_llaves, 0);
	buscar_coicidencia(caja_chapas, caja_llaves, caja_correcta, tamanio_chapas, tamanio_llaves);
	imprimir_coicidencias(caja_correcta, tamanio_llaves, 0);
}

void llevar_arreglo(int caja[], int tamanio, int indice)
{
	if (indice == tamanio)
	{
		return;
	}
	
	scanf("%d", &caja[indice]);
	llevar_arreglo(caja, tamanio, indice + 1);
}

void buscar_coicidencia(int caja_chapas[], int caja_llaves[], int caja_final[], int tamanio_chapas, int tamanio_llaves)
{
	int inicio, fin, mitad;
	for (int i = 0; i < tamanio_llaves; i++)
	{
		inicio = 0;
		fin = tamanio_chapas - 1;
		while (inicio <= fin)
		{
			mitad = trunc((inicio + fin) / 2);
			if (caja_llaves[i]==caja_chapas[mitad])
			{
				caja_final[i] = mitad + 1;
				break;
			}
			else if (caja_chapas[mitad] < caja_llaves[i])
			{
				inicio = mitad + 1;
			}
			else
			{
				fin = mitad - 1;
			}
		}
	}
}

void imprimir_coicidencias(int caja[], int tamanio, int indice)
{
	if (indice == tamanio)
	{
		return;
	}
	
	printf("%d ", caja[indice]);
	imprimir_coicidencias(caja, tamanio, indice + 1);
}
