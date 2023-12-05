#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
#define DIRIGIDO 1
#define NO_DIRIGIDO 0

typedef int TDato;

typedef struct{
	int tipo;
	int matriz[MAX_VERTICES][MAX_VERTICES];
	int numero_vertices;
	int maximo_vertices;
	bool vertices[MAX_VERTICES];
	bool visitado[MAX_VERTICES];
}TGrafo;

typedef struct{
	TDato datos[MAX_VERTICES];
	int cima;
	int maximo;
}TPila;

//funciones de la pila
void inicializar_pila(TPila *pila);
bool verificar_pila_llena(TPila pila);
bool verificar_pila_vacia(TPila pila);
void agregar_valor_pila(TPila *pila, int dato);
void eliminar_valor_pila(TPila *pila, int *dato);

//funciones del grafo
void inicializar_grafo(TGrafo *grafo, int tipo);
void agregar_vertice_grafo(TGrafo *grafo, int vertice);
void agregar_arista_grafo(TGrafo *grafo, int v1, int v2);
void eliminar_vertice_grafo(TGrafo *grafo, int vertice);
void eliminar_arista_grafo(TGrafo *grafo, int v1, int v2);

//funcion DES
void funcion_dfs(TGrafo *grafo, int vertice_inicio);

//funcion de recorrido
bool existe_camino(TGrafo *grafo, int v1, int v2);

//funcion bfs recursivo
void funcion_dfs_recursivo(TGrafo *grafo, int vertice_inicial);	
void dfs_recursivo(TGrafo *grafo,int vertice_inicial);

int main(){
	TGrafo grafo;
	inicializar_grafo(&grafo,NO_DIRIGIDO);
	
	return 0;
}

void inicializar_pila(TPila *pila){
	pila->maximo=MAX_VERTICES;
	pila->cima=0;
}
bool verificar_pila_llena(TPila pila){
	return pila.maximo==MAX_VERTICES;
}
bool verificar_pila_vacia(TPila pila){
	return pila.cima==0;
}
void agregar_valor_pila(TPila *pila, int dato){
	if(verificar_pila_llena(*pila)){
		return;
	}
	pila->datos[pila->cima]=dato;
	pila->cima+=1;
}
void eliminar_valor_pila(TPila *pila, int *dato){
	if(verificar_pila_vacia(*pila)){
		return;
	}
	*dato=pila->datos[pila->cima];
	pila->cima-=1;
}

	
void inicializar_grafo(TGrafo *grafo, int tipo){
	grafo->tipo=tipo;
	for(int i=0; i<MAX_VERTICES;i++){
		for(int j=0; j<MAX_VERTICES;j++){
			grafo->matriz[i][j]=0;
		}
		grafo->vertices[i]=false;
		grafo->visitado[i]=false;
	}
	grafo->numero_vertices=0;
	
}

void agregar_vertice_grafo(TGrafo *grafo, int vertice){
	if(vertice>=0 && vertice<MAX_VERTICES && !grafo->vertices[vertice]){
		grafo->vertices[vertice]=true;
		grafo->numero_vertices+=1;
	}
}
void agregar_arista_grafo(TGrafo *grafo, int v1, int v2){
	if(!grafo->vertices[v1]){
		agregar_vertice_grafo(*&grafo, v1);
	}
	if(!grafo->vertices[v2]){
		agregar_vertice_grafo(*&grafo, v2);
	}
	grafo->matriz[v1][v2]=1;
	if(grafo->tipo==NO_DIRIGIDO){
		grafo->matriz[v2][v1]=1;
	}
}
void eliminar_vertice_grafo(TGrafo *grafo, int vertice){
	if(vertice>=0 && vertice<MAX_VERTICES && grafo->vertices[vertice]==true){
		grafo->numero_vertices-=1;
		grafo->vertices[vertice]=false;
		for(int i=0; i<grafo->maximo_vertices;i++){
			grafo->matriz[vertice][i]=0;
			grafo->matriz[i][vertice]=0;
		}
	}
}
void eliminar_arista_grafo(TGrafo *grafo, int v1, int v2){
	if(v1>=0 && v2>=0 && v1<grafo->maximo_vertices && v2<grafo->maximo_vertices && grafo->vertices[v1] && grafo->vertices[v2]){
		grafo->matriz[v1][v2]=0;
		if(grafo->tipo==NO_DIRIGIDO){
			grafo->matriz[v2][v1]=0;
		}
	}
}
	
void funcion_dfs(TGrafo *grafo, int vertice_inicio){
	TPila pila;
	inicializar_pila(&pila);
	agregar_valor_pila(&pila, vertice_inicio);
	grafo->visitado[vertice_inicio]=true;
	while(!verificar_pila_vacia(pila)){
		int vertice_actual;
		eliminar_valor_pila(&pila, &vertice_actual);
		for(int i=0;i<MAX_VERTICES; i++){
			if(grafo->matriz[vertice_actual][i]!=0 && grafo->visitado[i]==false){
				agregar_valor_pila(&pila, i);
				grafo->visitado[i]=true;
			}
		}
	}
}

bool existe_camino(TGrafo *grafo, int v1, int v2){
	funcion_dfs(*&grafo, v1);
	if(grafo->visitado[v2]){
		return true
	}
	return false;
}
	
void funcion_dfs_recursivo(TGrafo *grafo, int vertice_inicial){
	dfs_recursivo(*&grafo, vertice_inicial);
}

void dfs_recursivo(TGrafo *grafo,int vertice_inicial){
	if(grafo->visitado[vertice_inicial]){
		return
	}
	for(int i=0; i<grafo->maximo_vertices;i++){
		if(grafo->matriz[vertice_inicial]!=0 && grafo->visitado==false){
			dfs_recursivo(*&grafo, i);
		}
	}
}
