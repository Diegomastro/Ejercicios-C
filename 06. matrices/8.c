/*
Realizar el juego de tatetí para dos jugadores. El jugador 1 utilizará la letra X y el jugador 2 la letra O para marcar sus
elecciones. El tablero armarlo con una matriz de 3x3 que debe ser visualizada en pantalla en cada jugada marcando
la ubicación elegida por cada jugador.
*/

#include <stdio.h>
#include <ctype.h>

/*
Muestra el tablero en pantalla
ARGS:
tablero =  array2d que contiene 'X','O',' ' 
*/
void mostrarTablero(char tablero[][3])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("\n\n\n");
	}
	printf("+---+---+---+\n");
	for (i = 0; i < 3; i++)
	{
		printf("| %c | %c | %c | \n", tablero[i][0], tablero[i][1], tablero[i][2]);
		printf("+---+---+---+\n");
	}
}

/*
Pide al usuario y valida las coordeanadas en las cuales hacer la jugada
ARGS:
coords  = array donde se guardan las cordenadas
tablero = array2d que contiene 'X','O',' ' 
VALORES VALIDOS:
(1 <= valor <= 3)
NOTA:
Al valor que pone el usuario se le resta uno, porque el usuario mete valores
entre 1 y 3 pero los indices de 'tablero[][]' son entre 0 y 2
*/
void get_coords(int coords[], char tablero[][3])
{
	while (1)
	{
		printf("Numero de fila y columna: ");
		scanf("%d%d", &coords[0], &coords[1]);
		fflush(stdin);
		if (1 <= coords[0] && coords[0] <= 3 && 1 <= coords[1] && coords[1] <= 3) /* if (coords[0] && coords[1]) entre 1 y 3 */
		{
			coords[0] -= 1;
			coords[1] -= 1;
			if (tablero[coords[0]][coords[1]] != ' ')
			{
				printf("ESE LUGAR YA ESTA OCUPADO! \n");
				continue;
			}
			break;
		}	
		printf("ERROR! AMBOS VALOLRES DEBEN ESTAR ENTRE 1 Y 3! (Usa la guia de abajo para ayuda)\n\n");
		printf("| 1 1 | 1 2 | 1 3 | \n");
		printf("|-----+-----+-----+ \n");
		printf("| 2 1 | 2 2 | 2 3 | \n");
		printf("|-----+-----+-----+ \n");
		printf("| 3 1 | 3 2 | 3 3 | \n\n");
		printf("Presiona ENTER para continuar\n");
		fflush(stdin);
		getchar();
		fflush(stdin);
		mostrarTablero(tablero);
	}
}

/*
Pone una 'X' o un 'O' en una posicion del tablero
ARGS:
tablero = array2d que contiene 'X','O',' ' 
coords  = array donde se guardan las cordenadas
simbolo = 'X' || 'O'; el 'dibujito' que pone el jugador en el tablero
*/
void jugar(char tablero[][3], int coords[], char simbolo)
{
	tablero[coords[0]][coords[1]] = simbolo;
}

/*
Se fija si gano el jugador 's'
ARGS:
t = tablero (array2d que contiene 'X','O',' ')
s = simbolo ('X' || 'O'; el 'dibujito' que pone el jugador en el tablero)
NOTA:
Puse los args con una letra sola porque sino el if quedaba muy desprolijo
*/
int checkwin(char t[][3], char s)
{
	if ((t[0][0] == s && t[0][1] == s && t[0][2] == s) ||
		(t[1][0] == s && t[1][1] == s && t[1][2] == s) ||
		(t[2][0] == s && t[2][1] == s && t[2][2] == s) ||
		(t[0][0] == s && t[1][0] == s && t[2][0] == s) ||
		(t[0][1] == s && t[1][1] == s && t[2][1] == s) ||
		(t[0][2] == s && t[1][2] == s && t[2][2] == s) ||
		(t[0][0] == s && t[1][1] == s && t[2][2] == s) ||
		(t[0][2] == s && t[1][1] == s && t[2][0] == s))
	{
		return 1;
	}
	return 0;
}

/*
Printea quien ganó
ARGS:
simbolo = 'X' || 'O'; el 'dibujito' que pone el jugador en el tablero
*/
void printwin(char simbolo)
{
	printf("Gana el jugador %c ! \n", simbolo);
}

/*
Pregunta si quiere volver a jugar
RETURNS:
0 = false
1 = true
*/
char reiniciar()
{
	char pregunta;
	int res;
	printf("Presione S si desea jugar otra vez: ");
	scanf("%c", &pregunta);
	(tolower(pregunta) == 's') ? (return 1) : (return 0);
}

/*
Pone todos los valores del tablero en ' '
ARGS:
tablero = array2d que contiene 'X','O',' ' 
*/
void vaciarTablero(char tablero[][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			tablero[i][j] = ' ';
		}
	}
}

int main()
{
	char tablero[3][3];
	int coords[2];
	int i;
	char simbolo; /* X || O ; el simbolo que se pone en el tablero*/

	while (1)
	{
		vaciarTablero(tablero);
		for (i = 1; i <= 9; i++)
		{	
			(i % 2) ? (simbolo = 'X') : (simbolo = 'O'); /* Jugador 1 usa 'X' ; jugador 2 usa 'O' */
			mostrarTablero(tablero);
			get_coords(coords, tablero);
			jugar(tablero, coords, simbolo);
			if (i < 4) continue;
			if (checkwin(tablero, simbolo))
			{
				mostrarTablero(tablero);
				printwin(simbolo);
				if (tolower(reiniciar()) != 's')
				{
					return 0;
				}
			}
		}
		mostrarTablero(tablero);
		printf("EMPATE! \n");
		if (!reiniciar())
		{
			break;
		}
	}
	return 0;
}
