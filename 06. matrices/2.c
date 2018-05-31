/*
Ingresar una matriz de 2x3 por teclado. 
Calcular la matriz traspuesta.
{                {
{1,2,3},  ---->  {1,2},
{4,5,6}   ---->  {3,4},
}                {5,6}
                 }
*/

#include <stdio.h>
#define FILAS 2
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
Printea un array2d
ARGS:
arr[][] = array2d a mostrar
*/
void print_arr2d(int arr[][FILAS])
{
	int i,
		j;
	for (i = 0; i < COLS; i++)
	{
		for (j = 0; j < FILAS; j++)
		{
			printf("%5d ", arr[i][j]);
		}
	printf("\n");
	}
}

/*
agarra un array2d y lo devuelve traspuesto; las filas pasan a  ser columnas y viceversa. ej:
{1,2,3},      {1,4},
{4,5,6}; ---> {2,5},
              {3,6};
*/
void trasponer(int arr[][COLS], int arr2[][FILAS])
{
	int i,
		j;
	for (i = 0; i < FILAS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			arr2[j][i] = arr[i][j];
		}
	}
}

int main()
{
	int arr[FILAS][COLS];
	int arr2[COLS][FILAS];

	get_arr2d(arr);
	trasponer(arr, arr2);
	print_arr2d(arr2);
}