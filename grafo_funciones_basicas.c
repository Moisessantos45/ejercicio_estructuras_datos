#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 101
#define DIRIGIDO 1
#define NO_DIRIGIDO 0

typedef int TDato;
typedef struct{
	int tipo;
	int matriz[MAX_VERTICES][MAX_VERTICES];
	int nume_vertices;
	bool vertices[MAX_VERTICES];
}TGrafo;

void inicializar_grafo(TGrafo *grafo, int tipo);
void agregar_valores_grafo(TGrafo *grafo);
void agregar_vertices(TGrafo *grafo, int vertice);
void agregar_arista(TGrafo *grafo, int v1, int v2);
void eliminar_vertice(TGrafo *grafo, int vertice);
void eliminar_arista(TGrafo *grafo, int v1, int v2);
void imprimir_grafo(TGrafo grafo);

int main() {
	TGrafo grafo;	
	inicializar_grafo(&grafo,DIRIGIDO);
	agregar_valores_grafo(&grafo);
	return 0;
}

void inicializar_grafo(TGrafo *grafo, int tipo){
	grafo->tipo=tipo;
	for(int i=0; i<MAX_VERTICES; i++){
		for(int j=0; j<MAX_VERTICES;j++){
			grafo->matriz[i][j]=0;
		}		
		grafo->vertices[i]=false;
	}
	grafo->nume_vertices=0;
}

void agregar_valores_grafo(TGrafo *grafo){
	int max_vertices, operaciones;
	char opcion;
	scanf("%d %d",&operaciones,&max_vertices);
	while(operaciones>0){
		getchar();
		scanf("%c",&opcion);
		switch(opcion){
		case 'A':
			break;
		case 'V':
			break;
		}
		operaciones--;
	}
}

void agregar_vertices(TGrafo *grafo, int vertice){
	if(vertice>=0 && vertice<MAX_VERTICES && !grafo->vertices[vertice]){
		grafo->vertices[vertice]=true;
		grafo->nume_vertices+=1;
	}
}
void agregar_arista(TGrafo *grafo, int v1, int v2){
	if(grafo->vertices[v1]==false){
		agregar_vertices(*&grafo, v1);
	}
	if(grafo->vertices[v2]==false){
		agregar_vertices(*&grafo, v2);
	}
	grafo->matriz[v1][v2]=1;
	if(grafo->tipo==NO_DIRIGIDO){
		grafo->matriz[v2][v1]=1;
	}
}
void eliminar_vertice(TGrafo *grafo, int vertice){
	if(vertice>=0 && vertice<MAX_VERTICES && grafo->vertices[vertice]==true){
		grafo->nume_vertices-=1;
		grafo->vertices[vertice]=false;
		for(int i=0; i<MAX_VERTICES; i++){
			grafo->matriz[vertice][i]=0;
			grafo->matriz[i][vertice]=0;
		}
	}
}
void eliminar_arista(TGrafo *grafo, int v1, int v2){
	if(v1>=0 && v1<MAX_VERTICES && v2>=0 && v2<MAX_VERTICES && grafo->vertices[v1] && grafo->vertices[v2]){
		grafo->matriz[v1][v2]=0;
		if(grafo->tipo==NO_DIRIGIDO){
			grafo->matriz[v2][v1]=0;
		}
	}
}
	
void imprimir_grafo(TGrafo grafo){
	for(int i=0; i<MAX_VERTICES;i++){
		for(int j=0; j<MAX_VERTICES;j++){
			if(grafo.matriz[i][j]==1){
				printf("(%d,%d) ",i,j);
			}
		}
	}
}

