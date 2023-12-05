#include <stdio.h>
#include <stdbool.h>
#define MAX 1000

typedef int TDato;
typedef struct
{
	TDato datos[MAX];
	int inicio;
	int ultimo;
} TCola;

typedef struct
{
	TDato data[MAX];
	int inicio;
	int ultimo;
} TColaCopia;

void inicializar_cola(TCola *cola, TColaCopia *copia);
bool cola_original_vacia(TCola cola);
bool cola_original_llena(TCola cola);
bool cola_copia_vacia(TColaCopia cola);
bool cola_copia_llena(TColaCopia cola);
void agregar_original(TCola *cola, int cantidad);
void agregar_copia(TColaCopia *copia, int dato);
void eliminar_cola_original(TCola *cola);
void eliminar_cola_copia(TColaCopia *copia);
void ordenar_cola(TCola *cola, TColaCopia *copia);
int consultar_cola_original(TCola cola);
int consultar_cola_copia(TColaCopia copia);

int main()
{
	TCola cola;
	TColaCopia copia;
	int i = 0;
	int array[] = {53, 22, 48, 37, 67, 12, 44, 24};
	inicializar_cola(&cola, &copia);
	while (i < 8)
	{
		agregar_original(&cola, array[i]);
		i++;
	}
	ordenar_cola(&cola, &copia);
	while (!cola_copia_vacia(copia))
	{
		printf("%d ", consultar_cola_copia(copia));
		eliminar_cola_copia(&copia);
	}
	
	return 0;
}

void inicializar_cola(TCola *cola, TColaCopia *copia)
{
	cola->inicio = 0;
	cola->ultimo = 0;
	copia->inicio = 0;
	copia->ultimo = 0;
}

bool cola_original_vacia(TCola cola)
{
	return cola.inicio == cola.ultimo;
}

bool cola_original_llena(TCola cola)
{
	return cola.ultimo == MAX;
}

bool cola_copia_vacia(TColaCopia copia)
{
	return copia.inicio == copia.ultimo;
}

bool cola_copia_llena(TColaCopia copia)
{
	return copia.ultimo == MAX;
}

void agregar_original(TCola *cola, int cantidad)
{
	if (cola_original_llena(*cola))
	{
		return;
	}
	cola->datos[cola->ultimo] = cantidad;
	cola->ultimo += 1;
}

void agregar_copia(TColaCopia *copia, int dato)
{
	if (cola_copia_llena(*copia))
	{
		return;
	}
	copia->data[copia->ultimo] = dato;
	copia->ultimo += 1;
}

void eliminar_cola_original(TCola *cola)
{
	if (cola_original_vacia(*cola))
	{
		return;
	}
	cola->inicio += 1;
}

void eliminar_cola_copia(TColaCopia *copia)
{
	if (cola_copia_vacia(*copia))
	{
		return;
	}
	copia->inicio += 1;
}


void ordenar_cola(TCola *cola, TColaCopia *copia)
{
	while (!cola_original_vacia(*cola))
	{
		int aux = consultar_cola_original(*cola);
		eliminar_cola_original(*&cola);
		while (!cola_copia_vacia(*copia) && consultar_cola_copia(*copia) >= aux)
		{
			int temp = consultar_cola_copia(*copia);
			eliminar_cola_copia(*&copia);
			agregar_original(*&cola, temp);
		}		
		agregar_copia(*&copia, aux);
	}
}

int consultar_cola_original(TCola cola)
{
	return cola.datos[cola.inicio];
}

int consultar_cola_copia(TColaCopia copia)
{
	return copia.data[copia.inicio];
}
