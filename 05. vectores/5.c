/*
Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos
finaliza con un DNI negativo. Se sabe que como máximo pueden presentarse a rendir 60
alumnos. Mostrar:
a) Listado alumnos con su correspondiente DNI y la nota obtenida (en forma de listado)
b) La máxima nota obtenida y el DNI de los alumnos que la obtuvieron
*/

#include <stdio.h>
#include <conio.h>

int get_dni()
{
    int num;
    printf("DNI: ");
    scanf("%d", &num);
    fflush(stdin);
    return num;
}

int get_nota()
{
    int num;
    while (1)
    {
    printf("NOTA: ");
    scanf("%d", &num);
    fflush(stdin);
    if (0 <= num && num <= 10) break;
    }
    return num;
}

void vaciar(int arr[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        arr[i] = 0;
    }
}

void append(int valor, int arr[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = valor;
            break;
        }
    }
}
int main()
{
    int dnis[60] = {0};
    int notas[60];
    int mejoresdnis[60] = {0};
    int mejornota = 0;
    int i;
    printf("Para dejar de ingresar datos, ponga un DNI negativo \n");

    for (i = 0; i < 60; i++)
    {
        dnis[i]  = get_dni();
        if (dnis[i] < 0) break;
        notas[i] = get_nota();
        if (notas[i] > mejornota)
        {
            mejornota = notas[i];
            vaciar(mejoresdnis, 60);
            mejoresdnis[0] = dnis[i];
        }
        else if (notas[i] == mejornota)
        {
            append(dnis[i], mejoresdnis, 60);
        }

    }
    
    for (i = 0; i < 60; i++)
    {
        if (dnis[i] < 0) break;
        printf("%d ==> %d \n", dnis[i], notas[i]);
    }
    printf("---\n");
    printf("Mejor nota: %d \n", mejornota);
    printf("DNIs de alumnos con esa nota: \n");
    for (i = 0; i < 60; i++)
    {
        if (mejoresdnis[i] == 0) break;
        printf("%d \n", mejoresdnis[i]);
    }
    return 0;
}
