/*
Hacer una función llamada EN_RANGO que reciba 3 enteros correspondientes
a un número a validar y los límites superior e inferior del rango.
La función debe retornar un 1 si el número a validar
se encuentra dentro del rango indicado o un 0 si no lo está.
*/

#include <stdio.h>
#include <conio.h>

int en_rango(int num, int lim_inf, int lim_sup)
{
    if (lim_inf <= num && num <= lim_sup)
    {
        return 1;
    }
    return 0;
}

int get_num()
{
    int num;
    printf("Numero: ");
    scanf("%d", &num);
    fflush(stdin);
    return num;
}

int get_lim_inf()
{
    int lim_inf;
    printf("Limite inferior: ");
    scanf("%d", &lim_inf);
    fflush(stdin);
    return lim_inf;
}

int get_lim_sup(int lim_inf)
{
    int lim_sup;
    while (1)
    {
    printf("Limite superior: ");
    scanf("%d", &lim_sup);
    fflush(stdin);
    if (lim_sup > lim_inf) break;
    printf("Limite superior debe ser mayor al inferior! \n");
    }
    return lim_sup;
}

int main()
{
    int num     = get_num(),
        lim_inf = get_lim_inf(),
        lim_sup = get_lim_sup(lim_inf);

    if (en_rango(num, lim_inf, lim_sup))
    {
        printf("Esta en rango");
    }
    else
    {
        printf("No esta en rango");
    }
    getch();
    return 0;
}
