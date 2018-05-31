/*
Una empresa debe registrar los pedidos recibidos de cada uno de sus 10 productos a lo largo del día. Por cada
pedido se recibe:
Código de producto (de 1 a 10)
Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
La carga finaliza cuando se ingresa un producto con código igual a cero.
Al finalizar se debe emitir un listado con código y cantidad de unidades solicitadas de cada producto.
*/
#include <stdio.h>
#include <conio.h>

/*
Pide al usuario y valida un codigo
VALORES VALIDOS:
(0 <= valor <= 10)
*/
int get_cod()
{
	int cod;
	while (1)
	{
		printf("Cod: ");
		scanf("%d", &cod);
		fflush(stdin);
		if (0 <= cod && cod <= 10) break;
		printf("CODIGO INVALIDO! DEBE SER ENTRE 0-10 \n");
	}
	return cod;
}

/*
Pide al usuario y valida una cantidad
VALORES VALIDOS:
(valor > 0)
*/
int get_cant()
{
	int cant;
	while (1)
	{
		printf("Cantidad: ");
		scanf("%d", &cant);
		if (cant > 0) break;
		printf("CANT INVALIDA, NO PUEDE SER NEGATIVA o 0\n");
	}
	return cant;
}

int main()
{
	int i,
		cod,
		cant,
		vendidos[10] = {0};

	while (1)
	{
		cod  = get_cod();
		if (cod == 0) break;
		cant = get_cant();
		vendidos[cod-1] += cant;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%2d: %d \n", i+1, vendidos[i]);
	}
	getch();
	return 0;
}