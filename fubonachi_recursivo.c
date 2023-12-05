#include <stdio.h>

long long fibonacci_recursive(int num, int *cont);

int main() {
	int n;
	int cont = 0;
	
	scanf("%d", &n);
	long long result = fibonacci_recursive(n, &cont);
	printf("%lld %d",result, cont);
	return 0;
}

long long fibonacci_recursive(int num, int *cont) {
	(*cont)++;
	
	if (num <= 1) {
		return num;
	} else {
		return fibonacci_recursive(num-1, cont) + fibonacci_recursive(num-2, cont);
	}
}



