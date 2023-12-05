#include <stdio.h>

int conversor(int num);

int main() {	
	long long resultado;
	int numero;
	scanf("%d",&numero);
	resultado=conversor(numero);
	printf("%lld", resultado);
}

int conversor(int num){
	if(num==0){
		return 0;
	}
	int operacion = num % 2;
	return operacion + 10 * conversor(num / 2);
}
