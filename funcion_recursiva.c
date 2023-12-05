#include <stdio.h>

int recursivo(int a, int b);

int main() {
	
	int resul;
	int a,b;
	scanf("%d %d", &a,&b);
	resul=recursivo(a,b);
	printf("%d ", resul);
	return 0;
}

int recursivo(int a, int b){
	if(a<b){
		return 20;
	}
	if(a==b){
		return recursivo(a-2,b-2)*2;
	}else if(a>b){
		return recursivo(a-1,b-1)+2;
	}
}
