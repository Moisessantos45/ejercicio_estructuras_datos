#include <stdio.h>
#define MAX 1000000

void llenar_arreglo(long long caja[], long long tamanio, int indice);
void invertir(long long caja[], int inicio, long long final_p);
void vuelta(long long caja[], int inicio, long long final_p);
void intercambiar(long long *posicion_i, long long *posicion_j);
void imprimir(long long caja[], long long tamanio, int indice);

int main()
{
	long long caja[MAX];
	long long tamanio;
	scanf("%lld", &tamanio);
	llenar_arreglo(caja, tamanio, 0);
	invertir(caja, 0, tamanio - 1);
	imprimir(caja, tamanio, 0);
	return 0;
}

void llenar_arreglo(long long caja[], long long tamanio, int indice)
{
	if (indice == tamanio)
	{
		return;
	}
	scanf("%lld", &caja[indice]);
	llenar_arreglo(caja, tamanio, indice + 1);
}

void invertir(long long caja[], int inicio, long long final_p)
{
	vuelta(caja, inicio, final_p);
	if (final_p - inicio + 1 > 2)
	{
		invertir(caja, inicio, inicio + (final_p - inicio) / 2);
		invertir(caja, inicio + (final_p - inicio) / 2 + 1, final_p);
	}
}

void vuelta(long long caja[], int inicio, long long final_p)
{
	if (inicio >= final_p)
	{
		return;
	}
	intercambiar(&caja[inicio], &caja[final_p]);
	vuelta(caja, inicio + 1, final_p - 1);
}

void intercambiar(long long *posicion_i, long long *posicion_j)
{
	long long temp = *posicion_i;
	*posicion_i = *posicion_j;
	*posicion_j = temp;
}

void imprimir(long long caja[], long long tamanio, int indice)
{
	if (indice == tamanio)
	{
		return;
	}
	printf("%lld ", caja[indice]);
	imprimir(caja, tamanio, indice + 1);
}


