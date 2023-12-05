#include <stdio.h>

int maximo(int valor_a, int valor_b);

int main() {
	int a,b;
	int resul;
	scanf("%d %d", &a, &b);
	resul=maximo(a,b);
	printf("%d", resul);
	
	return 0;
}

int maximo(int valor_a, int valor_b){
	if(valor_b==0){
		return valor_a;
	}
	return maximo(valor_b,valor_a%valor_b);
}
