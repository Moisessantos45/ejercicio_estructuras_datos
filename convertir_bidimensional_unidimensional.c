#include <stdio.h>
#include <stdlib.h>
#define N 100

void pideDatos(int *ren, int *col);
void llenaArreglo(int ren, int col, int arregloBi[N][N]);
void cambiaArreglos(int ren, int col, int arregloBi[N][N], int arregloUn[N * N], int *contUn);
void ordenaArreglo(int arregloUn[N * N], int contUn);

int main()
{
	int ren, col, arregloBi[N][N];
	int arregloUn[N * N];
	int contUn = 0;
	
	pideDatos(&ren, &col);
	llenaArreglo(ren, col, arregloBi);
	cambiaArreglos(ren, col, arregloBi, arregloUn, &contUn);
	ordenaArreglo(arregloUn, contUn);
	
	return 0;
}

void pideDatos(int *ren, int *col)
{
	printf("De cuantos renglones sera la matriz: ");
	scanf("%d", ren);
	
	printf("De cuantas columnas sera la matriz: ");
	scanf("%d", col);
}

void llenaArreglo(int ren, int col, int arregloBi[N][N])
{
	int posicion;
	
	for (int cont1 = 0; cont1 < ren; cont1++)
		for (int cont2 = 0; cont2 < col; cont2++)
	{
			scanf("%d", &posicion);
			arregloBi[cont1][cont2] = posicion;
	}
		
		printf("\n");
		
		for (int i = 0; i < ren; i++)
		{
			for (int j = 0; j < col; j++)
				printf("%d ", arregloBi[i][j]);
			
			printf("\n");
		}
		printf("\n");
}

void cambiaArreglos(int ren, int col, int arregloBi[N][N], int arregloUn[N * N], int *contUn)
{
	for (int i = 0; i < ren; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arregloUn[*contUn] = arregloBi[i][j];
//			printf("%lld ", arregloUn[*contUn]);
			(*contUn)++;
		}
	}
}

void ordenaArreglo(int arregloUn[N * N], int contUn)
{
	int posicion;
	int cont, cont2;
	for (cont = 0; cont < contUn; cont++)
	{
		posicion = arregloUn[cont];
		cont2 = cont;
		while (cont2 > 0 && arregloUn[cont2 - 1] > posicion)
		{
			arregloUn[cont2] = arregloUn[cont2 - 1];
			cont2--;
		}
		arregloUn[cont2] = posicion;
	}
	
	for (int i = 0; i < contUn; i++){
		printf("%d ", arregloUn[i]);
	}
		
}
