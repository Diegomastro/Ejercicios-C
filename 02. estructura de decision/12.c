/**Un negocio de artículos de computación vende CD según la siguiente escala de precios :
- sueltos, entre 1 y 9 a 1 $ c/u
- la caja de 10 cuesta 8 $
- la caja de 50 cuesta 35 $
- si la compra excede las 100 unidades se efectúa un descuento del 10%
NOTA : se aceptan compras entre 1 y 500 CD.
Se pide que se ingrese una cantidad de CD que se quiere comprar y calcule e informe el importe a pagar. */

#include <stdio.h>
#define SUELTO    1
#define CAJA_10   8
#define CAJA_50   35
#define DESCUENTO .1  // 10%

int main()
{
    int cant, cant_caja_50, cant_caja_10, cant_suelto;
    int hay_desc = 0; //boolean
    float precio;
    while (1)
    {
        printf("Cantidad de CDs comprados: ");
        scanf("%d", &cant);
        if (1 < cant && cant < 500)
        {
            break;
        }
        fflush(stdin);
        printf("ERROR!\nSolo se aceptan compras de entre 1 y 500 CDs!\n");
    }
    if (cant > 100)
    {
        hay_desc = 1;
    }
    cant_caja_50 = cant / 50;
    cant         = cant % 50;
    cant_caja_10 = cant / 10;
    cant_suelto  = cant % 10;
    precio = (cant_caja_50 * CAJA_50 + cant_caja_10 * CAJA_10 + cant_suelto * SUELTO);

    if (hay_desc)
    {
        precio = precio * (1-DESCUENTO);
    }
    printf("Precio: $%.2f", precio);
    return 0;
}
