/*
Se ingresan datos de los empleados de una empresa:
 Legajo (entero entre 1000 y 5000)
 Sueldo básico (float mayor a 1000)
 Antigüedad en años ( mayor o igual a 0)
 Sexo ( 'M' o 'F')
 Categoría (entero entre 1 a 5)
Por cada empleado ingresado se debe calcular el sueldo final a abonar sabiendo que:
 Las Categorías 2 y 3 tienen $500 de bonificación
 La Categoría 4 tiene 10% de bonificación
 La Categoría 5 tiene 30% de bonificación
 Si la antigüedad es mayor a 10 años recibe una bonificación del 10% adicional
Todos los datos ingresados deben ser validados.
El ingreso finaliza con un legajo igual a cero.
Informar:
 El sueldo a abonar a cada empleado
 Cantidad de empleados de más de 10 años de antigüedad
 El mayor sueldo y el legajo del empleado que cobra dicho sueldo
 Cantidad de hombres y de mujeres
*/

#include <stdio.h>
#include <conio.h>
#include <ctype.h>

/*
Pide al usuario y valida un legajo
VALORES VALIDOS:
(1000 <= valor <= 5000) || 0
*/
int get_legajo()
{
    int legajo;
    while (1)
    {
        printf("Legajo: ");
        scanf("%d", &legajo);
        fflush(stdin);
        if ( (1000 <= legajo && legajo <= 5000) || (legajo == 0) )
        {
            return legajo;
        }
        printf("LEGAJO INVALIDO! (Entre 1000-5000) \n");
    }
}

/*
Pide al usuario y valida un sueldo
VALORES VALIDOS:
(valor > 1000)
*/
float get_sueldo()
{
    float sueldo;
    while (1)
    {
        printf("Sueldo: ");
        scanf("%f", &sueldo);
        fflush(stdin);
        if (sueldo > 1000)
        {
            return sueldo;
        }
        printf("SUELDO INVALIDO! (Mayor a 1000) \n");
    }
}

/*
Pide al usuario y valida la antiguedad de un empleado
VALORES VALIDOS:
(valor >= 0)
*/
int get_antig()
{
    int antig;
    while (1)
    {
        printf("Antiguedad: ");
        scanf("%d", &antig);
        fflush(stdin);
        if (antig >= 0)
        {
            return antig;
        }
        printf("ANTIGUEDAD INVALIDA (MAYOR A 0) \n");
    }
}

/*
Pide al usuario y valida el sexo 
VALORES VALIDOS:
'M' || 'F'
*/
char get_sexo()
{
    int sexo;
    while (1)
    {
        printf("Sexo: ");
        fflush(stdin); /*No tendria que hacer falta, pero por las dudas*/
        sexo = toupper(getchar());
        fflush(stdin);
        if (sexo == 'M' || sexo == 'F')
        {
            return sexo;
        }
        printf("SEXO INVALIDO! (M/F) \n");
    }
}

/*
Pide al usuario y valida la categoria de importancia.
VALORES VALIDOS:
(1 <= valor <= 5)
*/
int get_categ()
{
    int categ;
    while (1)
    {
        printf("Categoria: ");
        scanf("%d", &categ);
        fflush(stdin);
        if (1 <= categ && categ <= 5)
        {
            return categ;
        }
        printf("CATEGORIA INVALIDA (Entre 1-5) \n");
    }
}


int main()
{
    int   lista_legajo[100] = {0};
    float lista_sueldo[100] = {0};

    int legajo,
        antig,
        categ,
        legajo_mayor_sueldo,
        i,
        count = 0,
        cant_viejos  = 0,       //antig > 10
        cant_hombres = 0,
        cant_mujeres = 0;

    float sueldo,
          sueldo_nuevo,
          mayor_sueldo = 0;

    char sexo;

    while (1)
    {
        //entrada de datos
        legajo = get_legajo() ;
        if (legajo == 0) break;   //salida del while
        sueldo = get_sueldo() ;
        antig  = get_antig()  ;
        sexo   = get_sexo()   ;
        categ  = get_categ()  ;
        printf("----------\n");

        switch (categ)
        {
        case 1:
            sueldo_nuevo = sueldo;
            break;
        case 2:
        case 3:
            sueldo_nuevo = sueldo + 500;
            break;
        case 4:
            break;
            sueldo_nuevo = sueldo * 1.1;
        case 5:
            sueldo_nuevo = sueldo * 1.3;
            break;
        }

        if (antig > 10)
        {
            sueldo_nuevo += sueldo * .1;
            cant_viejos++;
        }

        if (sexo == 'M')
        {
            cant_hombres++;
        }
        else
        {
            cant_mujeres++;
        }

        if (sueldo_nuevo > mayor_sueldo)
        {
            mayor_sueldo = sueldo_nuevo;
            legajo_mayor_sueldo = legajo;
        }

        lista_legajo[count] = legajo;
        lista_sueldo[count] = sueldo_nuevo;
        count++;
    }

    //tablita fachera
    printf("-------+---------------+ \n");
    printf("LEGAJO | SUELDO A PAGAR| \n");
    printf("-------+---------------+ \n");
    for(i = 0; i < count; i++)
    {
        printf("%d   | $%13.2f| \n", lista_legajo[i], lista_sueldo[i]);
    }
    printf("-------+---------------+ \n");

    printf("Mayor sueldo: $%.2f (Legajo %d) \n", mayor_sueldo, legajo_mayor_sueldo);
    printf("Empleados con mas de 10 anos de antiguedad: %d \n", cant_viejos);
    printf("Cantidad de hombres: %d \n", cant_hombres);
    printf("Cantidad de mujeres: %d \n", cant_mujeres);
    getch();
    return 0;
}
