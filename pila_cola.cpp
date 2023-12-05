#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10000
#define CARCTER 10

typedef int TDato;
typedef struct captura
{
	TDato datos[MAX];
	int maximo;
	int cima;
	int inicio;
	int fin;
	char tipo[CARCTER];
} TPila_cola;

void inicializar_pila(TPila_cola *pila_cola);
bool verificar_pila_cola_vacia(TPila_cola pila_cola);
bool verificar_pila_cola_llena(TPila_cola pila_cola);
void agregar_dato_pila_cola(TPila_cola *pila_cola, int cantidad);
void agregar_pila_cola(TPila_cola *pila_cola, int num);
void ordenar_pila_cola(TPila_cola *pila_cola);
void vaciar_pila_cola(TPila_cola *pila_cola);
void imprimir_dato_pila_cola(TPila_cola pila_cola);

int main()
{
	TPila_cola pila_cola;
	int cantidad;
	inicializar_pila(&pila_cola);
	scanf("%d", &cantidad);
	agregar_dato_pila_cola(&pila_cola,cantidad);
}

void inicializar_pila(TPila_cola *pila_cola)
{
	pila_cola->maximo = MAX;
	pila_cola->cima = 0;
	pila_cola->inicio = 0;
	pila_cola->fin = 0;
	strcpy(pila_cola->tipo, "pila");
}

bool verificar_pila_cola_vacia(TPila_cola pila_cola)
{
	return pila_cola.cima == 0 || pila_cola.inicio == pila_cola.fin;
}

bool verificar_pila_cola_llena(TPila_cola pila_cola)
{
	return pila_cola.cima == MAX || pila_cola.fin == MAX;
}

void agregar_dato_pila_cola(TPila_cola *pila_cola, int cantidad)
{
	char opcion[CARCTER];
	TDato numero;
	while (cantidad > 0)
	{
		scanf("%s", opcion);
		if (strcmp(opcion, "AGREGA") == 0)
		{
			scanf("%d", &numero);
			agregar_pila_cola(*&pila_cola, numero);
		}
		else if (strcmp(opcion, "QUITA") == 0)
		{
			imprimir_dato_pila_cola(*pila_cola);
			vaciar_pila_cola(*&pila_cola);
		}
		else if (strcmp(opcion, "CAMBIA") == 0)
		{
			if (strcmp(pila_cola->tipo, "pila"))
			{
				strcpy(pila_cola->tipo, "cola");
			}
			else
			{
				strcpy(pila_cola->tipo, "pila");
			}
		}
		cantidad--;
	}
}

void agregar_pila_cola(TPila_cola *pila_cola, int num)
{
	if (verificar_pila_cola_llena(*pila_cola))
	{
		return;
	}
	
	if (strcpy(pila_cola->tipo, "cola")==0)
	{
		if (pila_cola->fin == MAX && pila_cola->inicio > 0)
		{
			ordenar_pila_cola(*&pila_cola);
		}
		pila_cola->datos[pila_cola->inicio] = num;
		pila_cola->fin += 1;
	}
	else
	{
		pila_cola->datos[pila_cola->cima] = num;
		pila_cola->cima += 1;
	}
}

void ordenar_pila_cola(TPila_cola *pila_cola)
{
	int tamanio = pila_cola->fin - pila_cola->inicio;
	for (int i = 0; i < tamanio; i++)
	{
		pila_cola->datos[i]= pila_cola->datos[pila_cola->inicio + i];
	}
	pila_cola->inicio = 0;
	pila_cola->fin = tamanio;
}

void vaciar_pila_cola(TPila_cola *pila_cola)
{
	if (verificar_pila_cola_vacia(*pila_cola))
	{
		return;
	}
	if (strcpy(pila_cola->tipo, "cola"))
	{
		if (pila_cola->fin == MAX && pila_cola->inicio > 0)
		{
			ordenar_pila_cola(*&pila_cola);
		}
		pila_cola->inicio+=1;
	}
	else
	{
		pila_cola->cima -= 1;
	}
}

void imprimir_dato_pila_cola(TPila_cola pila_cola){
	if (verificar_pila_cola_vacia(pila_cola))
	{
		return;
	}
	
	if (strcpy(pila_cola.tipo, "cola"))
	{
		printf("%d\n", pila_cola.datos[pila_cola.inicio]);
	}
	else
	{
		printf("%d\n", pila_cola.datos[pila_cola.cima-1]);
	}
}
