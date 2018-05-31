/*
Se deben ingresar los códigos de 15 productos de una empresa (números de 3 dígitos)
Luego se ingresan las ventas realizadas durante el día. Por cada venta se ingresa código de
vendedor, código de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005
Se puede recibir más de una venta de un mismo vendedor y articulo.
El ingreso de datos finaliza con código de vendedor igual a 0.
Se desea:
a) Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas
CANTIDAD CODIGO
XXX XXX
XXX XXX
b) Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades)
*/

#include <stdio.h>

/*
Printea un array
ARGS:
arr[] = array a mostrar
len   = tamaño del array
*/
void printarr(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/*
Printea dos arrays en paralelo. por ej
arr1 = {'a1', 'a2', 'a3'}
arr2 = {'b1', 'b2', 'b3'}
result = 'a1' 'b1' ; 'a2' 'b2' ; 'a3' 'b3' 
ARGS:
arr1[] = primer array a mostrar
arr2[] = segundo array a mostrar
len    = tamaño de los arrays 
*/
void print_paralelo(int arr1[], int arr2[], int len)
{
	int i;
	for (i = len-1; i > 0; i--)
	{
		printf("%5d %5d \n", arr1[i], arr2[i]);
	}
}

/*
ordena de menor a mayor un array, y hace los mismos movimientos en el segundo. 
Funciona como un dict de  python. ej:
arr1 {3,1,2}
arr2 {'bananas', 'manzanas', 'naranjas'}
result : {1,2,3} ; {'manzanas', 'naranjas', 'bananas'}
ARGS:
arr1[] = array a evaluar, array independiente
arr2[] = array dependiente
len    = tamaño de los arrays
*/
void sort_paralelo(int arr1[], int arr2[], int len)
{
	int i, 
		j,
		aux;

	for (i = 0; i < len-1; i++)
	{
		for (j = 0; j < len-1-i; j++)
		{
			if (arr1[j] > arr1[j+1])
			{
				aux = arr1[j];
				arr1[j] = arr1[j+1];
				arr1[j+1] = aux;

				aux = arr2[j];
				arr2[j] = arr2[j+1];
				arr2[j+1] = aux;
			}
		}
	}
}

/* 
Devuelve la posicion de la primera ocurrencia de 'valor' en 'arr'
ARGS:
valor = valor a buscar
arr[] = array en el que buscar 'valor'
len   = tamaño del array
RETURNS:
-1 = 'valor' no esta en 'arr'
otro = posicion de la primera ocurrencia de 'valor' en 'arr'
*/
int indexof(int valor, int arr[], int len) 
{
	int i;
	for (i = 0; i < len; i++)
	{
		if(valor == arr[i])
		{
			return i;
		}
	}
	return -1;
}

/*
Pide al usuario que cargue 15 productos.
VALORES VALIDOS:
(Numeros de 3 cifras) &&
(Cada valor puede ser ingresado una sola vez)
*/
void get_productos(int productos[])
{
	int i;
	for (i = 0; i < 15; i++)
	{
		printf("Ingresar cod. producto %d: ", i+1);
		scanf("%d", &productos[i]);
		fflush(stdin);
		if (!(100 <= productos[i] && productos[i] <= 999))
		{
			printf("COD. DEBE SER DE 3 CIFRAS! \n");
			i--;
			continue;
		}
		if (indexof(productos[i], productos, i) != -1)    /*if productos[i] esta en productos*/
		{
			printf("ESE COD. YA FUE INGRESADO!\n");
			i--;
			continue;
		}
	}
}

/*
Pide al usuario y valida el codigo de vendedor
VALORES VALIDOS:
(1001 <= valor <= 1005) || 0
*/
int get_vendedor()
{
	int vendedor;
	while (1)
	{
		printf("Cod. de vendedor: ");
		scanf("%d", &vendedor);
		fflush(stdin);
		if ((1001 <= vendedor && vendedor <= 1005) || (vendedor == 0)) break;
		printf("COD DEBE ESTAR ENTRE 1001-1005! (o 0 para terminar)\n");
	}
	return vendedor;
}

/*
Pide al usuario y valida un codigo de producto
VALORES VALIDOS:
(Numeros que esten en 'productos')
ARGS:
productos[] = lista de codigos validos
*/
int get_cod(int productos[])
{
	int cod;
	while(1)
	{
		printf("Cod. de producto: ");
		scanf("%d", &cod);
		fflush(stdin);
		if (indexof(cod, productos, 15) != -1) break;   /*if (cod esta en productos) break*/
		printf("CODIGO INVALIDO! \n");
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
		printf("Cant. de unidades: ");
		scanf("%d", &cant);
		fflush(stdin);
		if (cant > 0) break;
		printf("CANT. DEBE SER POSITIVA! \n");
	}
	return cant;
}


int main()
{
	int cant,
		cod,
		i,
		vendedor;
	
	int productos[15],
		vendedores[5] = {1001, 1002, 1003, 1004, 1005},
		vendidas[15] = {0},
		ventas[5] = {0};

	get_productos(productos);

	while (1)
	{
		vendedor = get_vendedor();
		if (vendedor == 0) break; 
		cod = get_cod(productos);
		cant = get_cant();
		vendidas[indexof(cod, productos, 15)] += cant;
		ventas[vendedor-1001] ++;
		printf("VENTA REGISTRADA! \n");
	}
	sort_paralelo(vendidas, productos, 15);
	print_paralelo(productos, vendidas, 15);
	printf("---\n");

	printf("MENORES VENTAS: \n");
	sort_paralelo(ventas, vendedores, 5);
	for(i = 0; i < 5; i++)
	{
		printf("%d ", vendedores[i]);
		if (ventas[i] != ventas[i+1]) break;
	}
	return 0;
}
