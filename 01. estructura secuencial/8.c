/**Conociendo la cantidad de tarros de pintura que existe en un
deposito de una pinturería y sabiendo que el 50% son tarros de 1Lt.
,el 30% tarros de 4Lts. y el resto tarros de 20Lts. Determinar la
cantidad de tarros de 1Lt. , 4Lts. Y 20 Lts.*/

#include <stdio.h>
#define TARROS_1  .5
#define TARROS_4  .3
#define TARROS_20 (1-TARROS_1-TARROS_4)

int main() {
    int cant_tarros;
    printf("Cantidad de tarros: ");
    scanf("%d", &cant_tarros);
    printf("Tarros de 1L:  %.f \nTarros de 4L:  %.f \nTarros de 20L: %.f",TARROS_1*cant_tarros, TARROS_4*cant_tarros, TARROS_20*cant_tarros);
    return 0;
}
