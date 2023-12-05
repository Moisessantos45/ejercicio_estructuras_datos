#include <stdio.h>

int encontrar(int num);
int mayor(int valor_1,int valor_2);

int main() {
	int numero,primo=1;
	scanf("%d", &numero);	
	while (primo <= numero) {
		printf("%d\n", primo);
		primo = encontrar(primo + 1);
	}
}

int encontrar(int num) {
	int cont = 2;
	
	while (cont < num) {
		if (num % cont == 0) {
			num++;
			cont = 2;
		} else {
			cont++;
		}
	}
	
	return num;
}



