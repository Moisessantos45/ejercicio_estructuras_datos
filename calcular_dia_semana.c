#include <stdio.h>

int main() {
	int anio,mes,dia,calcular_dia,residuo,semana,operacion,division;
	int dia_anterior, dia_actual,dia_posterior;
	scanf("%d %d %d",&anio,&mes,&dia);
	if(mes>2){
		mes=mes-2;
	}else{
		mes=mes+10;
		anio=anio-1;
	}
	division=anio/100;
	residuo=anio%100;
	operacion=(13*mes-1)/5+residuo/4+division/4;
	calcular_dia=(operacion+residuo+dia+5*division)%7;
	dia_actual = calcular_dia;
	dia_anterior = (dia_actual == 0) ? 6 : dia_actual - 1;
	dia_posterior = (dia_actual == 6) ? 0 : dia_actual + 1;
	printf("%d %d %d",dia_anterior,dia_actual,dia_posterior );
}

