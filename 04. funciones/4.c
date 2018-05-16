/**
Se realizó un concurso de tiro al blanco. Por cada participante se ingresa un número que lo
identifica y el resultado de los disparos efectuados.
El ingreso finaliza con un número de participante negativo.
Cada participante efectúa 10 disparos, registrándose las coordenadas X-Y de cada disparo.
 No considere disparos sobre los ejes pero sí en el centro (si es sobre los ejes las coordenadas
deberán volver a ingresarse).
 Para determinar el cuadrante utilizar la función CUADRANTE que reciba las dos coordenadas
y retorne el cuadrante al cual pertenece (1 a 4) y 0 para indicar un tiro en el centro.
Para calcular el puntaje utilizar la función PUNTAJE que reciba 5 parámetros que representan la
cantidad disparos en cada eje y en el centro. La función debe retornar el puntaje obtenido según la
siguiente escala:
 Cuadrantes 1 y 2: 50 puntos
 Cuadrantes 3 y 4: 40 puntos
 Centro: 100 puntos
Determinar:
a) Puntaje obtenido por cada participante, detallando cuantos disparos realizó en cada
cuadrante.
b) Mostrar el número del participante ganador y el puntaje obtenido.
c) Cantidad total de disparos en el centro (de todos los participantes)
*/

#include <stdio.h>
#include <conio.h>

int cuadrante(int x, int y)
{
    int cuad;
    if (x == 0  &&  y == 0)
        cuad = 0;
    else if (x > 0  &&  y > 0)
        cuad = 1;
    else if (x < 0  &&  y > 0)
        cuad = 2;
    else if (x < 0  &&  y < 0)
        cuad = 3;
    else if (x > 0  &&  y < 0)
        cuad = 4;
    return cuad;
}

int puntaje(int cuad_0, int cuad_1, int cuad_2, int cuad_3, int cuad_4)
{
    return (cuad_0 * 100  +  (cuad_1 + cuad_2) * 50  +  (cuad_3 + cuad_4) * 40);
}
int main()
{
    int i,
        x,
        y,
        cuad,
        cuad_0,
        cuad_1,
        cuad_2,
        cuad_3,
        cuad_4,
        puntos,
        participante;

    while (1)
    {
        printf("ID Participante: ");
        scanf("%d", &participante);
        fflush(stdin);
        if (participante < 0) break; // salida del while
        cuad_0 = cuad_1 = cuad_2 = cuad_3 = cuad_4 = 0;
        for (i = 0; i < 10; i++)
        {
            printf("Coords. disparo %d (x y): ", i + 1);
            scanf("%d%d", &x, &y);
            fflush(stdin);
            if ((x == 0) == (y == 0))
            {
                break;
            }
            printf("Disparo sobre eje no cuenta!");

            cuad = cuadrante(x, y);
            switch(cuad)
            {
            case 0:
                cuad_0++;
            case 1:
                cuad_1++;
            case 2:
                cuad_2++;
            case 3:
                cuad_3++;
            case 4:
                cuad_4++;
            }
        }
        puntos = puntaje(cuad_0, cuad_1, cuad_2, cuad_3, cuad_4);

        //TODO terminar
    }
}
