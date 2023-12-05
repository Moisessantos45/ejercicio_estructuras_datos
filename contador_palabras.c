#include <stdio.h>
#include <string.h>

int main() {
	char frase[100];
	gets(frase); 
	
	char *token = strtok(frase, " ");
	while (token != NULL) {
		printf("\"%s\" tiene %d caracteres\n", token, strlen(token));
		token = strtok(NULL, " ");
	}
	
	return 0;
}
