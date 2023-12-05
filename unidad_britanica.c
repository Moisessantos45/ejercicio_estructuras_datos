#include <stdio.h>
#include <math.h>

int main() {
	int pulgadas;
	int millas, furlongs, yardas, pies, pulgadas_completas;
	scanf("%d",&pulgadas);
	
	millas =round(pulgadas/63360);
	pulgadas %= 63360;
	
	furlongs =round(pulgadas/7920);
	pulgadas %= 7920;
	
	yardas =round(pulgadas/36);
	pulgadas %= 36;
	
	pies =round(pulgadas/12);
	pulgadas %= 12;
	
	pulgadas_completas = pulgadas;
	
	printf("%d %d %d %d %d", millas,furlongs,yardas,pies,pulgadas_completas);
}

