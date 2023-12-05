#include <stdio.h>

long long area(int num);

int main() {
	int numero;
	long long valor;
	scanf("%d",&numero);
	valor=area(numero);
	printf("%lld", valor);
	
	return 0;
}

long long area(int num){
	long long resul;
	
	if(num==1){
		return 1;
	}	
	return area(num - 1) + 4 * (num - 1);
}

