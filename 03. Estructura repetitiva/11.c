/**
Ingresar N
Ingresar N Números naturales.
Determinar e informar:
a) La sumatoria de los valores múltiplos de 3.
b) La cantidad de valores múltiplos de 5
c) La sumatoria de los valores que se ingresan en orden par.
*/
#include <stdio.h>
#include <conio.h>

int main()
{
    int i,
        cant,
        num,
        act_a = 0, /*suma de los múltiplos de 3*/
        act_b = 0, /*cantidad de múltiplos de 5*/
        act_c = 0; /*suma de los valores ingresados en orden par*/

    printf("Ingrese un numero: ");
    scanf("%d", &cant);
    printf("Ingrese %d numeros naturales: ", cant);
    for(i = 0; i < cant; i++)
    {
        scanf("%d", &num);
        if (num % 3 == 0)
        {
          act_a += num;
        }
        if (num % 5 == 0)
            act_b++;
        {
        }
        if (i % 2 == 1)
        {
            act_c += num;
        }
    }
    printf("Suma de los múltiplos de 3: %d \n", act_a);
    printf("Cantidad de múltiplos de 5: %d \n", act_b);
    printf("Suma de los valores ingresados en orden par: %d \n", act_c);
    getch();
    return 0;

}
