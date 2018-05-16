/**Un fabricante de repuestos para tractores ha descubierto que ciertos artículos identificados por los
números de catálogo 12121 al 18081; 30012 al 45565 y 67000 al 68000 son defectuosos. Desea que se
confeccione un programa que informándole el número de catálogo indique si el artículo es o no
defectuoso. Los artículos del catálogo van desde el 1200 al 90000.-
*/

#include <stdio.h>

int main()
{
    int num;
    do
    {
    printf("Numero de serie: (1200-90000)");
    scanf("%d", &num);
    fflush(stdin);
    } while (!(1200 < num && num < 90000));

    if(12121 < num && num < 18081 ||
       30012 < num && num < 45565 ||
       67000 < num && num < 68000)
    {
        printf("DEFECTUOSO");
    }
    else{
        printf("OK");
    }
    return 0;
}
