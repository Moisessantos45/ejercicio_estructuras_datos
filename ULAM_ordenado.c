#include <stdio.h>
#define MAX 1000

int secuencia(int num,int *indice,int caja[]);
void ordenarSecuencia(int caja[],int indice);
void llenarArreglo(int caja[], int indice, int tamanio);

int main() {
	int numero;
	int indice=0;
	int numeros[MAX];
	scanf("%d", &numero);
	numero=secuencia(numero,&indice,numeros);
	ordenarSecuencia(numeros,indice);
	llenarArreglo(numeros,0,indice);
	return 0;
}

int secuencia(int num,int *indice, int caja[]){
	caja[(*indice)++]=num;
	if(num==1){
		return num;
	}	
	if(num%2==0){
		return secuencia(num/2, indice, caja);
	}else{
		return secuencia(num*3+1, indice, caja);
	}
}
	

void ordenarSecuencia(int caja[], int indice) {
	for (int i = 1; i < indice; i++) {
		int valor = caja[i];
		int j = i - 1;			
		while (j >= 0 && caja[j] > valor) {
			caja[j + 1] = caja[j];
			j = j - 1;
		}			
		caja[j + 1] = valor;
	}
}
	

void llenarArreglo(int caja[], int indice, int tamanio){
	if(indice==tamanio){
		return;
	}
	
	printf("%d ", caja[indice]);
	llenarArreglo(caja,indice+1,tamanio);
}
	
