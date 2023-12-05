#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int num_cuenta;
    char nombre[50];
    float saldo;
} TCuenta;

void opciones();
void abrir_cuenta(char nombre_file[], TCuenta cuenta);
int verificar_cuenta(char nombre_file[], int num_cuenta);
void consultar_data_file(char nombre_file[]);
void consultar_datos(char nombre_file[], int numero_cuenta);
void actulizar_datos(char nombre_file[], int numero_cuenta);
void solicitar_datos(TCuenta *cuenta);
void ordenar_registros(char nombre_file[]);
void cerrar_cuenta(char nombre_file[], char nombre_new_file[], int numero_cuentas);

int main()
{
    opciones();
}

void opciones()
{
    TCuenta cuenta;
    int numero_cuenta;
    char caracter = 'r';
    char nombre[50] = "cuentas.bin";
    char new_nombre[50] = "new_cuentas.bin";
    while (caracter != 's')
    {
        scanf("%c", &caracter);
        switch (caracter)
        {
        case 'A':
            scanf("%d %s %f", &cuenta.num_cuenta, cuenta.nombre, &cuenta.saldo);
            abrir_cuenta(nombre, cuenta);
            break;
        case 'B':
            consultar_data_file(nombre);
            break;
        case 'E':
            scanf("%d", &numero_cuenta);
            cerrar_cuenta(nombre, new_nombre, numero_cuenta);
            break;
        case 'C':
            scanf("%d", &numero_cuenta);
            consultar_datos(nombre, numero_cuenta);
            break;
        case 'U':
            scanf("%d", &numero_cuenta);
            actulizar_datos(nombre, numero_cuenta);
            break;
		case 'O':
			ordenar_registros(nombre);
			break;
        default:
            break;
        }
    }
}

