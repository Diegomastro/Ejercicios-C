/**
Ingresar N artículos (códigos) y sus correspondientes precios. Indicar el artículo más caro y el precio
más barato.
NOTA: TODOS LOS ARTICULOS TIENEN PRECIOS DISTINTOS
*/
#include <stdio.h>
#include <conio.h>
#include <limits.h>

/*
Pide al usuario y valida una cantidad.
VALORES VALIDOS:
(valor > 0)
*/
int get_cant()
{
    int cant;
    while (1)
    {
        printf("Cant de articulos: ");
        scanf("%d", &cant);
        fflush(stdin);
        if (0 < cant && cant < 51)
        {
            return cant;
        }
        printf("Debe estar entre 1 y 50 \n");
    }
}

/*
Pide al usuario y valida un codigo.
VALORES VALIDOS:
(valor >= 0 )
*/
int get_cod()
{
    int cod;
    while (1)
    {
    printf("Cod. de articulo: ");
    scanf("%d", &cod);
    fflush(stdin);
    if (cod >= 0)
    {
        return cod;
    }
    printf("CODIGO INVALIDO! \n");
    }

}


/*
Pide al usuario y valida un precio.
VALORES VALIDOS:
(valor > 0)
*/
float get_precio()
{
    float precio;
    while (1)
    {
    printf("Precio: $");
    scanf("%f", &precio);
    fflush(stdin);
    if (precio > 0)
    {
        return precio;
    }
    printf("PRECIO INVALIDO! \n");
    }
}


int main()
{
    int i,
    cod,
    cant,
    cod_max;

    float precio,
    precio_min = INT_MAX,
    precio_max = 0;

    cant = get_cant();
    for (i = 0; i < cant; i++)
    {
        cod = get_cod();
        precio = get_precio();

        if (precio > precio_max)
        {
            precio_max = precio;
            cod_max    = cod;
        }
        if (precio < precio_min)
        {
            precio_min = precio;
        }
    }
    printf("Precio mas barato: $%.2f \n", precio_min);
    printf("Articulo mas caro: %d ($%.2f) \n", cod_max, precio_max);
    getch();
    return 0;
}
