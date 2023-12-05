//Estructuras de datos 1
//Moises santos hernandez
//24/10/23
//  Round Robin - imprimir en orden en que terminan los procesos de un maquina
// el tiempo para que termine se ingresa mediante eso tenemos que imprimir

#include <stdio.h>
#include <stdbool.h>
#define MAX 1000

typedef int TDato;

typedef struct
{
	TDato id[MAX];
	TDato tiempo[MAX];
	int inicio;
	int ultimo;
} TCola;

void inicializar_cola(TCola *cola);
bool verificar_cola_vacia(TCola cola);
bool verificar_cola_llena(TCola cola);
void leer_datos(TCola *cola, int cantidad);
void agregar_cola(TCola *cola, int id, int tiempo);
void ordenar_cola(TCola *cola);
void eliminar_dato_cola(TCola *cola);
void imprimir_cola(TCola *cola, int tiempo);

int main()
{
	TCola cola;
	int cantidad, tiempo;
	inicializar_cola(&cola);
	scanf("%d %d", &cantidad, &tiempo);
	leer_datos(&cola, cantidad);
	imprimir_cola(&cola, tiempo);
}

void inicializar_cola(TCola *cola)
{
	cola->ultimo = 0;
	cola->inicio = 0;
}

bool verificar_cola_vacia(TCola cola)
{
	return cola.inicio == cola.ultimo;
}

bool verificar_cola_llena(TCola cola)
{
	return cola.ultimo == MAX;
}

void leer_datos(TCola *cola, int cantidad)
{
	int id, tiempo;
	while (cantidad > 0)
	{
		scanf("%d %d", &id, &tiempo);
		agregar_cola(*&cola, id, tiempo);
		cantidad--;
	}
}

void agregar_cola(TCola *cola, int id, int tiempo)
{
	if (verificar_cola_llena(*cola))
	{
		return;
	}
	
	if (cola->ultimo == MAX && cola->inicio > 0)
	{
		ordenar_cola(*&cola);
	}
	cola->id[cola->ultimo] = id;
	cola->tiempo[cola->ultimo] = tiempo;
	cola->ultimo += 1;
}

void ordenar_cola(TCola *cola)
{
	int tamanio = cola->ultimo - cola->inicio;
	for (int i = 0; i < tamanio; i++)
	{
		cola->id[i] = cola->id[cola->inicio + 1];
		cola->tiempo[i] = cola->tiempo[cola->inicio + 1];
	}
	cola->inicio = 0;
	cola->ultimo = tamanio;
}

void eliminar_dato_cola(TCola *cola)
{
	if (verificar_cola_vacia(*cola))
	{
		return;
	}
	int inicio=cola->inicio;
	cola->inicio=inicio+1;
}

void imprimir_cola(TCola *cola, int tiempo)
{
	while (!verificar_cola_vacia(*cola))
	{
		if (cola->ultimo == MAX && cola->inicio > 0)
		{
			ordenar_cola(*&cola);
		}
		
		if (cola->tiempo[cola->inicio] <= tiempo)
		{
			printf("%d\n", cola->id[cola->inicio]);
			eliminar_dato_cola(*&cola);
		}
		else
		{
			int tiempo_restante = cola->tiempo[cola->inicio] - tiempo;
			agregar_cola(*&cola, cola->id[cola->inicio], tiempo_restante);
			eliminar_dato_cola(*&cola);
		}
	}
}
