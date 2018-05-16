/**
Un negocio de perfumería efectúa descuento en sus ventas según el importe de éstas, con la siguiente
escala:
    a) menor a 50 pesos el 3.5 %
    b) entre 50 y 150 pesos el 10 %
    c) entre 151 y 300 pesos el 20 %.
    d) mayor a 300 pesos el 25 %
Confeccionar un programa:
1-) Que solicite un importe original e informe a éste, el descuento a efectuar y el importe neto a cobrar, con
mensajes aclaratorios.
2-) Importe promedio
Se debe contemplar que se puedan ingresar varios importes y para finalizar se ingresa un valor negativo o
cero.
*/
#include <stdio.h>
#define DESC_1 .035
#define DESC_2 .1
#define DESC_3 .2
#define DESC_4 .25

int main()
{
    int cant_ventas = 0;
    float subtotal,
          descuento,
          total,
          total_ventas = 0;

    while (1)
    {
        printf("Precio: ");
        scanf("%f", &subtotal);
        fflush(stdin);

        if (subtotal <= 0)
        {
            break;
        }
        else if (subtotal <= 50)
        {
            descuento = subtotal * DESC_1;
        }
        else if (subtotal <= 150)
        {
            descuento = subtotal * DESC_2;
        }
        else if (subtotal <= 300)
        {
            descuento = subtotal * DESC_3;
        }
        else
        {
            descuento = subtotal * DESC_4;
        }

        total = subtotal - descuento;
        cant_ventas++;
        total_ventas += total;

        printf("Subtotal:  $%.2f \n", subtotal);
        printf("Descuento: $%.2f \n", descuento);
        printf("Total:     $%.2f \n", total);
        printf("---\n");
    }
    printf("Precio promedio: %.2f", total_ventas / cant_ventas);
    return 0;
}
