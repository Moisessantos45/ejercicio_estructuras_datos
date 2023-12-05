#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define DIRIGIDO 1
#define NO_DIRIGIDO 0

typedef int TDato; 
typedef struct
{
	TDato datos[MAX_VERTICES];
	int cima;
	int maximo;
} TPila;

typedef struct
{
	int tipo;
	char matriz[MAX_VERTICES][MAX_VERTICES];
	int numero_vertices;
	int maximo_vertices;
	bool vertices[MAX_VERTICES];
	bool visitado[MAX_VERTICES];
} TGrafo;

void inicializar_pila(TPila *pila);
bool verificar_esta_llena(TPila pila);
bool verificar_esta_vacia(TPila pila);
void agregar_pila(TPila *pila, TDato dato);
void eliminar_pila(TPila *pila, TDato *dato);

void inicializar_grafo(TGrafo *grafo, int tipo);
void agregar_datos_grafo(TGrafo *grafo);
void agregar_vertice_grafo(TGrafo *grafo, int vertice);
void agregar_arista_grafo(TGrafo *grafo, int vertice_one, int vertice_two, char letra);
void eliminar_vertice_grafo(TGrafo *grafo, int vertice);
void eliminar_arista_grafo(TGrafo *grafo, int vertice_one, int vertice_two);

void recorrido_DFS(TGrafo *grafo, int vertice);
int contarIslas(TGrafo *grafo);

int main()
{
	TGrafo grafo;
	inicializar_grafo(&grafo, NO_DIRIGIDO);
	agregar_datos_grafo(&grafo);
	return 0;
}

void inicializar_pila(TPila *pila)
{
	pila->maximo = MAX_VERTICES;
	pila->cima = 0;
}

bool verificar_esta_llena(TPila pila)
{
	return pila.cima == MAX_VERTICES;
}

bool verificar_esta_vacia(TPila pila)
{
	return pila.cima == 0;
}

void agregar_pila(TPila *pila, TDato dato)
{
	if (verificar_esta_llena(*pila))
	{
		return;
	}
	pila->datos[pila->cima] = dato;
	pila->cima += 1;
}

void eliminar_pila(TPila *pila, TDato *dato)
{
	if (verificar_esta_vacia(*pila))
	{
		return;
	}
	
	*dato = pila->datos[pila->cima - 1];
	pila->cima -= 1;
}

void inicializar_grafo(TGrafo *grafo, int tipo)
{
	grafo->tipo = tipo;
	grafo->numero_vertices = 0;
	grafo->maximo_vertices = MAX_VERTICES;
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		for (int j = 0; j < MAX_VERTICES; j++)
		{
			grafo->matriz[i][j] = 0;
		}
		grafo->vertices[i] = false;
		grafo->visitado[i] = false;
	}
}

void agregar_datos_grafo(TGrafo *grafo)
{
	int valor_n, valor_m;
	char valor_a;	
	scanf("%d %d", &valor_n, &valor_m);
	grafo->maximo_vertices=valor_n*valor_m;
	for(int i=0; i<valor_n;i++)
	{
		for(int j=0; j<valor_m;j++){
			scanf(" %c", &valor_a);
			agregar_arista_grafo(grafo, i, j, valor_a);
		}
		
	}
	// int cantidad = recorrido_DFS(*&grafo, 0);
	int cantidad=contarIslas(*&grafo);
	printf("cantidad %d", cantidad);
}

void agregar_vertice_grafo(TGrafo *grafo, int vertice)
{
	if (vertice >= 0 && vertice < grafo->maximo_vertices && !grafo->vertices[vertice])
	{
		grafo->vertices[vertice] = true;
		grafo->numero_vertices += 1;
	}
}

void agregar_arista_grafo(TGrafo *grafo, int vertice_one, int vertice_two, char letra)
{
	if (!grafo->vertices[vertice_one])
	{
		agregar_vertice_grafo(*&grafo, vertice_one);
	}
	if (!grafo->vertices[vertice_two])
	{
		agregar_vertice_grafo(*&grafo, vertice_two);
	}
	grafo->matriz[vertice_one][vertice_two] = letra;
	if (grafo->tipo == NO_DIRIGIDO)
	{
		grafo->matriz[vertice_two][vertice_one] = letra;
	}
}

void eliminar_vertice_grafo(TGrafo *grafo, int vertice)
{
	if (vertice >= 0 && vertice < grafo->maximo_vertices && grafo->vertices[vertice])
	{
		grafo->numero_vertices -= 1;
		grafo->vertices[vertice] = false;
		for (int i = 0; i < grafo->maximo_vertices; i++)
		{
			grafo->matriz[vertice][i] = 0;
			grafo->matriz[i][vertice] = 0;
		}
	}
}

void eliminar_arista_grafo(TGrafo *grafo, int vertice_one, int vertice_two)
{
	if (vertice_one >= 0 && vertice_one < grafo->maximo_vertices && grafo->vertices[vertice_one] &&
		vertice_two >= 0 && vertice_two < grafo->maximo_vertices && grafo->vertices[vertice_two])
	{
		grafo->matriz[vertice_one][vertice_two] = 0;
		if (grafo->tipo == NO_DIRIGIDO)
		{
			grafo->matriz[vertice_two][vertice_one] = 0;
		}
	}
}

// int recorrido_DFS(TGrafo *grafo, int vertice)
// {
// 	TPila pila;
// 	int encontrados = 0;
// 	grafo->visitado[vertice] = true;

// 	if (grafo->matriz[vertice][vertice] == 'L')
// 	{
// 		encontrados += 1;
// 	}

// 	inicializar_pila(&pila);
// 	agregar_pila(&pila, vertice);

// 	while (!verificar_esta_vacia(pila))
// 	{
// 		int vertice_actual;
// 		eliminar_pila(&pila, &vertice_actual);

// 		for (int i = 0; i < grafo->maximo_vertices; i++)
// 		{
// 			if (grafo->matriz[vertice_actual][i] == 'L' && !grafo->visitado[i])
// 			{
// 				encontrados += 1;
// 				agregar_pila(&pila, i);
// 				grafo->visitado[i] = true;
// 			}
// 		}
// 	}

// 	return encontrados;
// }

int contarIslas(TGrafo *grafo) {
	int numeroDeIslas = 0;
	
	for (int i = 0; i < grafo->maximo_vertices; i++) {
		if (grafo->matriz[i][i] == 'L' && !grafo->visitado[i]) {
			recorrido_DFS(*&grafo, i);
			numeroDeIslas++;
		}
	}
	
	return numeroDeIslas;
}

void recorrido_DFS(TGrafo *grafo, int vertice) {
	TPila pila;
	inicializar_pila(&pila);
	agregar_pila(&pila, vertice);
	
	while (!verificar_esta_vacia(pila)) {
		int vertice_actual;
		eliminar_pila(&pila, &vertice_actual);
		grafo->visitado[vertice_actual] = true;
		for (int i = 0; i < grafo->maximo_vertices; i++) {
			if (grafo->matriz[vertice_actual][i] == 'L' && !grafo->visitado[i]) {
				agregar_pila(&pila, i);
			}
		}
	}
}

