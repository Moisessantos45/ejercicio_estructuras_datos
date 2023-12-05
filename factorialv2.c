#include <stdio.h>

int main() {
	int t, num, cont=0, j;
	long long fact;
	
	scanf("%d", &t);
	
	while(cont < t) {
		scanf("%d", &num);
		fact = 1;
		j = 2;
		while(j <= num) {
			fact *= j;
			j++;
		}
		printf("%lld\n", fact);
		cont++;
	}
}

