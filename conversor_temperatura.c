#include <stdio.h>

int main() {
	int temperatura,verificar=1,centigrados;
	scanf("%d", &temperatura);
	centigrados = (temperatura - 32) * 5 / 9;
	if (centigrados <= 36) {
		verificar = 0;
	}
	printf("%d %d\n", centigrados, verificar);
}
