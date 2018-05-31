/*
Ingresar una matriz de 5x4 por teclado. Realizar una función
que genere un vector con la suma por fila de dicha matriz.
*/

#include <stdio.h>
#define FILAS 5
#define COLS  4

/*
Pide al usuario que llene un array2d de tamanio FILAS x COLS
ARGS:
arr[][] = El array a rellenar; 
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
Llena un array con la suma de cada fila de un array2d 
ARGS:
arr[][] = array2d sobre el que se suma
sumas[] = array donde se guardan las sumas de cada fila de 'arr[][]'
*/
void sacar_sumas(int arr[][COLS], int sumas[])
{
	int i,
		j,
		suma;

	for (i = 0; i < FILAS; i++)
	{
		suma = 0;
		for (j = 0; j < COLS; j++)
		{
			suma += arr[i][j];
		}
		sumas[i] = suma;
	}
}

/*
Printea un array
ARGS:
arr[] = El array a mostrar
*/
void print_arr(int arr[])
{
	int i;

	for (i = 0; i < FILAS; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int arr[FILAS][COLS];
	int sumas[FILAS];

	get_arr2d(arr);
	sacar_sumas(arr, sumas);
	print_arr(sumas);
	return 0;
}