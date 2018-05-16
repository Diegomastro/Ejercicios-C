/**
En una empresa trabajan N empleados, de cada uno se tiene:
sueldo básico, antigüedad, cantidad de hijos y estudios superiores (‘S’ o ‘N’).

Además se conocen los porcentajes de aumento del sueldo que dependen de los siguientes factores:
    Si el empleado tiene más de 10 años de antigüedad: aumento del 10%
    Si el empleado tiene más de 2 hijos: aumento del 10%, en caso contrario 5%
    Si el empleado posee estudios superiores: aumento del 5%

Determinar:
    a-) Por cada empleado: número de empleado, el sueldo básico y el nuevo sueldo.
    b-) Sueldo nuevo promedio de la empresa.
*/

#include <stdio.h>
#include <conio.h>

int main()
{
    int i,
        cant_empleados,
        antig,
        hijos;
    float sueldo_basico,
          sueldo_aumentos = 0,
          sueldo_suma = 0;
    char estudios;

    float lista_sueldo_basico[100] = {0};
    float lista_sueldo_nuevo [100] = {0};

    printf("Cantidad de empleados en la empresa: ");
    scanf("%d", &cant_empleados);

    for(i = 0; i < cant_empleados; i++)
    {
        printf("Empleado %03d: \n", i+1);
        printf("Sueldo basico: ");
        scanf("%f", &sueldo_basico);
        fflush(stdin);
        printf("Años de antiguedad: ");
        scanf("%d", &antig);
        fflush(stdin);
        printf("cantidad de hijos: ");
        scanf("%d", &hijos);
        fflush(stdin);
        printf("Tiene estudios ('S':SI 'N':NO): ");
        scanf("%d", &estudios);
        fflush(stdin);
        printf("--- \n");

        if  (antig < 10)
        {
            sueldo_aumentos += sueldo_basico * .1;
        }
        if (hijos > 2)
        {
            sueldo_aumentos += sueldo_basico *.1;
        }
        else
        {
            sueldo_aumentos += sueldo_basico *.05;
        }
        if (estudios == 's' || estudios == 'S')
        {
            sueldo_aumentos += sueldo_basico * .05;
        }
        lista_sueldo_basico[i] = sueldo_basico;
        lista_sueldo_nuevo [i] = sueldo_basico + sueldo_aumentos;
        sueldo_suma           += sueldo_basico + sueldo_aumentos;
        sueldo_aumentos        = 0;
    }
    for (i = 0; i < cant_empleados; i++)
    {
        printf("Empleado %03d: \n", i+1);
        printf("Sueldo basico: $%10.2f \n", lista_sueldo_basico[i]);
        printf("Sueldo nuevo : $%10.2f \n", lista_sueldo_nuevo [i]);
    }
    printf("--- \n");
    printf("Prom. S.Nuevo: $%10.2f", sueldo_suma / cant_empleados);
    getch();
    return 0;
}

























