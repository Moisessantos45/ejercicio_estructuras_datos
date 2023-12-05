#include <stdio.h>
#include <math.h>

double formula(float valor_x, float valor_y, float valor_z);
float potencia(float num, int elevacion);

int main() {
	float valor_x, valor_y, valor_z;
	double resultado;
	scanf("%f %f %f", &valor_x, &valor_y, &valor_z);
	resultado = formula(valor_x, valor_y, valor_z);
	printf("%.6f", resultado);
}

double formula(float valor_x, float valor_y, float valor_z) {
	double respuesta;
	respuesta = ((2*valor_x+3)/valor_z)*(potencia(valor_y,3)-valor_z)/((valor_x+2*(valor_y)+3*(valor_z))/(valor_z-2*(valor_y)-3*(valor_x))+potencia(valor_x,2)+potencia(valor_z,2));
	return respuesta;
}

float potencia(float num, int elevacion) {
	float resultado = 1;
	for(int i = 0; i < elevacion; i++) {
		resultado *= num;
	}
	resultado = roundf(resultado * 100) / 100; 
	return resultado;
}

