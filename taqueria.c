#include <stdio.h>
#include <stdbool.h>
#define MAX 1000

typedef int TDato;
typedef struct
{
	TDato datos[MAX];
	TDato ventas;
	int inicio;
	int fin;
} TCola;

void incializar_cola(TCola *cola);
bool cola_esta_vacia(TCola cola);
bool cola_esta_llena(TCola cola);
void agregar_cola(TCola *cola, int num);
void ordenar_cola(TCola *cola);
void aumentar_venta(TCola *cola);
void desencolar(TCola *cola);

int main()
{
	TCola cola;
	incializar_cola(&cola);
	int operaciones;
	int operacion, cantidad, clientes;
	scanf("%d", &operaciones);
	while (operaciones > 0)
	{
		scanf("%d", &operacion);
		switch (operacion)
		{
		case 1:
			scanf("%d", &cantidad);
			agregar_cola(&cola, cantidad);
			break;
		case 2:
			if (!cola_esta_vacia(cola)) {
				aumentar_venta(&cola);
				desencolar(&cola);
			}
			break;
		case 3:
			clientes = cola.fin - cola.inicio;
			printf("%d\n", clientes);
			break;
		case 4:
			printf("%d\n", cola.ventas);
			break;
			
		default:
			break;
		}
		
		operaciones--;
	}
}

void incializar_cola(TCola *cola)
{
	cola->inicio = 0;
	cola->fin = 0;
	cola->ventas = 0;
}

bool cola_esta_vacia(TCola cola)
{
	return cola.inicio == cola.fin;
}
bool cola_esta_llena(TCola cola)
{
	return cola.fin == MAX;
}

void agregar_cola(TCola *cola, int num)
{
	if (cola_esta_llena(*cola))
	{
		return;
	}
	
	cola->datos[cola->fin] = num;
	cola->fin += 1;
}

void ordenar_cola(TCola *cola)
{
	int tamanio = cola->fin - cola->fin;
	for (int i = 0; i < tamanio; i++)
	{
		cola->datos[i] = cola->datos[cola->inicio + i];
	}
	cola->inicio = 0;
	cola->fin = tamanio;
}

void aumentar_venta(TCola *cola)
{
	cola->ventas += cola->datos[cola->inicio];
}

void desencolar(TCola *cola)
{
	if (cola_esta_vacia(*cola))
	{
		return;
	}
	cola->inicio += 1;
}
