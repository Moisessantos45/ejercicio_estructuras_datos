#include <stdio.h>

int mostrar(int numero);
long long sumarPrimos(int num);
int validarNumero(int cont, int cont2);

int main() {
	
	int numero;
	scanf("%d",&numero);
	if(validarNumero(numero, 2)==0 || numero<3){
		printf("%d ",numero);
	}else{
		mostrar(numero);
	}
	return 0;
}

int mostrar(int numero){
	int original=numero;
	int suma=0,anterior=numero;
	long long resul;
	
	while(suma!=original){
		resul=sumarPrimos(numero);
		numero=resul;
		suma+=resul;
		if(suma>original){
			suma-=resul;
		}
		if(anterior!=suma){
			printf("%lld ",resul);
		}
		anterior=suma;
	}
	return 0;
}
	
	long long sumarPrimos(int num){
		int cont=0, primo,cont2,divisores;
		while(cont<num){
			cont2=2;
			divisores=validarNumero(cont,cont2);
			if(divisores==0){
				primo=cont;
			}
			cont++;
		}
		return primo;
	}
		
		int validarNumero(int cont,int cont2){
			int encontrado=0;
			while(cont2<cont && encontrado<1){
				if(cont%cont2==0){
					encontrado++;
				}
				cont2++;
			}
			return encontrado;
		}
			
