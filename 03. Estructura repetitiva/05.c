/**
 Confeccionar un programa que :
a) Solicite el ingreso de un valor entero N, <= 12
y luego una lista de N números reales.
b) Calcule e informe :
1) el promedio de los positivos
2) el promedio de los negativos
3) la cantidad de ceros.
c) Si el valor ingresado N es mayor que 12 informar 'VALOR EXCEDIDO ' y FINALIZAR
*/

#include <stdio.h>

int main()
{
    int n,
        i,
        num,
        cant_pos   = 0,
        cant_neg   = 0,
        suma_pos   = 0,
        suma_neg   = 0,
        cant_ceros = 0;

    float prom_pos,
          prom_neg;

    printf("Ingrese un numero entre 1-12: ");
    scanf("%d", &n);
    fflush(stdin);
    if (0 < n && n < 13)
    {
        printf("Ingrese %d numeros: ", n);
        for (i=0; i<n; i++)
        {
            scanf("%d", &num);
            if (num == 0)
            {
                cant_ceros++;
            }
            else if (num > 0)
            {
                suma_pos += num;
                cant_pos++;
            }
            else
            {
                suma_neg += num;
                cant_neg++;
            }
        }
            if (cant_pos == 0)
            {
                prom_pos = 0;
            }
            else
            {
                prom_pos = (float)suma_pos / cant_pos;
            }
            if (cant_neg == 0)
            {
                prom_neg = 0;
            }
            else
            {
                prom_neg = (float)(suma_neg*-1) / cant_neg;
            }

            printf("Promedio positivos: %.2f\n", prom_pos);
            printf("Promedio negativos: %.2f\n", prom_neg);
            printf("Cantidad de ceros: %d", cant_ceros);
    }
    else
    {
      printf("ERROR! Numero invalido.");
      return 123;
    }

    return 0;
}



