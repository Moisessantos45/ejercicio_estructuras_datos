#include <stdio.h>

long long factorial(int num);

int main()
{
	int cantidad, numero;
	long long resultado;
	scanf("%d", &cantidad);	
	while(cantidad-->0)
	{
		scanf("%d", &numero);
		resultado = factorial(numero);
		printf("%lld\n", resultado);
	}
}

long long factorial(int num)
{
	long long resul=1;
	for (int i = 1; i <= num; i++)
	{
		resul = resul * i;
	}
	
	return resul;
}
