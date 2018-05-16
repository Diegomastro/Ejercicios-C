/**
 Se realizó un concurso de tiro al blanco. Existen 5 participantes y cada uno de ellos efectúa 10 disparos,
registrándose las coordenadas X-Y de cada disparo.
Determinar:
a-) Cuantos disparos se efectuaron en cada cuadrante por cada participante
b-) Cuantos disparos se efectuaron en total en el centro.
*/
#include <stdio.h>
#include <conio.h>

int main()
{
    int i,
        j,
        x,
        y,
        cuad_0,
        cuad_1,
        cuad_2,
        cuad_3,
        cuad_4,
        eje,
        total_0 = 0;
    printf("CONTADOR DE DISPAPROS");
    printf("(Nota: Inserte las coordenadas x y separadas con un espacio)");
    for(i=1;i<=5;i++)
    {
        cuad_0 = cuad_1 = cuad_2 = cuad_3 = cuad_4 = eje = 0;
        printf("Participante %d: \n", i);
        for (j = 1; j <= 10; j++)
        {
            printf("Disparo %d:", j);
            scanf("%d%d", &x, &y);
            fflush(stdin);
            if (x == 0  &&  y == 0)
            {
                total_0++;
                cuad_0++;
            }
            else if (x > 0  &&  y > 0)
            {
                cuad_1++;
            }
            else if (x < 0  &&  y > 0)
            {
                cuad_2++;
            }
            else if (x < 0  &&  y < 0)
            {
                cuad_3++;
            }
            else if (x > 0  &&  y < 0)
            {
                cuad_4++;
            }
            else
            {
                eje++;
            }
        }

        printf("Cuadrante 1: %d \n", cuad_1);
        printf("Cuadrante 2: %d \n", cuad_2);
        printf("Cuadrante 3: %d \n", cuad_3);
        printf("Cuadrante 4: %d \n", cuad_4);
        printf("Sobre  ejes: %d \n", eje)   ;
        printf("Al Centro!!: %d \n", cuad_0);
        printf("--- \n");
    }
    printf("Total tiros al centro: %d", total_0);
    getch();
    return 0;
}
