#include <stdio.h>

int narcista(int num);
int contar_digitos(int num);
int potencia(int base, int elevacion);

int main() {
	int numero;
	scanf("%d", &numero);
	if(narcista(numero)) printf("Es Narcisista");
	else printf("No es Narcisista");
}

int narcista(int num){
	int numero=num;
	int digitos=contar_digitos(num);
	int resultado=0,valor;
	
	while(num!=0){
		valor=num%10;
		resultado +=potencia(valor, digitos);
		num/=10;
	}	
	return numero==resultado;
}

int contar_digitos(int num) {
	int cont = 0;
	while (num > 0) {
		num = num / 10;
		cont++;
	}
	return cont;
}

int potencia(int base, int elevacion) {
	int cont = base;
	for (int i = 1; i < elevacion; i++) {
		base= base*cont;
	}
	return base;
}
