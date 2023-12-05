//Estructuras de datos 1
//Moises santos hernandez
//24/10/23
// Paréntesis Balanceados - es mediante una cadena de parantesis y corchetes etc y leerlos
// verificar si la cadena esta balanceada es decir si cada caracter tiene su cerrie


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define CARCTER 100
#define MAX 1000

typedef char TDato;
typedef struct
{
	TDato caracter[CARCTER];
	int maximo;
	int cima;
} TPila;

void inicializar_pila(TPila *pila);
bool verificar_pila_vacia(TPila pila);
bool verificar_pila_llena(TPila pila);
void opciones(TPila *pila, int cantidad);
void leer_caracteres(TPila *pila, char caracter[]);
void agregar_pila(TPila *pila, char caracter);
void imprimir_pila(TPila pila);
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
	
	char caracter[CARCTER];
	while (cantidad > 0)
	{
		scanf("%s", caracter);
		leer_caracteres(*&pila, caracter);
		cantidad--;
	}
}

void leer_caracteres(TPila *pila, char caracter[])
{
	for (int i = 0; caracter[i] != '\0'; i++)
	{
		agregar_pila(*&pila, caracter[i]);
	}
	imprimir_pila(*pila);
}

void agregar_pila(TPila *pila, char caracter)
{
	if (verificar_pila_llena(*pila))
	{
		return;
	}
	if (pila->cima >= 1)		
	{
		if ((caracter == ')' && pila->caracter[pila->cima - 1] == '(') || (caracter == ']' && pila->caracter[pila->cima - 1] == '[') || (caracter == '}' && pila->caracter[pila->cima - 1] == '{')) {
			vaciar_pila(pila);
			return;
		}
	}
	pila->caracter[pila->cima]= caracter;
	pila->cima += 1;
}

void imprimir_pila(TPila pila)
{
	if (verificar_pila_vacia(pila))
	{
		puts("SI");
	}
	else
	{
		puts("NO");
	}
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
