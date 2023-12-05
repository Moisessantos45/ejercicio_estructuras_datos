#include <stdio.h>
#include <stdbool.h>
#define MAX 10000

typedef int TDato;

typedef struct
{
	TDato datos[MAX];
	int tamanio;
} TConjunto;

void inicializar_conjunto(TConjunto *conjunto);
bool conjunto_esta_vacio(TConjunto conjunto);
bool conjunto_esta_lleno(TConjunto conjunto);
void ciclo_agregar_leer(TConjunto *conjunto);
bool agregar_conjunto(TConjunto *conjunto, TDato dato);
bool atender_persona_conjunto(TConjunto *conjunto, TDato dato);
int buscar_dato_conjunto(TConjunto *conjunto, TDato dato);

int main()
{
	TConjunto conjunto;
	inicializar_conjunto(&conjunto);
	ciclo_agregar_leer(&conjunto);
}

void inicializar_conjunto(TConjunto *conjunto)
{
	conjunto->tamanio = 0;
}

bool conjunto_esta_vacio(TConjunto conjunto)
{
	return conjunto.tamanio == 0;
}
bool conjunto_esta_lleno(TConjunto conjunto)
{
	return conjunto.tamanio == MAX;
}

void ciclo_agregar_leer(TConjunto *conjunto)
{
	TDato dato;
	int rango, cantidad;
	char letra;
	scanf("%d %d", &rango, &cantidad);
	while (cantidad > 0)
	{
		getchar();
		scanf("%c", &letra);
		switch (letra)
		{
		case 'I':
			scanf("%d",&dato);
			agregar_conjunto(*&conjunto, dato);
			break;
		case 'C':
			printf("%d\n", conjunto->tamanio);
			break;
		case 'E':
			scanf("%d",&dato);
			atender_persona_conjunto(*&conjunto, dato);
			break;
		default:
			break;
		}
		cantidad--;
	}
}

bool agregar_conjunto(TConjunto *conjunto, TDato dato)
{
	if (conjunto_esta_lleno(*conjunto))
	{
		return false;
	}
	int pos = buscar_dato_conjunto(*&conjunto, dato);
	if (pos == -1)
	{
		conjunto->datos[conjunto->tamanio] = dato;
		conjunto->tamanio += 1;
		return true;
	}
	else
	{
		return false;
	}
}

bool atender_persona_conjunto(TConjunto *conjunto, TDato dato)
{
	int post = buscar_dato_conjunto(*&conjunto, dato);
	if (post == -1)
	{
		return false;
	}
	conjunto->datos[post] = conjunto->datos[conjunto->tamanio - 1];
	conjunto->tamanio -= 1;
	return true;
}

int buscar_dato_conjunto(TConjunto *conjunto, TDato dato)
{
	for (int i = 0; i < conjunto->tamanio; i++)
	{
		if (conjunto->datos[i] == dato)
		{
			return i;
		}
	}	
	return -1;
}
