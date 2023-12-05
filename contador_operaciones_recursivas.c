#include <stdio.h>

int producto(long long valor_a, long long valor_b, int *cont);

int main() {
	long long valor_a, valor_b;
	int resultado;
	int cont=0;
	scanf("%lld %lld", &valor_a, &valor_b);
	resultado=producto(valor_a, valor_b, &cont);
	printf("%d",cont);
	return 0;
}

int producto(long long valor_a, long long valor_b,int *cont) {
	if (valor_a == 0) {
		return 0;
	} else if (valor_a > 0 && valor_a % 2 == 0) {
		(*cont) += 2; 
		return 2 * producto(valor_a / 2, valor_b, *&cont);
	} else {
		(*cont) += 3;
		return 2 * producto(valor_a / 2, valor_b,*&cont) + valor_b;
	}
}


