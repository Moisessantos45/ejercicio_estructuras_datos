#include <stdio.h>

int main() {
	int num,factorial=1,cont=1;
	scanf("%d",&num);
	while(cont<=num){
		factorial=factorial*cont;			
		cont++;
	}
	printf("%d ",factorial);
}

