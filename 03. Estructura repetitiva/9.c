/**
Determinar todos los números primos entre 1 y 100.
Contar dichos números.
*/

#include <stdio.h>

int main()
{
    int i,
        j,
        cant = 1; //Arranca en 1, porque esta contando el '2' de la linea siguiente

    printf("2, "); // 2 es el unico primo par, entonces lo pongo aca y chequeo solo los impares;

    for (i = 3; i < 100; i += 2)
    {
        for (j = 3; j <= i; j += 2)
        {
            if (i == j)
            {
                printf("%d, ", j);
                cant++;
                break;
            }
            else if (i % j == 0)
            {
                break;
            }
        }
    }
    printf("Cant. de primos: %d", cant);
    return 0;
}
