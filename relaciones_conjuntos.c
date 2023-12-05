#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef int TDato;

typedef struct
{
    TDato datos[MAX];
    int tamanio;
} TConjuntos;

void inicializar_conjunto(TConjuntos *conjunto);
bool conjunto_esta_vacio(TConjuntos conjunto);
bool conjunto_esta_lleno(TConjuntos conjunto);
void ciclo_agregar_leer(TConjuntos *conjunto, TConjuntos *conjunto_1);
void llenar_conjunto(TConjuntos *conjunto, int tamanio, int pos);
bool agregar_conjunto(TConjuntos *conjunto, TDato dato);
int buscar_dato_conjunto(TConjuntos *conjunto, TDato dato);
void relacion_conjunto(TConjuntos *conjunto, TConjuntos *conjunto_1);
int recorrer_conjunto(TConjuntos *conjunto, TConjuntos *conjunto_1);

int main()
{
    TConjuntos conjunto_one, conjuto_two;
    inicializar_conjunto(&conjunto_one);
    inicializar_conjunto(&conjuto_two);
    ciclo_agregar_leer(&conjunto_one, &conjuto_two);
}

void inicializar_conjunto(TConjuntos *conjunto)
{
    conjunto->tamanio = 0;
}

bool conjunto_esta_vacio(TConjuntos conjunto)
{
    return conjunto.tamanio == 0;
}

bool conjunto_esta_lleno(TConjuntos conjunto)
{
    return conjunto.tamanio == MAX;
}

void ciclo_agregar_leer(TConjuntos *conjunto, TConjuntos *conjunto_1)
{
    int tamanio_1, tamanio_2;
	scanf("%d %d",&tamanio_1,&tamanio_2);
    llenar_conjunto(*&conjunto, tamanio_1, 0);
    llenar_conjunto(*&conjunto_1, tamanio_2, 0);
	relacion_conjunto(*&conjunto,*&conjunto_1);
}

void llenar_conjunto(TConjuntos *conjunto,int tamanio, int pos)
{
    if (tamanio == pos)
    {
        return;
    }
    int dato;
    scanf("%d", &dato);
    agregar_conjunto(*&conjunto, dato);
	pos++;
    llenar_conjunto(*&conjunto, tamanio, pos);
}

bool agregar_conjunto(TConjuntos *conjunto, TDato dato)
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

int buscar_dato_conjunto(TConjuntos *conjunto, TDato dato)
{
    for (int i = 0; i < conjunto->tamanio; i++)
    {
        if (dato == conjunto->datos[i])
        {
            return i;
        }
    }
    return -1;
}

void relacion_conjunto(TConjuntos *conjunto, TConjuntos *conjunto_1)
{
    int relacion = recorrer_conjunto(*&conjunto, *&conjunto_1);

    if (relacion == 0)
    {
        printf("A = B");
    }
    else if (relacion == 1)
    {
        printf("A < B");
    }
    else if (relacion == 2)
    {
        printf("A > B");
    }
    else
    {
        printf("A != B");
    }
}

int recorrer_conjunto(TConjuntos *conjunto, TConjuntos *conjunto_1)
{
    int suma = 0;
    for (int i = 0; i < conjunto->tamanio; i++)
    {
        for (int j = 0; j < conjunto_1->tamanio; j++)
        {
            if (conjunto->datos[i] == conjunto_1->datos[j])
            {
                suma++;
            }
        }
    }
    if (conjunto_1->tamanio == conjunto->tamanio && suma == conjunto->tamanio)
    {
        return 0;
    }
    else if (conjunto_1->tamanio > conjunto->tamanio && suma == conjunto->tamanio)
    {
        return 1;
    }
    else if (conjunto_1->tamanio < conjunto->tamanio && suma == conjunto_1->tamanio)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
