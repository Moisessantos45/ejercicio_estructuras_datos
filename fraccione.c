#include <stdio.h>
#define MAX 1000

void llenarArreglo(int caja[], int *tamanio);
double fracciones_recursiva(int caja[], int tamanio, int index);

int main() {
	
	int tamanio;
	int caja[MAX];
	double resultado;
	
	llenarArreglo(caja,&tamanio);
	resultado=fracciones_recursiva(caja,tamanio,0);
	printf("%f", resultado);
	return 0;
}


void llenarArreglo(int caja[], int *tamanio){
	scanf("%d",&*tamanio);
	
	for(int i=0; i<*tamanio;i++){
		scanf("%d", &caja[i]); 
	}
}

double fracciones_recursiva(int caja[], int tamanio, int index) {
	if (index == tamanio - 1) {
		return caja[index];
	} else {
		double resultado_anterior = fracciones_recursiva(caja, tamanio, index + 1);
		return caja[index] + 1.0 / resultado_anterior;
	}
}
	



