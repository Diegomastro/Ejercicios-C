/*
Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos
finaliza con un DNI negativo. Se sabe que como máximo pueden presentarse a rendir 60
alumnos. Mostrar:
a) Listado alumnos con su correspondiente DNI y la nota obtenida (en forma de listado)
b) La máxima nota obtenida y el DNI de los alumnos que la obtuvieron
*/

#include <stdio.h>
#include <conio.h>

/*
Pide al usuario y valida un DNI
VALORES VALIDOS:
(Numeros de 8 cifras)
*/
int get_dni()
{
    int num;
    while (1)
    {   
    printf("DNI: ");
    scanf("%d", &num);
    fflush(stdin);
    if (10000000 <= num && num <= 99999999) break;
    printf("DNI INVALIDO! DEBE TENER 8 CIFRAS \n");
    }
    return num;
}

/*
Pide al usuario y valida una nota
VALORES VALIDOS:
(0 <= valor <= 10)
*/
int get_nota()
{
    int num;
    while (1)
    {
    printf("NOTA: ");
    scanf("%d", &num);
    fflush(stdin);
    if (0 <= num && num <= 10) break;
    printf("NOTA INVALIDA! DEBE SER ENTRE 0-10 \n")
    }
    return num;
}

/*
Pone en 0 todos los elementos de un array
ARGS:
arr[] = array a setear en '0'
len   = tamaño del array (o posicion hasta la que se quiere poner 0s)
*/
void vaciar(int arr[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        arr[i] = 0;
    }
}

/*
Reemplaza el primer 0 del array por un valor
ARGS:
valor = valor a agregar
arr[] = array en el que agregar a 'valor'
len   = tamaño del array  
*/
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