int verificar_cuenta(char nombre_file[], int num_cuenta)
{
    FILE *fp = NULL;
    TCuenta cuentas;
    fp = fopen(nombre_file, "rb");
    if (fp == NULL)
    {
        return 2;
    }

    while (fread(&cuentas, sizeof(TCuenta), 1, fp))
    {
        fread(&cuentas, sizeof(TCuenta), 1, fp);
        if (cuentas.num_cuenta == num_cuenta)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void abrir_cuenta(char nombre_file[], TCuenta cuenta)
{
    FILE *fp = NULL;
    int existe_cuenta = verificar_cuenta(nombre_file, cuenta.num_cuenta);
    fp = fopen(nombre_file, "a+b");
    if (fp == NULL)
    {
        return;
    }
    if (existe_cuenta != 2 && existe_cuenta != 1)
    {
        fwrite(&cuenta, sizeof(TCuenta), 1, fp);
        fclose(fp);
    }
    else if (existe_cuenta == 2)
    {
        printf("No se encontro archivo");
		fclose(fp);
    }
    else
    {
        printf("La cuenta ya existe");
		fclose(fp);
    }
}

void consultar_datos(char nombre_file[], int numero_cuenta)
{
    FILE *fp = NULL;
    TCuenta cuenta;
    int existe_cuenta = verificar_cuenta(nombre_file, numero_cuenta);
    fp = fopen(nombre_file, "rb");
    if (fp == NULL)
    {
        return;
    }
    else if (existe_cuenta == 0)
    {
        return;
    }
    else if (existe_cuenta == 2)
    {
        return;
    }

    while (if (cuenta.num_cuenta == numero_cuenta)==1)
    {        
        {
            printf("%d %s %.0f\n", cuenta.num_cuenta, cuenta.nombre, cuenta.saldo);
            return;
        }
    }
    fclose(fp);
}

void consultar_data_file(char nombre_file[])
{
    FILE *fp = NULL;
    TCuenta cuenta;
    fp = fopen(nombre_file, "rb");
    if (fp == NULL)
    {
        return;
    }
    while (fread(&cuenta, sizeof(TCuenta), 1, fp)==1)
    {
/*        fread(&cuenta, sizeof(TCuenta), 1, fp);*/
        printf("%d %s %.0f\n", cuenta.num_cuenta, cuenta.nombre, cuenta.saldo);
    }
    fclose(fp);
}

void actulizar_datos(char nombre_file[], int numero_cuenta)
{
    FILE *fp = NULL;
    TCuenta cuenta;
    int existe_cuenta = verificar_cuenta(nombre_file, numero_cuenta);
    fp = fopen(nombre_file, "r+b");
    if (fp == NULL)
    {
        return;
    }
	if(existe_cuenta == 2){
		fclose(fp);
		return;
	}
    if (existe_cuenta != 0)
    {        
		fread(&cuenta, sizeof(TCuenta), 1, fp);
        while (!feof(fp))
        {
            if (cuenta.num_cuenta == numero_cuenta)
            {
                solicitar_datos(&cuenta);
				fseek(fp, -sizeof(TCuenta), SEEK_CUR);
                fwrite(&cuenta, sizeof(TCuenta), 1, fp);
				fclose(fp);
                break;
            }
            fread(&cuenta, sizeof(TCuenta), 1, fp);
        }
    }
    else
    {
        printf("La cuenta no existe");
		fclose(fp);
    }
}

void solicitar_datos(TCuenta *cuenta)
{
    char opcion = 'r';
    float dinero;
    while (opcion != 'C')
    {
        scanf(" %c", &opcion);
        switch (opcion)
        {
        case 'N':
            scanf("%s", cuenta->nombre);
            break;
        case 'D':
            scanf("%f", &dinero);
            cuenta->saldo += dinero;
			break;
        case 'R':
            scanf("%f", &dinero);
            cuenta->saldo -= dinero;
			break;
		case 'C':
			printf("Saliendo del programa.\n");
			break;
        default:
            printf("Opcion  no valida");
            break;
        }
    }
}

void ordenar_registros(char nombre_file[])
{
	FILE *fp = NULL;
	TCuenta cuentas[100];
	int num_cuentas = 0;
	int i, j;
	TCuenta temp;
	fp = fopen(nombre_file, "r+b");
	if (fp == NULL)
	{
		printf("No se pudo abrir el archivo\n");
		return;
	}
	
	while (fread(&cuentas[num_cuentas], sizeof(TCuenta), 1, fp))
	{
		num_cuentas++;
	}
	for (i = 0; i < num_cuentas - 1; i++)
	{
		for (j = 0; j < num_cuentas - i - 1; j++)
		{
			if (cuentas[j].num_cuenta > cuentas[j + 1].num_cuenta)
			{
				temp = cuentas[j];
				cuentas[j] = cuentas[j + 1];
				cuentas[j + 1] = temp;
			}
		}
	}
	rewind(fp);
	for (i = 0; i < num_cuentas; i++)
	{
		fwrite(&cuentas[i], sizeof(TCuenta), 1, fp);
	}
	fclose(fp);
}


void cerrar_cuenta(char nombre_file[], char nombre_new_file[], int numero_cuentas)
{
    FILE *fp = NULL, *fp_new = NULL;
    TCuenta cuentas;
    int existe_cuenta = verificar_cuenta(nombre_file, numero_cuentas);
    fp = fopen(nombre_file, "rb");
    fp_new = fopen(nombre_new_file, "wb");
    if (fp == NULL)
    {
        return;
    }
    else if (fp_new == NULL)
    {
        return;
    }
    else if (existe_cuenta == 2)
    {
        return;
    }
    else
    {
        if (existe_cuenta != 0)
        {
            while (fread(&cuentas, sizeof(TCuenta), 1, fp)==1)
            {                
                if (cuentas.num_cuenta != numero_cuentas)
                {
                    fwrite(&cuentas, sizeof(TCuenta), 1, fp_new);
                    printf("%f\n", cuentas.saldo);
                }
            }
            fclose(fp);
            fclose(fp_new);
            remove(nombre_file);
            rename(nombre_new_file, nombre_file);
        }
    }
}
