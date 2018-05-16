/**Conociendo los asistentes a un cine el día miércoles y sabiendo que
el precio del cine es de $50 y que por ser miércoles tiene un descuento
del 10%. Calcular la recaudación del cine. */

#include <stdio.h>
#define PRECIO 50
#define DESCUENTO .9 //Descuento de 10%, .9 es lo que queda del precio

int main(){
    int asist;
    printf("Insertar cantidad de personas que asistiran: ");
    scanf("%d", &asist);
    printf("Recaudacion: $%.2f", asist * PRECIO * DESCUENTO);
    return 0;
}
