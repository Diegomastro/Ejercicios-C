/*
Ingresar una matriz de 3x3 por teclado y un número entero. 
Realizar el producto de la matriz por la constante.
*/

#include <stdio.h>
#define FILAS 3
#define COLS  3

/*
Pide al usuario que llene un array2d de tamaño 'FILAS' x 'COLS'
PREREQS:
#define FILAS algo
#define COLS  algo
ARGS:
arr[][] = array a llenar 
*/
void get_arr2d(int arr[][COLS])
{
	int i,
		j;

	for (i = 0; i < FILAS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			printf("Posicion %d, %d: ", i, j);
			scanf("%d", &arr[i][j]);
			fflush(stdin);

		}
	}
}

/*
Pide al usuario que ingrese un numero
*/
int get_k()
{
	int k;
	printf("Constante: ");
	scanf("%d", &k);
	return k;
}

/*
A cada numero de un array2d lo multiplica por 'k', 
devuelve el array2d ya multiplicado
ARGS:
arr[][] = array2d a multiplicar
k       = numero por el cual multiplicar
*/
void mult_arr2d(int arr[][COLS], int k)
{
	int i,
		j;

	for (i = 0; i < FILAS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			arr[i][j] *= k;
		}
	}
}

/*
Printea un array2d
ARGS:
arr[][] = array2d a mostrar
*/
void print_arr2d(int arr[][COLS])
{
	int i,
		j;
	for (i = 0; i < FILAS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			printf("%5d ", arr[i][j]);
		}
	printf("\n");
	}
}

int main()
{
	int arr[3][3],
		k;

	get_arr2d(arr);
	k = get_k();
	mult_arr2d(arr, k);
	print_arr2d(arr);
	return 0;
}