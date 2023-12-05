#include <stdio.h>
#include <string.h>
#define NO_EXISTE -1
#define LIMITE_USER 1000
#define MAX_CARACTER 10

typedef struct Banco{
	int num_cuenta;
	char nombre_cuenta[MAX_CARACTER];
	float saldo_cuenta;
} TBanco;

void opciones_banco(int opciones,TBanco cuentas[],int *cantidad_user);
int busqueda_lineal(TBanco cuenta_users[], int cont_user, int numero_cuenta);
void agregar_user(TBanco cuentas[], int *cont_user, int numero_cuenta, char nombre_user[], float saldo_cuenta);
void actulizar_cuentas(TBanco cuentas[], int *cont_user, int numero_cuenta);
void imprimir_consulta(TBanco cuentas[],int numero_cuenta, int cont_user);
void depositar_dinero(TBanco cuentas[],int numero_cuenta,float deposito, int cont_user);
void retirar_dinero(TBanco cuentas[],int numero_cuenta,float retiro,int cont_user);

int main()
{
	TBanco cuentas[LIMITE_USER];
	int cantidad_user = 0;
	int operaciones;
	scanf(" %d", &operaciones);
	opciones_banco(operaciones,cuentas,&cantidad_user);
	return 0;
}

void opciones_banco(int opciones,TBanco cuentas[],int *cantidad_user)
{
	int cont = 1,numero_cuenta;
	char opcion;
	char nombre[MAX_CARACTER];
	float saldo;
	while (cont <= opciones)
	 {
		scanf(" %c", &opcion);
		switch (opcion)
		{
		case 'A':
			scanf("%d %s %f",&numero_cuenta, nombre, &saldo);
			agregar_user(cuentas, *&cantidad_user,numero_cuenta, nombre, saldo);
			break;
		case 'B':
			scanf("%d",&numero_cuenta);
			actulizar_cuentas(cuentas,*&cantidad_user,numero_cuenta);
			break;
		case 'C':
			scanf("%d",&numero_cuenta);
			imprimir_consulta(cuentas,numero_cuenta,*cantidad_user);
			break;
		case 'D':
			scanf("%d %f",&numero_cuenta,&saldo);
			depositar_dinero(cuentas,numero_cuenta,saldo,*cantidad_user);
			break;
		case 'E':
			scanf("%d %f",&numero_cuenta,&saldo);
			retirar_dinero(cuentas,numero_cuenta,saldo,*cantidad_user);
			break;
		}
		cont++;
	}
}

int busqueda_lineal(TBanco cuenta_users[], int cont_user, int numero_cuenta)
{	
	if(cont_user==0) return NO_EXISTE;
	for (int i = 0; i < cont_user; i++)
	{
		if (cuenta_users[i].num_cuenta == numero_cuenta)
		{
			return i;
		}
	}
	return NO_EXISTE;
}

void agregar_user(TBanco cuentas[], int *cont_user, int numero_cuenta, char nombre_user[], float saldo_cuenta)
{
	int validar = busqueda_lineal(cuentas, *cont_user, numero_cuenta);
	if (validar != NO_EXISTE)
	{
		puts("ERROR");
	}
	else
	{
		int posicion = *cont_user;
		cuentas[posicion].num_cuenta =numero_cuenta;
		strcpy(cuentas[posicion].nombre_cuenta, nombre_user);
		cuentas[posicion].saldo_cuenta=saldo_cuenta;
		(*cont_user)++;
		puts("OK");
	}
}

void actulizar_cuentas(TBanco cuentas[], int *cont_user, int numero_cuenta){
	int validar = busqueda_lineal(cuentas, *cont_user, numero_cuenta);
	if(validar==NO_EXISTE){
		puts("ERROR");
	}else{
		int cuenta=validar;
		cuentas[cuenta]=cuentas[*cont_user-1];
		(*cont_user)--;
		puts("OK");
	}
	
}

void imprimir_consulta(TBanco cuentas[],int numero_cuenta, int cont_user){
	int validar = busqueda_lineal(cuentas, cont_user, numero_cuenta);
	if(validar==NO_EXISTE){
		puts("ERROR");
	}else{
		printf("%s %.0f",cuentas[validar].nombre_cuenta,cuentas[validar].saldo_cuenta);
	}
}
	
void depositar_dinero(TBanco cuentas[],int numero_cuenta,float deposito, int cont_user){
	int validar = busqueda_lineal(cuentas, cont_user, numero_cuenta);
	if(validar==NO_EXISTE){
		puts("ERROR");
	}else{
		cuentas[validar].saldo_cuenta+=deposito;
		printf("%s %.0f",cuentas[validar].nombre_cuenta,cuentas[validar].saldo_cuenta);
	}
}

void retirar_dinero(TBanco cuentas[],int numero_cuenta,float retiro,int cont_user){
	int validar = busqueda_lineal(cuentas, cont_user, numero_cuenta);
	if(validar==NO_EXISTE){
		puts("ERROR");
	}else{
		if(cuentas[validar].saldo_cuenta>=retiro){
			cuentas[validar].saldo_cuenta-=retiro;
			printf("%s %.0f",cuentas[validar].nombre_cuenta,cuentas[validar].saldo_cuenta);
		}else{
			puts("ERROR");
		}
	}
}
