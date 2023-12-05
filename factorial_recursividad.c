#include <stdio.h>

long long sumatoria(int num);

int main() {
	int numero;
	long long resultado;
	scanf("%d", &numero);
	resultado = sumatoria(numero);
	printf("%lld",resultado);
	return 0;
}

long long sumatoria(int num) {
	if (num != 1) {
		return num + sumatoria(num - 1);
	}
	return num;
}
