#include <stdio.h>

int main() {
	int P, S, B;
	scanf("%d %d %d", &P, &S, &B);
	
	char terreno[1001];
	scanf("%s", terreno);
	
	int tiempo_total = 0;
	for (int i = 0; terreno[i] != '\0'; i++) {
		if (terreno[i] == '-') {
			tiempo_total += P;
		} else if (terreno[i] == '/') {
			tiempo_total += S;
		} else if (terreno[i] == '\\') {
			tiempo_total += B;
		}
	}
	
	printf("%d\n", tiempo_total);
	
	return 0;
}
