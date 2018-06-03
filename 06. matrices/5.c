/*
Se desea desarrollar un sistema de reservas de entradas para un cine. La sala consta de 12 filas numeradas de la 1 a
la 12 y cada fila tiene 9 asientos numerados a partir de la fila central, con los asientos impares a la derecha y los
pares a la izquierda, como en el siguiente esquema:
8 6 4 2 1 3 5 7 9
Para la carga, se debe mostrar al usuario un esquema con los asientos disponibles y reservados. Marcando con una
letra D los disponibles y una con una letra R los reservados.
Por cada reserva se debe solicitar la fila y el número de asiento a reservar. Si ya se encuentra reservado se debe
informar con un mensaje para que seleccione otro asiento. Luego de cada reserva aceptada, se debe actualizar el
esquema que muestra los asientos. El ingreso de datos finaliza con una fila con un número negativo.
Al finalizar mostrar la cantidad de asientos disponibles y la cantidad de asientos reservados
*/

#include <stdio.h>

/*
Hace una pausa, pide al usuario que aprete enter para continuar;
NOTA:
Es util antes de 'mostrarAsientos()', asi no se te va a la mierda
todo lo que tenes en pantalla
*/
void pausa()
{
	printf("\nPRESIONA ENTER PARA CONTINUAR \n");
	fflush(stdin);
	getchar();
	fflush(stdin);
}

/*
Pone todos los asientos en 'D' (disponible)
ARGS:
asientos = array2d que guarda el estado de los asientos: 'D' || 'R'
*/
void llenarAsientos(char asientos[][9])
{
	int i,
		j;

	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 9; j++)
		{
			asientos[i][j] = 'D';
		}
	}
}

/*
Muestra el estado de los asientos
ARGS:
asientos = array2d que guarda el estado de los asientos: 'D' || 'R'
*/
void mostrarAsientos(char asientos[][9])
{
	int i,
		j;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	for (i = 0; i < 12; i++)
	{
		for(j = 0; j < 9; j++)
		{
			printf("%c ", asientos[i][j]);
		}
		printf("\n");
	}
}

/*
Pide al usuario y valida una fila
VALORES VALIDOS:
(valor <= 12)
*/
int pedirFila()
{
	int fila;
	while(1)
	{
		printf("Fila: ");
		scanf("%d", &fila);
		if (fila <= 12) break;
		printf("ERROR! filas validas: \n*Entre 1 y 12 \n*0 para ayuda \n*nro. negativo para salir\n");
	}
	return fila;
}

/*
Muestra ayuda sobre la distribucion de los asientos
NOTA:
Hace falta la ayuda, el que numeró los asientos asi es un hdp,
podia haberle puesto (1 2 3 4 5 6 7 8 9) pero le gusto mas (8 6 4 2 1 3 5 7 9)
*/
void ayuda()
{
	int i;
	printf("Los asientos se numeran de la siguiente manera \n");
	for (i = 0; i < 12; i++)
	{
		printf("Fila %02d: 8 6 4 2 1 3 5 7 9 ", i+1);
		printf("\n");
	}
	pausa();
}

/*
Pide al usuario y valida un numero de asiento (una columna para nuestro array2d)
VALORES VALIDOS:
(1 <= valor <= 9)
*/
int pedirCol()
{
	int col;
	while (1)
	{
		printf("N. de asiento: ");
		scanf("%d", &col);
		if (1 <= col && col <= 9) break;
		printf("N. de asiento debe estar entre 1-9\n");
	}
	return col;
}

/*
Chequea si un asiento esta disponible
ARGS:
fila     = fila del asiento
col      = numero de asiento
asientos = array2d que guarda el estado de los asientos: 'D' || 'R'
RETURNS:
0 = false
1 = true
*/
int estaLibre(int fila, int col, char asientos[][9])
{
	int r;
	(asientos[fila][col] == 'D') ? (r = 1) : (r = 0);
	return r;
}

/*
Cambia un asiento de 'D' a 'R'
ARGS:
fila     = fila del asiento
col      = numero de asiento
asientos = array2d que guarda el estado de los asientos: 'D' || 'R'
NOTA:
no chequea si el asiento esta 'D'; 
asi que hay que hacer ese chequeo antes de llamar a esta funcion 
*/
void reservar(int fila, int col, char asientos[][9])
{
	asientos[fila][col] = 'R';
}

int main()
{
	int col,
		disponibles = 0,
		fila,
		i,
		indices[] = {4,3,5,2,6,1,7,8,0},
		j,
		reservados = 0;

	char asientos[12][9];
	llenarAsientos(asientos);

	while (1)
	{
		mostrarAsientos(asientos);

		fila = pedirFila();
		if (fila == 0)
		{
			ayuda();
			continue;
		}
		if (fila < 0) break;

		col = pedirCol();       
		col--;                  /* Transformamos los valores del */
		col = indices[col];     /*  usuario en valores que nos   */
		fila--;                 /*        sirven a nosotros      */

		if (estaLibre(fila, col, asientos))
		{
			reservar(fila, col, asientos);
			printf("ASIENTO RESERVADO CON EXITO! \n");
		}
		else
		{
			printf("ERROR! ASIENTO RESERVADO ANTERIORMENTE\n");
		}
		pausa();
	}

	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 9; j++)
		{
			(asientos[i][j] == 'D') ? (disponibles++) : (reservados++);
		}
	}
	printf("ASIENTOS DISPONIBLES: %d \n", disponibles);
	printf("ASIENTOS RESERVADOS : %d \n", reservados);
	return 0;
}

