/**
Se ingresan 100 letras.
Determinar la cantidad de vocales ingresadas */

#include <stdio.h>
#include <ctype.h>

int main()
{
    int cant;
    char letra;
    printf("Ingresar 100 letras: ");
    for(int i=0; i<100;i++)
    {
        scanf("%c", &letra);
        letra = tolower(letra);
        if (letra == 'a' ||
            letra == 'e' ||
            letra == 'i' ||
            letra == 'o' ||
            letra == 'u' )
        {
            cant++;
        }
    }
    printf("Cant. de vocales: %d", cant);
    return 0;
}
