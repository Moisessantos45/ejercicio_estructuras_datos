#include <stdio.h>
#define MAX 1000

void llenarArreglo(int *longitud, int arreglo[]);
void secuencia(int caja[],int tamanio,int diferencias[]);
int absoluto(int num);
void condicion(int valor1,int tamanio,int diferencias[]);
void encontrado(int diferencias[],int num);
int verificar(int diferencias[], int tamanio);

int main() {
	int caja[MAX], tamanio = 0;
	int diferencias[MAX],resultado;
	
	llenarArreglo(&tamanio, caja);
	secuencia(caja,tamanio,diferencias);
	resultado=verificar(diferencias, tamanio);
	printf("%d",resultado);
	return 0;
}

void llenarArreglo(int *longitud, int arreglo[]) {
	scanf("%d", &*longitud);
	for (int i = 0; i < *longitud; i++) {
		scanf("%d", &arreglo[i]);
	}
}

void secuencia(int caja[],int tamanio,int diferencias[]){
	int diferencia;
	for (int i = 0; i < tamanio - 1; i++) {		
		diferencia = absoluto(caja[i] - caja[i + 1]);
		condicion(diferencia,tamanio,diferencias);
	}
}
	
int absoluto(int num){
	if(num<0){
		return -num;
	}
	return num;
}

void condicion(int valor1,int tamanio,int diferencias[]){
	if (valor1 >= 1 && valor1 <= tamanio - 1) {
		encontrado(diferencias,valor1);
	}
}
	
void encontrado(int diferencias[],int num){
	diferencias[num - 1] = 1;
}

int verificar(int diferencias[], int tamanio) {
	for (int i = 0; i < tamanio - 1; i++) {
		if (diferencias[i] == 0) {
			return i+1;
		}
	}
	return 0;
}

