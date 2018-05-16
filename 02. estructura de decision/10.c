/**Confeccionar un programa que permita ingresar 4 valores enteros de longitud, de a uno por vez y
determine el menor valor y su número de orden. Informe los valores ingresados e identifique al menor con
mensaje aclaratorio. */

#include <stdio.h>

int main()
{
    long num1, num2, num3, num4;
    int chico;
    printf("Inserte 4 numeros: ");
    scanf("%d%d%d%d", &num1, &num2, &num3, &num4);
    if (num1<num2 && num1<num3 && num1<num4)
    {
    chico = 1;
    }
    else if (num2<num3 && num2<num4)
    {
    chico = 2;
    }
    else if (num3<num4)
    {
    chico = 3;
    }
    else
    {
    chico = 4;
    }
    printf("Los valores ingresados fueron:\n%d\n%d\n%d\n%d\n", num1, num2, num3, num4);
    printf("El mas chico es el %dª",chico);
    return 0;
}
