/**Un negocio vende distintos artículos identificados por un código, según se muestra:
.código 1; 10 ; 100 : l0 pesos la unidad
.código 2; 22; 222 : 7 pesos la unidad. La caja de 10 unidades vale 65 pesos.
.código 3; 33 : 3 pesos la unidad. Si la compra es por más de 10 unidades se hace un descuento
del 10% sobre el total de la compra.
.código 4 ;44 : 1 peso la unidad. */

#include <stdio.h>

int main()
{
    int cod, cant, cajas, sueltos;
    int codes[10] = {1, 10, 100, 2, 22, 222, 3, 33, 4, 44};
    float precio;
    int valid = 0; //bool
    while (1)
    {
        printf("Cod. del articulo: ");
        scanf("%d",&cod);
        for (int i = 0; i < 10; i++)
        {
            if (cod == codes[i])
            {
            valid = 1;
            }
        }
        fflush(stdin);
        if (valid) break;
        printf("Codigo no valido.\n");

    }
    while (1)
    {
        printf("Cantidad a comprar: ");
        scanf("%d", &cant);
        fflush(stdin);
        if (0 < cant && cant < 3000) break;
        printf("Cantidad invalida, solo hasta 3000 unidades.\n");
    }
    switch(cod)
    {
    case 1: case 10: case 100:
        precio = 10* cant;
        break;
    case 2: case 22: case 222:
        cajas = cant / 10;
        sueltos = cant % 10;
        precio = cajas * 65 + sueltos * 7;
        break;
    case 3: case 33:
        precio = cant * 3;
        if (cant > 10)
        {
            precio *= .9;
        }
        break;
    default:
        precio = cant;
    }
    printf("Importe: $%4.2f", precio);
    return 0;
}
