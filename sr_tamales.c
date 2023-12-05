#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef int TDato;
typedef struct
{
    TDato Personas[MAX];
    bool formado[MAX];
    int numero_invitado;
    int tamanio;
    int posicion;
} TConjunto;

void inicializar_conjunto(TConjunto *conjunto);
bool conjunto_esta_vacio(TConjunto conjunto);
bool conjunto_esta_lleno(TConjunto conjunto);
void ciclo_agregar_leer(TConjunto *conjunto);
bool agregar_conjunto(TConjunto *conjunto, TDato dato);
bool atender_persona_conjunto(TConjunto *conjunto);
int buscar_dato_conjunto(TConjunto *conjunto, TDato dato);

void consltar(TConjunto conjunto);
int main()
{
    TConjunto conjunto;
    inicializar_conjunto(&conjunto);
    ciclo_agregar_leer(&conjunto);
}

void inicializar_conjunto(TConjunto *conjunto)
{
    conjunto->tamanio = 0;
    conjunto->posicion = 0;
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
    int eventos;
    char evento[30];
    int numero;
    scanf("%d", &eventos);
    while (eventos > 0)
    {
        scanf("%s", evento);
        if (strcmp(evento, "FORMA") == 0)
        {
            scanf("%d", &numero);
            agregar_conjunto(*&conjunto, numero);
        }
        else if (strcmp(evento, "ATIENDE") == 0)
        {
            atender_persona_conjunto(*&conjunto);
        }
        eventos--;
    }
}
bool agregar_conjunto(TConjunto *conjunto, TDato dato)
{
    if (conjunto_esta_lleno(*conjunto))
    {
        return false;
    }
    int persona = buscar_dato_conjunto(*&conjunto, dato);
    if (!conjunto->formado[persona])
    {
        conjunto->Personas[conjunto->tamanio] = dato;
        conjunto->formado[conjunto->tamanio] = true;
        conjunto->tamanio += 1;
    }
}

bool atender_persona_conjunto(TConjunto *conjunto)
{
    if (conjunto_esta_vacio(*conjunto))
        return false;
    int persona = buscar_dato_conjunto(*&conjunto, conjunto->Personas[conjunto->posicion]);
    if (persona == -1)
    {
        printf("SI TAMAL %d\n", conjunto->Personas[conjunto->posicion]);
        conjunto->formado[conjunto->posicion] = false;
        conjunto->posicion += 1;
        return true;
    }
    else
    {
        printf("NO TAMAL %d\n", conjunto->Personas[conjunto->posicion]);
        conjunto->posicion += 1;
        return false;
    }
}

int buscar_dato_conjunto(TConjunto *conjunto, TDato dato)
{
    for (int i = 0; i < conjunto->tamanio; i++)
    {
        if (dato == conjunto->Personas[i] && conjunto->posicion != i)
        {
            return i;
        }
    }
    return -1;
}
