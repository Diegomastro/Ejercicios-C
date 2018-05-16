/**Confeccionar un programa que pueda determinar el importe a pagar por una prestaci�n m�dica seg�n
su c�digo. Los importes se cobran seg�n la siguiente tabla:
A  $20 ; D $40 ; F  $60 ; M  $150 ; T  $150
Por cada prestaci�n se debe ingresar el n�mero de historia del paciente y el c�digo de la prestaci�n.
Se debe emitir un ticket para cada uno, con el n�mero de la historia, el c�digo y el importe a pagar*/

#include <stdio.h>
#include <ctype.h>
#define PRECIO_A  20
#define PRECIO_D  40
#define PRECIO_F  60
#define PRECIO_M 150
#define PRECIO_T 150

int main()
{
    int historia, precio;
    char cod;

    printf("Numero de historia: ");
    scanf("%d", &historia);
    fflush(stdin);
    while (1)
    {
        printf("Codigo: ");
        cod = toupper(getchar());
        fflush(stdin);
        if (cod == 'A' || cod == 'D' ||cod == 'F' ||
            cod == 'M' || cod == 'T' )
        {
            break;
        }
        printf("Codigo invalido\n");
    }
    printf("--- \nNro Historia: %d \nCodigo: %c\n",historia,cod);

    switch(cod)
    {
        case 'A': precio = PRECIO_A; break;
        case 'D': precio = PRECIO_D; break;
        case 'F': precio = PRECIO_F; break;
        case 'M': precio = PRECIO_M; break;
        case 'T': precio = PRECIO_T; break;
    }
    printf("Precio: $%d", precio);
    return 0;
}
