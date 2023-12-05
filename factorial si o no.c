#include <stdio.h>
#include <math.h>

int main() {
	int i,dato,fac;
	float num, suma;
	printf("Ingresa un numero: ");
	scanf("%f", &num);
	dato=num;
	suma=0;
	while(i>0){
		i=1;
		fac=1;
		while(i<=(dato%10)){
			fac=fac*1;
			i=i+1;
		}
		dato=trunc(dato/10);
		suma=suma+fac;
	}
	
	return 0;
}

