#include <stdio.h>
#define FILA 100
#define COL 100

void llenarMatrix(int matrix[][COL], int fila, int col);
void separarMatriz(int matrix[][COL], int fila, int col);
void ordenarSecuencia(int caja[], int fila, int col);
int ordernarRespuesta(int caja[], int fila, int col);
void imprimirMatrix(int matriz[][COL], int fila, int col);

int main()
{
	int matriz[FILA][COL];
	int filas, columnas;
	scanf("%d %d", &filas, &columnas);
	llenarMatrix(matriz, filas, columnas);
	separarMatriz(matriz, filas, columnas);
	imprimirMatrix(matriz, filas, columnas);
	return 0;
}

void llenarMatrix(int matrix[][COL], int fila, int col)
{
	for (int i = 0; i < fila; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
}

void separarMatriz(int matrix[][COL], int fila, int col)
{
	for (int t = 0; t < col; t++)
	{
		int columna[fila];
		for (int i = 0; i < fila; i++)
		{
			columna[i] = matrix[i][t];
		}
		ordenarSecuencia(columna, 0, fila - 1);
		for (int i = 0; i < fila; i++)
		{
			matrix[i][t] = columna[i];
		}
	}
}

int ordernarRespuesta(int caja[], int fila, int col)
{
	int valor = caja[col];
	int i = fila - 1;
	for (int j = fila; j <= col - 1; j++)
	{
		if (caja[j] < valor)
		{
			i++;
			int temp = caja[i];
			caja[i] = caja[j];
			caja[j] = temp;
		}
	}
	int temp = caja[i + 1];
	caja[i + 1] = caja[col];
	caja[col] = temp;
	return i + 1;
}

void ordenarSecuencia(int caja[], int fila, int col)
{
	if (fila < col)
	{
		int parte = ordernarRespuesta(caja, fila, col);
		ordenarSecuencia(caja, fila, parte - 1);
		ordenarSecuencia(caja, parte + 1, col);
	}
}

void imprimirMatrix(int matriz[][COL], int fila, int col)
{
	for (int i = 0; i < fila; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}
