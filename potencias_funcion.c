#include <stdio.h>

long long potencias(int num,int elevacion);

int main() {
	int numero,potencia;
	long long resultado;
	
	scanf("%d %d",&numero, &potencia);
	resultado=potencias(numero,potencia);
	printf("%lld",resultado);
}

long long potencias(int num,int elevacion){
	int cont=num;
	for(int i=1; i<elevacion; i++){
		num=num*cont;
	}
	return num;
}
