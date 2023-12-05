#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

int stack[MAXN];
int top = -1;

void push(int value) {
	stack[++top] = value;
}

void pop() {
	--top;
}

int peek() {
	return stack[top];
}

int main() {
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; ++i) {
		int value;
		scanf("%d", &value);
		
		while (top >= 0 && peek() == value) {
			pop();
			value *= 2;
		}
		
		push(value);
	}
	
	printf("%d\n", top + 1);
	for (int i = top; i >= 0; --i) {
		printf("%d\n", stack[i]);
	}
	
	return 0;
}
