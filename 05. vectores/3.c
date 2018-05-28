/*
Realizar una función que reciba por parámetro dos vectores enteros de 5 elementos cada
uno y genere un vector de 10 posiciones con el contenido de ambos vectores intercalados.
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

void combinar(int v1[], int v2[], int v3[])
{
    int i;
    for(i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            v3[i] = v1[i/2];
        }
        else
        {
            v3[i] = v2[i/2];
        }
    }

}

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
