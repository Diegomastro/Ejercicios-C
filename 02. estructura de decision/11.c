/**Confeccionar un programa que solicite e ingrese 3 valores
reales positivos, mayores que cero y :
a) calcule e informe el promedio de los 3 valores ingresados.
b) determine e informe si forman o no triángulo.
( suma de c/ 2 de sus lados > al tercero ) */

#include <stdio.h>

int main()
{
    int num1, num2, num3;
    float prom;
    printf("Ingrese 3 numeros positivos: ");
    scanf("%d%d%d", &num1, &num2, &num3);
    printf("Promedio: %.2f\n" ,(num1 + num2 + num3) / 3.);

    if (num1+num2 > num3 &&
        num1+num3 > num2 &&
        num2+num3 > num1)
    {
        printf("Forman un triangulo");
    }
    else
    {
        printf("No forman un triangulo");
    }
    return 0;
}
