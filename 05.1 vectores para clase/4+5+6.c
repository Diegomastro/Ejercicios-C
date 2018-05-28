/*
Se ingresan DNI, código de sector (1 a 5) y sueldo de los empleados de una empresa. Se sabe que como máximo la
empresa tiene 100 empleados. Se desea:
a. Cargar los datos de los empleados mediante la función CargaEmpleados. La carga finaliza con un empleado
con DNI 99.
b. Generar un vector con la cantidad de empleados en cada sector mediante la función CuentaPorSector y
mostrarlo en forma de listado.
c. Determinar el importe total a pagar de sueldos mediante la función TotalAPagar
d. Mostrar el listado de empleados ordenado por sueldo de mayor a menor.
e. Mostrar un listado ordenado de menor a mayor por cantidad de empleados en cada sector
*/

#include <stdio.h>
#include <conio.h>

int get_dni()
{
	int dni;
	while (1)
	{
		printf("DNI: ");
		scanf("%d", &dni);
		fflush(stdin);
		if ((10000000 <= dni && dni <= 99999999)  || (dni == 99)) break;
		printf("DNI INVALIDO! (8 cifras o '99' para terminar)\n");
	}
	return dni;
}

int get_sector()
{
	int sector;
	while (1)
	{
		printf("COD. DE SECTOR: ");
		scanf("%d", &sector);
		fflush(stdin);
		if (1 <= sector && sector <= 5) break;
		printf("SECTOR INVALIDO (1-5) \n");
	}
	return sector;
}

float get_sueldo()
{
	float sueldo;
	while (1)
	{
		printf("SUELDO: ");
		scanf("%f", &sueldo);
		fflush(stdin);
		if (sueldo > 0) break;
		printf("SUELDO INVALIDO (Debe ser positivo) \n");
	}
	return sueldo;
}

void cargaEmpleados(int num, int dni[], int sector[], float sueldo[])
{
	int cod;

	dni[num] = get_dni();
	if (dni[num] == 99) return;

	cod = get_sector();
	sector[cod-1]++;
	sueldo[num] = get_sueldo();
}

void printarr_int(int arr[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

float TotalAPagar(float arr[], int len)
{
	int i, 
		res = 0;	

	for (i = 0; i < len; i++)
	{
		res += arr[i];
	}
	return res;
}

void sort(int arr[], int len)
{
	int i,
		j,
		aux;

	for (i=0; i < len-1; i++)
	{
		for (j=0; j < len-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				aux      = arr[j];
				arr[j]   = arr[j+1];
				arr[j+1] = aux;
			}
		}
	}
}

int main()
{
	int dni[100];
	int sector[5] = {0};
	float sueldo[100];
	int i;
	int cant_empleados;
	float total;

/* <A> */
	for (i = 0; i < 100; i++)
	{
		cargaEmpleados(i, dni, sector, sueldo);
		if (dni[i] == 99)
		{
			cant_empleados = i;
			break;
		}
	}
/* </A> */

/* <B> */
	printf("TOTAL POR SECTOR: \n");
	printarr_int(sector, 5);
/* </B> */

/* <C> */	
	total = TotalAPagar(sueldo, cant_empleados);
	printf("TOTAL A PAGAR: $%.2f ", total);
/* </C> */

/* <D> */
/* d. Mostrar el listado de empleados ordenado por sueldo de mayor a menor. */
/* </D> */

/* <E> */
/* e. Mostrar un listado ordenado de menor a mayor por cantidad de empleados en cada sector */
/* </E> */

	return 0;
}

