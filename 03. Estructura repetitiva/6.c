/**
Un negocio de venta de granos desea controlar las ventas realizadas. De cada una ingresa el importe total
y un código que indica la forma de pago. El código puede ser:
C : cooperativa , 30% de descuento
E : contado, 10% de descuento
T : con tarjeta, 12% de recargo
Se debe ingresar una F para finalizar el día de venta y arrojar los siguientes totales.
Efectivo en caja : xxxx.xx
Ventas con tarjeta : xxxx.xx
Total de ventas : xxxx.xx
Importe del IVA : xxxx.xx ( 21% del total vendido)
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    int listo = 0; // flag
    float precio,
          total_efectivo = 0,
          total_tarjeta  = 0,
          total_ventas   = 0;
    char cod;
    printf("Lista de codigos: \nC: Cooperativa \nE: Efectivo \nT: tarjeta \nF: Finalizar \n--- \n");
    while (!listo)
    {
        printf("Precio: ");
        scanf("%f", &precio);
        fflush(stdin);
        printf("Codigo: ");
        scanf("%c", &cod);
        fflush(stdin);
        switch (tolower(cod))
        {
        case 'c':
            precio *= .7;
            break;
        case 'e':
            precio*= .9;
            total_efectivo += precio;
            break;
        case 't':
            precio *= 1.12;
            total_tarjeta += precio;
            break;
        case 'f':
            listo = 1;
            break;
        default:
            precio = 0;
            printf("ERROR! Codigo no valido.\n");
        }
        total_ventas += precio;

    }

    printf("Efectivo en caja:   $%7.2f \n", total_efectivo);
    printf("Ventas con tarjeta: $%7.2f \n", total_tarjeta);
    printf("Total de ventas:    $%7.2f \n", total_ventas);
    printf("importe del IVA:    $%7.2f \n", total_ventas * .21);
    return 0;

}
