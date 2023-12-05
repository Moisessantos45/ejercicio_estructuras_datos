#include <stdio.h>

long long factorial(int num);

int main() {
	int numero;
	long long resultado;
	scanf("%d", &numero);
	resultado = factorial(numero);
	printf("%lld",resultado);
	return 0;
}

long long factorial(int num) {
	if (num != 1) {
		return num * factorial(num - 1);
	}
	return num;
}


