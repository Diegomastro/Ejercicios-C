/**Se ingresan las notas de dos evaluaciones de un alumno.
Determinar la nota promedio*/

#include <stdio.h>

int main(){
    int nota1, nota2;
    printf("Ingresar las dos notas: ");
    scanf("%d%d", &nota1, &nota2);
    printf("Promedio: %4.1f", (float)(nota1+nota2)/2);
    return 0;
}

