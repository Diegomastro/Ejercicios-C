/**Ingresar 3 valores reales y :
a] Si los dos primeros son mayores al tercero informar “ MAYORES AL TERCERO “.
b] Si los tres son iguales informar “TRES IGUALES”
c] si alguno de los dos primeros es menor al tercero informar “ALGUNO ES MENOR” */

#include <stdio.h>

int main(){
    int num1, num2, num3;
    printf("Ingrese 3 numeros: ");
    scanf("%d%d%d", &num1, &num2, &num3);
    if (num1>num3 && num2>num3){
        printf("MAYORES AL TERCERO");
    }
    else if (num1 == num2 && num2 == num3){
        printf("TRES IGUALES");
    }
    else if (num1 < num3 || num2 < num3){
        printf("ALGUNO ES MENOR");
    }
    return 0;
}
