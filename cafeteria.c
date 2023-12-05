//Estructuras de datos 1
//Moises santos hernandez
//24/10/23
// Formados en la cafetería - atander un fila de alumnos y trabajadores que estan formados
// pero se le da prioridad a los trabajores si hay en la fila si no lo hay pasa el alumno

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define CARCTER 10
#define MAX 1000

//dato de tipo char
typedef char TDato;
typedef struct
{
	//cree los datos que almacenaran los datos de cada alumno y trabajador
	//con esto me evito crear otra estructura de tipo cola
	TDato alumnos[CARCTER][CARCTER];
	TDato trabajadores[CARCTER][CARCTER];
	//definir los inicio y final de cada dato
	int inicio_alumno;
	int inicio_trabajador;
	int ultimo_alumno;
	int ultimo_trabajador;
	
} TCola;

//definir las funciones basicas
void inicializar_cola(TCola *cola);
bool cola_alumno_vacia(TCola cola);
bool cola_alumno_llena(TCola cola);
bool cola_trabajador_vacia(TCola cola);
bool cola_llena_trabajador(TCola cola);
void agregar_persona(TCola *cola, int cantidad);
void agregar_pila_alumno(TCola *cola, char nombre[]);
void agregar_pila_trabajador(TCola *cola,char nombre[]);
void eliminar_dato_alumno(TCola *cola);
void eliminar_dato_trabajador(TCola *cola);
void ordenar_cola_alumno(TCola *cola);
void ordenar_cola_trabajador(TCola *cola);
void imprimir_persona(TCola *cola);
void consultar_alumnos(TCola cola);
void consultar_trabajadores(TCola cola);

int main()
{
	//crear el dato de cola
	TCola cola;
	int cantidad;
	//llamas a la funcion de iniciarlizar
	inicializar_cola(&cola);
	scanf("%d", &cantidad);
	agregar_persona(&cola,cantidad);
	return 0;
}

//esta funciob lo que hace es iniciliar los datos de inicio y final para cada dato
//para alumno y trabajador
void inicializar_cola(TCola *cola)
{
	cola->inicio_alumno = 0;
	cola->inicio_trabajador = 0;
	cola->ultimo_alumno = 0;
	cola->ultimo_trabajador = 0;
}


//funcion de tipo boolean regresa un true o false
//comparamos si esta vacia comparando si incio y final son iguales
bool cola_alumno_vacia(TCola cola)
{
	return cola.inicio_alumno == cola.ultimo_alumno;
}

//funcion de tipo boolean regresa un true o false
//comparamos si esta vacia comparando si final ya llego al maximo
bool cola_alumno_llena(TCola cola)
{
	return cola.ultimo_alumno == MAX;
}

//esta funciones son iguales alas de arriba
bool cola_trabajador_vacia(TCola cola)
{
	return cola.inicio_trabajador == cola.ultimo_trabajador;
}

bool cola_llena_trabajador(TCola cola)
{
	return cola.ultimo_trabajador == MAX;
}

//una funcin para agregar los datos 
void agregar_persona(TCola *cola, int cantidad)
{
	TDato nombre[CARCTER];
	char opcion[CARCTER*2];
	while (cantidad > 0)
	{	
		fgets(opcion, sizeof(opcion), stdin);
		// Elimina el carácter de nueva línea al final de la cadena
		opcion[strcspn(opcion, "\n")] = 0;
		//scanf(" %[^\n]",opcion);*/
		if(strcmp(opcion,"LLEGA ALUMNO")==0){
			scanf("%s", nombre);
			printf("%s\n",nombre);
			agregar_pila_alumno(*&cola, nombre);
		}else if(strcmp(opcion,"LLEGA TRABAJADOR")==0){
			scanf("%s", nombre);
			agregar_pila_trabajador(*&cola, nombre);
		}else if(strcmp(opcion,"ATIENDE")==0){
			imprimir_persona(*&cola);
		}
		cantidad--;
	}
}

