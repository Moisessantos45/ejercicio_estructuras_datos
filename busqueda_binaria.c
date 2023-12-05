#include <stdio.h>
#include <math.h>
#define MAX 1000
void llenarArreglo(int caja[], int tamanio);
void buscar_coicidencia(int secuencia_incial[], int secuencia_buscar[], int posiciones[], int tamanio_1, int tamanio_2);
void imprimir_coicidencias(int caja[], int tamanio, int indice);

int main()
{
	int tamanio, tamanio2;
	int secuencia[MAX], secuencia2[MAX];
	int posiciones[MAX];
	int izq = 0, der;
	scanf("%d", &tamanio);
	llenarArreglo(secuencia, tamanio);
	scanf("%d", &tamanio2);
	llenarArreglo(secuencia2, tamanio2);
	
	buscar_coicidencia(secuencia, secuencia2, posiciones, tamanio, tamanio2);
	imprimir_coicidencias(posiciones, tamanio2, 0);
	return 0;
}

void llenarArreglo(int caja[], int tamanio){
	for (int i = 0; i < tamanio; i++)
	{
		scanf("%d", &caja[i]);
	}
}

void buscar_coicidencia(int secuencia_inicial[], int secuencia_buscar[], int posiciones[], int tamanio_1, int tamanio_2)
{
	for (int i = 0; i < tamanio_2; i++)
	{
		int izquierda = 0;
		int derecha = tamanio_1 - 1;
		posiciones[i] = 0;
		
		while (izquierda <= derecha)
		{
			int mitad = izquierda + (derecha - izquierda) / 2;
			
			if (secuencia_inicial[mitad] == secuencia_buscar[i])
			{
				posiciones[i] = 1;
				break;
			}
			else if (secuencia_inicial[mitad] < secuencia_buscar[i])
			{
				izquierda = mitad + 1;
			}
			else
			{
				derecha = mitad - 1;
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
