#include <stdio.h>

int main() {
	
	float calificaciones[5][3] = {
	{7.0, 6.0, 8.0},
	{6.0, 7.0, 8.0},
	{9.0, 8.0, 7.0},
	{8.0, 8.0, 9.0},
	{7.0, 8.0, 8.0}
	};
	float promedio=0;
	float suma;
	float columna;
	
	char *cadena[10]={"calculo d", "programacion", "arquitectura", "software","fisica a"};
	printf(" Parciales  ");
	for(int i=0; i<3; i++){
		printf("%d   ", i);
	}
	printf("\n");
	for(int i=0; i<5; i++){
		printf(" %s: ", cadena[i]);
		suma=0;
		columna=0;
		for(int j=0; j<3; j++){
			printf("%.1f ", calificaciones[i][j]);
			suma += calificaciones[i][j];
		}
		promedio=promedio< suma ? suma: promedio;
		printf("\n");
	}
	promedio/=5;
	
	printf("El promedio mayor: %.1f\n", promedio);
/*				   "0" "1" "2"*/
/*		calculo d: 7.0 6.0 8.0*/
/*		programacion: 6.0 7.0 8.0*/
/*		arquitectura: 9.0 8.0 7.0*/
/*		software: 8.0 8.0 9.0*/
/*		fisica a: 7.0 8.0 8.0*/
	
		
	return 0;
}

