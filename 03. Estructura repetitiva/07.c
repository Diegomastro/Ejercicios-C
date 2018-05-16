/**
Dado un numero de DNI y los dos exámenes parciales confeccionar
un programa que pueda, ingresando dichos datos.
Determinar:
a)  DNI, las notas y su condición final.
    PROMOCIONA : ambas notas > = 7
    RINDE EXAMEN FINAL : ambas notas > = 4
    REPROBO LA MATERIA : alguna nota no cumple lo anterior
b)  Nota promedio de alumnos promocionados.
El programa finaliza cuando se ingresa un valor negativo como número de DNI.
*/

#include <stdio.h>

int main()
{
    int dni,
        n1,
        n2,
        condicion, //flag:  0=prom; 1=aprob; 2=reprob;
        cant_promocionados = 0,
        suma_promocionados = 0;
    float promedio_promocionados;

    do
    {
        printf("DNI: ");
        scanf("%d", &dni);
        fflush(stdin);
        if (dni < 0)
            break;
        printf("Notas: ");
        scanf("%d%d", &n1, &n2);
        fflush(stdin);
        printf("---\n");
        if (n1 < 0 || n1 > 10 ||  n2 < 0 || n2 > 10) //notas fuera de rango
        {
            printf("ERROR! \n");
            continue;
        }

        if (n1 >= 7 && n2 >= 7)
        {
            condicion = 0; //promocionado
            cant_promocionados += 1;
            suma_promocionados += n1 + n2;
        }
        else if (n1 >= 4 && n2 >= 4)
        {
            condicion = 1; //aprobado
        }
        else
        {
            condicion = 2; //reprobado
        }

        printf("DNI: %d \n", dni);
        printf("Notas: %d, %d \n", n1 ,n2);

        switch(condicion)
        {
        case 0:
            printf("Condicion: PROMOCIONA \n");
            break;
        case 1:
            printf("Condicion: RINDE EXAMEN FINAL \n");
            break;
        case 2:
            printf("Condicion: REPROBO LA MATERIA \n");
            break;
        }
        printf("---\n");
    }while (dni > 0);
    if (cant_promocionados > 0)
    {
        promedio_promocionados = (float) suma_promocionados / cant_promocionados;
        printf("Nota promedio de alumnos promocionados: %.2f", promedio_promocionados);
    }
    else
    {
        printf("No hubo alumnos promocionados");
    }
}

