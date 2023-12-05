#include <stdio.h>

int main() {
	int lado_1,lado_2,lado_3,triangulo=0,faltante=0,minimo;
	scanf("%d %d %d",&lado_1,&lado_2,&lado_3);
	if(lado_1+lado_2>lado_3 && lado_2+lado_3>lado_1 && lado_3+lado_1>lado_2){
		
		if(lado_1==lado_2 && lado_1==lado_3 && lado_2==lado_3) triangulo=1;
		else if(lado_1==lado_2 || lado_2==lado_3 || lado_3==lado_1) triangulo=2;
		else triangulo=3;
	}else{
		minimo = lado_1 > lado_2 ? (lado_1 > lado_3 ? lado_1 : lado_3) : (lado_2 > lado_3 ? lado_2 : lado_3);
		faltante = minimo - (lado_1 + lado_2 + lado_3 - minimo) + 1;
	}
	printf("%d %d",triangulo, faltante);
}

