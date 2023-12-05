#include <stdio.h>

long long todoTriangulo(int dato_m,int dato_n);
int verificar(int letra_a,int letra_b,int letra_c);

int main() {
	int valor_n,valor_m;
	long long cantidad=0,valor_a,valor_b,valor_c;	
	scanf("%d %d",&valor_m,&valor_n);
	cantidad=todoTriangulo(valor_m,valor_n);
	printf("%lld",cantidad);
	
	return 0;
}

long long todoTriangulo(int dato_m,int dato_n){
	int resultado=0,valor_a,valor_b,valor_c;
	for(valor_a=dato_m;valor_a<=dato_n; valor_a++){
		for(valor_b=valor_a; valor_b<=dato_n;valor_b++){
			for(valor_c=valor_b;valor_c<=dato_n;valor_c++){
				if(verificar(valor_a,valor_b,valor_c)){
					resultado++;
				}
			}
		}
	}
	return resultado;
}
	
int verificar(int letra_a,int letra_b,int letra_c){
		return (letra_a + letra_b > letra_c && letra_b + letra_c > letra_a && letra_c + letra_a > letra_b && ((letra_a == letra_b && letra_b != letra_c) || (letra_b == letra_c && letra_a != letra_c)));
}

