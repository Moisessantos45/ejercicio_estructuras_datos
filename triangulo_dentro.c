#include <stdio.h>

int main()
{
	int base_triangulo_1, altura_triangulo_1, base_triangulo_2, altura_triangulo_2;
	int rotado=0,triangulo=0;
	scanf("%d %d %d %d", &base_triangulo_1, &altura_triangulo_1, &base_triangulo_2, &altura_triangulo_2);
	
	if ((base_triangulo_1 <= base_triangulo_2 && altura_triangulo_1 <= altura_triangulo_2) ||
		(base_triangulo_1 <= altura_triangulo_2 && altura_triangulo_1 <= base_triangulo_2))
	{
		if(base_triangulo_1 <= altura_triangulo_2 && altura_triangulo_1 <= base_triangulo_2) rotado=1;
		triangulo=1;
		printf("%d %d",triangulo, rotado);
	}
	else if ((base_triangulo_2 <= base_triangulo_1 && altura_triangulo_2 <= altura_triangulo_1) ||
		(base_triangulo_2 <= altura_triangulo_1 && altura_triangulo_2 <= base_triangulo_1))
		{
		if(base_triangulo_2 <= altura_triangulo_1 && altura_triangulo_2 <= base_triangulo_1) rotado=1;
		triangulo=2;
		printf("%d %d",triangulo, rotado);
		}
	else
		{
		printf("%d %d",triangulo, rotado);
		}
}


