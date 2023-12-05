#include <stdio.h>

int main() {
	int a,b,c,d,e,p,q;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	p=a;
	q=a;
	if(b > q) {
		q = b;
	}
	if(b < p) {
		p = b;
	}
	
	if(c > q) {
		q = c;
	}
	if(c < p) {
		p = c;
	}
	
	if(d > q) {
		q = d;
	}
	if(d < p) {
		p = d;
	}
	
	if(e > q) {
		q = e;
	}
	if(e < p) {
		p = e;
	}
	
	printf("%d %d", p,q);
}

