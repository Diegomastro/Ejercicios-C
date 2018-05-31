/*
Realizar una función que reciba por parámetro dos vectores enteros de 5 elementos cada
uno y genere un vector de 10 posiciones con el contenido de ambos vectores uno a
continuación del otro.
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
Combina dos arrays, uno atras del otro. por ej:
v1 = {1,2,3,4,5}; 
v2 = {6,7,8,9,10};
v3 = {1,2,3,4,5,6,7,8,9,10}
ARGS:
v1[] = primer array a combinar
v2[] = segundo array a combinar
v3[] = v1 y v2 combinados
*/
void combinar(int v1[], int v2[], int v3[])
{
    int i;
    for(i = 0; i < 5; i++)
    {
        v3[i] = v1[i];
    }
    for (i = 5; i < 10; i++)
    {
        v3[i] = v2[i-5];
    }
}

/*
Printea un array
ARGS:
vec[] = array a mostrar
len   = tamaño del array
*/
void mostrar(int vec[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int main()
{
    int v1[5] ;
    int v2[5] ;
    int v3[10];
    carga(v1, 5);
    carga(v2, 5);
    combinar(v1, v2, v3);
    mostrar(v3, 10);
    getch();
    return 0;
}
