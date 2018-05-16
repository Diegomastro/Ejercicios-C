/*
Se ingresan números enteros, hasta que se ingrese el numero cero.
Determinar los 2 valores mayores.
NOTA: TODOS LOS NUMEROS SON DISTINTOS.
*/

#include <stdio.h>
#include <conio.h>

int main()
{
    int num,
        max1,
        max2 = 0;

    printf("Ingrese numeros enteros (El programa termina cuando ingresa un 0): ");
    scanf("%d", &max1);
    fflush(stdin);
    if (max1 == 0)
    {
        printf("El unico numero ingresado fue un 0");
        getch();
        return 0;
    }
    while (1)
    {
        scanf("%d", &num);
        fflush(stdin);
        if (num == 0)
        {
            break;
        }
        else if (num > max1)
        {
            max2 = max1;
            max1 = num ;
        }
        else if (num > max2)
        {
            max2 = num;
        }
    }
    printf("Mayor   : %d \n", max1);
    printf("2* Mayor: %d \n", max2);
    getch();
    return 0;
}
