//Estructuras de datos 1
//Moises santos hernandez
//24/10/23
// Los bebés marcianos - imprimir el nombre de la madre y bebe deacuerdo a los que estan en la fila
// claro se tiene que seguir las condiciones que dice que solo se imprime siempre y cuando este el nombre
// de un bebe y un madre de lo contrario no se pueden forman los pares

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define CARCTER 10
#define MAX 1000

typedef char TDato;
typedef struct
{
	TDato nombres[CARCTER][CARCTER];
	TDato caracter[CARCTER][CARCTER];
	int maximo;
	int cima;
} TPila;

void inicializar_pila(TPila *pila);
bool verificar_pila_vacia(TPila pila);
bool verificar_pila_llena(TPila pila);
void opciones(TPila *pila, int cantidad);
void agregar_pila(TPila *pila, char nombre[], char caracter);
void imprimir_pila(char nombreMadre[], char nombre[]);
void vaciar_pila(TPila *pila);

int main()
{
	TPila pila;
	int cantidad;
	inicializar_pila(&pila);
	scanf("%d", &cantidad);
	opciones(&pila, cantidad);
}

void inicializar_pila(TPila *pila)
{
	pila->maximo = MAX;
	pila->cima = 0;
}

bool verificar_pila_vacia(TPila pila)
{
	return pila.cima == 0;
}

bool verificar_pila_llena(TPila pila)
{
	return pila.cima == MAX;
}

void opciones(TPila *pila, int cantidad)
{
	
	TDato nombre[CARCTER];
	char caracter;
	while (cantidad > 0)
	{
/*		getchar();*/
		scanf(" %c %s",&caracter, nombre);
		agregar_pila(*&pila,nombre,caracter);
		cantidad--;
	}
}

void agregar_pila(TPila *pila, char nombre[], char caracter)
{
	if (verificar_pila_llena(*pila))
	{
		return;
	}
	if (pila->cima >= 1 && caracter != pila->caracter[pila->cima - 1][0])
	{
		imprimir_pila(pila->nombres[pila->cima - 1], nombre);
		vaciar_pila(*&pila);
		return;
	}

	pila->caracter[pila->cima][0] = caracter;
	strcpy(pila->nombres[pila->cima], nombre);
	pila->cima += 1;
}

void imprimir_pila(char nombreMadre[], char nombre[])
{
	printf("%s %s\n",nombre, nombreMadre);
}

void vaciar_pila(TPila *pila)
{
	if (verificar_pila_vacia(*pila))
	{
		return;
	}
	int cima = pila->cima - 1;
	pila->cima = cima;
}
