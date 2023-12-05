#include <stdio.h>

void invertir(int arr[], int inicio, int fin) {
	if (inicio >= fin)
		return;
	int temp = arr[inicio];
	arr[inicio] = arr[fin];
	arr[fin] = temp;
	invertir(arr, inicio + 1, fin - 1);
}

int main() {
	int arr[] = {2, 7, 1 ,8};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	invertir(arr, 0, n - 1);
	
	printf("Arreglo invertido: \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	return 0;
}


