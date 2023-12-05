#include <stdio.h>
#include <stdbool.h>

#define MAX 101
#define DIRIGIDO 1
#define NO_DIRIGIDO 0

typedef struct
{
	int datos[MAX];
	int final;
	int actual;
} TCola;

typedef struct
{
	int tipo;
	int matrix[MAX][MAX];
	int maximo_vertices;
	int numero_actual_vertices;
	bool vertices[MAX];
	bool visitados[MAX];
} TGrafo;

void inicializar_cola(TCola *cola);
bool verificar_cola_vacia(TCola cola);
bool verificar_cola_llena(TCola cola);
void agregar_dato_cola(TCola *cola, int dato);
void eliminar_cola(TCola *cola, int *dato);

void inicialiar_grafo(TGrafo *grafo, int tipo);
void agregar_datos_grafo(TGrafo *grafo);
void agregar_vertices_grafo(TGrafo *grafo, int vertice);
void agregar_arista_grafo(TGrafo *grafo, int vertice_one, int vertice_two, char letra);
void eliminar_vertice(TGrafo *grafo, int vertices);
void eliminar_arista(TGrafo *grafo, int vertice_one, int vertice_two);

int buscar_dora(TGrafo *grafo,int valor_a,int valor_b);
void recorrido_BFS(TGrafo *grafo, int vertice);

int main()
{
	TGrafo grafo;
	inicialiar_grafo(&grafo, DIRIGIDO);
	agregar_datos_grafo(&grafo);
}

void inicializar_cola(TCola *cola)
{
	cola->final = 0;
	cola->actual = 0;
}

bool verificar_cola_vacia(TCola cola)
{
	return cola.final == cola.actual;
}

bool verificar_cola_llena(TCola cola)
{
	return cola.final == MAX;
}

void agregar_dato_cola(TCola *cola, int dato)
{
	if (verificar_cola_llena(*cola))
	{
		return;
	}
	cola->datos[cola->final] = dato;
	cola->final += 1;
}

void eliminar_cola(TCola *cola, int *dato)
{
	if (verificar_cola_vacia(*cola))
	{
		return;
	}
	
	*dato = cola->datos[cola->actual];
	cola->actual += 1;
}

void inicialiar_grafo(TGrafo *grafo, int tipo)
{
	grafo->tipo = tipo;
	grafo->numero_actual_vertices = 0;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			grafo->matrix[i][j] = 0;
		}
		grafo->vertices[i] = false;
		grafo->visitados[i] = false;
	}
}

void agregar_datos_grafo(TGrafo *grafo)
{
	char letra;
	int valor_a, valor_b;
	scanf("%d %d", &valor_a, &valor_b);
	for (int i = 0; i < valor_a; i++)
	{
		for (int j = 0; j < valor_b; j++)
		{
			scanf(" %c", &letra);
			agregar_arista_grafo(*&grafo, i, j, letra);
		}
	}
	int pos = buscar_dora(*&grafo,valor_a,valor_b);
	if (pos != -1)
	{
		printf("%d",pos);
		recorrido_BFS(*&grafo,pos);
	}
	printf("\n");
	for (int i = 0; i < valor_a; i++)
	{
		for (int j = 0; j < valor_b; j++)
		{
			printf("%c", grafo->matrix[i][j]);
		}
		printf("\n");
	}
}


void agregar_vertices_grafo(TGrafo *grafo, int vertice)
{
	if (vertice >= 0 && vertice < grafo->maximo_vertices && !grafo->vertices[vertice])
	{
		grafo->vertices[vertice] = true;
		grafo->numero_actual_vertices += 1;
	}
}

void agregar_arista_grafo(TGrafo *grafo, int vertice_one, int vertice_two, char letra)
{
	if (!grafo->vertices[vertice_one])
	{
		agregar_vertices_grafo(*&grafo, vertice_one);
	}
	if (!grafo->vertices[vertice_two])
	{
		agregar_vertices_grafo(*&grafo, vertice_two);
	}
	grafo->matrix[vertice_one][vertice_two] = letra;
	if (grafo->tipo == NO_DIRIGIDO)
	{
		grafo->matrix[vertice_two][vertice_one] = letra;
	}
}

void eliminar_vertice(TGrafo *grafo, int vertices)
{
	if (vertices >= 0 && vertices < grafo->maximo_vertices && grafo->vertices[vertices])
	{
		grafo->vertices[vertices] = false;
		grafo->numero_actual_vertices -= 1;
		for (int i = 0; i < grafo->maximo_vertices; i++)
		{
			grafo->matrix[vertices][i] = 0;
			grafo->matrix[i][vertices] = 0;
		}
	}
}

void eliminar_arista(TGrafo *grafo, int vertice_one, int vertice_two)
{
	if (vertice_one >= 0 && vertice_one < grafo->maximo_vertices && grafo->vertices[vertice_one] &&
		vertice_two >= 0 && vertice_two < grafo->maximo_vertices && grafo->vertices[vertice_two])
	{
		grafo->matrix[vertice_one][vertice_two] = 0;
		if (grafo->tipo == NO_DIRIGIDO)
		{
			grafo->matrix[vertice_two][vertice_one] = 0;
		}
	}
}

int buscar_dora(TGrafo *grafo, int valor_a, int valor_b)
{
	for (int i = 0; i < valor_a; i++)
	{
		for (int j = 0; j < valor_b; j++)
		{
			if (grafo->matrix[i][j] == '#')
			{
				return i * valor_b + j;
			}
		}
	}
	return -1;
}

/*void recorrido_BFS(TGrafo *grafo, int vertice)*/
/*{*/
/*	TCola cola;*/
/*	inicializar_cola(&cola);*/
/*	grafo->vertices[vertice] = true;*/
/*	agregar_dato_cola(&cola, vertice);*/
/*	while (!verificar_cola_vacia(cola))*/
/*	{*/
/*		int actual;*/
/*		eliminar_cola(&cola, &actual);*/
/*		for (int i = 0; i < MAX; i++)*/
/*		{*/
/*			if (!grafo->visitados[i] && grafo->matrix[actual][i] != '*')*/
/*			{*/
/*				grafo->matrix[actual][i] = '#';*/
/*				grafo->visitados[i] = true;*/
/*				agregar_dato_cola(&cola, i);*/
/*			}*/
/*		}*/
/*	}*/
/*}*/

void recorrido_BFS(TGrafo *grafo, int vertice)
{
	TCola cola;
	inicializar_cola(&cola);
	grafo->vertices[vertice] = true;
	agregar_dato_cola(&cola, vertice);
	
	while (!verificar_cola_vacia(cola))
	{
		int actual;
		eliminar_cola(&cola, &actual);
		
		for (int i = 0; i < MAX; i++)
		{
			if (!grafo->visitados[i] && (grafo->matrix[actual][i] == '.' || grafo->matrix[actual][i] != '*'))
			{
				grafo->matrix[actual][i] = '#';
				grafo->visitados[i] = true;
				agregar_dato_cola(&cola, i);
			}
		}
	}
}



