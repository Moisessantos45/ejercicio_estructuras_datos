#include <stdio.h>

void leer_alumno(char nombre_alumno[], float calificacion, char nombre_archivo_salida[]);
void lectura_datos(char nombre_archivo_salida[]);

int main()
{
	
/*	leer_alumno("juan", 7.5, "lectura.txt");*/
/*	leer_alumno("pedro", 6.5, "lectura.txt");*/
/*	leer_alumno("jose angel", 6.5, "lectura.txt");*/
/*	leer_alumno("miguel lopez", 6.5, "lectura.txt");*/
	lectura_datos("lectura.txt");
	return 0;
}

void leer_alumno(char nombre_alumno[], float calificacion, char nombre_archivo_salida[])
{
	FILE *fp = fopen(nombre_archivo_salida, "at");
	if (fp != NULL)
	{
		fprintf(fp, "%s, %f\n", nombre_alumno, calificacion);
		fclose(fp);
	}
	else
	{
		printf("Archivo no procesado");
	}
}

void lectura_datos(char nombre_archivo_salida[])
{
	FILE *fp = fopen(nombre_archivo_salida, "rt");
	char nombre_alumno[50];
	float calificacion;
	if (fp == NULL)
	{
		printf("Archivo no procesado");
	}
	else
	{
		fscanf(fp, "%s %f\n", nombre_alumno, &calificacion);
		while (!feof(fp))
		{
			printf("Nombre del alumno: %s calificacion: %f\n", nombre_alumno, calificacion);
			fscanf(fp, "%[^,], %f\n", nombre_alumno, &calificacion);
		}
		fclose(fp);
	}
}

