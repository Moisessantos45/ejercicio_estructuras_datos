#include <stdio.h>
#include <math.h>

double formula(float valor_x, float valor_y, float valor_z);

int main() {
	float valor_x, valor_y, valor_z;
	double resultado;
	scanf("%f %f %f", &valor_x, &valor_y, &valor_z);
	resultado = formula(valor_x, valor_y, valor_z);
	printf("%.6f", resultado);
}

double formula(float valor_x, float valor_y, float valor_z) {
	double respuesta;
	float resultado;
	respuesta = ((2*valor_x+3)/valor_z)*((roundf(pow(valor_y,3) * 100) / 100)-valor_z)/((valor_x+2*(valor_y)+3*(valor_z))/(valor_z-2*(valor_y)-3*(valor_x))+(roundf(pow(valor_x,2) * 100) / 100)+(roundf(pow(valor_z,2) * 100) / 100));
	return respuesta;
}



