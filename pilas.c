#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10

typedef struct Persona{
	
	char nombre[50];
	int edad;
	float estatura;
	
}TPersona;

typedef struct Domicilio{
	
	int codigo_postal;
	int numero_domicilio;
	
}TDomicilio;

typedef struct Nodo{
	
	TPersona persona;
	TDomicilio domicilio;
	
}TNodo;

typedef struct Pilas{
	
	int tamanio;
	int cantidad_actual;
	TNodo datos[MAX];
	
}TPila;

void opciones(TPila *personas, int opcion);
void inicializar_pila(TPila *personas);
bool verificar_lleno(TPila personas);
bool verificar_vacio(TPila personas);
void llenar_pila(TPila *personas);
void consultar_datos(TPila personas);
void eliminar_dato(TPila *personas);


int main() {
	
	TPila personas;
	inicializar_pila(&personas);
	int opcion=0;
	while(opcion!=5){
		printf("1: llenar pila\n");
		printf("2: consultar pila\n");
		printf("3: vaciar pila\n");
		printf("4: salida\n");
		scanf("%d",&opcion);
		opciones(&personas,opcion);
	}
	return 0;
}

void inicializar_pila(TPila *personas){
	personas->tamanio = MAX;
	personas->cantidad_actual = 0;
}

void opciones(TPila *personas, int opcion){
	switch(opcion){
	case 1:llenar_pila(*&personas);
	break;
	case 2:consultar_datos(*personas);
	break;
	case 3:eliminar_dato(*&personas);
	break;
	case 4: return;
	break;
	}
}

void llenar_pila(TPila *personas)
{
	if (verificar_lleno(*personas))
	{
		printf("La pila está llena\n");
		return;
	}
		
	char nombre[50];
	int edad, codigo_postal, numero_domicilio;
	float estatura;
		
	getchar();
	scanf("%[^\n]", nombre);
	scanf("%d %f %d %d", &edad,&estatura,&codigo_postal,&numero_domicilio);
	int cantidad_actual = personas->cantidad_actual;
	strcpy(personas->datos[cantidad_actual].persona.nombre, nombre);
	personas->datos[cantidad_actual].persona.edad = edad;
	personas->datos[cantidad_actual].persona.estatura = estatura;
	personas->datos[cantidad_actual].domicilio.codigo_postal = codigo_postal;
	personas->datos[cantidad_actual].domicilio.numero_domicilio = numero_domicilio;
	cantidad_actual +=1;
	personas->cantidad_actual = cantidad_actual;
}

bool verificar_lleno(TPila personas){
	return personas.cantidad_actual==personas.tamanio-1;
}

bool verificar_vacio(TPila personas){
	return personas.cantidad_actual==0;
}

void consultar_datos(TPila personas){
	if(verificar_vacio(personas)){
		printf("pila vacia\n");
		return;
	}
	int cantidad_actual = personas.cantidad_actual-1;
	printf("%s %d %f %d %d",personas.datos[cantidad_actual].persona.nombre,personas.datos[cantidad_actual].persona.edad,personas.datos[cantidad_actual].persona.estatura,personas.datos[cantidad_actual].domicilio.codigo_postal,personas.datos[cantidad_actual].domicilio.numero_domicilio);
}
	

void eliminar_dato(TPila *personas) {
	if (verificar_vacio(*personas)) {
		printf("La pila está vacía\n");
		return;
	}
	int cantidad_actual = personas->cantidad_actual;
	strcpy(personas->datos[cantidad_actual-1].persona.nombre, "");
	personas->datos[cantidad_actual-1].persona.edad = 0;
	personas->datos[cantidad_actual-1].persona.estatura = 0;
	personas->datos[cantidad_actual-1].domicilio.codigo_postal = 0;
	personas->datos[cantidad_actual-1].domicilio.numero_domicilio = 0;
	personas->cantidad_actual = cantidad_actual-1;
}
