/**
Dados 20 notas y legajos de alumnos de un curso. Determinar:
Cantidad de alumnos aplazados.
Imprimir los legajos cuya nota sea mayor a 8.
*/

#include <stdio.h>
#define CANT_ALUMNOS 20

int get_nota()
{
    int nota;
    while (1)
    {
    scanf("%d", &nota);
    fflush(stdin);
    if (0 <= nota && nota <= 10) break;
    printf("Nota debe estar entre 0-10");
    }
    return nota;
}

int get_cond(int nota) // 0 = Aplazo 1 = aprobado 2 = muy bien
{
    int cond = 1; //aprobado

    if (nota < 4)
    {
        cond = 0;  //Aplazo
    }
    else if (nota > 8)
    {
        cond = 2; //muybien
    }
    return cond;
}

int main()
{
    int nota,
        cond,
        aplazados = 0,
        aprobados = 0,
        muybien   = 0;
    for(int i=0; i < CANT_ALUMNOS; i++)
    {
        printf("Ingresar nota del alumno %d: ", i+1);
        nota = get_nota();
        cond = get_cond(nota);
        switch(cond)
        {
            case 0:
                aplazados++;
            case 1:
                aprobados++;
            case 2:
                muybien++;
        }
    }
    printf("Aplazados: %d\n", aplazados);
    printf("Aprobados: %d\n",  aprobados);
    printf("Nota mayor a 8: %d", muybien);
    return 0;
}
