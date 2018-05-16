/** Se ingresan la cantidad de horas trabajadas de un empleado y
sabiendo que el valor por hora es de $30. Determinar su sueldo. */

#include <stdio.h>
#define VALOR_HORA 30
int main() {
    int horas;
    printf("Ingresar cantidad de horas trabajadas: ");
    scanf("%d", &horas);
    printf("Sueldo: $%.2f",(float)VALOR_HORA * horas);
    return 0;
}
