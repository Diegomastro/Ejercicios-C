/**Se ingresa un numero entero de 3 cifras. Descomponerlo en
unidad , decena y centena. */

#include <stdio.h>

int main() {
    int num, cent, dec, un;
    printf("Ingrese un numero de 3 cifras: ");
    scanf("%d", &num);
    cent = num / 100;
    num  = num % 100;
    dec  = num / 10;
    un   = num % 10;
    printf("Tu numero tiene %d centenas, %d decenas y %d unidades", cent, dec, un);
    return 0;
}
