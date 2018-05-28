/*
Construir una función que reciba dos vectores enteros de igual tamaño y retorne un 1 si
iguales o un 0 sino lo son.
*/
#include <stdio.h>
#include <conio.h>

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
