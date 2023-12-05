#include <stdio.h>

long long potencia(int base, int exponente);
long long formula(int valor_a);
long long formula_g(int valor_b, int valor_c);
long long formula_h(int valor_x, int valor_y, int valor_z);

int main() {
	int valor_x, valor_y, valor_z;
	long long resultado;
	
	scanf("%d %d %d", &valor_x, &valor_y, &valor_z);
	
	resultado = formula_h(valor_x, valor_y, valor_z);
	
	printf("%lld\n", resultado);
	
	return 0;
}

long long potencia(int base, int exponente) {
	long long resultado = 1;
	for(int i = 0; i < exponente; i++) {
		resultado *= base;
	}
	return resultado;
}

long long formula(int valor_a) {
	return 4 * potencia(valor_a, 3) + formula_g(2 *valor_a, -3 * valor_a);
}

long long formula_g(int valor_b, int valor_c) {
	return (7 * valor_b - 3) % (potencia(valor_c, 2) + 1);
}

long long formula_h(int valor_x, int valor_y, int valor_z) {
	return formula(valor_x / valor_y) + 3 * formula_g(valor_z / valor_y, valor_x);
}

