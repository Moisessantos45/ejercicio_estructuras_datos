//Estructuras de datos 1
//Moises santos hernandez
//24/10/23
// A jugar 2048 - simular el juego de 2048 donde los numero iguales se sumaban conforme caian
// ademas de imprimir los valores del tamaño de la pila final y los valores de la pila

#include <stdio.h>
#include <stdbool.h>
#define MAX 1000

typedef int TDato;
typedef struct{
	TDato datos[MAX];
	int maximo;
	int cima;
	
}TPila;


void inicializar_pila(TPila *pila);
void solicitar_numeros(TPila *pila,int cantidad);
void agregar_pila(TPila *pila, TDato dato);
bool verificar_pila_vacia(TPila pila);
bool verificar_pila_llena(TPila pila);
void eliminar_dato(TPila *pila);
void imprimir_pila(TPila *pila);

int main() {
	TPila pila;
	int cantidad;
	int cima;
	scanf("%d",&cantidad);
	inicializar_pila(&pila);
	solicitar_numeros(&pila,cantidad);
	cima=pila.cima;
	printf("%d\n",cima);
	while(cima>0){
		imprimir_pila(&pila);
		cima--;
	}
	return 0;
}

void inicializar_pila(TPila *pila){
	pila->maximo=MAX;
	pila->cima=0;
}

bool verificar_pila_vacia(TPila pila){
	return pila.cima==0;
}

bool verificar_pila_llena(TPila pila){
	return pila.cima==pila.maximo; 
}

void solicitar_numeros(TPila *pila,int cantidad){
	TDato num;
	while(cantidad>0){
		scanf("%d",&num);
		agregar_pila(*&pila,num);
		cantidad--;
	}
}

void agregar_pila(TPila *pila, TDato dato){
	if(verificar_pila_llena(*pila)){
		return;
	}
	while (pila->cima>=0 && pila->datos[pila->cima-1]==dato) {
		eliminar_dato(*&pila);
		dato=dato*2;
	}
	pila->datos[pila->cima]=dato;
	pila->cima+=1;		
}

void eliminar_dato(TPila *pila){
	if(verificar_pila_vacia(*pila)){
		return;
	}
	int cima=pila->cima;
	pila->cima=cima-1;
}
	
void imprimir_pila(TPila *pila){
	int cima=pila->cima;
	printf("%d\n",pila->datos[cima-1]);
	eliminar_dato(*&pila);
}
