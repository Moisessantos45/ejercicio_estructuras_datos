#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef int TDato
	
typedef struct{
	TDato datos[MAX];
	int inicio;
	int fin;
}TCola;

void inicializar(TCola *cola);
bool verificar_esta_vacia(TCola *cola);
bool verificar_esta_llena(TCola *cola);
void agregar_cola(TCola *cola);
void desencolar(TCola *cola);
void ordenar_cola(TCola *cola);
int consultar(TCola cola);

int main(){
	TCola cola;
	TDato datos[]={53,22,48,37,67,12,41,24};
	agregar_cola(*&cola,datos);
	while(!verificar_esta_vacia(cola)){
		printf("%d", consultar(cola));
		desencolar(&cola);
	}
}

void inicializar(TCola *cola){
	cola->inicio=0;
	cola->fin=0;
}

bool verificar_esta_vacia(TCola *cola){
	return cola->cima==cola->fin;
}
bool verificar_esta_llena(TCola *cola){
	return cola->fin==MAX;
}

void agregar_cola(TCola *cola,TDato dato){
	if(verificar_esta_llena(*cola)){
		return;
	}
	pila->datos[pila->fin]=dato;
	pila->fin+=1;
}
	
void desencolar(TCola *cola){
	if(verificar_esta_vacia(*cola)){
		return;
	}
	cola->inicio+=1;
}
void ordenar_cola(TCola *cola);

int consultar(TCola cola){
	if(verificar_esta_vacia(cola)){
		return 0;
	}
	return pila.datos[pila.inicio];
}
