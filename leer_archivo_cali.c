#include <stdio.h>
#define MAX 100

typedef struct{
	char carrera;
	int clave;
	float calificacion;
}TAlumnos;


void imprimir(TAlumnos alumnos[],int indice);
void ordenarAlumnos(TAlumnos alumnos[], int indice);

int main() {
	TAlumnos alumnos[MAX];
	FILE *file = fopen("alumnos.txt", "r");
	if (file == NULL) {
		printf("No se pudo abrir el archivo.\n");
		return 1;
	}
	
	int i=0;
	fscanf(file, "%c %d %f\n",  &alumnos[i].carrera, &alumnos[i].clave, &alumnos[i].calificacion);
	i++;
	while (!feof(file)) {
		fscanf(file, "%c %d %f\n",  &alumnos[i].carrera, &alumnos[i].clave, &alumnos[i].calificacion);
		i++;
	}
	imprimir(alumnos,i);
	fclose(file);
	return 0;
}

void imprimir(TAlumnos alumnos[], int indice){
	for(int i=0; i<indice;i++){
		printf("Carácter: %c, Número: %d, Decimal: %.1f\n", alumnos[i].carrera, alumnos[i].clave, alumnos[i].calificacion);
	}
}
