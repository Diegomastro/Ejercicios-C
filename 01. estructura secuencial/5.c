/**Se ingresa un nro. entero que representa una fecha con formato
(ddmmaa). Se pide transformarlo a un nro. con formato (aammdd)*/

#include <stdio.h>

int main() {
    int fecha, dd, mm, aa;
    printf("Inserta una fecha (Formato DDMMAA)");
    scanf("%6d", &fecha);
    dd = fecha / 10000;
    fecha %= 10000;
    mm = fecha / 100;
    aa = fecha % 100;
    fecha = aa * 10000 + mm * 100 + dd;
    printf("Fecha formato AAMMDD: %6d", fecha);
    return 0;
}
