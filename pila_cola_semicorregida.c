#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10000
#define CARACTER 10

typedef int TDato;

typedef struct pila_cola {
	TDato datos[MAX];
	int cima;
	int inicio;
	int fin;
	char tipo[CARACTER];
} TPila_cola;

void inicializar_pila(TPila_cola *pila_cola) {
	pila_cola->cima = 0;
	pila_cola->inicio = 0;
	pila_cola->fin = 0;
	strcpy(pila_cola->tipo, "pila");
}

bool verificar_pila_cola_vacia(TPila_cola pila_cola) {
	return pila_cola.cima == 0 || pila_cola.inicio == pila_cola.fin;
}

void agregar_dato_pila_cola(TPila_cola *pila_cola, TDato dato) {
	if (strcmp(pila_cola->tipo, "pila") == 0) {
		pila_cola->datos[pila_cola->cima] = dato;
		pila_cola->cima++;
	} else {
		pila_cola->datos[pila_cola->fin] = dato;
		pila_cola->fin++;
	}
}

void quitar_dato_pila_cola(TPila_cola *pila_cola) {
	if (verificar_pila_cola_vacia(*pila_cola)) {
		return;
	}
	
	if (strcmp(pila_cola->tipo, "pila") == 0) {
		pila_cola->cima--;
		printf("%d\n", pila_cola->datos[pila_cola->cima]);
	} else {
		printf("%d\n", pila_cola->datos[pila_cola->inicio]);
		pila_cola->inicio++;
	}
}

void cambiar_tipo_pila_cola(TPila_cola *pila_cola) {
	if (strcmp(pila_cola->tipo, "pila") == 0) {
		strcpy(pila_cola->tipo, "cola");
	} else {
		strcpy(pila_cola->tipo, "pila");
	}
}

int main() {
	TPila_cola pila_cola;
	inicializar_pila(&pila_cola);
	
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		char evento[CARACTER];
		scanf("%s", evento);
		
		if (strcmp(evento, "AGREGA") == 0) {
			TDato valor;
			scanf("%d", &valor);
			agregar_dato_pila_cola(&pila_cola, valor);
		} else if (strcmp(evento, "QUITA") == 0) {
			quitar_dato_pila_cola(&pila_cola);
		} else if (strcmp(evento, "CAMBIA") == 0) {
			cambiar_tipo_pila_cola(&pila_cola);
		}
	}
	
	return 0;
}
