#include <stdio.h>
#define MAX 1000

typedef struct Calificaciones
{
	int examen_obligatorio;
	int examen_opcional;
	float promedio;
	int examenes;
} TCalificacion;

void solicitar_calificaciones(TCalificacion calificaciones[], int cantidad);
void calcular_promedio(TCalificacion calificaciones[], int cantidad);
void ordenar_calificaciones(TCalificacion calificaciones[], int inicio, int fin);
int division(TCalificacion calificaciones[], int inicio, int fin);
void intercambiar(TCalificacion *exam_a, TCalificacion *exam_b);
void imprimir_calificaciones(TCalificacion calificaciones[], int cantidad);

int main()
{
	TCalificacion calificacion[MAX];
	int cantidad;
	scanf("%d", &cantidad);
	solicitar_calificaciones(calificacion, cantidad);
	imprimir_calificaciones(calificacion, cantidad);
	return 0;
}

void solicitar_calificaciones(TCalificacion calificaciones[], int cantidad)
{
	for (int i = 0; i < cantidad; i++)
	{
		scanf("%d %d", &calificaciones[i].examen_obligatorio, &calificaciones[i].examen_opcional);
		int examenes=calificaciones[i].examen_opcional==-1 ? 1:2;
		calificaciones[i].examenes=examenes;
	}
	calcular_promedio(calificaciones,cantidad);
}

void calcular_promedio(TCalificacion calificaciones[], int cantidad){
	for (int i = 0; i < cantidad; i++)
	{
		calificaciones[i].promedio=calificaciones[i].examenes==2 ? (calificaciones[i].examen_obligatorio+calificaciones[i].examen_opcional)/2: calificaciones[i].examen_obligatorio;
	}
	ordenar_calificaciones(calificaciones, 0, cantidad - 1);
}

void ordenar_calificaciones(TCalificacion calificaciones[], int inicio, int fin)
{
	if (inicio < fin)
	{
		int mitad = division(calificaciones, inicio, fin);
		ordenar_calificaciones(calificaciones, inicio, mitad - 1);
		ordenar_calificaciones(calificaciones, mitad + 1, fin);
	}
}

int division(TCalificacion calificaciones[], int inicio, int fin)
{
	TCalificacion posicion = calificaciones[fin];
	int i = inicio - 1;
	
	for (int j = inicio; j <= fin - 1; j++) {
		if (calificaciones[j].promedio > posicion.promedio) {
			i++;
			intercambiar(&calificaciones[i], &calificaciones[j]);
		} else if (calificaciones[j].promedio == posicion.promedio) {
			if (calificaciones[j].examenes == 1 && posicion.examenes != 1) {
				i++;
				intercambiar(&calificaciones[i], &calificaciones[j]);
			} else if (calificaciones[j].examenes != 1 && posicion.examenes == 1) {
				i++;
				intercambiar(&calificaciones[i], &calificaciones[j]);
			} else if (calificaciones[j].examenes > posicion.examenes) {
				i++;
				intercambiar(&calificaciones[i], &calificaciones[j]);
			} else if (calificaciones[j].examenes == posicion.examenes) {
				if (calificaciones[j].examen_obligatorio > posicion.examen_obligatorio) {
					i++;
					intercambiar(&calificaciones[i], &calificaciones[j]);
				}
			}
		}
	}   
	intercambiar(&calificaciones[i + 1], &calificaciones[fin]);
	return (i + 1);
}

void intercambiar(TCalificacion *exam_a, TCalificacion *exam_b)
{
	TCalificacion temp = *exam_a;
	*exam_a = *exam_b;
	*exam_b = temp;
}

void imprimir_calificaciones(TCalificacion calificaciones[], int cantidad)
{
	for (int i = 0; i < cantidad; i++)
	{
		printf("%d %d\n", calificaciones[i].examen_obligatorio, calificaciones[i].examen_opcional);
	}
}

