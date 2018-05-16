/**
Se ingresan 50 números enteros.
Determinar el promedio de los números pares.
*/

#include <stdio.h>
#define CANT_NUMS 50

int main()
{
    int i,
        num,
        suma = 0,
        cant_pares = 0;
    float promedio;

    printf("Ingrese 50 numeros: ");
    for (int i=0; i<CANT_NUMS; i++)
    {
        scanf("%d",&num);
        if (num % 2 == 0)
        {
            suma += num;
            cant_pares += 1;
        }
    }
    promedio = (float)suma / cant_pares;
    printf("Promedio de los pares: %.4f", promedio);
    return 0;

}
