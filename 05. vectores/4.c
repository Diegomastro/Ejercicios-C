/*
Construir una función que reciba dos vectores enteros de igual tamaño y retorne un 1 si
iguales o un 0 sino lo son.
*/
#include <stdio.h>
#include <conio.h>

/*
Llena un array
ARGS:
vec[] = el array a llenar
len   = tamaño del array
*/
void carga(int vec[], int len)
{
    int i;
    printf("Ingrese %d numeros: ", len);
    for(i = 0; i < len; i++)
    {
        fflush(stdin);
        scanf("%d", &vec[i]);
    }
}

/*
Chequea si dos arrays son iguales
ARGS:
v1[] = primer array a comparar
v2[] = segundo array a comparar
len  = tamaño de los arrays (o hasta que posicion se quiere chequear)
RETURNS:
0 = False
1 = True
*/
int iguales(int v1[], int v2[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (v1[i] != v2[i])
            return 0;
    }
    return 1;
}

int main()
{
    int v1[10];
    int v2[10];
    carga(v1, 10);
    carga(v2, 10);
    printf("--- \n%d \n---", iguales(v1, v2, 10));
    getch();
    return 0;
}
