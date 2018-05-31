/*
Ingresar un vector de 10 números reales mediante una función llamada CARGA. Luego
mediante una segunda función llamada INVERTIR generar un segundo vector del mismo
tamaño con los elementos ubicados en el orden inverso al del vector original.
*/
#include <stdio.h>
#include <conio.h>

/*
Llena un array de 10 numeros
ARGS:
vec[] = el array a llenar
*/
void carga(int vec[])
{
    int i;
    printf("Ingrese 10 numeros: ");
    for(i = 0; i < 10; i++)
    {
        fflush(stdin);
        scanf("%d", &vec[i]);
    }
}

/*
Invierte un array de tamaño 10
ARGS:
v1[] = array original
v2[] = array invertido
*/
void invertir(int v1[], int v2[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        v2[9-i] = v1[i];
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
    int vec[10];
    int vec2[10];
    carga(vec);
    invertir(vec, vec2);
    mostrar(vec, 10);
    mostrar(vec2, 10);
    getch();
    return 0;
}
