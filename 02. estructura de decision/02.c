/**Dados tres nros. Determinar e informar con un mensaje si el
primer nro. ingresado es menor que los otros dos. */

#include <stdio.h>

int main(){
    int num1, num2, num3;
    printf("Ingrese 3 numeros: ");
    scanf("%d%d%d", &num1, &num2, &num3);
    if (num1 < num2 && num1 < num3){
        printf("El primer numero es el menor.");
    }
    else {
    printf("El primer numero NO es el menor");
    }
    return 0;
}
