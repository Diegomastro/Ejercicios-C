/**En una producción de plafones se sabe que el 2.5% son
defectuosos. Conociendo la cantidad fabricada.
Determinar: a-) Cantidad de plafones aceptados.
b-) Cantidad de plafones defectuosos. */

#include <stdio.h>
#define ACEPTADOS   .975
#define DEFECTUOSOS .025

int main(){
    int cant;
    printf("Cantidad de plafones: ");
    scanf("%d", &cant);
    printf("Cantidad de plafones aceptados:   %.f \nCantidad de plafones defectuosos: %.f", \
           cant*ACEPTADOS, cant*DEFECTUOSOS);
    return 0;
}
