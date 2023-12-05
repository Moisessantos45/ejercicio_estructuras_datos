#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct Encuesta{
	int id;
	char nombre[50];
	float estatura;
	float peso;
	float imc;
}TData;

void llenar_encusta(TData personas[], int cantidad);
void calcular_img(TData personas[], int cantidad);
void ordenar_personas(TData personas[], int cantidad);
void intercambio(TData *a,TData *b);
void imprimir_personas(TData personas[], int cantidad);

int main() {
	TData personas[MAX];
	int cantidad;
	scanf("%d",&cantidad);
	llenar_encusta(personas,cantidad);
	imprimir_personas(personas,cantidad);
	return 0;
}

void llenar_encusta(TData personas[], int cantidad){
	for(int i=0;i<cantidad;i++){
		scanf("%d", &personas[i].id);
		getchar();
		scanf("%[^\n]",personas[i].nombre);
		scanf("%f %f", &personas[i].peso, &personas[i].estatura);
	}
	calcular_img(personas,cantidad);
}
	
void calcular_img(TData personas[], int cantidad){
	for(int i=0;i<cantidad;i++){
		int imc=(personas[i].peso)/(personas[i].estatura*personas[i].estatura);
		personas[i].imc=imc;
	}
	ordenar_personas(personas, cantidad);
}

void ordenar_personas(TData personas[], int cantidad){
	for(int i=1;i<cantidad;i++){
		int j=i;
		while(j>0 && personas[j].imc>personas[j-1].imc){
			intercambio(&personas[j],&personas[j-1]);
			j--;
		}
	}
}
		

void intercambio(TData *a,TData *b){
	TData tem=*a;
	*a=*b;
	*b=tem;
}
	
void imprimir_personas(TData personas[], int cantidad){
	for(int i=0;i<cantidad;i++){
		printf("%d %s %.2f\n",personas[i].id, personas[i].nombre,personas[i].imc);
	}
}