void agregar_pila_alumno(TCola *cola,char nombre[])
{
	if (cola_alumno_llena(*cola))
	{
		return;
	}
	//aqui llamamos a una funcion que se enecarga de ordenar la cola en caso que se llene pero tenga
	//vacio los casillas del inicio
	if (cola->ultimo_alumno == MAX && cola->inicio_alumno > 0)
	{
		ordenar_cola_alumno(*&cola);
	}
	//usamos strcpy para copiar los datos a la cola y aumentamos el valor de final
	strcpy(cola->alumnos[cola->ultimo_alumno], nombre);
	cola->ultimo_alumno += 1;
}
//aqui es lo mismo que la funcion de arriba solo que para trabajador
void agregar_pila_trabajador(TCola *cola, char nombre[])
{
	if (cola_llena_trabajador(*cola))
	{
		return;
	}
	
	if (cola->ultimo_trabajador == MAX && cola->inicio_trabajador > 0)
	{
		ordenar_cola_trabajador(*&cola);
	}
	strcpy(cola->trabajadores[cola->ultimo_trabajador], nombre);
	cola->ultimo_trabajador += 1;
}

//para eliminar un dato de verifca si esta vacia la cola primero asi no asersoramos que nos de error
void eliminar_dato_alumno(TCola *cola)
{
	if (cola_alumno_vacia(*cola))
	{
		return;
	}
	//aumentamos el inicio ya que que el que se elimina el primer valor de la cola
	int final = cola->inicio_alumno;
	cola->inicio_alumno = final + 1;
}

void eliminar_dato_trabajador(TCola *cola)
{
	if (cola_trabajador_vacia(*cola))
	{
		return;
	}
	int final = cola->inicio_trabajador;
	cola->inicio_trabajador = final + 1;
}

//para odenar la cola se usa un for, primero obtemos el tamaño actaul de cola
//shacemos una resta del ultimo con el inicio
void ordenar_cola_alumno(TCola *cola)
{
	int tamanio = cola->ultimo_alumno - cola->inicio_alumno;
	//el for lo que hara es ordenar los datos colocandolos en los espacios en blanco del inicio
	for (int i = 0; i < tamanio; i++)
	{
		strcpy(cola->alumnos[i], cola->alumnos[cola->inicio_alumno + i]);
	}
	//reseeteamos inicio en cero y final en tamanio
	cola->inicio_alumno = 0;
	cola->ultimo_alumno = tamanio;
}
void ordenar_cola_trabajador(TCola *cola)
{
	int tamanio = cola->ultimo_trabajador - cola->inicio_trabajador;
	for (int i = 0; i < tamanio; i++)
	{
		strcpy(cola->trabajadores[i], cola->trabajadores[cola->inicio_trabajador + i]);
	}
	cola->inicio_trabajador = 0;
	cola->ultimo_trabajador = tamanio;
}

//para imprimir solo es primero verificar si no esta vacia la cola de trabajadores ya queue
// a ellos se le da priopidad si es asi entonces llamamos a la funcionde consultar 
// para imprimir al trabajador pero al mismo tiempo los eliminamos 
//si no hay trabajadores entonces imprimimos al alumno y lo eliminamos
void imprimir_persona(TCola *cola)
{
	if (cola_trabajador_vacia(*cola))
	{
		consultar_alumnos(*cola);
		eliminar_dato_alumno(*&cola);
	}
	else
	{
		consultar_trabajadores(*cola);
		eliminar_dato_trabajador(*&cola);
	}
}

//la funcion sirve para imprimi el datoa ya se trabajador o del alumno
void consultar_alumnos(TCola cola)
{
	if (cola_alumno_vacia(cola))
	{
		return;
	}
	printf("%s", cola.alumnos[cola.inicio_alumno]);
}
void consultar_trabajadores(TCola cola)
{
	printf("%s", cola.trabajadores[cola.inicio_trabajador]);
}
