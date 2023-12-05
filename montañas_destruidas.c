#include <stdio.h>
#include <string.h>
#define MAX 1000

typedef struct{
	int altura;
	char nombre[10];
}TMontania;

void llenar_datos(TMontania montania[],int cantidad);
void ordenar(TMontania montania[],int inicio, int fin);
int division(TMontania montania[],int inicio, int fin);
void intercambiar(TMontania *a, TMontania *b);
void imprimir_registro(TMontania montania[],int cantidad);

int main() {
	TMontania montania[MAX];
	int cantidad;
	scanf("%d",&cantidad);
	llenar_datos(montania,cantidad);
	imprimir_registro(montania,cantidad);
	return 0;
}

void llenar_datos(TMontania montania[],int cantidad){
	for(int i=0; i<cantidad;i++){
		getchar();
		scanf("%d %[^\n]",&montania[i].altura, montania[i].nombre);
	}
	ordenar(montania,0,cantidad-1);
}

void ordenar(TMontania montania[],int inicio, int fin){
	if(inicio<fin){
		int mitad=division(montania,inicio,fin);
		ordenar(montania,inicio,mitad-1);
		ordenar(montania,mitad+1,fin);
	}
}

int division(TMontania montania[],int inicio, int fin){
	TMontania pivote=montania[fin];
	int i=inicio-1;
	
	for(int j=inicio;j<=fin-1;j++){
		if(montania[j].altura>pivote.altura){
			i++;
			intercambiar(&montania[i],&montania[j]);
		}else if(montania[j].altura==pivote.altura){
			if(strcmp(montania[j].nombre,pivote.nombre)>0){
				i++;
				intercambiar(&montania[i],&montania[j]);
			}
		}
	}
	intercambiar(&montania[i+1],&montania[fin]);
	return i+1;
}

void intercambiar(TMontania *a, TMontania *b){
	TMontania temp=*a;
	*a=*b;
	*b=temp;
}

void imprimir_registro(TMontania montania[],int cantidad){
	for(int i=0; i<cantidad;i++){
		printf("%s \n",montania[i].nombre);
	}
}
