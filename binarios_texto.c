#include <stdio.h>
#include <stdbool.h>

#define MAX 100
typedef struct
{
    int clave;
    char nombre[50];
    float precio;
    int cantidad;
} TCuenta;

void opciones();
void abrir_cuenta(char nombre_file[], TCuenta cuenta);
void consultar_datos(char nombre_file[]);
void crear_txt(char nombre_file[]);
void leer_datos_text();
void ordenar_registros(char nombre_file[]);

int main()
{
    opciones();
}

void opciones()
{
    TCuenta cuenta;
    char caracter = 'r';
    char nombre[50] = "cuentas.bin";
    while (caracter != 's')
    {
        scanf("%c", &caracter);
        switch (caracter)
        {
        case 'A':
            scanf("%d %s %f %d", &cuenta.clave, cuenta.nombre, &cuenta.precio, &cuenta.cantidad);
            abrir_cuenta(nombre, cuenta);
            break;
        case 'C':
            consultar_datos(nombre);
            break;
        case 'O':
            ordenar_registros(nombre);
            break;
        case 'N':
            crear_txt(nombre);
            break;
		case 'L':
			leer_datos_text();
			break;
        default:
            break;
        }
    }
}

void abrir_cuenta(char nombre_file[], TCuenta cuenta)
{
    FILE *fp = NULL;
    fp = fopen(nombre_file, "a+b");
    if (fp == NULL)
    {
        return;
    }
    else
    {
        fwrite(&cuenta, sizeof(TCuenta), 1, fp);
        fclose(fp);
    }
}

void consultar_datos(char nombre_file[])
{
    FILE *fp = NULL;
    TCuenta cuenta;
    fp = fopen(nombre_file, "rb");
    if (fp == NULL)
    {
        return;
    }
    else
    {
        while (fread(&cuenta, sizeof(TCuenta), 1, fp) == 1)
        {
/*            fread(&cuenta, sizeof(TCuenta), 1, fp);*/
            printf("%d %s %.0f %d\n", cuenta.clave, cuenta.nombre, cuenta.precio,cuenta.cantidad);
        }
        fclose(fp);
    }
}

void crear_txt(char nombre_file[])
{
    FILE *fp = NULL,*fp_txt=NULL;
    TCuenta cuentas[MAX];
    int i = 0;
    fp = fopen(nombre_file, "rb");
	fp_txt=fopen("ganancia.txt","w");
    if (fp == NULL)
    {
        return;
    }
	if(fp_txt==NULL){
		return;
	}
    while (fread(&cuentas[i], sizeof(TCuenta), 1, fp) == 1)
    {
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d %s %.0f %d\n", cuentas[j].clave, cuentas[j].nombre, cuentas[j].precio, cuentas[j].cantidad);
		int ganancia=cuentas[j].precio*cuentas[j].cantidad;
		if(ganancia>1000){
			fprintf(fp_txt,"%d %d\n",cuentas[j].clave, ganancia);
		}
		
    }
    fclose(fp);
	fclose(fp_txt);
}

void leer_datos_text(){
	FILE *fp_txt=NULL;
	int clave,cantidad;
	fp_txt=fopen("ganancia.txt","r");
	if(fp_txt==NULL){
		return;
	}
	
	while(fscanf(fp_txt,"%d %d",&clave, &cantidad)==2){
		printf("%d %d\n",clave,cantidad);
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
            if (cuentas[j].precio > cuentas[j + 1].precio)
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
