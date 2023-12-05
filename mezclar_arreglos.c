#include <stdio.h>
#define MAX 10000

void llenar_arreglo(int caja[], int tamanio);
void unir_arreglos(int caja[], int caja2[], int caja_ordenada[], int tamanio, int tamanio2);
void mezclar(int caja_ordenada[], int caja1[], int tamanio1, int caja2[], int tamanio2);
void ordenar(int caja1[], int caja2[], int caja_ordenada[], int tamanio1, int tamanio2, int *valor_i, int *valor_j,int *valor_k);
void ordenar_arreglos(int caja[], int caja_ordenada[], int tamanio1, int *valor_cont,int *valor_k);
void imprimir(int caja_ordenada[], int tamanio);

int main()
{
	int caja1[MAX];
	int caja2[MAX];
	int caja_ordenada[MAX];
	int tamanio1, tamanio2;
	
	scanf("%d %d", &tamanio1, &tamanio2);	
	llenar_arreglo(caja1, tamanio1);
	llenar_arreglo(caja2,tamanio2);
	
	unir_arreglos(caja1, caja2, caja_ordenada, tamanio1, tamanio2);
	mezclar(caja_ordenada, caja1, tamanio1, caja2, tamanio2);
	imprimir(caja_ordenada, tamanio1 + tamanio2);
	
	return 0;
}

void llenar_arreglo(int caja[], int tamanio)
{

	for (int i = 0; i < tamanio; i++)
	{
		scanf("%d", &caja[i]);
	}
}

void unir_arreglos(int caja[], int caja2[], int caja_ordenada[], int tamanio, int tamanio2)
{
	for (int i = 0; i < tamanio; i++)
	{
		caja_ordenada[i] = caja[i];
	}
	
	for (int i = 0; i < tamanio2; i++)
	{
		caja_ordenada[tamanio + i] = caja2[i];
	}
}

void mezclar(int caja_ordenada[], int caja1[], int tamanio1, int caja2[], int tamanio2)
{
	int i = 0, j = 0, k = 0;
	ordenar(caja1,caja2, caja_ordenada, tamanio1, tamanio2, &i, &j,&k);
	ordenar_arreglos(caja1,caja_ordenada,tamanio1,&i,&k);
	ordenar_arreglos(caja2,caja_ordenada,tamanio2,&j,&k);
}

void ordenar(int caja1[], int caja2[], int caja_ordenada[], int tamanio1, int tamanio2, int *valor_i, int *valor_j,int *valor_k){

	while (*valor_i < tamanio1 && *valor_j < tamanio2)
	{
		if (caja1[*valor_i] < caja2[*valor_j])
		{
			caja_ordenada[(*valor_k)++] = caja1[(*valor_i)++];
		}
		else
		{
			caja_ordenada[(*valor_k)++] = caja2[(*valor_j)++];
		}
	}
}
	
void ordenar_arreglos(int caja[], int caja_ordenada[], int tamanio1, int *valor_cont,int *valor_k){
	while (*valor_cont < tamanio1)
	{
		caja_ordenada[(*valor_k)++] = caja[(*valor_cont)++];
	}
}

void imprimir(int caja_ordenada[], int tamanio)
{
	for (int i = 0; i < tamanio; i++)
	{
		printf("%d ", caja_ordenada[i]);
	}
}
