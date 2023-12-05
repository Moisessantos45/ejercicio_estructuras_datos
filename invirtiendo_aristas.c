#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 1000
#define DIRIGIDO 1
#define NO_DIRIGIDO 0

typedef int TDato;
typedef struct
{
	int tipo;
	int matriz[MAX_VERTICES][MAX_VERTICES];
	int nume_vertices;
	bool vertices[MAX_VERTICES];
	int maximo_vertices;
} TGrafo;

void inicializar_grafo(TGrafo *grafo, int tipo);
void agregar_valores_grafo(TGrafo *grafo);
void agregar_vertices(TGrafo *grafo, int vertice);
void agregar_arista(TGrafo *grafo, int v1, int v2);
void agregar_arista_i(TGrafo *grafo, int v1);
void eliminar_vertice(TGrafo *grafo, int vertice);
void eliminar_arista(TGrafo *grafo, int v1, int v2);
void imprimir_grafo(TGrafo grafo);

int main()
{
	TGrafo grafo;
	inicializar_grafo(&grafo, NO_DIRIGIDO);
	agregar_valores_grafo(&grafo);
	imprimir_grafo(grafo);
	return 0;
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
	}
	grafo->nume_vertices = 0;
}

void agregar_valores_grafo(TGrafo *grafo)
{
	int max_vertices,arista1, arista2;
	long long operaciones;
	char opcion;
	scanf("%d %lld",&max_vertices, &operaciones);
	grafo->maximo_vertices=max_vertices;
	while (operaciones > 0)
	{
		getchar();
		scanf("%c", &opcion);
		switch (opcion)
		{
		case 'A':
			scanf("%d %d",&arista1, &arista2);
			agregar_arista(*&grafo, arista1, arista2);
			break;
		case 'V':
			scanf("%d",&arista2);
			agregar_arista_i(*&grafo,arista2);
			break;
		}
		operaciones--;
	}
}

void agregar_vertices(TGrafo *grafo, int vertice)
{
	if (vertice >= 0 && vertice < grafo->maximo_vertices && !grafo->vertices[vertice])
	{
		grafo->vertices[vertice] = true;
		grafo->nume_vertices += 1;
	}
}

void agregar_arista(TGrafo *grafo, int v1, int v2)
{
	if (!grafo->vertices[v1])
	{
		agregar_vertices(grafo, v1);
	}
	if (!grafo->vertices[v2])
	{
		agregar_vertices(grafo, v2);
	}
	int *fila_v1 = grafo->matriz[v1];
	if (fila_v1[v2] == 1) 
	{
		eliminar_arista(grafo, v1, v2);
	} 
	else 
	{
		fila_v1[v2] = 1;
		if (grafo->tipo == NO_DIRIGIDO)
		{
			grafo->matriz[v2][v1] = 1;
		}
	}
}

void agregar_arista_i(TGrafo *grafo, int v1)
{
	int *fila = grafo->matriz[v1];
	for (int i = 0; i < grafo->maximo_vertices; i++)
	{
		if (v1 != i)
		{
			if (fila[i] == 1)
			{
				eliminar_arista(grafo, v1, i);
			}
			else
			{
				agregar_arista(grafo, v1, i);
			}
		}
	}
}

void eliminar_vertice(TGrafo *grafo, int vertice)
{
	if (vertice >= 0 && vertice < grafo->maximo_vertices && grafo->vertices[vertice] == true)
	{
		grafo->nume_vertices -= 1;
		grafo->vertices[vertice] = false;
		for (int i = 0; i < grafo->maximo_vertices; i++)
		{
			grafo->matriz[vertice][i] = 0;
			grafo->matriz[i][vertice] = 0;
		}
	}
}

void eliminar_arista(TGrafo *grafo, int v1, int v2)
{
	if (v1 >= 0 && v1 < grafo->maximo_vertices && v2 >= 0 && v2 < grafo->maximo_vertices && grafo->vertices[v1] && grafo->vertices[v2])
	{
		grafo->matriz[v1][v2] = 0;
		if (grafo->tipo == NO_DIRIGIDO)
		{
			grafo->matriz[v2][v1] = 0;
		}
	}
}

void imprimir_grafo(TGrafo grafo)
{
	for (int i = 0; i < grafo.maximo_vertices; i++)
	{
		for (int j = 0; j <i; j++)
		{
			if (grafo.matriz[i][j])
			{
				printf("%d %d \n", i, j);
			}
		}
	}
}
