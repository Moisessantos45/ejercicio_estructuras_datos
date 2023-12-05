#include <stdio.h>

int dibujarTriangulo(int num);

int main() {
	int numero; 
	scanf("%d",&numero);
	dibujarTriangulo(numero);
	return 0;
}

int dibujarTriangulo(int num) {
	int espacio = num/ 2;
	
	for (int i = 0; i < num; i += 2) {
		int arrobas = i + 1;
		int espacios= espacio - (i / 2);
		
		for (int j = 0; j < espacios; j++) {
			printf(" ");
		}
		for (int j = 0; j < arrobas; j++) {
			printf("@");
		}
		printf("\n");
	}
	
	return 0;
}
