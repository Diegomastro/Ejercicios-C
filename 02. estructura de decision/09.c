/**La farmacia Sindical efectúa descuentos a sus afiliados según el importe de la compra con la siguiente
escala:
a) menor de 55 $ el descuento es del 4,5 %
b) entre 55 y 100 $ “ 8,0 %
c) más de 100 $ el descuento es del 10,5%
Confeccionar un programa que reciba un importe e informe : el precio ingresado, el descuento y el precio
neto a cobrar, con mensajes aclaratorios. */

#include <stdio.h>

int main()
{
    float precio,desc,total;
    printf("Subtotal: ");
    scanf("%f", &precio);

    if (precio < 55)
    {
    desc   = .045;
    total = precio*(1-desc);
    }
    else if (precio < 100)
    {
    desc   = .08;
    total = precio*(1-desc);
    }
    else
    {
    desc   = .105;
    total = precio*(1-desc);
    }

    printf("Descuento: $%.2f \n", precio*desc);
    printf("Total: $%.2f", total);
}
