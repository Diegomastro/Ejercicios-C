/**Ingresar el valor de la hora y las horas trabajadas.
Calcular su sueldo si se sabe que recibe un premio
de $500 si trabajo más de 50 horas y si trabajo
más de 150 horas, $ 1000 adicionales. */

#include <stdio.h>
#define PREMIO_BAJO 500
#define PREMIO_ALTO 1000

int main(){
    int cant_horas;
    float valor_hora, sueldo;
    printf("Cant. de horas trabajadas: ");
    scanf("%d", &cant_horas);
    fflush(stdin);
    printf("Valor por hora:" );
    scanf("%f", &valor_hora);
    if (cant_horas > 50){
        if (cant_horas > 150){
        sueldo = valor_hora * cant_horas + PREMIO_ALTO;
        }
        else{
            sueldo = valor_hora * cant_horas + PREMIO_BAJO;
        }
    }
    else{
        sueldo = valor_hora*cant_horas;
    }
    printf("Sueldo: $%.2f",sueldo);
    return 0;
}
