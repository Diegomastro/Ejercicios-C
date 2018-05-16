/*
Se ingresan DNI y la nota promedio de 40 alumnos.
Determinar el DNI de los alumnos de mayor nota promedio.
*/
#include <stdio.h>
#include <conio.h>

int main()
{
    int i,
        j,
        dni,
        nota,
        mejor_nota = 0;

    int mejores[40]  = {0};
    int cont_mejores = 0;

    for (i = 0; i < 40; i++)
    {
        //Insertar y validar DNI
        while (1)
        {
            printf("DNI: ");
            scanf("%d", &dni);
            fflush(stdin);
            if (0 < dni && dni < 100000000)
            {
                break;
            }
            else
            {
                printf("DNI INVALIDO! \n");
            }
        }

        //Insertar y validar nota
        while (1)
        {
            printf("Nota: ");
            scanf("%d", &nota);
            fflush(stdin);
            if (0 <= nota && nota <= 10)
            {
                break;
            }
            else
            {
                printf("NOTA INVALIDA! \n");
            }
        }

        //chequear la nota
        if (nota == mejor_nota)
        {
            mejores[cont_mejores] = dni;
            cont_mejores++;
        }
        else if (nota > mejor_nota)
        {
            mejor_nota = nota;
            for (j = 0; j < 40; j++)
            {
                if (mejores[j] == 0)
                {
                    break;
                }
                mejores[j] = 0;
            }
            mejores[0] = dni;
            cont_mejores = 1;
        }
    }

    printf("Mejor Nota: %d \n", mejor_nota);
    printf("DNIs: \n");
    for (i = 0; i < 40; i++)
    {
        if (mejores[i] == 0)
        {
            break;
        }
        printf("%08d \n", mejores[i]);
    }
    getch();
    return 0;
}
