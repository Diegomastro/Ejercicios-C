/*
(Vectores Paralelos y Búsqueda)
2) Idem ejercicio anterior pero con código de productos no correlativos de 4 dígitos. Los códigos deben solicitarse al
iniciar el programa mediante la función IngresaCodigos.
(Máximo y Mínimo)
3) Determinar en el ejercicio anterior:
a. El / los productos del cual se solicitaron mayor cantidad de unidades
b. El / los productos del cual se solicitaron menos cantidad de unidades
*/
#include <stdio.h>
#include <conio.h>

void IngresaCodigos(int v[], int len)
{
	int i = 0, j;
	printf("INGRESAR CODIGOS DE 4 DIGITOS; PARA FINALIZAR INTRODUZCA UNA LETRA\n");
	while (1)
	{
		printf("Ingresar codigo: ");
		scanf("%d", &v[i]);
		fflush(stdin);
		if (v[i] == 0) break;
		if (!(1000 <= v[i] && v[i] <= 9999))
		{
			printf("CODIGO INVALIDO\n");
			continue;
		}
		for (j = 0; j < i; j++)
		{
			if (v[i] == v[j])
			{
				printf("CODIGO INVALIDO\n");
				continue;
			}
		}
		i++;
	}
}

int get_cod(int cods[], int len)
{
	int cod;
	int i;
	int valido = 0;
	while(1)
	{
		printf("Cod: ");
		scanf("%d", &cod);
		fflush(stdin);
		for (i = 0; i < len; i++)
		{
			if (cods[i] == 0) break;
			if (cod == cods[i] || cod == 0)
			{
				valido = 1;
				break;
			}
		}
		if (valido == 1) break;
		printf("CODIGO INVALIDO!!!\n");
	}
	return cod;
}

int get_cant()
{
	int cant;
	while(1)
	{
	printf("Cant: ");
	scanf("%d", &cant);
	fflush(stdin);
	if (cant > 0) break;
	printf("CANT INVALIDA; DEBE SER POSITIVA");
	}
	return cant;
}

/*solo funciona con valores validados,
NO CUBRE SI NUM NO ESTA EN V[] */
int find_index(int num, int v[]) 
{                                
	int i = 0;
	while (1)
	{
		if (num == v[i]) break;
		i++;
	}
	return i;
}


/* NO HACE FALTA QUE NUM ESTE EN V[] */
int find_index_safe(int num, int v[], int len)
{
	int i = 0,
		pos = -1;
	while(pos == -1 && i < len)
	{
		if (num == v[i])
		{
			pos = i;
		}
		i++;
	}
	return pos;
}

int get_mayor(int v[], int len)
{
	int mayor = v[0];
	int i;
	for (i = 0; i < len; i++)
	{
		if (v[i] > mayor)
		{
			mayor = v[i];
		}

	}
	return mayor;
}

int get_menor(int v[], int len)
{
	int menor = v[0];
	int i;
	for (i = 0; i < len; i++)
	{
		if (v[i] < menor  &&  v[i] != 0)
		{
			menor = v[i];
		}
	}
	return menor;
}

void parallel_print(int value,int arr_to_look[],  int arr_to_print[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (arr_to_look[i] == value)
		{
			printf("%d \n", arr_to_print[i]);
		}
	}
}

int main()
{
	int cods[10] = {0};
	int vendidos[10] = {0};
	int mayores[10] = {0};
	int menores[10] = {0};
	int cod, cant, i, max, min;

	IngresaCodigos(cods, 10);
	while (1)
	{
		cod   = get_cod(cods, 10);
		if (cod == 0) break;
		cant  = get_cant();
		vendidos[index] += cant;
	}

	for (i = 0; i < 10; i++)
	{
		if (cods[i] == 0) break;
		printf("%d : %d \n", cods[i], vendidos[i]);
	}
	max = get_mayor(vendidos, 10);
	min = get_menor(vendidos, 10);
	printf("MAXIMOS: (%d unids.)\n", max);
	parallel_print(max, vendidos, cods, 10);
	printf("MINIMOS: (%d unids.)\n", min);
	parallel_print(min, vendidos, cods, 10);
	return 0;
}
