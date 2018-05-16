/**
Dadas las edades y estaturas de 45 alumnos de un curso.
Determinar:
a) Edad promedio.
b) Estatura promedio.
c) Cantidad de alumnos mayores de 10 años.
d) Cantidad de alumnos que miden menos de 1.40 cm
*/

#include <stdio.h>

int main()
{
    int   edad,
          altura,
          total_edad = 0,
          total_altura = 0,
          mas_10 = 0,
          menos_140 = 0;
    float prom_edad,
          prom_altura;

    for (int i=0; i<45; i++)
    {
        printf("Edad Alumno %d : ", i+1);
        scanf("%d", &edad);
        fflush(stdin);
        printf("Estatura Alumno %d (en cms): ", i+1);
        scanf("%d", &altura);
        fflush(stdin);
        total_edad += edad;
        total_altura += altura;
        if (altura<140)
        {
            menos_140++;
        }
        if (edad>10)
        {
            mas_10++;
        }
    }
    prom_edad   = total_edad   / 45.;
    prom_altura = total_altura / 45.;
    printf("Edad promedio: %.2f\n", prom_edad);
    printf("Estatura promedio: %.2f\n", prom_altura);
    printf("Cantidad de alumnos mayores de 10 años: %d\n", mas_10);
    printf("Cantidad de alumnos que miden menos de 1.40 cm: %d\n", menos_140);
    return 0;
}
