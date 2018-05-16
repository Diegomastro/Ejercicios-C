/*
En un proceso de control se evalúan valores de temperatura, finalizando cuando de ingresa un valor
ficticio de temperatura -50.
Determinar el valor máximo y mínimo medido y sus posiciones respecto al ingreso.
NOTA: TODOS LOS VALORES MEDIDOS SON DISTINTOS
*/

#include <stdio.h>
#include <conio.h>
#include <limits.h>

int main()
{
    int num,
        max = INT_MIN,
        min = INT_MAX,
        ordmax = 0,
        ordmin = 0,
        count = 0;

    printf("Para finalizar ingrese -50 como temperatura \n --- \n");
    printf("Ingrese las temperaturas: ");
    while (1)
    {
        scanf("%d", &num);
        fflush(stdin);
        if (num == -50)
        {
            break;
        }
        if (num > max)
        {
            max = num;
            ordmax = count;
        }
        if  (num < min)
        {
            min = num;
            ordmin = count;
        }
        count++;
    }
    printf("Valor minimo: %d (%d^ valor ingresado) \n", min, ordmin);
    printf("Valor maximo: %d (%d^ valor ingresado) \n", max, ordmax);
    getch();
    return 0;
}
