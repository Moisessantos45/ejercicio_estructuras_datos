#include <stdio.h>

int posibles(int valor_a,int valor_b,int valor_c, int valor_d);
int vericar_numeros(int num_1,int num_2,int num_3);
int vericar_letras(int letra_1,int letra_2);

int main() {
	int letra_a, letra_b, letra_c, letra_d;
	int cantidad;
	scanf("%d %d %d %d", &letra_a, &letra_b, &letra_c, &letra_d);
	cantidad=posibles(letra_a,letra_b,letra_c,letra_d);
	printf("%d",cantidad);
	
	return 0;
}

int posibles(int valor_a,int valor_b,int valor_c, int valor_d){
	int cantidad=0;
	
	for(int num1=valor_a;num1<=valor_b;num1++){
		for(int num2=valor_a;num2<=valor_b;num2++){
			for(int num3=valor_a;num3<=valor_b;num3++){
				if(vericar_numeros(num1,num2,num3)){
					for(int letra1=valor_c; letra1<=valor_d;letra1++){
						for(int letra2=valor_c;letra2<=valor_d;letra2++){
							if(vericar_letras(letra1,letra2)){
								cantidad++;
							}
						}
					}
				}
			}
		}
	}
	
	return cantidad;
}
int vericar_numeros(int num_1,int num_2,int num_3){
	return num_1!=num_2 && num_1!=num_3 && num_2!=num_3;
}
	
int vericar_letras(int letra_1,int letra_2){
	return letra_1!=letra_2;
}

