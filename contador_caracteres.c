#include <stdio.h>
#include <string.h>

int main() {
	int N;
	printf("Ingrese el n�mero de l�neas que desea leer: ");
	scanf("%d", &N);
	fflush(stdin); // Limpia el b�fer de entrada
	
	for (int i = 0; i < N; i++) {
		char frase[100];
		printf("Ingrese una l�nea de texto: ");
		fflush(stdin); // Limpia el b�fer de entrada antes de cada lectura
		gets(frase);
		
		char *token = strtok(frase, " ");
		while (token != NULL) {
			printf("\"%s\" tiene %d caracteres\n", token, strlen(token));
			token = strtok(NULL, " ");
		}
	}
	
	return 0;
}
