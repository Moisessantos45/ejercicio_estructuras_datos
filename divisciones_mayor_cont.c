#include <stdio.h>

int divisiones(int num,int *mayor);

int main() {
	int mayor=0;
	int numero,valor;
	scanf("%d",&numero);
	valor=divisiones(numero,&mayor);
	printf("%d %d",valor,mayor);
	return 0;
}

int divisiones(int num,int *mayor){
	int cont;
	if(num==1){
		return 0;
	}	
	if(num%2==0){
		cont=divisiones(num/2,*&mayor);
	}else{
		cont=divisiones((num*3)+1,*&mayor);
	}
	*mayor= *mayor > num ? *mayor : num;
	
	return 1+cont;
}
