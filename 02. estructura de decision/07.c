/**Un fabricante de repuestos para tractores ha descubierto que ciertos art�culos identificados por los
n�meros de cat�logo 12121 al 18081; 30012 al 45565 y 67000 al 68000 son defectuosos. Desea que se
confeccione un programa que inform�ndole el n�mero de cat�logo indique si el art�culo es o no
defectuoso. Los art�culos del cat�logo van desde el 1200 al 90000.-
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
