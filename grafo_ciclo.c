#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 101
#define DIRIGIDO 1
#define NO_DIRIGIDO 0

typedef int TDato;

typedef struct
{
	int tipo;
	int matriz[MAX_VERTICES][MAX_VERTICES];
	int numero_vertices;
	int maximo_vertices;
	bool vertices[MAX_VERTICES];
	bool visitado[MAX_VERTICES];
} TGrafo;

typedef struct
{
	TDato datos[MAX_VERTICES];
	int inicio;
	int fin;
} TCola;

// funciones de la cola
void inicializar_cola(TCola *cola);
bool verificar_cola_llena(TCola cola);
bool verificar_cola_vacia(TCola cola);
void agregar_valor_cola(TCola *cola, int dato);
void eliminar_valor_cola(TCola *cola, int *dato);

// funciones del grafo
void inicializar_grafo(TGrafo *grafo, int tipo);
void agregar_datos_grafo(TGrafo *grafo);
void agregar_vertice_grafo(TGrafo *grafo, int vertice);
void agregar_arista_grafo(TGrafo *grafo, int v1, int v2);

// funcion DES
int distancia_minima(TGrafo *grafo, int v1, int v2);
void recorrido_BFS(TGrafo *grafo, int vertice);

int main()
{
	TGrafo grafo;
	inicializar_grafo(&grafo, NO_DIRIGIDO);
	agregar_datos_grafo(&grafo);
	return 0;
}

void inicializar_cola(TCola *cola)
{
	cola->inicio = 0;
	cola->fin = 0;
}
bool verificar_cola_llena(TCola cola)
{
	return cola.fin == MAX_VERTICES;
}
bool verificar_cola_vacia(TCola cola)
{
	return cola.inicio == cola.fin;
}

void agregar_valor_cola(TCola *cola, int dato)
{
	if (verificar_cola_llena(*cola))
	{
		return;
	}
	cola->datos[cola->fin] = dato;
	cola->fin += 1;
}
void eliminar_valor_cola(TCola *cola, int *dato)
{
	if (verificar_cola_vacia(*cola))
	{
		return;
	}
	*dato = cola->datos[cola->inicio];
	cola->inicio += 1;
}

void inicializar_grafo(TGrafo *grafo, int tipo)
{
	grafo->tipo = tipo;
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		for (int j = 0; j < MAX_VERTICES; j++)
		{
			grafo->matriz[i][j] = 0;
		}
		grafo->vertices[i] = false;
		grafo->visitado[i] = false;
	}
	grafo->numero_vertices = 0;
}

void agregar_datos_grafo(TGrafo *grafo)
{
	int valor_a, valor_b, valor_n, valor_m, salida, destino;
	scanf("%d %d", &valor_n, &valor_m);
	grafo->maximo_vertices = valor_n;
	for (int i = 0; i < valor_m; i++)
	{
		scanf("%d %d", &valor_a, &valor_b);
		agregar_arista_grafo(*&grafo, valor_a, valor_b);
	}
	recorrido_BFS(*&grafo, 0);
}

void agregar_vertice_grafo(TGrafo *grafo, int vertice)
{
	if (vertice >= 0 && vertice < MAX_VERTICES && !grafo->vertices[vertice])
	{
		grafo->vertices[vertice] = true;
		grafo->numero_vertices += 1;
	}
}
void agregar_arista_grafo(TGrafo *grafo, int v1, int v2)
{
	if (!grafo->vertices[v1])
	{
		agregar_vertice_grafo(*&grafo, v1);
	}
	if (!grafo->vertices[v2])
	{
		agregar_vertice_grafo(*&grafo, v2);
	}
	grafo->matriz[v1][v2] = 1;
	if (grafo->tipo == NO_DIRIGIDO)
	{
		grafo->matriz[v2][v1] = 1;
	}
}

void recorrido_BFS(TGrafo *grafo, int vertice)
{
	TCola cola;
	inicializar_cola(&cola);
	grafo->visitado[vertice] = true;
	agregar_valor_cola(&cola, vertice);

	while (!verificar_cola_vacia(cola))
	{
		int actual;
		eliminar_valor_cola(&cola, &actual);

		for (int i = 0; i < grafo->maximo_vertices; i++)
		{
			if (grafo->matriz[actual][i] != 0 && !grafo->visitado[i])
			{
				agregar_valor_cola(&cola, i);
				grafo->visitado[i] = true;
			}
			else if (grafo->matriz[actual][i] != 0 && grafo->visitado[i])
			{
				printf("Se ha encontrado un ciclo.\n");
				return;
			}
		}
	}
	printf("No se ha encontrado un ciclo.\n");
}
