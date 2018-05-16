/** Se ingresan la cantidad de horas trabajadas y el valor
 por hora de un empleado. Determinar el sueldo. */

#include <stdio.h>

int main(){
    int horas;
    float valor;
    printf("Insertar cant. de horas trabajadas: ");
    scanf("%d", &horas);
    fflush(stdin);
    printf("Insertar valor por hora: ");
    scanf("%f", &valor);
    fflush(stdin);
    printf("Sueldo: $%.2f", horas*valor);
    return 0;
}
